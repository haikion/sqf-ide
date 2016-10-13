/**
 * @(#) LogFile.java
 */

package org.arma.side;

import java.io.File;
import java.io.FilenameFilter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import org.apache.commons.io.FileUtils;
import org.eclipse.swt.custom.StyledText;
import org.eclipse.swt.widgets.Display;
import org.simpledirectorywatchservice.DirectoryWatchService;
import org.simpledirectorywatchservice.SimpleDirectoryWatchService;

public class RptFile// extends File
{
    private static final Pattern ERROR_PATTERN = Pattern.compile(".*Error .*");//Matches any line containing "Error"
    private static final Pattern LINK_PATTERN = Pattern.compile("File.*, line [0-9]*");

    private static final String RPT_EXTENSION = ".rpt";
    
    private ArrayList<RptError> errors_ = new ArrayList<RptError>();
    private ArrayList<RptLink> links_ = new ArrayList<RptLink>();

    private String logString_;
	private String logPath_ = "/home/niko";
	private File logDir_ = new File(logPath_);
	private FilenameFilter fileFilter_;
	private StyledText logText_; //GUI Text element
    File rptFile_;
	
	public RptFile(String logPath, StyledText logText)
	{
	    logText_ = logText;
	    logPath_ = logPath;
	    logDir_ = new File(logPath_);
	    System.out.println(logDir_.getAbsolutePath());
	    
	    fileFilter_ = new FilenameFilter() {
            public boolean accept(File dir, String name) {
                String lowercaseName = name.toLowerCase();
                if (lowercaseName.endsWith(RPT_EXTENSION))
                {
                    return true;
                } 
                return false;
            }
        };
	    readLatestRpt();
	     try
	     {
	         watchDirectory();
	     } catch (IOException e)
	     {
	         e.printStackTrace();
	     }
	}


	public String getLogString()
	{
	    return logString_;
	}
	
	public ArrayList<RptError> getErrors()
	{
	    return errors_;
	}
	
	private void findLinks(String string)
	{
        Matcher matcher = LINK_PATTERN.matcher(string);
        while (matcher.find())
        {
           links_.add(new RptLink(matcher.group(), matcher.start()));
           System.out.println(matcher.group());
        }
	}
	
	//Activates rpt log directory monitoring for automated log updates
	private void watchDirectory() throws IOException
	{
	    DirectoryWatchService watchService = new SimpleDirectoryWatchService(); // May throw
	    watchService.register( // May throw
	            new DirectoryWatchService.OnFileChangeListener() 
	            {
	                @Override
	                public void onFileCreate(String filePath)
	                {
	                    readLatestRpt();
	                }

	                @Override
	                public void onFileModify(String filePath)
	                {
	                    try
                        {
                            updateRpt();
                        } catch (IOException e)
                        {
                            e.printStackTrace();
                        }
	                }

	                @Override
	                public void onFileDelete(String filePath)
	                {
	                    // File deleted
	                }
	            },
	            logPath_, // Directory to watch
	            "*" + RPT_EXTENSION
	    );
	    
	    watchService.start();
	}

    private void readLatestRpt()
    {    
        File[] files = logDir_.listFiles(fileFilter_); //TODO: Sort
        Arrays.sort(files, Collections.reverseOrder());
        rptFile_ = files[0];
        System.out.println("Selected rptFile: " + rptFile_.getName());
        try
        {
            //FIXME: Read last 1000 lines.
            String content = FileUtils.readFileToString(rptFile_);
            appendString(content);
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }
    
    //Reads updated lines from RPT.
    private void updateRpt() throws IOException
    {
        String newContent = FileUtils.readFileToString(rptFile_);
        if (!logString_.isEmpty())
            newContent = newContent.substring(logString_.length() - 1);
        appendString(newContent);
    }
    
    private void findErrors(String string)
    {
        Matcher matcher = ERROR_PATTERN.matcher(string);
        while (matcher.find())
        {
            String errorString = matcher.group();
            RptError newError = new RptError(errorString, matcher.start());
            errors_.add(newError);
        }
    }
    
    //Appends String and reads errors from it
    private void appendString(String string)
    {
        findErrors(string);
        findLinks(string);
        logString_ += string;
        Runnable appendLogRunnable = new Runnable()
        {
            @Override
            public void run()
            {
                logText_.append(string);
                
            }
        };
        Display.getDefault().asyncExec(appendLogRunnable);
    }


    public ArrayList<RptLink> getLinks()
    {
        return links_;
    }
}
