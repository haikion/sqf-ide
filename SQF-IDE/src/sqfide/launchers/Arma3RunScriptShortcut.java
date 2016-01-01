package sqfide.launchers;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.rmi.AlreadyBoundException;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

import org.apache.commons.io.FileUtils;
import org.eclipse.core.resources.IFile;
import org.eclipse.core.resources.IProject;
import org.eclipse.debug.ui.ILaunchShortcut;
import org.eclipse.jface.viewers.ISelection;
import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.ui.IEditorPart;

public class Arma3RunScriptShortcut extends Arma3LaunchConfigurationDelegate
        implements ILaunchShortcut
{

    @Override
    public void launch(ISelection selection, String mode)
    {
        TCPClient client = new TCPClient();
        
        if (!(selection instanceof IStructuredSelection)) 
        {
            System.out.println("Error: selection is no IStructuredSelection");
            return;
        }
        IStructuredSelection scriptSelection = (IStructuredSelection) selection;
        IFile scriptIFile = (IFile) scriptSelection.getFirstElement();
        File scriptFile = new File(scriptIFile.getLocation().toOSString());
        
        try
        {
            client.sendMessage(FileUtils.readFileToString(scriptFile, "UTF-8"));
        } catch ( IOException e ) 
        {
            e.printStackTrace();
        }
    }

    @Override
    public void launch(IEditorPart editor, String mode)
    {
        // TODO Auto-generated method stub

    }
}
