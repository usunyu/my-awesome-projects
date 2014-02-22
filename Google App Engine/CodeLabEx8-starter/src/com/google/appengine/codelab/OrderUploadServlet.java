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
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * This servlet responds to the request for uploading Order XML files.
 * 
 * @author
 */
@SuppressWarnings("serial")
public class OrderUploadServlet extends BaseServlet {

  private static final Logger logger = Logger.getLogger(OrderUploadServlet.class.getCanonicalName());

  /**
   * Read the contents of uploaded file and add the xml as a string in the Task Queue, processed
   * using backend
   */
  protected void doPost(HttpServletRequest req, HttpServletResponse resp)
      throws ServletException, IOException {
    
  }

  private void createBackendTask(String data) {
    
  }
  
}