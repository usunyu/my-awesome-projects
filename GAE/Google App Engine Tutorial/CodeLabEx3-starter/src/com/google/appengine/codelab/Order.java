package com.google.appengine.codelab;


import com.google.appengine.api.datastore.Entity;
import com.google.appengine.api.datastore.Key;
import com.google.appengine.api.datastore.KeyFactory;
import com.google.appengine.api.datastore.Transaction;


public class Order {

  public static Entity createOrUpdateOrder(String customerName, String itemName,
      String quantity, String price, String shipTo, String city, String state, String zip) {

    Transaction txn = Util.getDatastoreServiceInstance().beginTransaction();
    try {
      Entity customer = Customer.getSingleCustomer(customerName);
      //Entity item = Item.getSingleItem(itemName);
      Key customerkey = customer.getKey();

      Entity order = new Entity("Order", customerkey);
      order.setProperty("customerName", customerName);
      order.setProperty("status", "Pending");
      order.setProperty("shipTo", shipTo);
      order.setProperty("city", city);
      order.setProperty("state", state);
      order.setProperty("zip", zip);
      Util.getDatastoreServiceInstance().put(order);

      Entity lineItem = new Entity("LineItem", order.getKey());
      //key to string can be inserted instead of name, a better option
      lineItem.setProperty("itemName", itemName);
      lineItem.setProperty("quantity", quantity);
      lineItem.setProperty("price", price);
      lineItem.setProperty("orderID", String.valueOf(order.getKey().getId()));
      Util.getDatastoreServiceInstance().put(lineItem);
      txn.commit();
      return order;
    } finally {
      if (txn.isActive()) {
        txn.rollback();
      }
    }
  }
  
  public static Iterable<Entity> getAllOrders() {
	  Iterable<Entity> entities = Util.listEntities("Order", null, null);
	  return entities;
  }
  
  public static Iterable<Entity> getAllOrdersForCustomer(String customerName) {
    Key customerKey = KeyFactory.createKey("Customer", customerName);
    return Util.listChildren("Order", customerKey);
  }
}
