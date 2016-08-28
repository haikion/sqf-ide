package sqfide.preferences;


import org.eclipse.jface.dialogs.IDialogConstants;
import org.eclipse.jface.preference.IPreferenceStore;
import org.eclipse.jface.preference.PreferencePage;
import org.eclipse.jface.preference.RadioGroupFieldEditor;
import org.eclipse.swt.SWT;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Control;
import org.eclipse.swt.widgets.DirectoryDialog;
import org.eclipse.swt.widgets.FileDialog;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.List;
import org.eclipse.swt.widgets.Text;
import org.eclipse.ui.IWorkbench;
import org.eclipse.ui.IWorkbenchPreferencePage;
import org.eclipse.ui.dialogs.FileSelectionDialog;
import org.eclipse.ui.dialogs.PropertyPage;

public class IncludesPage 
	extends PropertyPage 
	implements IWorkbenchPreferencePage
{
	
	private static final int VERTICAL_DIALOG_UNITS_PER_CHAR = 8;
	private static final int LIST_HEIGHT_IN_CHARS = 10;
	private static final int LIST_HEIGHT_IN_DLUS = 
		LIST_HEIGHT_IN_CHARS * VERTICAL_DIALOG_UNITS_PER_CHAR;

	private List modsList_;
	private Button removeMod_;
	
	
	public IncludesPage() {
		//Create a new instance of the receiver
	}

	@Override
	protected Control createContents(Composite parent) 
	{
		Composite top = new Composite(parent, SWT.LEFT);

		// Sets the layout data for the top composite's 
		// place in its parent's layout.
		top.setLayoutData(new GridData(GridData.FILL_HORIZONTAL));

		// Sets the layout for the top composite's 
		// children to populate.
		top.setLayout(new GridLayout());
				

			
		Label listLabel = new Label(top, SWT.NONE);
		listLabel.setText("&Tags which do not require closing tags:");
		
		modsList_ = new List(top, SWT.BORDER);
		modsList_.add("@cba_a3 (D:\\My Documents\\Arma 3\\@cba_a3) (20 functions)");
	
		// Create a data that takes up the extra space
		// in the dialog and spans both columns.
		GridData listData = new GridData(GridData.FILL_HORIZONTAL);
		listData.heightHint = 
			convertVerticalDLUsToPixels(LIST_HEIGHT_IN_DLUS);
		modsList_.setLayoutData(listData);

		modsList_.addSelectionListener(new SelectionAdapter() {
			public void widgetSelected(SelectionEvent e) 
			{
				selectionChanged();
			}
		});
		
		// Create a composite for the add and remove buttons.
		Composite buttonGroup = new Composite(top, SWT.NONE);
		buttonGroup.setLayoutData(new GridData());
		GridLayout buttonLayout = new GridLayout();
		buttonLayout.numColumns = 2;
		buttonLayout.marginHeight = 0;
		buttonLayout.marginWidth = 0;
		buttonGroup.setLayout(buttonLayout);

		Button addTag = new Button(buttonGroup, SWT.NONE);
		addTag.setText("Include Mod");
		addTag.addSelectionListener(new SelectionAdapter() {
			public void widgetSelected(SelectionEvent e) 
			{	
				addMod();
			}
		});
		GridData addTagData = new GridData(GridData.FILL_HORIZONTAL);
		addTagData.heightHint = convertVerticalDLUsToPixels(IDialogConstants.BUTTON_HEIGHT);
		addTagData.widthHint = convertHorizontalDLUsToPixels(IDialogConstants.BUTTON_WIDTH);
		addTag.setLayoutData(addTagData);	
		
		removeMod_ = new Button(buttonGroup, SWT.NONE);
		removeMod_.setText("&Un-Include");
		removeMod_.setEnabled(false);
		removeMod_.addSelectionListener(new SelectionAdapter() {
			public void widgetSelected(SelectionEvent e) {	
				modsList_.remove(modsList_.getSelectionIndex());
				selectionChanged();
			}			
		});
		GridData removeTagData = new GridData(GridData.FILL_HORIZONTAL);
		removeTagData.heightHint = convertVerticalDLUsToPixels(IDialogConstants.BUTTON_HEIGHT);
		removeTagData.widthHint = convertHorizontalDLUsToPixels(IDialogConstants.BUTTON_WIDTH);			
		removeMod_.setLayoutData(removeTagData);
		
		GridData textData = new GridData(GridData.FILL_HORIZONTAL);
		textData.verticalAlignment = GridData.BEGINNING;
		
		return top;
	}

	protected void addMod() 
	{
		DirectoryDialog dialog = new DirectoryDialog(getShell(), SWT.OPEN);
		dialog.setFilterPath("c:\\temp");
		String result = dialog.open();
		
		modsList_.add(result);
	}

	@Override
	public void init(IWorkbench workbench) {
		// TODO Auto-generated method stub
		
	}
	
	/*
	 * Sets the enablement of the remove button depending
	 * on the selection in the list.
	 */
	private void selectionChanged() {
		int index = modsList_.getSelectionIndex();
		removeMod_.setEnabled(index >= 0);		
	}

}
