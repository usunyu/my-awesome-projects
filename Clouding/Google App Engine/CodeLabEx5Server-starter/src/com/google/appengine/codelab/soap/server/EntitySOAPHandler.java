// Copyright 2011, Google Inc. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
package com.google.appengine.codelab.soap.server;

import java.util.Iterator;
import javax.xml.bind.JAXB;
import javax.xml.namespace.QName;
import javax.xml.soap.MessageFactory;
import javax.xml.soap.SAAJResult;
import javax.xml.soap.SOAPBody;
import javax.xml.soap.SOAPElement;
import javax.xml.soap.SOAPException;
import javax.xml.soap.SOAPFault;
import javax.xml.soap.SOAPMessage;
import javax.xml.transform.dom.DOMSource;
import com.google.appengine.codelab.soap.server.jaxws.*;

public class EntitySOAPHandler {
  
  private static final String NAMESPACE_URI = "http://server.soap.codelab.appengine.google.com/";
  private static final QName CREATE_OR_UPDATE_PRODUCT_QNAME = new QName(NAMESPACE_URI,"createOrUpdateProduct");
  private static final QName CREATE_OR_UPDATE_ITEM_QNAME = new QName(NAMESPACE_URI,"createOrUpdateItem");
  private static final QName DELETE_PRODUCT_QNAME = new QName(NAMESPACE_URI,"deleteProduct");
  private static final QName DELETE_ITEM_QNAME = new QName(NAMESPACE_URI,"deleteItem");
  private static final QName GET_PRODUCT_QNAME = new QName(NAMESPACE_URI,"getProduct");
  private static final QName GET_ALL_PRODUCTS_QNAME = new QName(NAMESPACE_URI,"getAllProducts");
  private static final QName GET_ITEM_QNAME = new QName(NAMESPACE_URI,"getItem");
  private static final QName GET_ITEMS_FOR_PRODUCT_QNAME = new QName(NAMESPACE_URI,"getItemsForProduct");
  private static final QName GET_ALL_ITEMS_QNAME = new QName(NAMESPACE_URI,"getAllItems");
  
  
  private MessageFactory messageFactory;
  private EntityAdapter greeterAdapter;

}