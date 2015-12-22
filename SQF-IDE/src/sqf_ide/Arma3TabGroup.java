package sqf_ide;

import org.eclipse.debug.ui.AbstractLaunchConfigurationTabGroup;
import org.eclipse.debug.ui.ILaunchConfigurationDialog;
import org.eclipse.debug.ui.ILaunchConfigurationTab;

public class Arma3TabGroup extends AbstractLaunchConfigurationTabGroup 
{
    
    /**
     * Constructs a new Java applet tab group.
     * @return 
     */
    public void JavaAppletTabGroup() {
    }
    
    /* (non-Javadoc)
     * @see org.eclipse.debug.ui.ILaunchConfigurationTabGroup#createTabs(org.eclipse.debug.ui.ILaunchConfigurationDialog, java.lang.String)
     */
    public void createTabs(ILaunchConfigurationDialog dialog, String mode) {
        ILaunchConfigurationTab[] tabs = new ILaunchConfigurationTab[] {
            new Arma3ArgumentsTab(),
        };
        setTabs(tabs);
    }
    
}
