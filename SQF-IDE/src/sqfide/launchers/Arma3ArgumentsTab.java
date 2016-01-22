/*
 * @author Niko Häikiö
 * 
 * Implements run configuration settings for ArmA 3 launch.
 */
package sqfide.launchers;

import org.eclipse.core.runtime.CoreException;
import org.eclipse.debug.core.ILaunchConfiguration;
import org.eclipse.debug.core.ILaunchConfigurationWorkingCopy;
import org.eclipse.debug.ui.AbstractLaunchConfigurationTab;
import org.eclipse.debug.ui.StringVariableSelectionDialog;
import org.eclipse.debug.ui.WorkingDirectoryBlock;
import org.eclipse.swt.SWT;
import org.eclipse.swt.events.ModifyEvent;
import org.eclipse.swt.events.ModifyListener;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.events.TraverseEvent;
import org.eclipse.swt.events.TraverseListener;
import org.eclipse.swt.graphics.Font;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Group;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.Text;

public class Arma3ArgumentsTab extends AbstractLaunchConfigurationTab
{
    // Program arguments widgets
    private static final String ARMA3_PARAMETERS_LABEL = "ArmA 3 launch parameters";
    private static final String  ARMA3_OPTION_ID = "Arma3Arguments";
    protected Label fPrgmArgumentsLabel;
    protected Text fPrgmArgumentsText;
    // Working directory
    protected Arma3WorkingDirectoryBlock fWorkingDirectoryBlock;
        
    public Arma3ArgumentsTab() 
    {
        fWorkingDirectoryBlock = createWorkingDirBlock();
    }
    
    /**
     * Creates a control to specify a working directory.
     * 
     * @return the new {@link WorkingDirectoryBlock}
     * @since 3.4
     */
    protected Arma3WorkingDirectoryBlock createWorkingDirBlock() 
    {
        return new Arma3WorkingDirectoryBlock();
    }
    
    /**
     * @see org.eclipse.debug.ui.ILaunchConfigurationTab#createControl(Composite)
     */
    public void createControl(Composite parent) {
        Font font = parent.getFont();
        Composite comp = new Composite(parent, SWT.NONE);
        GridLayout layout = new GridLayout(1, true);
        comp.setLayout(layout);
        comp.setFont(font);
        
        GridData gd = new GridData(GridData.FILL_BOTH);
        comp.setLayoutData(gd);
        setControl(comp);
        
        Group group = new Group(comp, SWT.NONE);
        group.setFont(font);
        layout = new GridLayout();
        group.setLayout(layout);
        group.setLayoutData(new GridData(GridData.FILL_BOTH));
        
        String controlName = (ARMA3_PARAMETERS_LABEL); 
        group.setText(controlName);
        
        fPrgmArgumentsText = new Text(group, SWT.MULTI | SWT.WRAP | SWT.BORDER | SWT.V_SCROLL);
        fPrgmArgumentsText.addTraverseListener(new TraverseListener() {
            public void keyTraversed(TraverseEvent e) {
                switch (e.detail) {
                    case SWT.TRAVERSE_ESCAPE:
                    case SWT.TRAVERSE_PAGE_NEXT:
                    case SWT.TRAVERSE_PAGE_PREVIOUS:
                        e.doit = true;
                        break;
                    case SWT.TRAVERSE_RETURN:
                    case SWT.TRAVERSE_TAB_NEXT:
                    case SWT.TRAVERSE_TAB_PREVIOUS:
                        if ((fPrgmArgumentsText.getStyle() & SWT.SINGLE) != 0) {
                            e.doit = true;
                        } else {
                            if (!fPrgmArgumentsText.isEnabled() || (e.stateMask & SWT.MODIFIER_MASK) != 0) {
                                e.doit = true;
                            }
                        }
                        break;
                }
            }
        });
        gd = new GridData(GridData.FILL_BOTH);
        gd.heightHint = 40;
        gd.widthHint = 100;
        fPrgmArgumentsText.setLayoutData(gd);
        fPrgmArgumentsText.setFont(font);
        fPrgmArgumentsText.addModifyListener(new ModifyListener() {
            public void modifyText(ModifyEvent evt) {
                scheduleUpdateJob();
            }
        });
        
        String buttonLabel = "Parameters...";  

        Button pgrmArgVariableButton = createPushButton(group, buttonLabel, null); 
        pgrmArgVariableButton.setLayoutData(new GridData(GridData.HORIZONTAL_ALIGN_END));
        pgrmArgVariableButton.addSelectionListener(new SelectionAdapter() 
        {
            @Override
            public void widgetSelected(SelectionEvent e)
            {
                //TODO: Implement parameter menu
                StringVariableSelectionDialog dialog = new StringVariableSelectionDialog(getShell());
                dialog.open();
                String variable = dialog.getVariableExpression();
                if (variable != null) 
                {
                    fPrgmArgumentsText.insert(variable);
                }
            }
        });
        
        fWorkingDirectoryBlock.createControl(comp);     
    }
        
    /**
     * @see org.eclipse.debug.ui.ILaunchConfigurationTab#isValid(ILaunchConfiguration)
     */
    @Override
    public boolean isValid(ILaunchConfiguration config) 
    {
        return fWorkingDirectoryBlock.isValid(config);
    }
    
    //Set default values
    public void setDefaults(ILaunchConfigurationWorkingCopy configuration) 
    {
        fPrgmArgumentsText.setText(Constants.DEFAULT_ARMA3_LAUNCH_PARAMETERS);
        fWorkingDirectoryBlock.setDefaults(configuration);
    }
    
    /**
     * @see org.eclipse.debug.ui.ILaunchConfigurationTab#initializeFrom(ILaunchConfiguration)
     */
    @Override
    public void initializeFrom(ILaunchConfiguration configuration) 
    {
        String options = Constants.DEFAULT_ARMA3_LAUNCH_PARAMETERS;
        try
        {
            options = configuration.getAttribute(ARMA3_OPTION_ID, Constants.DEFAULT_ARMA3_LAUNCH_PARAMETERS);
        } catch (CoreException e)
        {
            e.printStackTrace();
        }       
        fPrgmArgumentsText.setText(options);
        fWorkingDirectoryBlock.initializeFrom(configuration);
    }
    
    /**
     * Saves changes to configuration
     */
    public void performApply(ILaunchConfigurationWorkingCopy configuration) 
    {
        configuration.setAttribute(ARMA3_OPTION_ID, getAttributeValueFrom(fPrgmArgumentsText));
        fWorkingDirectoryBlock.performApply(configuration);
    }
    
    /**
     * Returns the string in the text widget, or <code>null</code> if empty.
     * 
     * @param text the widget to get the value from
     * @return text or <code>null</code>k
     */
    protected String getAttributeValueFrom(Text text) 
    {
        String content = text.getText().trim();
        if (content.length() > 0) 
        {
            return content;
        }
        return null;
    }
    
    //Tab title
    public String getName() 
    {
        return "Arma 3 Launch Options";
    }
}
