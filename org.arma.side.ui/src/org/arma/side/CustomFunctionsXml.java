package org.arma.side;

import java.io.File;
import java.io.IOException;

import org.apache.commons.io.FileUtils;
import org.eclipse.core.internal.resources.Project;
import org.eclipse.core.resources.IProject;
import org.eclipse.core.resources.IResource;
import org.eclipse.core.runtime.CoreException;

public class CustomFunctionsXml
{
    private static final String CUSTOM_FUNCTIONS_NAME = "customFunctions.xml";
    private static final String REL_PATH = "/includes/" + CUSTOM_FUNCTIONS_NAME;
    private static final String DTD_PATH = "customFunctions.dtd";
    private static final String BASE_PATH = CUSTOM_FUNCTIONS_NAME;
            
    private IProject project_;
    private File customFunctionsXml_;
    private static File dtdFile_;// = Commons.getFile(DTD_PATH);
    private static File baseFile_;// = Commons.getFile(BASE_PATH);
    
    CustomFunctionsXml(IProject project)
    {
        project_ = project;
        customFunctionsXml_ = new File(project_.getLocation().toOSString() + REL_PATH);
        if (!customFunctionsXml_.exists())
            createEmptyXml();
    }
    
    public File getCustomFunctionsXml()
    {
        return customFunctionsXml_;
    }
    
    public File getDtd()
    {
        return dtdFile_;
    }
    
    public static boolean createEmptyXml(IProject project)
    {
        File customFunctionsXml = createCustomFunctionsXml(project);
        if (customFunctionsXml.exists())
            return false;
        try
        {
            customFunctionsXml.getParentFile().mkdirs();
            FileUtils.copyFile(Commons.getFile(BASE_PATH), customFunctionsXml);
        } catch (IOException | NullPointerException e)
        {
            e.printStackTrace();
            return false;
        }
        addDtdReference();
        try
        {
            project.refreshLocal(IResource.DEPTH_INFINITE, null);
        } catch (CoreException e)
        {
            e.printStackTrace();
        }
        return true;
    }
    
    private void createEmptyXml()
    {
        try
        {
            FileUtils.copyFile(baseFile_, customFunctionsXml_);
        } catch (IOException e)
        {
            e.printStackTrace();
        }
        addDtdReference();
    }

    private static void addDtdReference()
    {
        System.out.println("ToDo");
    }
    
    private static File createCustomFunctionsXml(IProject project)
    {
        return new File(project.getLocation().toOSString() + REL_PATH);
    }
}
