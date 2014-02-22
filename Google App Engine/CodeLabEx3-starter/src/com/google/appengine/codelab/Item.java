package com.google.appengine.codelab;

import java.util.List;

import com.google.appengine.api.datastore.Entity;
import com.google.appengine.api.datastore.FetchOptions;
import com.google.appengine.api.datastore.Key;
import com.google.appengine.api.datastore.KeyFactory;
import com.google.appengine.api.datastore.Query;
import com.google.appengine.api.datastore.Query.FilterOperator;

public class Item {

  /**
   * Create or update Item for a particular product. Product has one to many
   * relation-ship
   * 
   * @param productName
   *          : product name for which the item is created.
   * @param itemName
   *          : item name
   * @param price
   *          : price of the item
   * @return
   */
  public static Entity createOrUpdateItem(String productName, String itemName,
      String price) {
    Entity product = Product.getProduct(productName);
    Entity item = getSingleItem(itemName);
    if(item == null){
      item = new Entity("Item", product.getKey());
      item.setProperty("name", itemName);
      item.setProperty("product", productName);
      item.setProperty("price", price);
    }
    else{
      if (price != null && !"".equals(price)) {
    	item.setProperty("price", price);
      }
      if (productName != null && !"".equals(productName)) {
    	item.setProperty("product", productName);
      }
    }
    Util.persistEntity(item);
    return item;
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
   * Get the item given the name
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
    Query q = new Query("Item");
    q.addFilter("name", FilterOperator.EQUAL, itemName);
    List<Entity> results = Util.getDatastoreServiceInstance().prepare(q).asList(FetchOptions.Builder.withDefaults());
    if (!results.isEmpty()) {
      return (Entity)results.remove(0);
    }
    return null;
  }
}
