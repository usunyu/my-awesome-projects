// Copyright 2011, Google Inc. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
package com.google.appengine.codelab;

import java.io.DataInputStream;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.google.appengine.api.taskqueue.Queue;
import com.google.appengine.api.taskqueue.QueueFactory;
import com.google.appengine.api.taskqueue.TaskOptions;
import com.google.appengine.api.taskqueue.TaskOptions.Method;

/**
 * This servlet responds to the request corresponding to orders. The Class
 * places the order.
 * 
 * @author
 */
@SuppressWarnings("serial")
public class OrderUploadServlet extends HttpServlet {

  private static final Logger logger = Logger.getLogger(OrderUploadServlet.class.getCanonicalName());

  /**
   * Read the contents of uploaded file and add the xml as a string in the Task Queue, processed
   * using backend
   */
  protected void doPost(HttpServletRequest req, HttpServletResponse resp)
      throws ServletException, IOException {
    req.setAttribute("Accept", "text/xml");
    DataInputStream dataIn = new DataInputStream(req.getInputStream());
    //we are taking the length of Content type data
    int formDataLength = req.getContentLength();
    byte dataBytes[] = new byte[formDataLength];
    int byteRead = 0;
    int totalBytesRead = 0;
    //this loop converting the uploaded file into byte code
    while (totalBytesRead < formDataLength) {
      byteRead = dataIn.read(dataBytes, totalBytesRead,formDataLength);
      totalBytesRead += byteRead;
    }
    String file = new String(dataBytes);
    if(file.indexOf("<?xml") != -1){
      int start = file.indexOf("<?xml");
      file=file.substring(0, file.lastIndexOf("\n")-1);
      file=file.substring(start, file.lastIndexOf("\n")-1);
      logger.log(Level.WARNING, "adding to OrderQueue {0}", file);
      // Create Task and push it into Task Queue
      Queue queue = QueueFactory.getQueue("OrderQueue");
      TaskOptions taskOptions = TaskOptions.Builder.withUrl("/createOrder")
                                .param("xml", file)
                                .method(Method.POST);
      queue.add(taskOptions);
      resp.sendRedirect("/upload_finish.html");
    } else
      resp.sendRedirect("/");
  }
}