package sqfide.preferences;

import org.eclipse.jface.preference.FieldEditorPreferencePage;
import org.eclipse.jface.preference.StringFieldEditor;
import org.eclipse.ui.IWorkbench;
import org.eclipse.ui.IWorkbenchPreferencePage;
//import org.eclipse.wb.swt.FieldLayoutPreferencePage;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Control;
import org.eclipse.swt.widgets.Group;
import sqfide.Activator;

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
  
    public void init(IWorkbench workbench) {}

    @Override
    protected void createFieldEditors()
    {        
        addField(new StringFieldEditor("ipAddress", "Game Address: ", 30, getFieldEditorParent()));        
    }
}
