package org.arma.side;

import java.io.File;

import org.eclipse.core.commands.AbstractHandler;
import org.eclipse.core.commands.ExecutionEvent;
import org.eclipse.core.commands.ExecutionException;
import org.eclipse.core.commands.IHandler;
import org.eclipse.core.resources.IProject;
import org.eclipse.core.runtime.IAdaptable;
import org.eclipse.core.runtime.IPath;
import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.swt.SWT;
import org.eclipse.swt.widgets.DirectoryDialog;
import org.eclipse.ui.IWorkbenchWindow;
import org.eclipse.ui.PlatformUI;

public class IncludeModHandler extends AbstractHandler implements IHandler
{

    @Override
    public Object execute(ExecutionEvent event) throws ExecutionException
    {
        System.out.println("Test");
        
		DirectoryDialog dialog = new DirectoryDialog(PlatformUI.getWorkbench().getActiveWorkbenchWindow().getShell(), SWT.OPEN);
		//dialog.setFilterPath("c:\\temp");
		String result = dialog.open();
		IncludePrepper.prepareMod(new File(result), getProjectPath().toFile());
        
        return null;
    }
    
    public IPath getProjectPath()
    {
        IWorkbenchWindow window = PlatformUI.getWorkbench().getActiveWorkbenchWindow();
        if (window != null)
        {
            IStructuredSelection selection = (IStructuredSelection) window.getSelectionService().getSelection();
            Object firstElement = selection.getFirstElement();
            if (firstElement instanceof IAdaptable)
            {
                IProject project = (IProject)((IAdaptable)firstElement).getAdapter(IProject.class);
                IPath path = project.getLocation();
                System.out.println(path);
                return path;
            }
        }
        return null;
    }

}
