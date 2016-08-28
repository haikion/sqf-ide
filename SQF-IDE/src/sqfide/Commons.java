package sqfide;

import java.io.File;
import java.io.IOException;
import java.net.URL;

import org.eclipse.core.runtime.FileLocator;
import org.eclipse.core.runtime.Path;
import org.eclipse.core.runtime.Platform;

public class Commons
{
	//Returns installation or direct path (dev mode).
	public static File getFile(String path)
	{
        File sourceFile  = new File(path);
        //Installation path
        if (!sourceFile.isFile())
        {
        	System.out.println("Using installation path");
        	URL url = FileLocator.find(Platform.getBundle(Activator.PLUGIN_ID), new Path(path), null);
        	if (url == null)
        	{
        	    System.out.println("ERROR: " + path + " could not be located.");
        	    return null;
        	}
			try {
				String jarPath = FileLocator.resolve(url).getPath();
	            sourceFile = new File(jarPath);
			} catch (IOException e) {
				e.printStackTrace();
				return null;
			}
        }
        System.out.println("sourceFile = " + sourceFile.getAbsolutePath());
		
		return sourceFile;
	}
}
