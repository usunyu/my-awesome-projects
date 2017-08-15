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
import java.util.Map;
import java.util.logging.Level;
import java.util.logging.Logger;

import com.google.appengine.api.datastore.DatastoreService;
import com.google.appengine.api.datastore.DatastoreServiceFactory;
import com.google.appengine.api.datastore.Entity;
import com.google.appengine.api.datastore.EntityNotFoundException;
import com.google.appengine.api.datastore.Key;
import com.google.appengine.api.datastore.PreparedQuery;
import com.google.appengine.api.datastore.Query;
import com.google.appengine.api.datastore.Query.FilterOperator;
import com.google.appengine.api.datastore.Transaction;


/**
 * This is the utility class for all servlets. It provides method for inserting,
 * deleting, searching the entity from data store. Also contains method for
 * displaying the entity in JSON format.
 * 
 */
public class Util {

  private static final Logger logger = Logger.getLogger(Util.class.getCanonicalName());
  private static DatastoreService datastore = DatastoreServiceFactory.getDatastoreService();

/**
 * 
 * @param entity  : entity to be persisted
 */
  public static void persistEntity(Entity entity) {
	logger.log(Level.INFO, "Saving entity");
	Transaction txn = datastore.beginTransaction();
	try {
	  datastore.put(entity);
	  txn.commit();
	} finally {
	  if (txn.isActive()) {
	    txn.rollback();
	  } 
	}
  }

	/**
	 * Search and return the entity from the cache . If absent , search the datastore.
	 * @param key : key to find the entity
	 * @return  entity
	 */
  public static Entity findEntity(Key key) {
	logger.log(Level.INFO, "Search the entity");
	try {
	  return datastore.get(key);
	} catch (EntityNotFoundException e) {
	  return null;
	}
  }

	/***
	 * Search entities based on search criteria
	 * @param kind
	 * @param searchBy
	 *            : Searching Criteria (Property)
	 * @param searchFor
	 *            : Searching Value (Property Value)
	 * @return List all entities of a kind from the cache or datastore (if not
	 *         in cache) with the specified properties
	 */
  public static Iterable<Entity> listEntities(String kind, String searchBy,	String searchFor) {
	logger.log(Level.INFO, "Search entities based on search criteria");
	Query q = new Query(kind);
	if (searchFor != null && !"".equals(searchFor)) {
	  q.addFilter(searchBy, FilterOperator.EQUAL, searchFor);
	}
	PreparedQuery pq = datastore.prepare(q);
	logger.log(Level.WARNING, pq.toString());
	return pq.asIterable();
  }

	/**
	 * List the entities in JSON format
	 * 
	 * @param entities  entities to return as JSON strings
	 */
  public static String writeJSON(Iterable<Entity> entities) {
    logger.log(Level.INFO, "creating JSON format object");
	StringBuilder sb = new StringBuilder();
	int i = 0;
	sb.append("{\"data\": [");
	for (Entity result : entities) {
	  Map<String, Object> properties = result.getProperties();
	  sb.append("{");
	  if (result.getKey().getName() == null)
		sb.append("\"name\" : \"" + result.getKey().getId() + "\",");
	  else
		sb.append("\"name\" : \"" + result.getKey().getName() + "\",");

	  for (String key : properties.keySet()) {
		sb.append("\"" + key + "\" : \"" + properties.get(key) + "\",");
	  }
	  sb.deleteCharAt(sb.lastIndexOf(","));
	  sb.append("},");
	  i++;
	}
	if (i > 0) {
	  sb.deleteCharAt(sb.lastIndexOf(","));
	}  
	sb.append("]}");
	return sb.toString();
  }
  
	/**
	 * Utility method to send the error back to UI
	 * @param data
	 * @param resp
	 * @throws IOException 
	 */
  public static String getErrorResponse(Exception ex) throws IOException{
    return "Error:"+ex.toString();
  }
 
  public static DatastoreService getDatastoreServiceInstance(){
	  return datastore;
  }
}