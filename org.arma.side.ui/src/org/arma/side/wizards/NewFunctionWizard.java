/**
 * @(#) NewFunctionWizard.java
 */

package org.arma.side.wizards;

import java.io.File;

import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.jface.wizard.Wizard;
import org.eclipse.ui.INewWizard;
import org.eclipse.ui.IWorkbench;

public class NewFunctionWizard extends Wizard implements INewWizard
{
    private String functionName;
    
    private String functionsFile;
    
    private NewFunctionPage page_;
    
    private void introduceFunction( String name, File file )
    {
        
    }

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
