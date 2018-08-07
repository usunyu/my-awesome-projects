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
package com.google.appengine.codelab;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import com.google.appengine.api.datastore.Entity;
import com.google.appengine.api.datastore.Key;
import com.google.appengine.api.datastore.KeyFactory;

/**
 * This servlet responds to the request corresponding to users. The class
 * creates and manages the User Entity
 * 
 * @author
 */
@SuppressWarnings("serial")
public class CustomerServlet extends BaseServlet {

	private static final Logger logger = Logger.getLogger(CustomerServlet.class.getCanonicalName());

	/**
	 * Get the requested customer entities in JSON format
	 */
	protected void doGet(HttpServletRequest req, HttpServletResponse resp)
			throws ServletException, IOException {

		super.doGet(req, resp);
		logger.log(Level.INFO, "Obtaining Customer listing");
		String searchFor = req.getParameter("q");
		PrintWriter out = resp.getWriter();
		Iterable<Entity> entities = null;

		if (searchFor == null || searchFor.equals("")) {
			entities = Customer.getAllCustomers();
			out.println(Util.writeJSON(entities));
		} else {
			entities = Customer.getCustomer(searchFor);
			out.println(Util.writeJSON(entities));
		}
		return;
	}

	/**
	 * Insert the new customer
	 */
	protected void doPut(HttpServletRequest req, HttpServletResponse resp)
			throws ServletException, IOException {
		logger.log(Level.INFO, "Creating Customer");
		String nameKey = req.getParameter("name");
		String firstName = req.getParameter("firstName");
		String lastName = req.getParameter("lastName");
		String phone = req.getParameter("phone");
		String address = req.getParameter("address");
		String city = req.getParameter("city");
		String state = req.getParameter("state");
		String zip = req.getParameter("zip");
		String email = req.getParameter("eMail");
		Customer.createOrUpdateCustomer(nameKey, firstName, lastName, phone,
				address, city, state, zip, email);
	}

	/**
	 * Delete the customer
	 */
	protected void doDelete(HttpServletRequest req, HttpServletResponse resp)
			throws ServletException, IOException {
		String customerName = req.getParameter("id");
    logger.log(Level.INFO, "Deleting User {0}", customerName);
	  Key key = KeyFactory.createKey("Customer", customerName);
	  try {
	    // CASCADE_ON_DELETE
	    Iterable<Entity> entities = Util.listChildKeys("Order", key);
	    final List<Key> orderkeys = new ArrayList<Key>();
	    final List<Key> linekeys = new ArrayList<Key>();
	    for (Entity e : entities) {
	  	  orderkeys.add(e.getKey());
	  	  Iterable<Entity> lines = Util.listEntities("LineItem", "orderID",String.valueOf(e.getKey().getId()));
	  	  for(Entity en : lines){
	  		  linekeys.add(en.getKey());
	  	  }
	    }
	    Util.deleteEntity(linekeys);
	    Util.deleteEntity(orderkeys);
	  	Util.deleteFromCache(key);
	    Util.deleteEntity(key);
		} catch (Exception e) {
			String msg = Util.getErrorResponse(e);
			resp.getWriter().print(msg);
		}
	}

	/**
	 * Redirect the call to doDelete or doPut method
	 */
	protected void doPost(HttpServletRequest req, HttpServletResponse resp)
			throws ServletException, IOException {
		String action = req.getParameter("action");
		if (action.equalsIgnoreCase("delete")) {
			doDelete(req, resp);
			return;
		} else if (action.equalsIgnoreCase("put")) {
			doPut(req, resp);
			return;
		}
	}
}
