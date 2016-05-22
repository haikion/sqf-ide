/**
 * @(#) ExportPBOPage.java
 */

package sqfide.wizards;

import java.io.File;

import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.jface.wizard.WizardPage;
import org.eclipse.swt.SWT;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.Text;
import org.eclipse.ui.IWorkbench;

public class ExportPBOPage extends ImportMissionPage
{
	private Text outputPath_;
	
	public ExportPBOPage(String pageName, IStructuredSelection selection) {
		super(pageName, selection);
        setDescription("Export ArmA 3 mission as pbo archive.");
        setPathLabel("&Output Directory:");
	}
	
	@Override
    protected void checkPageComplete()
    {
        if (getMissionLocation() == null)
        {
            setErrorMessage("Mission location is undefined.");
            setPageComplete(false);
            return;
        }
        if (!getMissionLocation().isDirectory())
        {
            setErrorMessage("Invalid output location.");
            setPageComplete(false);
            return;
        }
        if (!getMissionLocation().canWrite())
        {
        	setErrorMessage("Directory is not writable.");
        	setPageComplete(false);
        	return;
        }
        setPageComplete(true);
    }
	
	public File getOutputDirectory()
	{
		return getMissionLocation();
	}
}
