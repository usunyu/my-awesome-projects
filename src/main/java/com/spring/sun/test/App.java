package com.spring.sun.test;

import java.util.List;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import org.springframework.context.support.FileSystemXmlApplicationContext;
import org.springframework.dao.DataAccessException;

public class App {

	public static void main(String[] args) {
		ApplicationContext context = new ClassPathXmlApplicationContext("com/spring/sun/test/beans/beans.xml");
		
		//Person person = (Person)context.getBean("person");
		//person.setTaxId(666);
		//System.out.println(person);
		//Address address2 = (Address)context.getBean("address2");
		//System.out.println(address2);
		
		//FruitBasket basket = (FruitBasket)context.getBean("basket");
		//System.out.println(basket);
		
		//Jungle jungle = (Jungle)context.getBean("jungle");
		//System.out.println(jungle);
		
		//Logger logger = (Logger)context.getBean("logger");
		//logger.writeConsole("Hello there");
		//logger.writeFile("Hi again");
		
		OfferDao offerDao = (OfferDao)context.getBean("offerDao");
		try {
			List<Offer> offers = offerDao.getOffers();
			
			for(Offer offer : offers) {
				System.out.println(offer);
			}
		} catch (DataAccessException e) {
			System.out.println(e.getMessage());
			System.out.println(e.getClass());
		}
		
		((ClassPathXmlApplicationContext)context).close();
	}

}
