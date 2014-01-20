package com.spring.sun.test;

public class Address {
	private String street;
	private String postcode;
	
	public Address(String street, String postcode) {
		super();
		this.street = street;
		this.postcode = postcode;
	}
	
	public void init() {
		System.out.println("Bean created:" + this);
	}

	@Override
	public String toString() {
		return "Address [street=" + street + ", postcode=" + postcode + "]";
	}
}
