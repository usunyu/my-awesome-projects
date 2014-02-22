package com.google.appengine.codelab;

import com.google.appengine.api.datastore.Entity;
import com.google.appengine.api.datastore.FetchOptions;
import com.google.appengine.api.datastore.Key;
import com.google.appengine.api.datastore.KeyFactory;
import com.google.appengine.api.datastore.Query;

public class Product {

  /**
   * Update the product
   * @param name: name of the product
   * @param description : description
   * @return  updated product
   */
  public static void createOrUpdateProduct(String name, String description) {
    Entity product = getProduct(name);
	if (product == null) {
	  product = new Entity("Product", name);
	  product.setProperty("description", description);
	} else {
	  product.setProperty("description", description);
	}
	Util.persistEntity(product);
  }

  /**
   * Return all the products
   * @param kind : of kind product
   * @return  products
   */
  public static Iterable<Entity> getAllProducts(String kind) {
	return Util.listEntities(kind, null, null);
  }

  /**
   * Get product entity
   * @param name : name of the product
   * @return: product entity
   */
  public static Entity getProduct(String name) {
	Key key = KeyFactory.createKey("Product",name);
	return Util.findEntity(key);
  }

  /**
   * Get all items for a product
   * @param name: name of the product
   * @return list of items
   */
  public static Iterable<Entity> getItems(String name) {
	Query query = new Query();
	Key parentKey = KeyFactory.createKey("Product", name);
	query.setAncestor(parentKey);
	query.addFilter(Entity.KEY_RESERVED_PROPERTY, Query.FilterOperator.GREATER_THAN, parentKey);
		Iterable<Entity> results = Util.getDatastoreServiceInstance()
				.prepare(query).asList(FetchOptions.Builder.withDefaults());
		return results;
	}
}
