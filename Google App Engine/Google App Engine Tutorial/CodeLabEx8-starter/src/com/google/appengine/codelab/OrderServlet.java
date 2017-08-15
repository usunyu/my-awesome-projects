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
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collection;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.google.appengine.api.datastore.DatastoreService;
import com.google.appengine.api.datastore.DatastoreServiceFactory;
import com.google.appengine.api.datastore.Entity;
import com.google.appengine.api.datastore.FetchOptions;
import com.google.appengine.api.datastore.Key;
import com.google.appengine.api.datastore.KeyFactory;
import com.google.appengine.api.datastore.PreparedQuery;
import com.google.appengine.api.datastore.Query;
import com.google.appengine.api.datastore.Query.FilterOperator;
import com.google.appengine.api.datastore.Query.SortDirection;

/**
 * This servlet responds to the request corresponding to orders. The Class
 * places the order.
 * 
 * @author
 */
@SuppressWarnings("serial")
public class OrderServlet extends BaseServlet {

  private static final Logger logger = Logger.getLogger(OrderServlet.class.getCanonicalName());
  DatastoreService datastore = DatastoreServiceFactory.getDatastoreService();

  /**
	* Redirect the call to the corresponding method.
	*/
  protected void doPost(HttpServletRequest req, HttpServletResponse resp)
			throws ServletException, IOException {
    String action = req.getParameter("action");
    if(action.equalsIgnoreCase("process")){
      logger.log(Level.WARNING, "Processing orders");
      int i=0;
      //get Ids for the orders confirmed for processing
      String orderid[] = new String[req.getParameterMap().size()-1];
      while(req.getParameter("id"+i)!=null){
        orderid[i]=req.getParameter("id"+i);
        i++;
      }
      int ordersConfirmed = confirmOrder(orderid);
      resp.getWriter().print(ordersConfirmed+" order(s) have been confirmed for processing");
    }
  }
  
  /**
   * Gets the orders from the Orders datastore and converts them to XML format(marshal) and 
   * put them in the queue for processing.
   * 
   * @param orderid : array of orders that are processed
   * @throws IOException
   */
  public static int confirmOrder(String[] orderid) throws IOException {
    
    return 0;
  }

  private static void addTaskToPullQueue(String data) {
    
  }

	/**
	 * Get the requested orders and the line items in JSON format
	 */
  protected void doGet(HttpServletRequest req, HttpServletResponse resp)
			throws ServletException, IOException {
    super.doGet(req, resp);
    logger.log(Level.INFO, "Getting orders from listing");
    String status = req.getParameter("q1");
    String id = req.getParameter("q2");
    List<Entity> entities = new ArrayList<Entity>();
    List<Key> keys = new ArrayList<Key>();
    PrintWriter out = resp.getWriter();
    Query q = new Query("order");
    if (status == null || status.equals("")) {
      q.addFilter("status", FilterOperator.EQUAL, "pending");
    } else {
      q.addFilter("status", FilterOperator.EQUAL, status);
    }
    q.addSort("createdTime", SortDirection.DESCENDING);
    PreparedQuery pq = datastore.prepare(q);
    entities = pq.asList(FetchOptions.Builder.withLimit(10000));
    if(id!= null && !"".equals(id)){
      String str_keys[] = id.split(",");
      DatastoreService datastore = Util.getDatastoreServiceInstance(); 
      for(String s : str_keys){
        Key key = KeyFactory.createKey("order", Long.valueOf(s));
        keys.add(key);
      }
      Collection<Entity> en = datastore.get(keys).values();
      entities.retainAll(en); //Retrieve results based on both, Status & ID
    } 
    out.println(Util.writeJSON(entities));
  }
}