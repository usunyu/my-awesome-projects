/**
 * Copyright 2011 Google
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package com.google.appengine.codelab;

import java.io.IOException;
import java.util.logging.Logger;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * This servlet responds to the request corresponding to orders made from task queue and processes them.
 * It also sends a mail to the customer who placed the order.
 * 
 * @author
 */
@SuppressWarnings("serial")
public class CreateOrderServlet extends HttpServlet {
	
  private static final Logger logger = Logger.getLogger(CreateOrderServlet.class.getCanonicalName());
  private static long recentId;

  @Override
  protected void doGet(HttpServletRequest req, HttpServletResponse resp)
      throws ServletException, IOException {
    createOrder(req, resp);
  }

  @Override
  protected void doPost(HttpServletRequest req, HttpServletResponse resp)
      throws ServletException, IOException {
    createOrder(req, resp);
  }

  /**
   * The method creates orders by unmarshalling the XML string based on the schema order-trial.xsd.
   * it logs an exception if the uploaded XML schema doesn't match the schema for this project.
   * 
   * @param req : HTTP request from the task queue
   * @param resp : HTTP response
   * @throws IOException
   */
  private void createOrder(HttpServletRequest req, HttpServletResponse resp)
      throws IOException {

  }
}