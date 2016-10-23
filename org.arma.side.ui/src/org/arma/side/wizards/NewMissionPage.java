package org.arma.side.wizards;

import org.eclipse.jface.viewers.ISelection;
import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.jface.wizard.WizardPage;
import org.eclipse.swt.SWT;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.Text;

/**
 * The "New" wizard page allows setting the container for the new file as well
 * as the file name. The page will only accept file name without the extension
 * OR with the extension that matches the expected one (mpe).
 */

public class NewMissionPage extends WizardPage
{
	private Text nameText;
	private ISelection selection;

	/**
	 * Constructor for SampleNewWizardPage.
	 * 
	 * @param pageName
	 */
	public NewMissionPage(ISelection selection)
	{
		super("wizardPage");
		setTitle("New arma 3 mission");
		setDescription("This wizard creates a new Arma 3 mission.");
		this.selection = selection;
	}

	/**
	 * @see IDialogPage#createControl(Composite)
	 */
	public void createControl(Composite parent)
	{
		Composite container = new Composite(parent, SWT.NULL);
		GridLayout layout = new GridLayout();
		container.setLayout(layout);
		layout.numColumns = 3;
		layout.verticalSpacing = 9;
		Label label = new Label(container, SWT.NULL);
		label.setText("&Mission Name:");
		nameText = new Text(container, SWT.NULL);

		initialize();
		dialogChanged();
		setControl(container);
	}

	/**
	 * Tests if the current workbench selection is a suitable container to use.
	 */

	private void initialize()
	{
		if (selection != null && selection.isEmpty() == false
				&& selection instanceof IStructuredSelection) {
			IStructuredSelection ssel = (IStructuredSelection) selection;
			if (ssel.size() > 1)
				return;
		}
		nameText.setText("New Mission");
	}

	/**
	 * Ensures that both text fields are set.
	 */

	private void dialogChanged()
	{
		String missionName = getMissionName();

		if (missionName.length() == 0) {
			updateStatus("File name must be specified");
			return;
		}
		if (missionName.replace('\\', '/').indexOf('/', 1) > 0) {
			updateStatus("File name must be valid");
			return;
		}
		int dotLoc = missionName.lastIndexOf('.');
		if (dotLoc != -1) {
			String ext = missionName.substring(dotLoc + 1);
			if (ext.equalsIgnoreCase("mpe") == false) {
				updateStatus("File extension must be \"mpe\"");
				return;
			}
		}
		updateStatus(null);
	}

	private void updateStatus(String message) {
		setErrorMessage(message);
		setPageComplete(message == null);
	}

	public String getMissionName() {
		return nameText.getText();
	}
}