package sqfide.preferences;

import org.eclipse.core.runtime.preferences.AbstractPreferenceInitializer;
import org.eclipse.jface.preference.IPreferenceStore;
import sqfide.Activator;

public class PreferenceInitializer
  extends AbstractPreferenceInitializer
{ 
    public void initializeDefaultPreferences()
    {
        IPreferenceStore store = Activator.getDefault().getPreferenceStore();

        store.setDefault("ipAddress", "localhost");
    }
}