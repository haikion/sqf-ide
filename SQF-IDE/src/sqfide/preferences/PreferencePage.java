package sqfide.preferences;

import org.eclipse.jface.preference.StringFieldEditor;
import org.eclipse.ui.IWorkbench;
import org.eclipse.ui.IWorkbenchPreferencePage;
import org.eclipse.wb.swt.FieldLayoutPreferencePage;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Control;
import org.eclipse.swt.widgets.Group;
import sqfide.Activator;

public class PreferencePage
  extends FieldLayoutPreferencePage
  implements IWorkbenchPreferencePage
{   
    public PreferencePage()
    {
        setPreferenceStore(Activator.getDefault().getPreferenceStore());
        setDescription("General Settings for SQF-IDE.");
    }
  
    public void init(IWorkbench workbench) {}
    
    public Control createPageContents(Composite parent)
    {      
        Composite container = new Composite(parent, 0);
        container.setLayout(new GridLayout(1, false));

        Group networkGroup = new Group(container, 0);
        networkGroup.setText("Game Integration Settings");
        networkGroup.setLayoutData(new GridData(GridData.FILL_HORIZONTAL));
        networkGroup.setLayout(new GridLayout(1, false));

        Composite composite = new Composite(networkGroup, 0);
        addField(new StringFieldEditor("ipAddress", "Game IP: ", 30, composite));
    
        return container;
    }
}
