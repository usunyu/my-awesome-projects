/**
 * Copyright 2011, Google Inc. All Rights Reserved.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
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
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.google.appengine.api.datastore.Entity;

/**
 * This servlet responds to the request corresponding to items. The class
 * creates and manages the ItemEntity
 * 
 * @author
 */
@SuppressWarnings("serial")
public class ItemServlet extends BaseServlet {

  private static final Logger logger = Logger.getLogger(ItemServlet.class.getCanonicalName());

  /**
   * Searches for the entity based on the search criteria and returns result in
   * JSON format
   */
  protected void doGet(HttpServletRequest req, HttpServletResponse resp)
      throws ServletException, IOException {
  	super.doGet(req,resp);
    logger.log(Level.INFO, "Obtaining Item listing");
    String searchBy = req.getParameter("item-searchby");
    String searchFor = req.getParameter("q");
    PrintWriter out = resp.getWriter();
    if (searchFor == null || searchFor.equals("")) {
      Iterable<Entity> entities = Item.getAllItems();
      out.println(Util.writeJSON(entities));
    } else if (searchBy == null || searchBy.equals("name")) {
      Iterable<Entity> entities = Item.getItem(searchFor);
      out.println(Util.writeJSON(entities));
    } else if (searchBy != null && searchBy.equals("product")) {
      Iterable<Entity> entities = Item.getItemsForProduct("Item", searchFor);
      out.println(Util.writeJSON(entities));
    }
  }

  /**
   * Creates entity and persists the same
   */
  protected void doPut(HttpServletRequest req, HttpServletResponse resp)
      throws ServletException, IOException {
    logger.log(Level.INFO, "Creating Item");
    String itemName = req.getParameter("name");
    String product = req.getParameter("product");
    String price = req.getParameter("price");
    Item.createOrUpdateItem(product, itemName, price);
  }

  /**
   * Delete the entity from the datastore. Throws an exception if there are any
   * orders associated with the item and ignores the delete action for it.
   */
  protected void doDelete(HttpServletRequest req, HttpServletResponse resp)
      throws ServletException, IOException {
  	super.doGet(req, resp);
  	logger.log(Level.INFO, "Deleting Item");
    String itemKey = req.getParameter("id");
    PrintWriter out = resp.getWriter();
    Iterable<Entity> entities = Util.listEntities("LineItem", "itemName", itemKey);
    try {
      for (Entity e : entities) {
        if (e != null)
          out.print("Cannot delete item as there are orders associated with this item.");
        return;
      }
      Entity e = Item.getSingleItem(itemKey);
      Util.deleteFromCache(e.getKey());
      Util.deleteEntity(e.getKey());
      out.print("Item deleted successfully.");
    } catch (Exception e) {
      String msg = Util.getErrorResponse(e);
      out.print(msg);
    }
  }

  /**
   * Redirects to delete or insert entity based on the action in the HTTP
   * request.
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