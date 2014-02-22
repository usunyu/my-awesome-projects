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
package com.google.appengine.codelab.xmpp.chat;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import com.google.appengine.api.xmpp.JID;
import com.google.appengine.api.xmpp.XMPPService;
import com.google.appengine.api.xmpp.XMPPServiceFactory;

/**
 * This servlet responds to the request corresponding to entity contact.
 * 
 * @author
 */
@SuppressWarnings("serial")
public class SendChatInviteServlet extends HttpServlet {
  @Override
  protected void doGet(HttpServletRequest req, HttpServletResponse resp)
      throws ServletException, IOException {

  }

  @Override
  protected void doPost(HttpServletRequest req, HttpServletResponse resp)
      throws ServletException, IOException {
    resp.setContentType("application/text; charset=utf-8");
    resp.setHeader("Cache-Control", "no-cache");
  	sendInvite(req, resp);
  }

  /**
   * This method is used to send a chat invitation to the user for opening a session 
   * with the app.
   * 
   * @param req : http request that contains the chat Id of the user
   * @param resp : http response for the request
   * @throws IOException
   */
  // Send Chat Invite to the particular email Id.
  private void sendInvite(HttpServletRequest req, HttpServletResponse resp)
      throws IOException {
    
  }
}
