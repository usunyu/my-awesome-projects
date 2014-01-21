package com.spring.sun.test;

import org.springframework.stereotype.Component;

@Component("fileWriter")
public class FileWriter implements LogWriter {
	public void write(String text) {
		// Write to a file here.
		// Dummy implementation
		System.out.println("Write to file: " + text);
		
	}
}
