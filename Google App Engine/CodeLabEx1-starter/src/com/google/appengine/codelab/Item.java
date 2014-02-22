package com.google.appengine.codelab;

import java.util.List;

import com.google.appengine.api.datastore.Entity;
import com.google.appengine.api.datastore.FetchOptions;
import com.google.appengine.api.datastore.Key;
import com.google.appengine.api.datastore.KeyFactory;
import com.google.appengine.api.datastore.Query;
import com.google.appengine.api.datastore.Query.FilterOperator;


/**
 * This class handles CRUD operations related to Item entity.
 * 
 *
 */

public class Item {

  /**
   * Create or update Item for a particular product. Product entity has one to many
   * relation-ship with Item entity
   * 
   * @param productName
   *          : product name for which the item is created.
   * @param itemName
   *          : item name
   * @param price
   *          : price of the item
   * @return
   */
  public static Entity createOrUpdateItem(String productName, String itemName,String price) {
    
    return null;
  }

  /**
   * get All the items in the list
   * 
   * @param kind
   *          : item kind
   * @return all the items
   */
  public static Iterable<Entity> getAllItems() {
  	Iterable<Entity> entities = Util.listEntities("Item", null, null);
  	return entities;
  }

  /**
   * Get the item by name
   * 
   * @param itemName
   *          : item name
   * @return Item Entity
   */
  public static Iterable<Entity> getItem(String itemName) {
  	Iterable<Entity> entities = Util.listEntities("Item", "name", itemName);
  	return entities;
  }

  /**
   * Get all the items for a product
   * 
   * @param kind
   *          : item kind
   * @param productName
   *          : product name
   * @return: all items of type product
   */
  public static Iterable<Entity> getItemsForProduct(String kind, String productName) {
    Key ancestorKey = KeyFactory.createKey("Product", productName);
    return Util.listChildren("Item", ancestorKey);
  }

  /**
   * get Item with item name
   * @param itemName: get itemName
   * @return  item entity
   */
  public static Entity getSingleItem(String itemName) {
    
    return null;
  }
  
  public static String deleteItem(String itemKey)
  {
    return null;
  }
}
