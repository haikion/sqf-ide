/*******************************************************************************
 * Copyright (c) 2007 IBM Corporation and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     IBM Corporation - initial API and implementation
 *******************************************************************************/
package sqfide.launchers;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.lang.reflect.InvocationTargetException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import org.eclipse.core.resources.IFile;
import org.eclipse.core.resources.IProject;
import org.eclipse.core.resources.IResource;
import org.eclipse.core.runtime.CoreException;
import org.eclipse.debug.core.DebugPlugin;
import org.eclipse.debug.core.ILaunchConfiguration;
import org.eclipse.debug.core.ILaunchConfigurationType;
import org.eclipse.debug.core.ILaunchConfigurationWorkingCopy;
import org.eclipse.debug.core.ILaunchManager;
import org.eclipse.debug.ui.ILaunchShortcut;
import org.eclipse.debug.ui.ILaunchShortcut2;
import org.eclipse.jdt.core.IType;
import org.eclipse.jdt.debug.ui.launchConfigurations.AppletParametersTab;
import org.eclipse.jdt.debug.ui.launchConfigurations.JavaLaunchShortcut;
import org.eclipse.jdt.internal.debug.ui.JDIDebugUIPlugin;
import org.eclipse.jdt.internal.debug.ui.launcher.AppletLaunchConfigurationUtils;
import org.eclipse.jdt.internal.debug.ui.launcher.LauncherMessages;
import org.eclipse.jdt.launching.IJavaLaunchConfigurationConstants;
import org.eclipse.jface.dialogs.MessageDialog;
import org.eclipse.jface.operation.IRunnableContext;
import org.eclipse.jface.viewers.ISelection;
import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.ui.IEditorPart;

/**
 * 
 * Launch shortcut for Java applets.
 * <p>
 * This class may be instantiated or subclassed.
 * </p>
 * @since 3.4
 */
public class Arma3LaunchShortcut extends Arma3LaunchConfigurationDelegate implements ILaunchShortcut  
{
    
    /*
    /* (non-Javadoc)
     * @see org.eclipse.jdt.debug.ui.launchConfigurations.JavaLaunchShortcut#createConfiguration(org.eclipse.jdt.core.IType)
     */
    
    protected ILaunchConfiguration createConfiguration(IType type) {
        ILaunchConfiguration config = null;
        ILaunchConfigurationType configType = getConfigurationType();
        try
        {
            ILaunchConfigurationWorkingCopy wc = configType.newInstance(null, 
                    DebugPlugin.getDefault().getLaunchManager().generateUniqueLaunchConfigurationNameFrom(
                            type.getElementName()));
            config = wc.doSave();
        } catch (CoreException e)
        {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        return config;
    }
    
    /* (non-Javadoc)
     * @see org.eclipse.jdt.debug.ui.launchConfigurations.JavaLaunchShortcut#getConfigurationType()
     */
    protected ILaunchConfigurationType getConfigurationType() {
        ILaunchManager lm = DebugPlugin.getDefault().getLaunchManager();
        return lm.getLaunchConfigurationType(IJavaLaunchConfigurationConstants.ID_JAVA_APPLET);     
    }

    /* (non-Javadoc)
     * @see org.eclipse.jdt.debug.ui.launchConfigurations.JavaLaunchShortcut#findTypes(java.lang.Object[], org.eclipse.jface.operation.IRunnableContext)
     */
    protected IType[] findTypes(Object[] elements, IRunnableContext context) 
            throws InterruptedException, CoreException {
        try {
            return AppletLaunchConfigurationUtils.findApplets(context, elements);
        } catch (InvocationTargetException e) {
            throw (CoreException)e.getTargetException();
        }
    }   

    /* (non-Javadoc)
     * @see org.eclipse.jdt.debug.ui.launchConfigurations.JavaLaunchShortcut#getTypeSelectionTitle()
     */
    protected String getTypeSelectionTitle() {
        return LauncherMessages.JavaAppletLaunchShortcut_0;
    }

    /* (non-Javadoc)
     * @see org.eclipse.jdt.debug.ui.launchConfigurations.JavaLaunchShortcut#getEditorEmptyMessage()
     */
    protected String getEditorEmptyMessage() {
        return LauncherMessages.JavaAppletLaunchShortcut_1;
    }

    /* (non-Javadoc)
     * @see org.eclipse.jdt.debug.ui.launchConfigurations.JavaLaunchShortcut#getSelectionEmptyMessage()
     */
    protected String getSelectionEmptyMessage() {
        return LauncherMessages.JavaAppletLaunchShortcut_2;
    }

    @Override
    public void launch(IEditorPart editor, String mode)
    {
        // TODO Auto-generated method stub
    }

    @Override
    public void launch(ISelection selection, String mode)
    {
        if (!(selection instanceof IStructuredSelection)) 
        {
            System.out.println("Error: selection is no IStructuredSelection");
            return;
        }
        IStructuredSelection missionSelection = (IStructuredSelection) selection;
        IProject missionProject = (IProject) missionSelection.getFirstElement();
        IFile missionFile = missionProject.getFile("mission.sqm");
        
        //TODO: Change to ArmA 3 path.
        File workingDir = new File("/home/niko"); 
        
        launchArma3(workingDir, missionFile, Constants.DEFAULT_ARMA3_LAUNCH_PARAMETERS);
    }
}
