package sqfide.launchers;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class RMIServer extends UnicastRemoteObject implements RMIInterface
{
    private static final long serialVersionUID = 1L;
    private static final int MAX_CODE_BLOCK_SIZE = 4096;
    private static final int TIMEOUT_MS = 100000;
   
    int begin_ = 0;
    int end_ = MAX_CODE_BLOCK_SIZE - 1;
    private String code_ = "";
    private boolean finished = false;
    private Long lastMessageReceived = System.currentTimeMillis();
    private String returnValue_ = null;
    private String errorMessage_;
    
    protected RMIServer() throws RemoteException
    {
        super();
    }
    
    @Override
    public String getCode()
    {
        String codeBlock = "";
        lastMessageReceived = System.currentTimeMillis();

        end_ = Math.min(end_, code_.length() - 1);
        if (begin_ > end_)
        {
            finished = true;
            return "";
        }
        codeBlock = code_.substring(begin_, end_);
        begin_ = end_ + 1;
        end_ = end_ + MAX_CODE_BLOCK_SIZE;
        return codeBlock;
    }

    @Override
    public void setReturnValue(String rVal)
    {
        returnValue_ = rVal;
    }
    
    public boolean working()
    {
        if (System.currentTimeMillis() - lastMessageReceived > TIMEOUT_MS )
        {
            //Timed out
            errorMessage_ = "Connection to the ArmA 3 game timed out.";
            return false;
        }
        else if (finished)
        {
            return false;
        }
        return true;
    }

    public void setCode(String code)
    {
        code_ = code;
    }
    
    public String getReturnValue()
    {
        return returnValue_;
    }
    
    public String errorMessage()
    {
        return errorMessage_;
    }
}
