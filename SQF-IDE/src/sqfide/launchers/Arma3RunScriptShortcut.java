package sqfide.launchers;

import java.io.File;
import java.io.IOException;
import org.apache.commons.io.FileUtils;
import org.eclipse.core.resources.IFile;
import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Status;
import org.eclipse.debug.ui.ILaunchShortcut;
import org.eclipse.jface.preference.IPreferenceStore;
import org.eclipse.jface.viewers.ISelection;
import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.ui.IEditorPart;
import org.eclipse.ui.statushandlers.StatusManager;

import com.mysite.www.arma3_wsdl.Arma3PortTypeProxy;
import sqfide.Activator;

public class Arma3RunScriptShortcut extends Arma3LaunchConfigurationDelegate
        implements ILaunchShortcut
{

    @Override
    public void launch(ISelection selection, String mode)
    {
        IPreferenceStore store = Activator.getDefault().getPreferenceStore();
        final String ipAddress = store.getString("ipAddress");
        
        if (!(selection instanceof IStructuredSelection)) 
        {
            StatusManager.getManager().handle(new Status(IStatus.ERROR, 
                    sqfide.Activator.PLUGIN_ID, 
                    "Arma3RunScriptShortcut Launch Error:" + 
                    "selection was not IStructuredSelection"),
                    StatusManager.LOG);
            return;
        }
        IStructuredSelection scriptSelection = (IStructuredSelection) selection;
        IFile scriptIFile = (IFile) scriptSelection.getFirstElement();
        File scriptFile = new File(scriptIFile.getLocation().toOSString());

        try
        {
            Arma3PortTypeProxy proxy = new Arma3PortTypeProxy();
            String endPoint = "http://" + ipAddress + ":" + Constants.PORT;
            proxy.setEndpoint(endPoint);
            proxy.runSQFScript(FileUtils.readFileToString(scriptFile, "UTF-8"));
        } catch ( IOException e1)
        {
            StatusManager.getManager().handle(new Status(IStatus.ERROR, 
                    sqfide.Activator.PLUGIN_ID, 
                    "Unable to connect to the game. Please verify the IP (" + ipAddress
                    + ") is correct and the port " + Constants.PORT + " is connectable."),
                    StatusManager.SHOW);
        }
    }

    @Override
    public void launch(IEditorPart editor, String mode)
    {
        // TODO Auto-generated method stub

    }
}
