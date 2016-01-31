package com.spring.sun.test;

import org.springframework.stereotype.Component;

@Component
public class ConsoleWriter implements LogWriter {

	public void write(String text) {
		System.out.println(text);
	}

}
