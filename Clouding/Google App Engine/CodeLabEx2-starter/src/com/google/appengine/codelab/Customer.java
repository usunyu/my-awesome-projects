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

import com.google.appengine.api.datastore.Entity;
import com.google.appengine.api.datastore.Key;
import com.google.appengine.api.datastore.KeyFactory;

/**
 * This class defines the methods for basic operations of create, update & retrieve
 * for customer entity
 * 
 * @author 
 *
 */
public class Customer {

	/**
	 * Checks if the entity is existing and if it is not, it creates the entity
	 * else it updates the entity
	 * 
	 * @param nickName
	 *          : username for the customer
	 * @param firstName
	 *          : first name of the customer
	 * @param lastName
	 *          : last name of the customer
	 * @param address
	 *          : address of customer
	 * @param phone
	 *          : contact phone number
	 * @param email
	 *          : email id of customer
	 */
	public static void createOrUpdateCustomer(String nickName, String firstName,
			String lastName, String phone, String address, String city, String state, String zip, String email) {
		Entity customer = getSingleCustomer(nickName);
		if (customer == null) {
			customer = new Entity("Customer", nickName);
			customer.setProperty("name", nickName);
			customer.setProperty("firstName", firstName);
			customer.setProperty("lastName", lastName);
			customer.setProperty("phone", phone);
			customer.setProperty("address", address);
			customer.setProperty("city", city);
			customer.setProperty("state", state);
			customer.setProperty("zip", zip);
			customer.setProperty("eMail", email);
		} else {
			if (firstName != null && !"".equals(firstName)) {
				customer.setProperty("firstName", firstName);
			}
			if (lastName != null && !"".equals(lastName)) {
				customer.setProperty("lastName", lastName);
			}
			if (phone != null && !"".equals(phone)) {
				customer.setProperty("phone", phone);
			}
			if (address != null && !"".equals(address)) {
				customer.setProperty("address", address);
			}
			if (city != null && !"".equals(city)) {
				customer.setProperty("city", city);
			}
			if (state != null && !"".equals(state)) {
				customer.setProperty("state", state);
			}
			if (zip != null && !"".equals(zip)) {
				customer.setProperty("zip", zip);
			}
			if (email != null && !"".equals(email)) {
				customer.setProperty("eMail", email);
			}
		}
		Util.persistEntity(customer);
	}

	/**
	 * List all the customers available
	 * 
	 * @return an iterable list with all the customers
	 */
	public static Iterable<Entity> getAllCustomers() {
		Iterable<Entity> entities = Util.listEntities("Customer", null, null);
		return entities;
	}

	/**
	 * Searches for a customer and returns the entity as an iterable The search is
	 * performed by creating a query and searching for the attribute
	 * 
	 * @param customerName
	 *          : username of the customer
	 * @return iterable with the customers searched for
	 */
	public static Iterable<Entity> getCustomer(String customerName) {
		Iterable<Entity> entities = Util.listEntities("Customer", "name",	customerName);
		return entities;
	}

	/**
	 * Searches for a customer and returns the entity as an iterable The search is
	 * key based instead of query
	 * 
	 * @param customerName
	 *          : username of the customer
	 * @return the entity with the username as key
	 */
	public static Entity getSingleCustomer(String customerName) {
		Key key = KeyFactory.createKey("Customer", customerName);
		return Util.findEntity(key);
	}
}
