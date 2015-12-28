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
        RMIServer server;
        try
        {
            server = new RMIServer();
        } catch (RemoteException e1)
        {
            e1.printStackTrace();
            return;
        }
        
        if (!(selection instanceof IStructuredSelection)) 
        {
            System.out.println("Error: selection is no IStructuredSelection");
            return;
        }
        IStructuredSelection scriptSelection = (IStructuredSelection) selection;
        IFile scriptIFile = (IFile) scriptSelection.getFirstElement();
        File scriptFile = new File(scriptIFile.getLocation().toOSString());
        
        Registry registry;
        System.out.println("Waiting message from ArmA 3 ...");
        try
        {
            server.setCode(FileUtils.readFileToString(scriptFile, "UTF-8"));

            registry = LocateRegistry.createRegistry(Constants.RMI_PORT);
            registry.bind(Constants.RMI_ID, server);
            while (server.working())
            {
                //Wait until code upload finishes or time out happens.
                Thread.sleep(1000);                
            }
            registry.unbind(Constants.RMI_ID); //Stop listening
            
            String rVal;
            String errorMessage;
            if ((rVal = server.getReturnValue()) != null )
            {
                System.out.println("Return Value: " + rVal);
            }
            else if ((errorMessage = server.errorMessage()) != null)
            {
                System.out.println("Error: " + server.errorMessage());
            }
            System.out.println("Script run completed. ");
        } catch (AlreadyBoundException | IOException | 
                InterruptedException | NotBoundException  e)
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
