package sqfide.wizards;

import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.ui.dialogs.WizardNewFileCreationPage;

public class NewSQFFileWizardPage extends WizardNewFileCreationPage
{

    public NewSQFFileWizardPage(IStructuredSelection selection)
    {
        super("NewSQFFileWizardPage", selection);
        setTitle("New SQF File");
        setDescription("Creates a new SQF File");
        setFileExtension("sqf");
        setFileName("script.sqf");
    }
}
