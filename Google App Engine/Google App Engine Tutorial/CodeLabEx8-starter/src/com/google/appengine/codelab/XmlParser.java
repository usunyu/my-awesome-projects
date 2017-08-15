package com.google.appengine.codelab;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.util.logging.Level;
import java.util.logging.Logger;

import javax.xml.bind.JAXBContext;
import javax.xml.bind.JAXBException;
import javax.xml.bind.Marshaller;
import javax.xml.bind.Unmarshaller;
import javax.xml.stream.XMLInputFactory;
import javax.xml.stream.XMLStreamException;
import javax.xml.stream.XMLStreamReader;
import javax.xml.validation.Schema;
import javax.xml.validation.SchemaFactory;

import org.xml.sax.SAXException;

import com.google.appengine.codelab.generated.OrderBooking;

public class XmlParser {

  private static final Logger logger = Logger.getLogger(XmlParser.class.getCanonicalName());

  /**
   * Verifies and converts an XML string to Java object
   * @param xml : String to be parsed
   * @return : Java object representation of the XML
   * @throws SAXException 
   */
  public OrderBooking unmarshalXml(String xml) throws SAXException {
    OrderBooking booking = null;
    try{
      JAXBContext jaxbContext = JAXBContext.newInstance(OrderBooking.class);
      XMLInputFactory inputFactory = XMLInputFactory.newInstance();
      XMLStreamReader eventReader = inputFactory.createXMLStreamReader(new java.io.StringReader(xml));
      SchemaFactory sf = SchemaFactory.newInstance(javax.xml.XMLConstants.W3C_XML_SCHEMA_NS_URI);
      Schema schema = sf.newSchema(new File("order-trial.xsd"));
      Unmarshaller unmarshaller = jaxbContext.createUnmarshaller();
      unmarshaller.setSchema(schema);
      booking = (OrderBooking)unmarshaller.unmarshal(eventReader);
    } catch(JAXBException ex){
      logger.log(Level.WARNING, ex.getMessage());	
    } catch (XMLStreamException ex) {
      logger.log(Level.WARNING, ex.getMessage());
    } 
    return booking;
  }
  
  /**
   * Convert a Java object to XML String
   * 
   * @param booking : Java object to be converted
   * @return : XML String format of the Java object
   */
  public String marshalXml(OrderBooking booking){
    JAXBContext jaxbContext;
    String s="";
    try {
      jaxbContext = JAXBContext.newInstance(OrderBooking.class);
      Marshaller marshaller = jaxbContext.createMarshaller();
      marshaller.setProperty(Marshaller.JAXB_FORMATTED_OUTPUT, Boolean.TRUE);
      ByteArrayOutputStream output = new ByteArrayOutputStream();
      marshaller.marshal( booking, output );
      s = output.toString();
      logger.log(Level.WARNING, s);
    } catch (JAXBException e) {
      logger.log(Level.WARNING, e.getMessage());
    }
    return s;
  }
}


