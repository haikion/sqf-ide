package org.arma.side;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class RptLink
{
    private static final Pattern FILE_PATTERN = Pattern.compile("File (.*),");
    private static final Pattern LINE_PATTERN = Pattern.compile("File .*, line ([0-9]*)");
    
    private String message_;
    private int offset_;
    private int line_;
    private String filePath_;
    
    public RptLink(String message, int offset)
    {
        message_ = message;
        offset_ = offset;
        
        Matcher matcher = FILE_PATTERN.matcher(message_);
        while (matcher.find())
        {
            filePath_ = matcher.group(1);
        }
        matcher = LINE_PATTERN.matcher(message_);
        while (matcher.find())
        {
            line_ = Integer.valueOf(matcher.group(1));
        }
    }
    
    public int getLength()
    {
        return message_.length();
    }
    
    public int getOffset()
    {
        return offset_;
    }
    
    public int getLine()
    {
        return line_;
    }
    
    public String getFilePath()
    {
        return filePath_;
    }
}
