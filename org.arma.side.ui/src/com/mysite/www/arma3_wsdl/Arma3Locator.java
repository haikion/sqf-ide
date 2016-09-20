/**
 * Arma3Locator.java
 *
 * This file was auto-generated from WSDL
 * by the Apache Axis 1.4 Apr 22, 2006 (06:55:48 PDT) WSDL2Java emitter.
 */

package com.mysite.www.arma3_wsdl;

public class Arma3Locator extends org.apache.axis.client.Service implements com.mysite.www.arma3_wsdl.Arma3 {

/**
 * gSOAP 2.8.27 generated service definition
 */

    public Arma3Locator() {
    }


    public Arma3Locator(org.apache.axis.EngineConfiguration config) {
        super(config);
    }

    public Arma3Locator(java.lang.String wsdlLoc, javax.xml.namespace.QName sName) throws javax.xml.rpc.ServiceException {
        super(wsdlLoc, sName);
    }

    // Use to get a proxy class for arma3
    private java.lang.String arma3_address = "http://www.mysite.com/arma3.cgi";

    public java.lang.String getarma3Address() {
        return arma3_address;
    }

    // The WSDD service name defaults to the port name.
    private java.lang.String arma3WSDDServiceName = "arma3";

    public java.lang.String getarma3WSDDServiceName() {
        return arma3WSDDServiceName;
    }

    public void setarma3WSDDServiceName(java.lang.String name) {
        arma3WSDDServiceName = name;
    }

    public com.mysite.www.arma3_wsdl.Arma3PortType getarma3() throws javax.xml.rpc.ServiceException {
       java.net.URL endpoint;
        try {
            endpoint = new java.net.URL(arma3_address);
        }
        catch (java.net.MalformedURLException e) {
            throw new javax.xml.rpc.ServiceException(e);
        }
        return getarma3(endpoint);
    }

    public com.mysite.www.arma3_wsdl.Arma3PortType getarma3(java.net.URL portAddress) throws javax.xml.rpc.ServiceException {
        try {
            com.mysite.www.arma3_wsdl.Arma3Stub _stub = new com.mysite.www.arma3_wsdl.Arma3Stub(portAddress, this);
            _stub.setPortName(getarma3WSDDServiceName());
            return _stub;
        }
        catch (org.apache.axis.AxisFault e) {
            return null;
        }
    }

    public void setarma3EndpointAddress(java.lang.String address) {
        arma3_address = address;
    }

    /**
     * For the given interface, get the stub implementation.
     * If this service has no port for the given interface,
     * then ServiceException is thrown.
     */
    public java.rmi.Remote getPort(Class serviceEndpointInterface) throws javax.xml.rpc.ServiceException {
        try {
            if (com.mysite.www.arma3_wsdl.Arma3PortType.class.isAssignableFrom(serviceEndpointInterface)) {
                com.mysite.www.arma3_wsdl.Arma3Stub _stub = new com.mysite.www.arma3_wsdl.Arma3Stub(new java.net.URL(arma3_address), this);
                _stub.setPortName(getarma3WSDDServiceName());
                return _stub;
            }
        }
        catch (java.lang.Throwable t) {
            throw new javax.xml.rpc.ServiceException(t);
        }
        throw new javax.xml.rpc.ServiceException("There is no stub implementation for the interface:  " + (serviceEndpointInterface == null ? "null" : serviceEndpointInterface.getName()));
    }

    /**
     * For the given interface, get the stub implementation.
     * If this service has no port for the given interface,
     * then ServiceException is thrown.
     */
    public java.rmi.Remote getPort(javax.xml.namespace.QName portName, Class serviceEndpointInterface) throws javax.xml.rpc.ServiceException {
        if (portName == null) {
            return getPort(serviceEndpointInterface);
        }
        java.lang.String inputPortName = portName.getLocalPart();
        if ("arma3".equals(inputPortName)) {
            return getarma3();
        }
        else  {
            java.rmi.Remote _stub = getPort(serviceEndpointInterface);
            ((org.apache.axis.client.Stub) _stub).setPortName(portName);
            return _stub;
        }
    }

    public javax.xml.namespace.QName getServiceName() {
        return new javax.xml.namespace.QName("http://www.mysite.com/arma3.wsdl", "arma3");
    }

    private java.util.HashSet ports = null;

    public java.util.Iterator getPorts() {
        if (ports == null) {
            ports = new java.util.HashSet();
            ports.add(new javax.xml.namespace.QName("http://www.mysite.com/arma3.wsdl", "arma3"));
        }
        return ports.iterator();
    }

    /**
    * Set the endpoint address for the specified port name.
    */
    public void setEndpointAddress(java.lang.String portName, java.lang.String address) throws javax.xml.rpc.ServiceException {
        
if ("arma3".equals(portName)) {
            setarma3EndpointAddress(address);
        }
        else 
{ // Unknown Port Name
            throw new javax.xml.rpc.ServiceException(" Cannot set Endpoint Address for Unknown Port" + portName);
        }
    }

    /**
    * Set the endpoint address for the specified port name.
    */
    public void setEndpointAddress(javax.xml.namespace.QName portName, java.lang.String address) throws javax.xml.rpc.ServiceException {
        setEndpointAddress(portName.getLocalPart(), address);
    }

}
