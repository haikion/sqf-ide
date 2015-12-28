package sqfide.launchers;

import java.io.File;

import org.eclipse.core.resources.IContainer;
import org.eclipse.core.resources.IProject;
import org.eclipse.core.runtime.CoreException;
import org.eclipse.debug.core.ILaunchConfiguration;
import org.eclipse.debug.internal.ui.DebugUIMessages;
import org.eclipse.debug.ui.WorkingDirectoryBlock;
import org.eclipse.jdt.core.IJavaProject;
import org.eclipse.jdt.internal.debug.ui.IJavaDebugHelpContextIds;
import org.eclipse.jdt.launching.IJavaLaunchConfigurationConstants;
import org.eclipse.jdt.launching.JavaRuntime;

public class Arma3WorkingDirectoryBlock extends WorkingDirectoryBlock
{    
    /**
     * Constructs a new working directory block.
     */
    public Arma3WorkingDirectoryBlock() {
        super(IJavaLaunchConfigurationConstants.ATTR_WORKING_DIRECTORY,
                IJavaDebugHelpContextIds.WORKING_DIRECTORY_BLOCK);
    }

    /* (non-Javadoc)
     * @see org.eclipse.debug.ui.WorkingDirectoryBlock#getProject(org.eclipse.debug.core.ILaunchConfiguration)
     */
    @Override
    protected IProject getProject(ILaunchConfiguration configuration)
            throws CoreException {
        IJavaProject project = JavaRuntime.getJavaProject(configuration);
        return project == null ? null : project.getProject();
    }

    /* (non-Javadoc)
     * @see org.eclipse.debug.ui.WorkingDirectoryBlock#log(org.eclipse.core.runtime.CoreException)
     */
    @Override
    protected void log(CoreException e) {
        setErrorMessage(e.getMessage());
    }
    
    /* (non-Javadoc)
     * @see org.eclipse.debug.ui.ILaunchConfigurationTab#isValid(org.eclipse.debug.core.ILaunchConfiguration)
     */
    @Override
    public boolean isValid(ILaunchConfiguration config) {
        if ( super.isValid(config) )
        {
            String workingDirPath = getWorkingDirectoryText();

            File Arma3Excutable = new File(workingDirPath + "/" + "arma3.exe");
            if ( Arma3Excutable.isFile() )
            {
                return true;
            }
            
            setErrorMessage("ArmA 3 executable (arma3.exe) not found in directory: " + workingDirPath);
        }
        return false;
    }
    
    /**
     * Sets the default working directory.
     */
    @Override
    protected void setDefaultWorkingDir() {
        try {
            ILaunchConfiguration config = getLaunchConfiguration();
            if (config != null) {
                IProject project = getProject(config);
                if (project != null) {
                    //TODO: Get steam dir
                    setDefaultWorkingDirectoryText("${workspace_loc:" + project.getFullPath().makeRelative().toOSString() + "}");  //$NON-NLS-1$//$NON-NLS-2$
                    return;
                }
            }
        }
        catch (CoreException ce) {
            log(ce);
        }
        setDefaultWorkingDirectoryText(System.getProperty("user.dir")); //$NON-NLS-1$
    }
}
