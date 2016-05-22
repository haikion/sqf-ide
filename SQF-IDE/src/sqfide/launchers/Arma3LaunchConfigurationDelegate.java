package sqfide.launchers;
import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.text.MessageFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

import org.eclipse.core.resources.IContainer;
import org.eclipse.core.resources.IFile;
import org.eclipse.core.resources.IProject;
import org.eclipse.core.resources.IResource;
import org.eclipse.core.resources.ResourcesPlugin;
import org.eclipse.core.runtime.CoreException;
import org.eclipse.core.runtime.IPath;
import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.core.runtime.Path;
import org.eclipse.debug.core.DebugEvent;
import org.eclipse.debug.core.DebugPlugin;
import org.eclipse.debug.core.IDebugEventSetListener;
import org.eclipse.debug.core.ILaunch;
import org.eclipse.debug.core.ILaunchConfiguration;
import org.eclipse.debug.core.ILaunchManager;
import org.eclipse.debug.core.model.IDebugTarget;
import org.eclipse.debug.core.model.ILaunchConfigurationDelegate;
import org.eclipse.debug.core.model.IProcess;
import org.eclipse.jdt.launching.AbstractJavaLaunchConfigurationDelegate;
import org.eclipse.jdt.launching.IJavaLaunchConfigurationConstants;
import org.eclipse.jdt.launching.JavaRuntime;
import org.eclipse.jface.viewers.IStructuredSelection;


public class Arma3LaunchConfigurationDelegate
        extends AbstractJavaLaunchConfigurationDelegate
        implements ILaunchConfigurationDelegate
{    
    /**
     * Mapping of ILaunch objects to File objects that represent the .html file
     * used to initiate the applet launch.  This is used to delete the .html
     * file when the launch terminates.
     */
    private static Map fgLaunchToFileMap = new HashMap();
    
    public void launch(ILaunchConfiguration configuration, String mode, 
            ILaunch launch, IProgressMonitor monitor) throws CoreException 
    {
        if (configuration == null) {
            abort("JavaAppletLaunchConfigurationDelegate.No_launch_configuration_specified_1",
                    null, IJavaLaunchConfigurationConstants.ERR_UNSPECIFIED_LAUNCH_CONFIG); //$NON-NLS-1$
        }
        
        monitor.beginTask("JavaAppletLaunchConfigurationDelegate.Starting_Applet_{0}..._1", 3); //$NON-NLS-1$
        monitor.subTask("JavaAppletLaunchConfigurationDelegate.Verifying_launch_attributes..._1"); //$NON-NLS-1$
        
        File workingDir = verifyWorkingDirectory(configuration);
        String parameters = 
                configuration.getAttribute(IJavaLaunchConfigurationConstants.ATTR_PROGRAM_ARGUMENTS, (String) null);
        
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
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }
    
    /* (non-Javadoc)
     * @see org.eclipse.debug.core.model.ILaunchConfigurationDelegate#launch(org.eclipse.debug.core.ILaunchConfiguration, java.lang.String, org.eclipse.debug.core.ILaunch, org.eclipse.core.runtime.IProgressMonitor)
     */
    /*
    public void launch2(ILaunchConfiguration configuration, String mode, ILaunch launch, IProgressMonitor monitor) throws CoreException {
            
        if (configuration == null) {
            abort("JavaAppletLaunchConfigurationDelegate.No_launch_configuration_specified_1", null, IJavaLaunchConfigurationConstants.ERR_UNSPECIFIED_LAUNCH_CONFIG); //$NON-NLS-1$
        }
        
        monitor.beginTask("JavaAppletLaunchConfigurationDelegate.Starting_Applet_{0}..._1", 3); //$NON-NLS-1$
        monitor.subTask("JavaAppletLaunchConfigurationDelegate.Verifying_launch_attributes..._1"); //$NON-NLS-1$
        
        verifyMainTypeName(configuration);

        IVMInstall vm = verifyVMInstall(configuration);

        IVMRunner runner = vm.getVMRunner(mode);
        if (runner == null) {
            if (mode == ILaunchManager.DEBUG_MODE) {
                abort(MessageFormat.format("JavaLocalApplicationLaunchConfigurationDelegate.0", 
                        new String[]{vm.getName()}), null, IJavaLaunchConfigurationConstants.ERR_VM_RUNNER_DOES_NOT_EXIST); 
                //$NON-NLS-1$
            } else {
                abort(MessageFormat.format("JavaLocalApplicationLaunchConfigurationDelegate.1",
                        new String[]{vm.getName()}), null, IJavaLaunchConfigurationConstants.ERR_VM_RUNNER_DOES_NOT_EXIST);
                //$NON-NLS-1$
            }
        }

        File workingDir = verifyWorkingDirectory(configuration);
        String workingDirName = workingDir.getAbsolutePath();
        
        // Program & VM args
        String javaPolicy = getJavaPolicyFile(workingDir);
        ExecutionArguments execArgs = new ExecutionArguments(getVMArguments(configuration), ""); //$NON-NLS-1$
        // Classpath
        String[] classpath = getClasspath(configuration);
        
        // Create VM config
        String appletViewerClassName = configuration.getAttribute(IJavaLaunchConfigurationConstants.
                ATTR_APPLET_APPLETVIEWER_CLASS, IJavaLaunchConfigurationConstants.DEFAULT_APPLETVIEWER_CLASS);
        VMRunnerConfiguration runConfig = new VMRunnerConfiguration(appletViewerClassName, classpath);
        
        // Construct the HTML file and set its name as a program argument
        File htmlFile = buildHTMLFile(configuration, workingDir);
        if (htmlFile == null) {
            abort("JavaAppletLaunchConfigurationDelegate.Could_not_build_HTML_file_for_applet_launch_1", null, IJavaLaunchConfigurationConstants.ERR_COULD_NOT_BUILD_HTML); //$NON-NLS-1$
        }           
        runConfig.setProgramArguments(new String[] {htmlFile.getName()});
        
        // Retrieve & set the VM arguments
        String[] vmArgs = execArgs.getVMArgumentsArray();
        String[] realArgs = new String[vmArgs.length+1];
        System.arraycopy(vmArgs, 0, realArgs, 1, vmArgs.length);
        realArgs[0] = javaPolicy;
        runConfig.setVMArguments(realArgs);
        
        runConfig.setWorkingDirectory(workingDirName);

        // Bootpath
        runConfig.setBootClassPath(getBootpath(configuration));
        
        // VM-specific attributes
        Map vmAttributesMap = getVMSpecificAttributesMap(configuration);
        runConfig.setVMSpecificAttributesMap(vmAttributesMap);
        
        monitor.worked(1);
        
        // Add a debug listener if necessary 
        if (fgLaunchToFileMap.isEmpty()) {
            DebugPlugin.getDefault().addDebugEventListener(this);
        }
        
        // Add a mapping of the launch to the html file 
        fgLaunchToFileMap.put(launch, htmlFile);
        
        monitor.subTask("JavaAppletLaunchConfigurationDelegate.Creating_source_locator..._2"); //$NON-NLS-1$
        // Set default source locator if none specified
        setDefaultSourceLocator(launch, configuration);
        monitor.worked(1);      

        // Launch the configuration
        try {
            runner.run(runConfig, launch, monitor);     
        } catch (CoreException ce) {
            htmlFile.delete();
            throw ce;
        }
        
        monitor.done();
    }
    */

    /**
     * Returns the system property string for the policy file
     * 
     * @param workingDir the working directory
     * @return system property for the policy file
     */
    /*
    public String getJavaPolicyFile(File workingDir) {
            File file = new File(workingDir, "java.policy.applet");//$NON-NLS-1$ 
            if (!file.exists()) {
                // copy it to the working directory
                File test = LaunchingPlugin.getFileInPlugin(new Path("java.policy.applet")); //$NON-NLS-1$
                try {
                    byte[] bytes = getFileByteContent(test);
                    BufferedOutputStream outputStream = new BufferedOutputStream(new FileOutputStream(file));
                    outputStream.write(bytes);
                    outputStream.close();
                } catch (IOException e) {
                    return "";//$NON-NLS-1$
                }
            }
        return "-Djava.security.policy=java.policy.applet";//$NON-NLS-1$
    }
    */
    /**
     * Using the specified launch configuration, build an HTML file that specifies the
     * applet to launch.  Return the name of the HTML file.
     * 
     * @param dir the directoru in which to make the file
     */
    /*
    private File buildHTMLFile(ILaunchConfiguration configuration, File dir) {
        FileWriter writer = null;
        File tempFile = null;
        try {
            String name = getMainTypeName(configuration);
            tempFile = new File(dir, name + System.currentTimeMillis() + ".html"); //$NON-NLS-1$ //$NON-NLS-2$
            writer = new FileWriter(tempFile);
            writer.write("<html>\n"); //$NON-NLS-1$
            writer.write("<body>\n"); //$NON-NLS-1$
            writer.write("<applet code="); //$NON-NLS-1$
            writer.write(name);
            writer.write(".class "); //$NON-NLS-1$
            String appletName = configuration.getAttribute(IJavaLaunchConfigurationConstants.ATTR_APPLET_NAME, ""); //$NON-NLS-1$
            if (appletName.length() != 0) {
                writer.write("NAME =\"" + appletName + "\" "); //$NON-NLS-1$ //$NON-NLS-2$
            }
            writer.write("width=\""); //$NON-NLS-1$
            writer.write(Integer.toString(configuration.getAttribute(IJavaLaunchConfigurationConstants.ATTR_APPLET_WIDTH, 200))); //$NON-NLS-1$
            writer.write("\" height=\""); //$NON-NLS-1$
            writer.write(Integer.toString(configuration.getAttribute(IJavaLaunchConfigurationConstants.ATTR_APPLET_HEIGHT, 200))); //$NON-NLS-1$
            writer.write("\" >\n"); //$NON-NLS-1$
            Map parameters = configuration.getAttribute(IJavaLaunchConfigurationConstants.ATTR_APPLET_PARAMETERS, new HashMap());
            if (parameters.size() != 0) {
                Iterator iterator= parameters.entrySet().iterator();
                while(iterator.hasNext()) {
                    Map.Entry next = (Map.Entry) iterator.next();
                    writer.write("<param name="); //$NON-NLS-1$
                    writer.write(getQuotedString((String)next.getKey()));
                    writer.write(" value="); //$NON-NLS-1$
                    writer.write(getQuotedString((String)next.getValue()));
                    writer.write(">\n"); //$NON-NLS-1$
                }
            }
            writer.write("</applet>\n"); //$NON-NLS-1$
            writer.write("</body>\n"); //$NON-NLS-1$
            writer.write("</html>\n"); //$NON-NLS-1$
        } catch(IOException e) {
        } catch(CoreException e) {
        } finally {
            if (writer != null) {
                try {
                    writer.close();
                } catch(IOException e) {
                }
            }
        }
        if (tempFile == null) {
            return null;
        }
        return tempFile;
    }
    */
    
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
                                if (fgLaunchToFileMap.isEmpty()) {
                                    DebugPlugin.getDefault().removeDebugEventListener(this);
                                }
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
            String outputDir = JavaRuntime.getProjectOutputDirectory(configuration); //Copy this
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
            abort(MessageFormat.format("AbstractJavaLaunchConfigurationDelegate.Working_directory_does_not_exist__{0}_12", new String[] {path.toString()}), null, IJavaLaunchConfigurationConstants.ERR_WORKING_DIRECTORY_DOES_NOT_EXIST); //$NON-NLS-1$
        } else {
            IResource res = ResourcesPlugin.getWorkspace().getRoot().findMember(path);
            if (res instanceof IContainer && res.exists()) {
                return res.getLocation().toFile();
            } 
            abort(MessageFormat.format("AbstractJavaLaunchConfigurationDelegate.Working_directory_does_not_exist__{0}_12", new String[] {path.toString()}), null, IJavaLaunchConfigurationConstants.ERR_WORKING_DIRECTORY_DOES_NOT_EXIST); //$NON-NLS-1$
        }
        // cannot return null - an exception will be thrown
        return null;        
    }
}
