package com.spring.sun.test;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import org.springframework.context.support.FileSystemXmlApplicationContext;

public class App {

	public static void main(String[] args) {
		ApplicationContext context = new ClassPathXmlApplicationContext("com/spring/sun/test/beans/beans.xml");
		
		Person person = (Person)context.getBean("person");
		person.speak();
		
		System.out.println(person);
		
		((ClassPathXmlApplicationContext)context).close();
	}

}
