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

import java.util.ArrayList;
import java.util.List;

import com.google.appengine.api.datastore.Entity;
import com.google.appengine.api.datastore.Key;
import com.google.appengine.api.datastore.KeyFactory;

/**
 * This class defines the methods for basic operations of create, update & retrieve
 * 
 * @author 
 *
 */
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
	public static Iterable<Entity> getItemsForProduct(String kind,
			String productName) {
		Key ancestorKey = KeyFactory.createKey("Product", productName);
		return Util.listChildren("Item", ancestorKey);
	}

	/**
	 * get Item with item name
	 * 
	 * @param itemName
	 *          : get itemName
	 * @return item entity
	 */
	public static Entity getSingleItem(String itemName) {
		Iterable<Entity> results = Util.listEntities("Item", "name", itemName);
		List<Entity> entity = new ArrayList<Entity>();
		for(Entity e : results)
			if(e!=null)
				entity.add(e);
		if (!entity.isEmpty()) {
      return (Entity)entity.remove(0);
    }
		return null;
	}
}
