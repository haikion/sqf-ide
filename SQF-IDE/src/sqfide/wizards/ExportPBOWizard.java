/**
 * @(#) ExportPBOWizard.java
 */

package sqfide.wizards;

import org.eclipse.core.resources.IProject;
import org.eclipse.core.runtime.IPath;
import org.eclipse.jdt.core.IJavaProject;
import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.jface.wizard.Wizard;
import org.eclipse.ui.IExportWizard;
import org.eclipse.ui.IWorkbench;

import sqfide.PBOArchiver;

public class ExportPBOWizard extends Wizard implements IExportWizard
{
    private ExportPBOPage page_;
    private IPath projectPath_;

    @Override
    public boolean performFinish()
    {
    	if (projectPath_ == null)
    	{
    		System.out.println("ERROR: project path is null...");
    		return false;
    	}
        PBOArchiver.pack(projectPath_.toFile(), page_.getMissionLocation());
        return true;
    }

	@Override
	public void init(IWorkbench workbench, IStructuredSelection selection) {
		// TODO Auto-generated method stub
	    Object obj = selection.getFirstElement();
	    if (obj instanceof IProject)
	    {
	    	IProject project = (IProject)obj;
	    	projectPath_ = project.getLocation();
	    	System.out.println("projectPath_ = " + projectPath_);
	    }
	    page_ = new ExportPBOPage("Export as PBO", selection);
	}
	
    @Override
    public void addPages()
    {
        addPage(page_);
    }
}
