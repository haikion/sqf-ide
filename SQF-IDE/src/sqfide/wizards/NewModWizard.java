/**
 * @(#) NewModWizard.java
 */

package sqfide.wizards;

import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.jface.wizard.Wizard;
import org.eclipse.ui.INewWizard;
import org.eclipse.ui.IWorkbench;

public class NewModWizard extends Wizard implements INewWizard
{
    private NewModPage page_;

    @Override
    public void init(IWorkbench workbench, IStructuredSelection selection)
    {
        // TODO Auto-generated method stub
        
    }

    @Override
    public boolean performFinish()
    {
        // TODO Auto-generated method stub
        return false;
    }
}
