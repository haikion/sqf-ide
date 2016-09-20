package org.arma.side.preferences;

import static com.sun.jna.platform.win32.WinReg.HKEY_LOCAL_MACHINE;

import org.arma.side.Activator;
import org.arma.side.launchers.Constants;
import org.eclipse.core.runtime.preferences.AbstractPreferenceInitializer;
import org.eclipse.jface.preference.IPreferenceStore;

import com.sun.jna.platform.win32.Advapi32Util;

public class PreferenceInitializer
  extends AbstractPreferenceInitializer
{ 
    public void initializeDefaultPreferences()
    {
        IPreferenceStore store = Activator.getDefault().getPreferenceStore();

        //Arma 3 parameters
    	store.setDefault("startupParameters", Constants.DEFAULT_ARMA3_LAUNCH_PARAMETERS);
        //Arma 3 exe
        String arma3Path = "enter path...";
        if (System.getProperty("os.name").contains("Windows"))
        {
            String reg1 = "Software\\Wow6432Node\\Bohemia Interactive\\arma 3";
            String reg2 = "SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\Steam App 107410";
            if (Advapi32Util.registryKeyExists(HKEY_LOCAL_MACHINE, reg1))
            {
            	System.out.println("EXISTS");
                arma3Path = Advapi32Util.registryGetStringValue(HKEY_LOCAL_MACHINE, reg1, "main");
            }
            else if (Advapi32Util.registryKeyExists(HKEY_LOCAL_MACHINE, reg2))
            {
            	arma3Path = Advapi32Util.registryGetStringValue(HKEY_LOCAL_MACHINE, reg2, "InstallLocation");
            }
        }
        store.setDefault("arma3exe", arma3Path + "\\arma3.exe");
        //Arma 3 game address
        store.setDefault("ipAddress", "localhost");
    }
}