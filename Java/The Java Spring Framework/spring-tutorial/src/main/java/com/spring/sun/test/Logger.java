package com.spring.sun.test;

/*
 * Dummy implementation of logger.
 */
import javax.annotation.*;
import javax.inject.Inject;
import javax.inject.Named;

import org.springframework.stereotype.Component;

@Component
public class Logger {

	private ConsoleWriter consoleWriter;
	private LogWriter fileWriter;

	@Inject
	public void setConsoleWriter(ConsoleWriter writer) {
		this.consoleWriter = writer;
	}

	@Inject
	@Named(value="fileWriter")
	public void setFileWriter(LogWriter fileWriter) {
		this.fileWriter = fileWriter;
	}
	
	public void writeFile(String text) {
		fileWriter.write(text);
	}
	
	public void writeConsole(String text) {
		if(consoleWriter != null)
			consoleWriter.write(text);
	}

	@PostConstruct
	public void init() {
		System.out.println("init");
	}
	
	@PreDestroy
	public void destroy() {
		System.out.println("destroy");
	}
}
