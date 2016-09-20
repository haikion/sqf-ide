/**
 * @(#) SQFPerspective.java
 */

package org.arma.side;

import org.eclipse.ui.IFolderLayout;
import org.eclipse.ui.IPageLayout;
import org.eclipse.ui.IPerspectiveFactory;
import org.eclipse.ui.wizards.newresource.BasicNewFileResourceWizard;
import org.eclipse.ui.wizards.newresource.BasicNewFolderResourceWizard;

public class SQFPerspective implements IPerspectiveFactory
{

    @Override
    public void createInitialLayout(IPageLayout layout)
    {
       layout.addNewWizardShortcut(BasicNewFolderResourceWizard.WIZARD_ID);
       layout.addNewWizardShortcut(BasicNewFileResourceWizard.WIZARD_ID);
       layout.addNewWizardShortcut("sqfide.wizards.NewMissionWizard");

       defineLayout(layout);
    }
    
    /**
     * Defines the initial layout for a page.
     * @param layout The layout we are filling
     */
    public void defineLayout(IPageLayout layout) {
        // Editors are placed for free.
        String editorArea = layout.getEditorArea();

        // Top left.
        IFolderLayout topLeft = layout.createFolder(
                "topLeft", IPageLayout.LEFT, (float) 0.26, editorArea);//$NON-NLS-1$
        topLeft.addView(IPageLayout.ID_PROJECT_EXPLORER);

        // Bottom right.
        IFolderLayout bottomRight = layout.createFolder(
                "bottomRight", IPageLayout.BOTTOM, (float) 0.66,//$NON-NLS-1$
                editorArea);
    }
}
