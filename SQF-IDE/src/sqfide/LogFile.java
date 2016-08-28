/**
 * @(#) LogFile.java
 */

package sqfide;

import java.io.File;
import java.util.ArrayList;

public class LogFile extends File
{
	/**
     * 
     */
    private static final long serialVersionUID = 1L;
    private ArrayList<SQFError> errors_;
	
	public LogFile( String logString )
	{
		super(logString);
	}
	
	private void parseLine( String line )
	{
		
	}
}
