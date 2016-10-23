/**
 * @(#) ImportPBOPage.java
 */

package org.arma.side.wizards;

import java.io.File;
import java.util.ArrayList;
import java.util.List;

import org.arma.side.PboArchiver;
import org.eclipse.core.resources.ResourcesPlugin;
import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.swt.widgets.FileDialog;

public class ImportPboPage extends ImportMissionPage
{
	static final String CPBO_EXUCTABLE = "tools\\cpbo.exe";
	private File testDir_;
	private File pboFile_;
	private File missionLocation_;
	List<String> cpboParams_ = new ArrayList<String>();
	
    public ImportPboPage(String pageName, IStructuredSelection selection)
    {
        super(pageName, selection);
        setDescription("Open existing ArmA 3 PBO mission.");
        cpboParams_.add(CPBO_EXUCTABLE);
        cpboParams_.add("-y");
        cpboParams_.add("-e");
    }
    
    public File getPboFile()
    {
    	return pboFile_;
    }
    
    @Override
    protected void checkPageComplete()
    {
        if (missionLocation_ == null)
        {
            setErrorMessage("Mission location is undefined.");
            setPageComplete(false);
            return;
        }
        if (testDir_ == null)
        {
        	setErrorMessage("Test directory is undefined");
        	setPageComplete(false);
        	return;
        }
        if (missionLocation_.exists())
        {
            setErrorMessage("Mission path " + missionLocation_.getAbsolutePath() + " already exists in a workspace.");
            setPageComplete(false);
            return;
        }

        if (!testDir_.exists())
        {
            setErrorMessage("Failure to test extract mission to path: " + testDir_.getAbsolutePath());
            setPageComplete(false);
            return;
        }
        String missionSQMPath = testDir_ + "\\mission.sqm";
        File missionSQM = new File(missionSQMPath);
        if (!missionSQM.isFile())
        {
            setErrorMessage(missionSQMPath + " not found in mission.");
            setPageComplete(false); 
            return;
        }
        setMissionLocation(missionLocation_);
        setErrorMessage(null);
        setPageComplete(true);
    }
    
    @Override
    protected void handleBrowse()
    {
        FileDialog diag = new FileDialog(getMissionText().getShell());
        String file = diag.open();
        if (file != null)
        {
            if (!file.endsWith(".pbo"))
            {
            	System.out.println("Not PBO!");
            	return;
            }
            
            String workspacePath = ResourcesPlugin.getWorkspace().getRoot().getLocation().toString();
            pboFile_ = new File(file);
            String missionName = pboFile_.getName().replaceAll(".pbo", "");
            missionLocation_ = new File(workspacePath + "\\" + missionName);
        	getMissionText().setText(file);

            System.out.println("missionLocation set to: " + missionLocation_.getAbsolutePath());
            //Test extract
            testDir_ = new File(System.getProperty("java.io.tmpdir") + "\\" + missionName);
            PboArchiver.extract(pboFile_, testDir_.getParentFile());;
            checkPageComplete();
        }
    }
    /*
    public Boolean extractPbO(String pboPath, File extractDir)
    {
    	List<String> params = new ArrayList<String>(cpboParams_);
    	File pboFile = new File(pboPath);
 
    	params.add(pboPath);
    	params.add(extractDir.getAbsolutePath());
    	if (!extractDir.getParentFile().exists() || !pboFile.exists())
    	{
    		return false;
    	}
    	
    	ProcessBuilder cpboP = new ProcessBuilder(params);
    	System.out.println(new File(CPBO_EXUCTABLE).getAbsolutePath() + " pboPath = " + pboPath 
    			+ " extractDir = " + extractDir.getAbsolutePath()
    			+ " params = " + params.toString());
    	Process cpboProcess;
    	try {
       		cpboProcess = cpboP.start();
    		cpboProcess.waitFor();
    		BufferedReader is = new BufferedReader(new InputStreamReader(cpboProcess.getInputStream()));

    		String line;
    	    while (( line = is.readLine()) != null)
    	      System.out.println(line);
    	    
		} catch (IOException | InterruptedException e) {
			e.printStackTrace();
			return false;
		}
    	System.out.println(cpboProcess.toString());
     	return cpboProcess.exitValue() == 0;
    }
    */
}
