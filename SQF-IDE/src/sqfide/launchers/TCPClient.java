package sqfide.launchers;
import java.io.*;
import java.net.*;

public class TCPClient
{
    public static final String EOF = "THIS_IS_THE_END";
    public static final String DEFAULT_HOST = "192.168.1.169";
    public static final int DEFAULT_PORT = 11000;
    
    private String host_ = DEFAULT_HOST;
    private int port_ = DEFAULT_PORT;
    
    public String sendMessage(String message) throws UnknownHostException, IOException 
    {
        String response;
        Socket clientSocket = new Socket(host_, port_);
        DataOutputStream outToServer = new DataOutputStream(clientSocket.getOutputStream());
        BufferedReader inFromServer = 
                new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
        outToServer.writeBytes(message + EOF);
        response = inFromServer.readLine();
        clientSocket.close();
        return response;
    }
}
