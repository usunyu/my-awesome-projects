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
import java.util.HashSet;
import java.util.Set;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import com.google.appengine.api.datastore.Entity;
import com.google.appengine.api.datastore.Key;
import com.google.appengine.api.datastore.KeyFactory;

/**
 * This servlet responds to the request corresponding to contacts.
 * This class creates and manages the Contact Entity.
 * 
 * @author
 */

@SuppressWarnings("serial")
public class ContactServlet extends HttpServlet {

  private static final Logger logger = Logger.getLogger(ItemServlet.class.getCanonicalName());
  private Util util = new Util();

  /**
   * Get the list of contacts in JSON format.
   */
  protected void doGet(HttpServletRequest req, HttpServletResponse resp)
      throws ServletException, IOException {
    logger.log(Level.INFO, "Obtaining Contact listing");
    resp.setContentType("text/json");
    PrintWriter out = resp.getWriter();
    String contactNameKey = req.getParameter("name");
    if(contactNameKey != null){
      Key key = KeyFactory.createKey("Contact", contactNameKey);
      Entity e = util.findEntity(key);
      if(e!=null){
        Set<Entity> result = new HashSet<Entity>();
        result.add(e);
        out.println(util.writeJSON(result));  
      }  
    }
    else{
      Iterable<Entity> entities = util.listEntities("Contact", null, null);
      out.println(util.writeJSON(entities));
    }
  }

  /**
   * Create the entity based on the request and persist it.
   */
  protected void doPut(HttpServletRequest req, HttpServletResponse resp)
      throws ServletException, IOException {
    logger.log(Level.INFO, "Creating Contact");
    Entity contact = createEntity(req);
    util.persistEntity(contact);
  }

  /**
   * Delete the specified contact from the Datastore.
   */
  protected void doDelete(HttpServletRequest req, HttpServletResponse resp)
      throws ServletException, IOException {
    String contactKey = req.getParameter("name");
    logger.log(Level.INFO, "Deleting Contact {0}", contactKey);
    Key key = KeyFactory.createKey("Contact", contactKey);
    util.deleteEntity(key);
  }

  /**
   * Delete or persist an entity based on the action passed through POST request.
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

/**
 * Update an existing entity.
 * @param updateEntity : Entity which has to be updated
 * @param request : Http request which has the values that are to be updated
 * @return the updated entity
 */
  private Entity updateEntity(Entity updateEntity, HttpServletRequest request) {
    String address = request.getParameter("address");
    String city = request.getParameter("city");
    String state = request.getParameter("state");
    String country = request.getParameter("country");
    String zip = request.getParameter("zip");
    String phone = request.getParameter("phone");
    String email = request.getParameter("email");
    
    if (phone != null && !"".equals(phone)) {
      updateEntity.setProperty("Phone", phone);
    }
    updateEntity.setProperty("Address", address);
    updateEntity.setProperty("City", city);
    updateEntity.setProperty("State", state);
    updateEntity.setProperty("Country", country);
    updateEntity.setProperty("Zip", zip);
    updateEntity.setProperty("Email", email);
    return updateEntity;
  }

  /**
   * Create the entity if the entity is not there else it updates the existing entity.
   * @param request : HTTP request which has values of the properties of the entity to be created
   * @return the created entity
   */
  private Entity createEntity(HttpServletRequest request) {
    String contactKey = request.getParameter("name");
    Key key = KeyFactory.createKey("Contact", contactKey);
    Entity entity = util.findEntity(key);
    if(entity==null){
      String address = request.getParameter("address");
      String city = request.getParameter("city");
      String state = request.getParameter("state");
      String country = request.getParameter("country");
      String zip = request.getParameter("zip");
      String phone = request.getParameter("phone");
      String email = request.getParameter("email");
      
      entity = new Entity("Contact", contactKey);
      entity.setProperty("Address", address);
      entity.setProperty("City", city);
      entity.setProperty("State", state);
      entity.setProperty("Country", country);
      entity.setProperty("Zip", zip);
      entity.setProperty("Phone", phone);
      entity.setProperty("Email", email);
      return entity;  
    }
    else{
      return updateEntity(entity, request);
    }
  } 
}
