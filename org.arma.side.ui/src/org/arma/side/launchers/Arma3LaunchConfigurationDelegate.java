package org.arma.side.launchers;
import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.text.MessageFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.eclipse.core.resources.IContainer;
import org.eclipse.core.resources.IFile;
import org.eclipse.core.resources.IResource;
import org.eclipse.core.resources.ResourcesPlugin;
import org.eclipse.core.runtime.CoreException;
import org.eclipse.core.runtime.IPath;
import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Path;
import org.eclipse.core.runtime.Status;
import org.eclipse.debug.core.DebugEvent;
import org.eclipse.debug.core.ILaunch;
import org.eclipse.debug.core.ILaunchConfiguration;
import org.eclipse.debug.core.model.IDebugTarget;
import org.eclipse.debug.core.model.ILaunchConfigurationDelegate;
import org.eclipse.debug.core.model.IProcess;
import org.eclipse.core.variables.VariablesPlugin;

public class Arma3LaunchConfigurationDelegate
        implements ILaunchConfigurationDelegate
{    
	
	
	/**
	 * Status code indicating that no launch configuration was specified.
	 * 
	 * @since 2.1
	 */
	public static final int ERR_UNSPECIFIED_LAUNCH_CONFIG = 122;	
	
	/**
	 * Launch configuration attribute key. The value is a string specifying
	 * program arguments for a Java launch configuration, as they should appear
	 * on the command line.
	 */
	//public static final String ATTR_PROGRAM_ARGUMENTS = LaunchingPlugin.getUniqueIdentifier() + ".PROGRAM_ARGUMENTS"; //$NON-NLS-1$
	public static final String ATTR_PROGRAM_ARGUMENTS = "UNDEFINED"; //$NON-NLS-1$
	
	/**
	 * Status code indicating the specified working directory
	 * does not exist.
	 */
	public static final int ERR_WORKING_DIRECTORY_DOES_NOT_EXIST = 108;	
	
    /**
     * Mapping of ILaunch objects to File objects that represent the .html file
     * used to initiate the applet launch.  This is used to delete the .html
     * file when the launch terminates.
     */
    private static Map fgLaunchToFileMap = new HashMap();
    
	/**
	 * Launch configuration attribute key. The value is a string specifying a
	 * path to the working directory to use when launching a local VM.
	 * When specified as an absolute path, the path represents a path in the local
	 * file system. When specified as a full path, the path represents a workspace
	 * relative path. When unspecified, the working directory defaults to the project
	 * associated with a launch configuration. When no project is associated with a
	 * launch configuration, the working directory is inherited from the current
	 * process.
	 */
	//public static final String ATTR_WORKING_DIRECTORY = LaunchingPlugin.getUniqueIdentifier() + ".WORKING_DIRECTORY";	 //$NON-NLS-1$
    public static final String ATTR_WORKING_DIRECTORY = "UNDEFINED";
    
	/**
	 * Throws a core exception with an error status object built from the given
	 * message, lower level exception, and error code.
	 * 
	 * @param message
	 *            the status message
	 * @param exception
	 *            lower level exception associated with the error, or
	 *            <code>null</code> if none
	 * @param code
	 *            error code
	 * @throws CoreException
	 *             the "abort" core exception
	 */
	protected void abort(String message, Throwable exception, int code)
			throws CoreException 
	{
		throw new CoreException(new Status(IStatus.ERROR, "org.arma.side", "Aborted"));
	}
    
    public void launch(ILaunchConfiguration configuration, String mode, 
            ILaunch launch, IProgressMonitor monitor) throws CoreException 
    {
    	

    	
        if (configuration == null) {
            abort("JavaAppletLaunchConfigurationDelegate.No_launch_configuration_specified_1",
                    null, ERR_UNSPECIFIED_LAUNCH_CONFIG); //$NON-NLS-1$
        }
        
        monitor.beginTask("JavaAppletLaunchConfigurationDelegate.Starting_Applet_{0}..._1", 3); //$NON-NLS-1$
        monitor.subTask("JavaAppletLaunchConfigurationDelegate.Verifying_launch_attributes..._1"); //$NON-NLS-1$
        
        File workingDir = verifyWorkingDirectory(configuration);
        String parameters = 
                configuration.getAttribute(ATTR_PROGRAM_ARGUMENTS, (String) null);
        
        launchArma3(workingDir, null, parameters);
        monitor.done();
    }
    
    protected void launchArma3(File arma3Dir, IFile missionFile, String startupParameters)
    {
        if (arma3Dir == null)
        {
            System.out.println("Error: arma3Dir undefined");
            return;
        }
        
        Process process;
        String line;
        String arma3Exe = arma3Dir.getAbsolutePath();;
        List<String> parametersList = new ArrayList<String>();
        if (startupParameters != null && !startupParameters.isEmpty())
        {
            //Split produces list size 1 even if string is empty...
            parametersList = Arrays.asList(startupParameters.split(" "));
        }
        List<String> cmdList = new ArrayList<String>();
        cmdList.add(arma3Exe);
        File mod = new File("@SI");
        cmdList.add("-mod=" + mod.getAbsolutePath());
        cmdList.addAll(parametersList);
        if (missionFile != null)
        {
            cmdList.add(missionFile.getLocation().toOSString());            
        }
        System.out.println("Running: " + arma3Exe + " parameters =" + cmdList.toString() ); //TODO: Print in runtime eclipse...
        try
        {
            process = new ProcessBuilder(cmdList).start();
            /*
            InputStream is = process.getInputStream();
            InputStreamReader isr = new InputStreamReader(is);
            BufferedReader br = new BufferedReader(isr);

            while ((line = br.readLine()) != null)
            {
                System.out.println(line);
            }
            */

        } catch (IOException e)
        {
            e.printStackTrace();
        }
    }
    
    private String getQuotedString(String string) {
        if (string.indexOf('"') == -1) {
            return '"' + string + '"';
        } 
        return '\'' + string + '\'';
    }
    
    /* (non-Javadoc)
     * @see org.eclipse.debug.core.IDebugEventSetListener#handleDebugEvents(org.eclipse.debug.core.DebugEvent[])
     */
    public void handleDebugEvents(DebugEvent[] events) {
        for (int i = 0; i < events.length; i++) {
            DebugEvent event = events[i];
            Object eventSource = event.getSource();
            switch(event.getKind()) {
                
                // Delete the HTML file used for the launch
                case DebugEvent.TERMINATE :
                    if (eventSource != null) {
                        ILaunch launch = null;
                        if (eventSource instanceof IProcess) {
                            IProcess process = (IProcess) eventSource;
                            launch = process.getLaunch();
                        } else if (eventSource instanceof IDebugTarget) {
                            IDebugTarget debugTarget = (IDebugTarget) eventSource;
                            launch = debugTarget.getLaunch();
                        }
                        File temp = (File) fgLaunchToFileMap.get(launch);
                        if (temp != null) {
                            try {
                                fgLaunchToFileMap.remove(launch);
                                temp.delete();
                            } finally {
                                //if (fgLaunchToFileMap.isEmpty()) {
                                //    DebugPlugin.getDefault().removeDebugEventListener(this);
                                //}
                            }
                        }
                    }
                    break;
            }
        }
    }

    /**
     * Returns the contents of the given file as a byte array.
     * @throws IOException if a problem occured reading the file.
     */
    protected static byte[] getFileByteContent(File file) throws IOException {
        InputStream stream = null;
        try {
            stream = new BufferedInputStream(new FileInputStream(file));
            return getInputStreamAsByteArray(stream, (int) file.length());
        } finally {
            if (stream != null) {
                try {
                    stream.close();
                } catch (IOException e) {
                }
            }
        }
    }
    
    /**
     * Returns the given input stream's contents as a byte array.
     * If a length is specified (ie. if length != -1), only length bytes
     * are returned. Otherwise all bytes in the stream are returned.
     * Note this doesn't close the stream.
     * @throws IOException if a problem occured reading the stream.
     */
    protected static byte[] getInputStreamAsByteArray(InputStream stream, int length)
        throws IOException {
        byte[] contents;
        if (length == -1) {
            contents = new byte[0];
            int contentsLength = 0;
            int bytesRead = -1;
            do {
                int available = stream.available();

                // resize contents if needed
                if (contentsLength + available > contents.length) {
                    System.arraycopy(
                        contents,
                        0,
                        contents = new byte[contentsLength + available],
                        0,
                        contentsLength);
                }

                // read as many bytes as possible
                bytesRead = stream.read(contents, contentsLength, available);

                if (bytesRead > 0) {
                    // remember length of contents
                    contentsLength += bytesRead;
                }
            } while (bytesRead > 0);

            // resize contents if necessary
            if (contentsLength < contents.length) {
                System.arraycopy(
                    contents,
                    0,
                    contents = new byte[contentsLength],
                    0,
                    contentsLength);
            }
        } else {
            contents = new byte[length];
            int len = 0;
            int readSize = 0;
            while ((readSize != -1) && (len != length)) {
                // See PR 1FMS89U
                // We record first the read size. In this case len is the actual read size.
                len += readSize;
                readSize = stream.read(contents, len, length - len);
            }
        }

        return contents;
    }
    
    
    /* (non-Javadoc)
     * @see org.eclipse.jdt.launching.AbstractJavaLaunchConfigurationDelegate#verifyWorkingDirectory(org.eclipse.debug.core.ILaunchConfiguration)
     */
    public File verifyWorkingDirectory(ILaunchConfiguration configuration) throws CoreException {
        IPath path = getWorkingDirectoryPath(configuration); //Copy This
        if (path == null) {
            // default working dir for applets is the project's output directory
        	String outputDir = null;
            //String outputDir = JavaRuntime.getProjectOutputDirectory(configuration); //Copy this
            if (outputDir == null) {
                // if no project attribute, default to eclipse directory
                return new File(System.getProperty("user.dir"));  //$NON-NLS-1$
            }
            IResource resource = ResourcesPlugin.getWorkspace().getRoot().findMember(outputDir);
            if (resource == null || !resource.exists()) {
                //default to eclipse directory
                return new File(System.getProperty("user.dir"));  //$NON-NLS-1$
            }
            return resource.getLocation().toFile(); 
        } 
        if (path.isAbsolute()) {
            File dir = new File(path.toOSString());
            if (dir.isDirectory()) {
                return dir;
            } 
            abort(MessageFormat.format("AbstractJavaLaunchConfigurationDelegate.Working_directory_does_not_exist__{0}_12", new String[] {path.toString()}), null, ERR_WORKING_DIRECTORY_DOES_NOT_EXIST); //$NON-NLS-1$
        } else {
            IResource res = ResourcesPlugin.getWorkspace().getRoot().findMember(path);
            if (res instanceof IContainer && res.exists()) {
                return res.getLocation().toFile();
            } 
            abort(MessageFormat.format("AbstractJavaLaunchConfigurationDelegate.Working_directory_does_not_exist__{0}_12", new String[] {path.toString()}), null, ERR_WORKING_DIRECTORY_DOES_NOT_EXIST); //$NON-NLS-1$
        }
        // cannot return null - an exception will be thrown
        return null;        
    }
    
	/**
	 * Returns the working directory path specified by the given launch
	 * configuration, or <code>null</code> if none.
	 * 
	 * @param configuration
	 *            launch configuration
	 * @return the working directory path specified by the given launch
	 *         configuration, or <code>null</code> if none
	 * @exception CoreException
	 *                if unable to retrieve the attribute
	 */
	public IPath getWorkingDirectoryPath(ILaunchConfiguration configuration)
			throws CoreException {
		String path = configuration.getAttribute(
				ATTR_WORKING_DIRECTORY,
				(String) null);
		if (path != null) {
			path = VariablesPlugin.getDefault().getStringVariableManager()
					.performStringSubstitution(path);
			return new Path(path);
		}
		return null;
	}
}
