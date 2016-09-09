package sqfide;

import java.io.File;
import java.io.ObjectOutputStream;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

import org.eclipse.core.internal.resources.Folder;
import org.eclipse.core.resources.IProject;
import org.eclipse.core.resources.IResource;
import org.eclipse.core.resources.IResourceChangeEvent;
import org.eclipse.core.resources.IResourceChangeListener;
import org.eclipse.core.resources.IResourceDelta;
import org.eclipse.core.resources.IResourceDeltaVisitor;
import org.eclipse.core.resources.ProjectScope;
import org.eclipse.core.runtime.CoreException;
import org.eclipse.core.runtime.preferences.IEclipsePreferences;
import org.eclipse.core.runtime.preferences.IScopeContext;
import org.osgi.service.prefs.BackingStoreException;

public class ModifyListener implements IResourceChangeListener 
{
	private final static String PREF_CONST = "functions";
	private final static String[] CONFIG_EXTENSIONS = {"hpp", "cpp", "h"};
	
    public void resourceChanged(IResourceChangeEvent event) 
    {
        //we are only interested in POST_CHANGE events
        if (event.getType() != IResourceChangeEvent.POST_CHANGE)
           return;
        IResourceDelta rootDelta = event.getDelta();
        IResourceDeltaVisitor visitor = new IResourceDeltaVisitor() 
        {
           public boolean visit(IResourceDelta delta) {
              //only interested in changed resources (not added or removed)
              if (delta.getKind() != IResourceDelta.CHANGED)
                 return true;
              //only interested in content changes
              if ((delta.getFlags() & IResourceDelta.CONTENT) == 0)
                 return true;
              IResource resource = delta.getResource();
              //only interested in files with the "txt" extension
              if (resource.getType() == IResource.FILE &&
            		  Arrays.asList(CONFIG_EXTENSIONS).contains(resource.getFileExtension().toLowerCase())) 
              {
            	  updateGlobalFunctions(resource.getProject());
              }
              return true;
           }
        };
        try {
            rootDelta.accept(visitor);
        } catch (CoreException e) {
            e.printStackTrace();
        }
    }
    
    public static void updateGlobalFunctions(IProject project)
    {
    	
    	File projectFolder = project.getLocation().toFile();
    	System.out.println("Folder " + projectFolder.getAbsolutePath());
    	projectFolder.listFiles();
    	Set<String> funcs = FunctionParser.parseFolder(projectFolder);
    	System.out.println("Found " + funcs.size() + " global function(s) from project" + project.getName());
    	System.out.println("Functions=" + funcs.toString());

    	//Save to project settings
    	IScopeContext projectScope = new ProjectScope(project);
    	IEclipsePreferences prefs = projectScope.getNode(PREF_CONST);
    	prefs.put(PREF_CONST, funcs.toString());
    	try 
    	{
			prefs.flush();
		} catch (BackingStoreException e) 
    	{
			e.printStackTrace();
		}
    	

    }
}
