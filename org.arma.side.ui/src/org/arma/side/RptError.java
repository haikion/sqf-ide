/**
 * Regular error line
 */

package org.arma.side;

public class RptError
{
    private int linkOffset_;
    private int linkLength_;
    private String sqfPath_;
    private int sqfLine_ = -1;
    private String message_;
    private int offset_;
	
	public RptError(String message, int offset)
	{
	    message_ = message;
	    offset_ = offset;
	}

	public int getLinkOffset()
	{
	    return linkOffset_;
	}
	
	public int getLinkLength()
	{
	    return linkLength_;
	}
	
	public int getSqfLine()
	{
	    return sqfLine_;
	}
	
	public String getSqfPath()
	{
	    return sqfPath_;
	}

    public int getLength()
    {
        return message_.length();
    }

    public int getOffset()
    {
        return offset_;
    }
}
