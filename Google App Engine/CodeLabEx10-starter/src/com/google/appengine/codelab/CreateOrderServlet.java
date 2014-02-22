/**
 * Copyright 2011 Google
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package com.google.appengine.codelab;

import java.io.IOException;
import java.util.Date;
import java.util.logging.Level;
import java.util.logging.Logger;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.xml.sax.SAXException;

import com.google.appengine.api.datastore.Entity;
import com.google.appengine.codelab.generated.Order;
import com.google.appengine.codelab.generated.OrderBooking;

/**
 * This servlet responds to the request corresponding to orders made from task queue and processes them.
 * It also sends a mail to the customer who placed the order.
 * 
 * @author
 */
@SuppressWarnings("serial")
public class CreateOrderServlet extends HttpServlet {
	
  private static final Logger logger = Logger.getLogger(CreateOrderServlet.class.getCanonicalName());
  private static long recentId;

  @Override
  protected void doGet(HttpServletRequest req, HttpServletResponse resp)
      throws ServletException, IOException {
    createOrder(req, resp);
  }

  @Override
  protected void doPost(HttpServletRequest req, HttpServletResponse resp)
      throws ServletException, IOException {
    createOrder(req, resp);
  }

  /**
   * The method processes the order and also triggers a mail confirmation for the same.
   * 
   * @param req : HTTP request from the task queue
   * @param resp : HTTP response
   * @throws IOException
   */
  private void createOrder(HttpServletRequest req, HttpServletResponse resp)
      throws IOException {
    resp.setContentType("application/json; charset=utf-8");
    resp.setHeader("Cache-Control", "no-cache");
    String xmlString = req.getParameter("xml");
    String mailContent ="";
    logger.log(Level.WARNING, "got the parameter {0}", xmlString);
    XmlParser parser = new XmlParser();
    OrderBooking orderBooking;
	try {
	  orderBooking = parser.unmarshalXml(xmlString);
	  for(Order ord : orderBooking.getOrder()){
        Entity order = new Entity("order");
        order.setProperty("customerName", ord.getCustomer());
        order.setProperty("itemName", ord.getItem());
        order.setProperty("quantity", ord.getQuantity().toString());
        order.setProperty("status", ord.getStatus());
        order.setProperty("price", ord.getPrice().toPlainString());
        order.setProperty("user_orderid", ord.getUserOrderid());
        Date date = new Date();
        order.setProperty("createdTime", date);
        Util.persistEntity(order);
        recentId = order.getKey().getId();
        mailContent+=(recentId+",");
	  }
	  logger.log(Level.WARNING, "orders have been created from the file you uploaded {0}", mailContent);
	} catch (SAXException ex) {
	  logger.log(Level.WARNING, ex.getMessage());
    }
  }
}