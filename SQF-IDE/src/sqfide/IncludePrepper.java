/*
 * Extracts every pbo in a mod. Used for includes.
 */
package sqfide;

import java.io.File;
import java.io.IOException;

import org.apache.commons.io.FileUtils;

public class IncludePrepper 
{
	//ToDo: Test
	public static boolean prepareMod(File modLocation, File projectLocation)
	{
		if (!modLocation.exists() || !projectLocation.exists())
		{
			System.out.println("ERROR: modLocatione exists = " + modLocation.exists() + 
					" projectLocation.exists() = " + projectLocation.exists());
			return false;
		}
		
		File includesDir = new File(projectLocation.getAbsolutePath() + "/includes");
		includesDir.mkdirs();
		
		File outputDir = new File(includesDir.getAbsolutePath() + "/" + modLocation.getName());
		extract(modLocation, outputDir);
		return FunctionParser.parseToXml(outputDir);
	}
	
	//Extracts all PBOs from mission or mod into specified outputDir. Copies non pbo files and dirs.
	public static boolean extract(File file, File outputDir)
	{
		for (String name : file.list())
		{
			File file2 = new File(file.getPath() + "/" + name);
			File output = new File(outputDir.getPath() + "/" + file2.getName());
			if (file2.isDirectory())
			{
				output = new File(outputDir.getPath() + "/" + file2.getName());
				extract(file2, output);
			}
			else if ("pbo".equals(getExtensions(name)))
			{
				outputDir.mkdirs();
				PBOArchiver.extract(file2, outputDir);
			}
			else
			{
				try {
					FileUtils.copyFile(file2, output);
				} catch (IOException e) {
					e.printStackTrace();
					return false;
				}
			}
		}
		
		return true;
	}
	
	private static String getExtensions(String fileName)
	{
		String extension = "";

		int i = fileName.lastIndexOf('.');
		if (i > 0) 
		{
		    extension = fileName.substring(i+1);
		}
		
		return extension;
	}
}
