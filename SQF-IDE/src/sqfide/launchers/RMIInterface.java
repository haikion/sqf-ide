package sqfide.launchers;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface RMIInterface extends Remote
{
    public String getCode() throws RemoteException;
    public void setReturnValue(String rVal) throws RemoteException;
}
