package com.spring.sun.test;

public class Person {
	
	private int id;
	private String name;
	private int taxId;
	private Address address;
	
	public Person() {
		
	}
	
	public Person(int id, String name) {
		this.id = id;
		this.name = name;
	}
	
	public void onCreate() {
		System.out.println("Person created: " + this);
	}
	
	public void onDestory() {
		System.out.println("Person destoryed");
	}
	
	public void setTaxId(int taxId) {
		this.taxId = taxId;
	}

	public void setAddress(Address address) {
		this.address = address;
	}

	@Override
	public String toString() {
		return "Person [id=" + id + ", name=" + name + ", taxId=" + taxId
				+ ", address=" + address + "]";
	}

	public void speak() {
		System.out.println("Hello, I am a person!");
	}
}
