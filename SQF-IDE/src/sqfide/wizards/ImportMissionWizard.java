/*******************************************************************************
 * Copyright (c) 2006 IBM Corporation and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     IBM Corporation - initial API and implementation
 *******************************************************************************/
package sqfide.wizards;

import java.net.URI;

import org.eclipse.core.resources.IFile;
import org.eclipse.core.resources.IProject;
import org.eclipse.core.resources.IProjectDescription;
import org.eclipse.core.resources.ResourcesPlugin;
import org.eclipse.core.runtime.CoreException;
import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.jface.wizard.Wizard;
import org.eclipse.swt.widgets.DirectoryDialog;
import org.eclipse.ui.IImportWizard;
import org.eclipse.ui.IWorkbench;

public class ImportMissionWizard extends Wizard implements IImportWizard 
{
	
	private ImportMissionPage mainPage;

	public ImportMissionWizard() 
	{
		super();
	}
	
	/* (non-Javadoc)
	 * @see org.eclipse.ui.IWorkbenchWizard#init(org.eclipse.ui.IWorkbench, org.eclipse.jface.viewers.IStructuredSelection)
	 */
	public void init(IWorkbench workbench, IStructuredSelection selection) 
	{
		setWindowTitle("Import ArmA 3 Mission"); //NON-NLS-1
		setNeedsProgressMonitor(true);
		mainPage = new ImportMissionPage("Import ArmA 3 Mission", selection);
	}
	
	/* (non-Javadoc)
     * @see org.eclipse.jface.wizard.IWizard#addPages()
     */
    public void addPages() 
    {
        super.addPages(); 
        addPage(mainPage);        
    }
    
	/* (non-Javadoc)
	 * @see org.eclipse.jface.wizard.Wizard#performFinish()
	 */
    public boolean performFinish() 
    {
        String missionName = mainPage.getMissionName();
        URI location = mainPage.getMissionDIR().toURI();
        
        IProject project = createProject(missionName, location);
        
        //IFile file = mainPage.createNewFile();
        if (project == null)
            return false;
        return true;
    }
    
    public IProject createProject(String projectName, URI location) 
    {
        IProject newProject = ResourcesPlugin.getWorkspace().getRoot().getProject(projectName);
        if (!newProject.exists())
        {
            URI projectLocation = location;
            IProjectDescription desc = newProject.getWorkspace().newProjectDescription(newProject.getName());
            //if (location != null && 
            //		ResourcesPlugin.getWorkspace().getRoot().getLocationURI().equals(location)) 
            //{
            //    projectLocation = null;
            //}
            desc.setLocationURI(projectLocation);
            try
            {
                newProject.create(desc, null);
                if (!newProject.isOpen()) 
                {
                    newProject.open(null);
                }
            }
            catch (CoreException e)
            {
                e.printStackTrace();
	        }
        }
        return newProject;
    }
}
