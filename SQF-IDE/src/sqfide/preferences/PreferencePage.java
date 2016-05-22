package sqfide.preferences;

import org.eclipse.jface.preference.FieldEditorPreferencePage;
import org.eclipse.jface.preference.FileFieldEditor;
import org.eclipse.jface.preference.StringFieldEditor;
import org.eclipse.ui.IWorkbench;
import org.eclipse.ui.IWorkbenchPreferencePage;
import sqfide.Activator;
import sqfide.launchers.Constants;

import com.sun.jna.platform.win32.Advapi32Util;
import static com.sun.jna.platform.win32.WinReg.HKEY_LOCAL_MACHINE;

public class PreferencePage
  extends FieldEditorPreferencePage
  implements IWorkbenchPreferencePage
{   
    public PreferencePage()
    {
        super(FieldEditorPreferencePage.GRID);
        setPreferenceStore(Activator.getDefault().getPreferenceStore());
        setDescription("General Settings for SQF-IDE.");
    }
  
    public void init(IWorkbench workbench) 
    {
    	System.out.println("init");
    }

    @Override
    protected void createFieldEditors()
    {
        addField(new StringFieldEditor("startupParameters", "Startup parameters:", getFieldEditorParent()));
        addField(new FileFieldEditor("arma3exe","Arma 3 executable:", true, getFieldEditorParent()));
        addField(new StringFieldEditor("ipAddress", "Game address:", 30, getFieldEditorParent()));
    }
    
}
