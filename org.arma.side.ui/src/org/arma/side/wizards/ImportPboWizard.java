/**
 * @(#) ImportPboWizard.java
 */

package org.arma.side.wizards;

import java.net.URI;

import org.arma.side.CustomFunctionsXml;
import org.arma.side.PboArchiver;
import org.eclipse.core.resources.IProject;
import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.ui.IImportWizard;
import org.eclipse.ui.IWorkbench;

public class ImportPboWizard extends ImportMissionWizard implements IImportWizard
{
    private ImportPboPage page_;
    
    @Override
	public void init(IWorkbench workbench, IStructuredSelection selection) 
	{
		setWindowTitle("Import ArmA 3 PBO Mission"); //NON-NLS-1
		setNeedsProgressMonitor(true);
		page_ = new ImportPboPage("Import ArmA 3 Mission", selection);
	}
    
    @Override
    public void addPages()
    {
        addPage(page_);
    }
    
	/* (non-Javadoc)
	 * @see org.eclipse.jface.wizard.Wizard#performFinish()
	 */
    @Override
    public boolean performFinish() 
    {
        String missionName = page_.getMissionName();
        URI location = page_.getMissionDIR().toURI();
        
        PboArchiver.extract(page_.getPboFile(), page_.getMissionDIR().getParentFile());;        
        IProject project = createProject(missionName, location);
        CustomFunctionsXml.createEmptyXml(project);
        
        if (project == null)
            return false;
        return true;
    }
}
