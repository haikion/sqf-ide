/**
 * @(#) LogFile.java
 */

package org.arma.side;

import java.io.File;
import java.util.ArrayList;

public class LogFile extends File
{
	/**
     * 
     */
    private static final long serialVersionUID = 1L;
    private ArrayList<SqfError> errors_;
	
	public LogFile( String logString )
	{
		super(logString);
	}
	
	private void parseLine( String line )
	{
		
	}
}
