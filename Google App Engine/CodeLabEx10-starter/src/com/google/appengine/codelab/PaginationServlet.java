package com.google.appengine.codelab;

import java.io.IOException;

import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@SuppressWarnings("serial")
public class PaginationServlet extends HttpServlet {
	
  public  static  final int	PAGE_SIZE = 10;
  
  public void doGet(HttpServletRequest req, HttpServletResponse resp)
			throws IOException {
	  
  }
}