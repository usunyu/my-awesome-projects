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
import java.util.Iterator;
import java.util.List;
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
import com.google.appengine.api.memcache.MemcacheService;
import com.google.appengine.api.memcache.MemcacheServiceFactory;


/**
 * This is the utility class for all servlets. It provides method for inserting,
 * deleting, searching the entity from data store. Also contains method for
 * displaying the entity in JSON format.
 * 
 */
public class Util {

  private static final Logger logger = Logger.getLogger(Util.class.getCanonicalName());
  private static DatastoreService datastore = DatastoreServiceFactory.getDatastoreService();

  private static MemcacheService keycache = MemcacheServiceFactory.getMemcacheService();

/**
 * 
 * @param entity  : entity to be persisted
 */
  public static void persistEntity(Entity entity) {
	logger.log(Level.INFO, "Saving entity");
	Key key = entity.getKey();
	Transaction txn = datastore.beginTransaction();
	try {
	  datastore.put(entity);
	  txn.commit();
	} finally {
	  if (txn.isActive()) {
	    txn.rollback();
	  } else {
	    addToCache(key, entity);
	  }
	}
  }

	/**
	 * Delete the entity from persistent store represented by the key
	 * @param key : key to delete the entity from the persistent store
	 */
  public static void deleteEntity(Key key) {
	logger.log(Level.INFO, "Deleting entity");
	Transaction txn = datastore.beginTransaction();
	try {
	  datastore.delete(key);
	  txn.commit();
	} finally {
	  if (txn.isActive()) {
	    txn.rollback();
	  } else {
		deleteFromCache(key);
	  }
	}
  }
  
  public static void deleteEntity(final List<Key> keys){
    datastore.delete(new Iterable<Key>() {
		public Iterator<Key> iterator() {
		  return keys.iterator();
		}
      });
    deleteFromCache(keys);
  }

	/**
	 * Search and return the entity from the cache . If absent , search the datastore.
	 * @param key : key to find the entity
	 * @return  entity
	 */
  public static Entity findEntity(Key key) {
	logger.log(Level.INFO, "Search the entity");
	try {
	  Entity e = getFromCache(key);
	  if (e != null) {
		return e;
	  }
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
  public static Iterable<Entity> listEntities(String kind, String searchBy,
			String searchFor) {
	logger.log(Level.INFO, "Search entities based on search criteria");
	Query q = new Query(kind);
	if (searchFor != null && !"".equals(searchFor)) {
	  q.addFilter(searchBy, FilterOperator.EQUAL, searchFor);
	}
	PreparedQuery pq = datastore.prepare(q);
	return pq.asIterable();
  }
  
  public static Iterable<Entity> listChildren(String kind, Key ancestor) {
	logger.log(Level.INFO, "Search entities based on parent");
	Query q = new Query(kind);
	q.setAncestor(ancestor);
	q.addFilter(Entity.KEY_RESERVED_PROPERTY, FilterOperator.GREATER_THAN, ancestor);
	PreparedQuery pq = datastore.prepare(q);
	return pq.asIterable();
  }
  
  public static Iterable<Entity> listChildKeys(String kind, Key ancestor) {
	logger.log(Level.INFO, "Search entities based on parent");
	Query q = new Query(kind);
	q.setAncestor(ancestor).setKeysOnly();
	q.addFilter(Entity.KEY_RESERVED_PROPERTY, FilterOperator.GREATER_THAN, ancestor);
	PreparedQuery pq = datastore.prepare(q);
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
	 * Retrieves Parent and Child entities into JSON String
	 * 
	 * @param entities
	 *            : List of parent entities
	 * @param childKind
	 *            : Entity type for Child
	 * @param fkName
	 *            : foreign-key to the parent in the child entity
	 * @return JSON string
	 */
  public static String writeJSON(Iterable<Entity> entities, String childKind, String fkName) {
	logger.log(Level.INFO, "creating JSON format object for parent child relation");
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
	  Iterable<Entity> child = listEntities(childKind, fkName,
	  String.valueOf(result.getKey().getId()));
	  for (Entity en : child) {
		for (String key : en.getProperties().keySet()) {
		  sb.append("\"" + key + "\" : \"" + en.getProperties().get(key)+ "\",");
		}
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
   * Adds the entity to cache
   * @param key : key of the entity
   * @param entity : Entity being added
   */
  public static void addToCache(Key key, Entity entity) {
	  logger.log(Level.INFO, "Adding entity to cache");
	keycache.put(key, entity);
  }

  public static void deleteFromCache(Key key) {
	logger.log(Level.INFO, "Deleting entity from cache");
	keycache.delete(key);
  }
  
  public static void deleteFromCache(List<Key> keys){
	  keycache.deleteAll(keys);
  }

  public static Entity getFromCache(Key key) {
	logger.log(Level.INFO, "Searching entity in cache");
	return (Entity) keycache.get(key);
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