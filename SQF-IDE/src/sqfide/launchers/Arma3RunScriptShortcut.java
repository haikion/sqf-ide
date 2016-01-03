package sqfide.launchers;

import java.io.File;
import java.io.IOException;

import javax.xml.rpc.ServiceException;

import org.apache.commons.io.FileUtils;
import org.eclipse.core.resources.IFile;
import org.eclipse.debug.ui.ILaunchShortcut;
import org.eclipse.jface.viewers.ISelection;
import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.ui.IEditorPart;
import com.mysite.www.arma3_wsdl.Arma3PortTypeProxy;

public class Arma3RunScriptShortcut extends Arma3LaunchConfigurationDelegate
        implements ILaunchShortcut
{

    @Override
    public void launch(ISelection selection, String mode)
    {
        //TCPClient client = new TCPClient();
        
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
            System.out.println("Building proxy");
            Arma3PortTypeProxy proxy = new Arma3PortTypeProxy();
            System.out.println("Setting end point");
            proxy.setEndpoint("http://192.168.1.169:8888");
            System.out.println("Executing runSQFScript");
            proxy.runSQFScript(FileUtils.readFileToString(scriptFile, "UTF-8"));
        } catch ( IOException e1)
        {
            // TODO Auto-generated catch block
            e1.printStackTrace();
        }
    }

    @Override
    public void launch(IEditorPart editor, String mode)
    {
        // TODO Auto-generated method stub

    }
}
