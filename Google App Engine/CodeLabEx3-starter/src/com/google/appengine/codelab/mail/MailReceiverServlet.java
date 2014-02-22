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
package com.google.appengine.codelab.mail;

import java.io.IOException;
import java.util.Properties;
import java.util.logging.Level;
import java.util.logging.Logger;

import javax.mail.MessagingException;
import javax.mail.Session;
import javax.mail.internet.MimeMessage;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
/**
 * This servlet responds to the mail receiving request.
 * 
 * @author
 */
@SuppressWarnings("serial")
public class MailReceiverServlet extends HttpServlet {
  private static Logger log = Logger.getLogger(MailReceiverServlet.class.getCanonicalName());

  public void doGet(HttpServletRequest req, HttpServletResponse resp)
      throws IOException {
    resp.setContentType("application/text; charset=utf-8");
    resp.setHeader("Cache-Control", "no-cache");
    try {
      ReceiveMail(req, resp);
    } catch (MessagingException e) {
      e.printStackTrace();
    }
  }

  public void doPost(HttpServletRequest req, HttpServletResponse resp)
      throws IOException {
    try {
    	receiveMail(req, resp);
    } catch (MessagingException e) {
    }
  }

  /**
   * This method logs when the app receives a mail to its email id.
   * 
   * @param req : http request containing the mail
   * @param resp : http response
   * @throws IOException
   * @throws MessagingException
   */
  public void receiveMail(HttpServletRequest req, HttpServletResponse resp)
      throws IOException, MessagingException {
   
  }
}
