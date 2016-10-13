package org.arma.side;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;

import org.eclipse.core.resources.IFile;
import org.eclipse.core.resources.IMarker;
import org.eclipse.core.resources.IWorkspace;
import org.eclipse.core.resources.ResourcesPlugin;
import org.eclipse.core.runtime.CoreException;
import org.eclipse.core.runtime.IPath;
import org.eclipse.core.runtime.Path;
import org.eclipse.swt.SWT;
import org.eclipse.swt.custom.StyleRange;
import org.eclipse.swt.custom.StyledText;
import org.eclipse.swt.graphics.Point;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Event;
import org.eclipse.swt.widgets.Listener;
import org.eclipse.ui.IWorkbenchPage;
import org.eclipse.ui.PlatformUI;
import org.eclipse.ui.ide.IDE;
import org.eclipse.ui.part.ViewPart;

public class RptView extends ViewPart
{
    public static final String ID = "org.arma.side.ui.rptView";
    
    private StyledText logText_;
    //TODO: Find out the dir from regs
    private RptFile file_;
    
    @Override
    public void createPartControl(Composite parent)
    {
        logText_ = new StyledText(parent, SWT.MULTI | SWT.H_SCROLL | SWT.V_SCROLL | SWT.BORDER);
        file_ = new RptFile("C:\\Users\\Niko\\AppData\\Local\\Arma 3", logText_);

        Listener scrollBackListener = new Listener() 
        {
            @Override
            public void handleEvent(Event event)
            {
                logText_.setTopPixel((logText_.getLineCount() - 1)*logText_.getLineHeight());
                hilightErors();
                hilightLinks();
            } 
        };
        logText_.addListener(SWT.Modify, scrollBackListener);
        addLinkListener();
        logText_.setTopPixel((logText_.getLineCount() - 1)*logText_.getLineHeight());
    }

    @Override
    public void setFocus()
    {   
    }
    
    private StyleRange createLinkStyle()
    {
        StyleRange style = new StyleRange();
        style.underline = true;
        style.underlineStyle = SWT.UNDERLINE_LINK;
        style.foreground = Display.getDefault().getSystemColor(SWT.COLOR_BLUE);
        return style;
    }
    
    private StyleRange createErrorStyle()
    {
        StyleRange style = new StyleRange();
        style.foreground = Display.getDefault().getSystemColor(SWT.COLOR_RED);
        return style;
    }
    
    private void addLinkListener()
    {
        logText_.addListener(SWT.MouseDown, event -> {
            try {
                Point point = new Point(event.x, event.y);
                int offset = logText_.getOffsetAtLocation(point);
                StyleRange style1 = logText_.getStyleRangeAtOffset(offset);
                if (style1 != null && style1.underline && style1.underlineStyle == SWT.UNDERLINE_LINK)
                {
                    for (RptLink link : file_.getLinks())
                    {
                        int linkStart = link.getOffset();
                        int linkEnd = linkStart + link.getLength();
                        if (offset > linkStart && offset < linkEnd)
                        {
                            openFile(link.getFilePath(), link.getLine());
                        }
                    }
                }
            } catch (IllegalArgumentException e) 
            {
                //Clicked on non link.
            }
        });
    }
    
    private void openFile(String filePath, int line)
    {
        IWorkbenchPage page = PlatformUI.getWorkbench().getActiveWorkbenchWindow().getActivePage();
        @SuppressWarnings("rawtypes")
        HashMap<String, Comparable> map = new HashMap<String, Comparable>();
        map.put(IMarker.LINE_NUMBER, new Integer(line));
        String editor = IDE.EDITOR_ID_ATTR;
        map.put(editor, "org.arma.xtext.Sqf");
        IFile file =  toIFile(filePath);
        try
        {
            IMarker marker = file.createMarker(IMarker.TEXT);
            marker.setAttributes(map);     
            IDE.openEditor(page, marker);
            marker.delete();
        } catch (CoreException e1)
        {
            e1.printStackTrace();
        }

    }
    
    private IFile toIFile(String path) 
    {
        IWorkspace workspace = ResourcesPlugin.getWorkspace();
        File file = new File(path);
        try
        {
            path = file.getCanonicalPath();
        } catch (IOException e)
        {
            e.printStackTrace();
        } //Adds cases
        IPath location = Path.fromOSString(path);
        IFile ifile = workspace.getRoot().getFileForLocation(location);
        return ifile;
     }
    
    private void hilightErors()
    {
        StyleRange style = createErrorStyle();
        ArrayList<RptError> errors = file_.getErrors();
        for (RptError error : errors)
        {
            style.start = error.getOffset();
            style.length = error.getLength();
            logText_.setStyleRange(style);
        }
    }
    
    private void hilightLinks()
    {
        StyleRange style = createLinkStyle();
        ArrayList<RptLink> links = file_.getLinks();
        for (RptLink link : links)
        {
            style.start = link.getOffset();
            style.length = link.getLength();
            logText_.setStyleRange(style);
        }
    }
}
