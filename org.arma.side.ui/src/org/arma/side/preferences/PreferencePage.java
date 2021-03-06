package org.arma.side.preferences;

import org.arma.side.Activator;
import org.eclipse.jface.preference.FieldEditorPreferencePage;
import org.eclipse.jface.preference.FileFieldEditor;
import org.eclipse.jface.preference.StringFieldEditor;
import org.eclipse.ui.IWorkbench;
import org.eclipse.ui.IWorkbenchPreferencePage;

public class PreferencePage
  extends FieldEditorPreferencePage
  implements IWorkbenchPreferencePage
{   
    public PreferencePage()
    {
        super(FieldEditorPreferencePage.GRID);
        setPreferenceStore(Activator.getDefault().getPreferenceStore());
        setDescription("General Settings for Side.");
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
