package com.spring.sun.test;

public class Robot {
	
	private String id = "Default robot";
	private String speech = "hello";
	
	public void speak() {
		System.out.println(id + ": " + speech);
	}

	public void setId(String id) {
		this.id = id;
	}

	public void setSpeech(String speech) {
		this.speech = speech;
	}
	
	
}
