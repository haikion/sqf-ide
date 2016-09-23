/**
 * @(#) PBOArchiver.java
 * 
 * Wrapper for kegetys cpbo
 */

package org.arma.side;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.URL;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.xml.parsers.DocumentBuilderFactory;

import org.eclipse.core.runtime.FileLocator;
import org.eclipse.core.runtime.Path;
import org.eclipse.core.runtime.Platform;

public class PBOArchiver
{
	static final String CPBO_EXUCTABLE = "tools/cpbo.exe";
	static final String MAKE_PBO_EXECUTABLE = "tools/MakePbo.exe";
	static final String EXTRACT_PBO_EXECUTABLE = "tools/ExtractPboDos.exe";
    static final String EXTRACT_PARAMS = "-K -P -Y";
    //ToDo: Packing ... /__\
    static final String PACK_PARAMS = "-y -p"; 
    static final Map<String, String> pathCache_ = new HashMap<String, String>();
    
	public static File extract( File pboFile, File outputDirectory )
	{
    	List<String> params = new ArrayList<String>();

    	params.add(getPath(EXTRACT_PBO_EXECUTABLE));
    	params.addAll(Arrays.asList(EXTRACT_PARAMS));
    	
    	if (!outputDirectory.exists() || !pboFile.exists())
    	{
    		System.out.println("File " + pboFile.getAbsolutePath()
    		+ " not found or output dir" + outputDirectory.getAbsolutePath()
    		+ " does not exist");
    		return null;
    	}
    	params.add(pboFile.getAbsolutePath());
        String outputPath =  outputDirectory.getAbsolutePath();// + "\\" + missionName;
    	params.add(outputPath);
    
    	try {
			runCmd(getPath(EXTRACT_PBO_EXECUTABLE) + " " + EXTRACT_PARAMS + " \"" + pboFile.getAbsolutePath() + "\" "
							+ "\"" + outputPath + "\"");
		} catch (IOException | InterruptedException e) {
			e.printStackTrace();
			return null;
		}
    	
    	File rVal = new File(outputPath);
    	if (!rVal.isDirectory())
    		return null;
    	
     	return rVal;
	}
	
	public static File pack( File missionDir, File outputDir )
	{
		if (!missionDir.exists())
		{
			System.out.println("missionDir " + missionDir.getAbsolutePath() + " does not exist.");
			return null;
		}
		
		String missionName = missionDir.getName();
		File outputFile = new File(outputDir.getAbsolutePath() + "\\" + missionName + ".pbo");
		
		int exitCode;
		try {
			exitCode = runCmd(getPath(CPBO_EXUCTABLE) + " " + PACK_PARAMS + " \"" + missionDir.getAbsolutePath() + "\" "
									+ "\"" + outputFile.getAbsolutePath() + "\"" );
		} catch (IOException | InterruptedException e) {
			e.printStackTrace();
			return null;
		}
				
		if ( exitCode != 0 && exitCode != 1 ) //exitCode 1 returned on extract when successful
			return null;
		
		if (!outputFile.isFile())
		{
			System.out.println("File " + outputFile.getAbsolutePath() + " does not exist.");
			return null;
		}
		return outputFile;
	}
	
	private static int runCmd(String cmd) throws IOException, InterruptedException
	{
		System.out.println("Running: " + cmd);
		final Process p = Runtime.getRuntime().exec(cmd);

		new Thread(new Runnable() {
		    public void run() {
		     BufferedReader input = new BufferedReader(new InputStreamReader(p.getInputStream()));
		     String line = null; 

		     try {
		        while ((line = input.readLine()) != null)
		            System.out.println(line);
		     } catch (IOException e) {
		            e.printStackTrace();
		     }
		    }
		}).start();

		return p.waitFor();
	}
	
	private static String getPath(String executable)
	{
		//Cache
		String cached = pathCache_.get(executable);
		if (cached != null)
			return cached;

		//Direct approach (Dev)
		File testFile = new File(executable);
		if (testFile.exists())
		{
			return testFile.getPath();
		}
		
		//Resource approach (Release)
        DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
        factory.setNamespaceAware(true);
        try 
        {
        	URL url = FileLocator.find(Platform.getBundle("org.arma.side.ui"), new Path(executable), null);
            String path = FileLocator.resolve(url).getPath();
            pathCache_.put(executable, path);
            System.out.println("Returning " + path);
            return path;
        }
        catch (IOException e) 
        {
            e.printStackTrace();
            return null;
        }		
	}
}
