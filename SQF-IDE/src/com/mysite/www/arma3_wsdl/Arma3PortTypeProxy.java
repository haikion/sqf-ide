package com.mysite.www.arma3_wsdl;

public class Arma3PortTypeProxy implements com.mysite.www.arma3_wsdl.Arma3PortType {
  private String _endpoint = null;
  private com.mysite.www.arma3_wsdl.Arma3PortType arma3PortType = null;
  
  public Arma3PortTypeProxy() {
    _initArma3PortTypeProxy();
  }
  
  public Arma3PortTypeProxy(String endpoint) {
    _endpoint = endpoint;
    _initArma3PortTypeProxy();
  }
  
  private void _initArma3PortTypeProxy() {
    try {
      arma3PortType = (new com.mysite.www.arma3_wsdl.Arma3Locator()).getarma3();
      if (arma3PortType != null) {
        if (_endpoint != null)
          ((javax.xml.rpc.Stub)arma3PortType)._setProperty("javax.xml.rpc.service.endpoint.address", _endpoint);
        else
          _endpoint = (String)((javax.xml.rpc.Stub)arma3PortType)._getProperty("javax.xml.rpc.service.endpoint.address");
      }
      
    }
    catch (javax.xml.rpc.ServiceException serviceException) {}
  }
  
  public String getEndpoint() {
    return _endpoint;
  }
  
  public void setEndpoint(String endpoint) {
    _endpoint = endpoint;
    if (arma3PortType != null)
      ((javax.xml.rpc.Stub)arma3PortType)._setProperty("javax.xml.rpc.service.endpoint.address", _endpoint);
    
  }
  
  public com.mysite.www.arma3_wsdl.Arma3PortType getArma3PortType() {
    if (arma3PortType == null)
      _initArma3PortTypeProxy();
    return arma3PortType;
  }
  
  public java.lang.Boolean runSQFScript(java.lang.String code) throws java.rmi.RemoteException{
    if (arma3PortType == null)
      _initArma3PortTypeProxy();
    return arma3PortType.runSQFScript(code);
  }
  
  
}