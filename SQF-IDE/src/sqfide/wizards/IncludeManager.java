package sqfide.wizards;

import org.eclipse.swt.SWT;
import org.eclipse.swt.events.MenuAdapter;
import org.eclipse.swt.events.MenuEvent;
import org.eclipse.swt.events.MenuListener;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.List;
import org.eclipse.swt.widgets.Menu;
import org.eclipse.swt.widgets.MenuItem;

//ToDo: Context Menu
//ToDo: File Browser
//ToDo: Label

public class IncludeManager {
	
	private List includeList_;
	
	IncludeManager(Composite parent)
	{
		includeList_ = new List(parent, SWT.NULL);
		includeList_.setSize(800, 800);
		includeList_.add("v");
		includeList_.add("hello3");
	}
	
	private boolean addInclude(String include)
	{
		includeList_.add(include);
		return true;
	}
	
	private boolean removeInclude(String include)
	{
		try
		{
			includeList_.remove(include);
		} catch (Exception e)
		{
			return false;
		}
		return true;
	}
	
	private void createContextMenu()
	{
		final Menu menu = new Menu(includeList_);
		includeList_.setMenu(menu);
		menu.addMenuListener(new MenuAdapter()
		{
			public void menuShown(MenuEvent e)
				{
					int selected = includeList_.getSelectionIndex();

					if(selected < 0 || selected >= includeList_.getItemCount())
						return;

					MenuItem[] items = menu.getItems();
					for (int i = 0; i < items.length; i++)
					{
						items[i].dispose();
					}
					MenuItem newItem = new MenuItem(menu, SWT.NONE);
					newItem.setText("Remove");
					//newItem.setText("Menu for \"" + includeList_.getItem(includeList_.getSelectionIndex()) + "\"");
				}
		});
	}
}
