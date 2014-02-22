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
import java.util.logging.Level;
import java.util.logging.Logger;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.xml.sax.SAXException;

import com.google.appengine.api.datastore.EntityNotFoundException;

/**
 * This servlet responds to the request corresponding to orders made from task queue and processes them.
 * It also sends a mail to the customer who placed the order.
 * 
 * @author
 */
@SuppressWarnings("serial")
public class ProcessOrderServlet extends HttpServlet {
	
  private static final Logger logger = Logger.getLogger(ProcessOrderServlet.class.getCanonicalName());

  @Override
  protected void doGet(HttpServletRequest req, HttpServletResponse resp)
		throws ServletException, IOException {
    resp.setContentType("application/text; charset=utf-8");
    resp.setHeader("Cache-Control", "no-cache");
    try {
      processOrder(req, resp);
    } catch (Exception e) {
      logger.log(Level.WARNING, e.getMessage());
    } 
  }

  @Override
  protected void doPost(HttpServletRequest req, HttpServletResponse resp)
      throws ServletException, IOException {
    resp.setContentType("application/text; charset=utf-8");
    resp.setHeader("Cache-Control", "no-cache");
	try {
      processOrder(req, resp);
	} catch (Exception e) {
      logger.log(Level.WARNING, e.getMessage());
	} 
  }

  /**
   * The method pulls the tasks from Queue and gets the respective orders from datastore
   * and updates the status to "processed". It also puts all the processed orders in a new entity
   * called "ProcessedOrder"
   * 
   * @param req : HTTP request from the task queue
   * @param resp : HTTP response
   * @throws IOException
   * @throws EntityNotFoundException 
   * @throws SAXException 
   */
  private void processOrder(HttpServletRequest req, HttpServletResponse resp)
      throws IOException, EntityNotFoundException, SAXException {
 
  }
}