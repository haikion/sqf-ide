/**
 * @(#) ExportPboWizard.java
 */

package org.arma.side.wizards;

import org.arma.side.PboArchiver;
import org.eclipse.core.resources.IProject;
import org.eclipse.core.runtime.IPath;
import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.jface.wizard.Wizard;
import org.eclipse.ui.IExportWizard;
import org.eclipse.ui.IWorkbench;

public class ExportPboWizard extends Wizard implements IExportWizard
{
    private ExportPboPage page_;
    private IPath projectPath_;

    @Override
    public boolean performFinish()
    {
    	if (projectPath_ == null)
    	{
    		System.out.println("ERROR: project path is null...");
    		return false;
    	}
        PboArchiver.pack(projectPath_.toFile(), page_.getMissionLocation());
        return true;
    }

	@Override
	public void init(IWorkbench workbench, IStructuredSelection selection)
	{
	    Object obj = selection.getFirstElement();
	    if (obj instanceof IProject)
	    {
	    	IProject project = (IProject) obj;
	    	projectPath_ = project.getLocation();
	    	System.out.println("projectPath_ = " + projectPath_);
	    }
	    page_ = new ExportPboPage("Export as PBO", selection);
	}
	
    @Override
    public void addPages()
    {
        addPage(page_);
    }
}
