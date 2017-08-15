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

import com.google.appengine.api.datastore.Entity;
import com.google.appengine.api.datastore.Key;
import com.google.appengine.api.datastore.KeyFactory;

/**
 * This class defines the methods for basic operations of create, update & retrieve
 * for the product entity
 * 
 * @author
 *
 */
public class Product {

	/**
	 * Update or create the product
	 * 
	 * @param name
	 *          : name of the product
	 * @param description
	 *          : description
	 * @return updated product
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
	 * 
	 * @param kind
	 *          : of kind product
	 * @return products
	 */
  public static Iterable<Entity> getAllProducts(String kind) {
    return Util.listEntities(kind, null, null);
  }

	/**
	 * Get product entity
	 * 
	 * @param name
	 *          : name of the product
	 * @return: product entity
	 */
  public static Entity getProduct(String name) {
    Key key = KeyFactory.createKey("Product", name);
    return Util.findEntity(key);
  }
}
