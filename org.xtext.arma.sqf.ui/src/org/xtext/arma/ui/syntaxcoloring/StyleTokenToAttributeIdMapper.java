package org.xtext.arma.ui.syntaxcoloring;

import java.util.HashSet;
import org.eclipse.xtext.ui.editor.syntaxcoloring.DefaultAntlrTokenToAttributeIdMapper;

public class StyleTokenToAttributeIdMapper extends DefaultAntlrTokenToAttributeIdMapper {
    private HashSet<String> layoutStyleDefinition = new HashSet<String>();
    private HashSet<String> layoutStyleAttribKeywords = new HashSet<String>();

    public StyleTokenToAttributeIdMapper() 
    {
        layoutStyleDefinition.add("'style'");
        layoutStyleDefinition.add("'extends'");
        layoutStyleDefinition.add("'gradient'");
        layoutStyleAttribKeywords.add("'description'");
        layoutStyleAttribKeywords.add("'background-color'");
        layoutStyleAttribKeywords.add("'gradient-orientation'");
        layoutStyleAttribKeywords.add("'highlighting'");
        layoutStyleAttribKeywords.add("'transparency'");
        layoutStyleAttribKeywords.add("'line-style'");
        layoutStyleAttribKeywords.add("'line-width'");
        layoutStyleAttribKeywords.add("'line-color'");
        layoutStyleAttribKeywords.add("'font-italic'");
        layoutStyleAttribKeywords.add("'font-name'");
        layoutStyleAttribKeywords.add("'font-color'");
        layoutStyleAttribKeywords.add("'font-size'");
        layoutStyleAttribKeywords.add("'font-bold'");
        layoutStyleAttribKeywords.add("'area'");
    }

    @Override
    protected String calculateId(String tokenName, int tokenType) 
    {
        //System.out.println("calculateId called" + " tokenName=" + tokenName
        //        + " tokenType=" + tokenType);
        if (layoutStyleDefinition.contains(tokenName)) 
        {
            return DefaultHighlightingConfiguration.KEYWORDSTYLEDEF_ID;
        }
        if (layoutStyleAttribKeywords.contains(tokenName)) 
        {
            return DefaultHighlightingConfiguration.KEYWORDATTRIB_ID;
        }
        if ("RULE_STRING".equals(tokenName))
        {
            return DefaultHighlightingConfiguration.STRING_ID;
        }
        if ("RULE_LOCAL_VARIABLE".equals(tokenName))
        {
            return DefaultHighlightingConfiguration.LOCAL_VARIABLE_ID;
        }
        if ("RULE_GLOBAL_FUNCTION".equals(tokenName))
        {
            return DefaultHighlightingConfiguration.GLOBAL_FUNCTION_ID;
        }
        return super.calculateId(tokenName, tokenType);
    }

    public String getId(int tokenType) 
    {
        return getMappedValue(tokenType);
    }
}

