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

import com.google.appengine.api.datastore.Entity;
import com.google.appengine.api.datastore.Key;
import com.google.appengine.api.datastore.KeyFactory;
import com.google.appengine.api.datastore.Transaction;

/**
 * This class defines the methods for basic operations of create, update & retrieve
 * for order entity
 *  
 * @author
 *
 */
public class Order {

	/**
	 * Create an entity if it does not exist, else update the existing entity.
	 * The order has header and line item. Both needs to be added in a single transaction.
	 * 
	 * @param customerName
	 *          : customer placing the order
	 * @param itemName
	 *          : name of item
	 * @param quantity
	 *          : number of units ordered for
	 * @param price
	 *          : total price of the order
	 * @param shipTo
	 *          : address where it needs to be shipped
	 * @throws IOException 
	 */
	public static void createOrUpdateOrder(String customerName, String itemName,
			String quantity, String price, String shipTo, String city, String state, String zip) throws IOException {
		
	}

	/**
	 * Get all the orders
	 * 
	 * @return : list of all orders
	 */
	public static Iterable<Entity> getAllOrders() {
		Iterable<Entity> entities = Util.listEntities("Order", null, null);
		return entities;
	}

	/**
	 * Get the list of orders for a specific customer
	 * 
	 * @param customerName
	 * @return the list of orders as iterable
	 */
	public static Iterable<Entity> getAllOrdersForCustomer(String customerName) {
		Key customerKey = KeyFactory.createKey("Customer", customerName);
		return Util.listChildren("Order", customerKey);
	}
}
