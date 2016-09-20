package org.arma.side.wizards;

import org.eclipse.core.resources.IFile;
import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.jface.wizard.Wizard;
import org.eclipse.ui.INewWizard;
import org.eclipse.ui.IWorkbench;

public class NewSQFFileWizard extends Wizard implements INewWizard
{

    private IStructuredSelection selection_;
    private NewSQFFileWizardPage newFileWizardPage_;
 

    public NewSQFFileWizard() {
        setWindowTitle("New Config File");
    } 

    @Override
    public void addPages() {
        newFileWizardPage_ = new NewSQFFileWizardPage(selection_);
        addPage(newFileWizardPage_);
    }
   
    @Override
    public boolean performFinish() 
    {
        IFile file = newFileWizardPage_.createNewFile();
        if (file != null)
            return true;
        else
            return false;
    }

    public void init(IWorkbench workbench, IStructuredSelection selection) 
    {
        this.selection_ = selection;
    }
}
