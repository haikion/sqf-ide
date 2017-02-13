package org.arma.side.launchers;

import org.eclipse.core.expressions.PropertyTester;
import org.eclipse.core.resources.IFile;
import org.eclipse.core.resources.IProject;

public class SideTester extends PropertyTester
{
    private static final String IS_ARMA_MISSION = "isArmaMission";
    private static final String IS_SQF_FILE = "isSqfFile";
    
    @Override
    public boolean test(Object receiver, String property, Object[] arg2, 
            Object expectedValue) 
    {
        if (IS_ARMA_MISSION.equals(property) && receiver instanceof IProject) 
        {
            IProject projectReceiver = (IProject) receiver;
            IFile missionFile = projectReceiver.getFile("mission.sqm");
            return missionFile.isAccessible();
        }
        else if (IS_SQF_FILE.equals(property) && receiver instanceof IFile)
        {
            IFile sqfFile = (IFile) receiver;
            return "sqf".equals(sqfFile.getFileExtension());
        }
        return false;
    }
}
