package org.xtext.arma.ui.syntaxcoloring;

import org.eclipse.swt.SWT;
import org.eclipse.swt.graphics.RGB;
import org.eclipse.xtext.ui.editor.syntaxcoloring.IHighlightingConfiguration;
import org.eclipse.xtext.ui.editor.syntaxcoloring.IHighlightingConfigurationAcceptor;
import org.eclipse.xtext.ui.editor.utils.TextStyle;

public class DefaultHighlightingConfiguration implements IHighlightingConfiguration
{

    public static final String KEYWORD_ID = "keyword";
    public static final String COMMENT_ID = "comment";
    public static final String STRING_ID = "string";
    public static final String LOCAL_VARIABLE_ID = "localVariable";
    public static final String GLOBAL_FUNCTION_ID = "globalFunction";
    public static final String KEYWORDSTYLEDEF_ID  = "KeywordsStyleDefinition";
    public static final String KEYWORDATTRIB_ID    = "KeywordsAttribShapes";
    
    @Override
    public void configure(IHighlightingConfigurationAcceptor acceptor) {
        acceptor.acceptDefaultHighlighting(
                KEYWORD_ID, "Keyword", keywordTextStyle());
        acceptor.acceptDefaultHighlighting(STRING_ID, "String", stringStyle());
        acceptor.acceptDefaultHighlighting(LOCAL_VARIABLE_ID, LOCAL_VARIABLE_ID, localVariableStyle());
        acceptor.acceptDefaultHighlighting(GLOBAL_FUNCTION_ID, GLOBAL_FUNCTION_ID, globalFunctionStyle());
        acceptor.acceptDefaultHighlighting(COMMENT_ID, COMMENT_ID, commentStyle());
    }
    
    private TextStyle stringStyle()
    {
        TextStyle textStyle = new TextStyle();
        textStyle.setColor(new RGB(0, 0, 255));
        return textStyle;
    }
    
    private TextStyle localVariableStyle()
    {
        TextStyle textStyle = new TextStyle();
        textStyle.setColor(new RGB(128, 255, 0));
        return textStyle;
    }
    
    private TextStyle commentStyle()
    {
        TextStyle textStyle = new TextStyle();
        textStyle.setColor(new RGB(211, 211, 211)); //Grey
        return textStyle;
    }
    
    private TextStyle globalFunctionStyle()
    {
        TextStyle textStyle = new TextStyle();
        textStyle.setColor(new RGB(244, 164, 96));
        return textStyle;
    }
    
    public TextStyle keywordTextStyle() {
        TextStyle textStyle = new TextStyle();
        textStyle.setColor(new RGB(127, 0, 85));
        textStyle.setStyle(SWT.BOLD);
        return textStyle;
    }
}
