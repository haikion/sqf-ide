package org.arma.xtext;

import java.util.HashSet;
import java.util.Set;

public class KeywordHandler
{
    private static HashSet<String> keywords_ = new HashSet<String>();
    
    public static HashSet<String> getKeywordsUpper()
    {
    	if (keywords_.isEmpty())
    		readKeywords();
    	
    	return keywords_;
    }
    
    static private void readKeywords()
    {
        Set<String> validMiddles = XmlReader.getCommandMiddlesUpper();
        Set<String> validLefts = XmlReader.getCommandLeftsUpper();
        Set<String> validParentlesses = XmlReader.getCommandParentlessesUpper();
        
        keywords_.addAll(validMiddles);
        keywords_.addAll(validLefts);
        keywords_.addAll(validParentlesses);
        System.out.println("keywords_ size: " + keywords_.size());
    }
}
