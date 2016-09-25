package org.arma.xtext.ui.syntaxcoloring;

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
        else if (layoutStyleAttribKeywords.contains(tokenName)) 
        {
            return DefaultHighlightingConfiguration.KEYWORDATTRIB_ID;
        }
        else if ("RULE_STRING_TERMINAL".equals(tokenName))
        {
            return DefaultHighlightingConfiguration.STRING_ID;
        }
        else if ("RULE_LOCAL_VARIABLE".equals(tokenName))
        {
            return DefaultHighlightingConfiguration.LOCAL_VARIABLE_ID;
        }
        else if ("RULE_GLOBAL_FUNCTION".equals(tokenName))
        {
            return DefaultHighlightingConfiguration.GLOBAL_FUNCTION_ID;
        }
        else if ("RULE_WS_COMMENT".equals(tokenName) || "RULE_SL_COMMENT".equals(tokenName))
        {
            return DefaultHighlightingConfiguration.COMMENT_ID;
        }
        else if ("RULE_COMMAND_MIDDLE_SPECIAL".equals(tokenName))
        {
        	return DefaultHighlightingConfiguration.KEYWORD_ID;
        }
        return super.calculateId(tokenName, tokenType);
    }

    public String getId(int tokenType) 
    {
        return getMappedValue(tokenType);
    }
}

