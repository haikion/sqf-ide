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
package org.arma.side.wizards;

import java.io.File;

import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.jface.wizard.WizardPage;
import org.eclipse.swt.SWT;
import org.eclipse.swt.events.ModifyEvent;
import org.eclipse.swt.events.ModifyListener;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.DirectoryDialog;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.Text;


public class ImportMissionPage extends WizardPage {
    
    private File missionLocation_;
    private Text missionText_;
    private String pathLabel_ = "&Mission Path:";
    
    public ImportMissionPage(String pageName, IStructuredSelection selection) {
        super("wizardPage");
        setTitle(pageName);
        setDescription("Open existing ArmA 3 mission.");
        setPageComplete(false);
    }
    
    protected void setPathLabel(String val)
    {
    	pathLabel_ = val;
    }
    protected File getMissionLocation()
    {
    	return missionLocation_;
    }
    
    protected void setMissionLocation(File val)
    {
    	missionLocation_ = val;
    }
    
    public String getMissionName() 
    {
        return missionLocation_.getName();
    }
    
    public Text getMissionText()
    {
    	return missionText_;
    }
    
    public File getMissionDIR()
    {
    return missionLocation_;
    }
    
    /**
     * @see IDialogPage#createControl(Composite)
     */
    public void createControl(Composite parent) {
        Composite container = new Composite(parent, SWT.NULL);
        GridLayout layout = new GridLayout();
        layout.numColumns = 3;
        layout.verticalSpacing = 9;
        container.setLayout(layout);
        
        Label label = new Label(container, SWT.NULL);
        label.setText(pathLabel_);
        
        missionText_ = new Text(container, SWT.BORDER | SWT.SINGLE);
        missionText_.setLayoutData(new GridData(GridData.FILL_HORIZONTAL));
        missionText_.addModifyListener(new ModifyListener()
        {
            public void modifyText(ModifyEvent e)
            {
                missionLocation_ = new File(missionText_.getText());
                checkPageComplete();
            }
        });
        
        Button button = new Button(container, SWT.PUSH);
        button.setText("Browse...");
        button.addSelectionListener(new SelectionAdapter() {
            public void widgetSelected(SelectionEvent e) {
                handleBrowse();
            }
        });
        
        setControl(container);
    }
    
    protected void checkPageComplete()
    {
        if (missionLocation_ == null)
        {
            setErrorMessage("Mission location is undefined.");
            setPageComplete(false);
            return;
        }
        if (!missionLocation_.isDirectory())
        {
            setErrorMessage("Invalid mission location.");
            setPageComplete(false);
            return;
        }
        String missionSQMPath = missionLocation_.getAbsolutePath() + "/mission.sqm";
        File missionSQM = new File(missionSQMPath);
        if (!missionSQM.isFile())
        {
            setErrorMessage(missionSQMPath + "not found.");
            setPageComplete(false); 
            return;
        }
        setPageComplete(true);
    }
    
    protected void handleBrowse()
    {
        DirectoryDialog diag = new DirectoryDialog(missionText_.getShell());
        String directory = diag.open();
        if (directory != null)
        {
            missionLocation_ = new File(directory);
            missionText_.setText(missionLocation_.getAbsolutePath());
        }
    }
    
    /*
    /* (non-Javadoc)
     * @see org.eclipse.ui.dialogs.WizardNewFileCreationPage#createAdvancedControls(org.eclipse.swt.widgets.Composite)
        
    protected void createAdvancedControls(Composite parent) {
        Composite fileSelectionArea = new Composite(parent, SWT.NONE);
        GridData fileSelectionData = new GridData(GridData.GRAB_HORIZONTAL
                | GridData.FILL_HORIZONTAL);
        fileSelectionArea.setLayoutData(fileSelectionData);

        GridLayout fileSelectionLayout = new GridLayout();
        fileSelectionLayout.numColumns = 3;
        fileSelectionLayout.makeColumnsEqualWidth = false;
        fileSelectionLayout.marginWidth = 0;
        fileSelectionLayout.marginHeight = 0;
        fileSelectionArea.setLayout(fileSelectionLayout);
        
        editor = new FileFieldEditor("fileSelect","Select Mission Directory: ",fileSelectionArea);
        editor.getTextControl(fileSelectionArea).addModifyListener(new ModifyListener(){
            public void modifyText(ModifyEvent e) {
                IPath path = new Path(ImportMissionPage.this.editor.getStringValue());
                setFileName(path.lastSegment());
            }
        });
        String[] extensions = new String[] { "*.*" }; //NON-NLS-1
        editor.setFileExtensions(extensions);
        fileSelectionArea.moveAbove(null);
    }
    */
}
