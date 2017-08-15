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

import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.google.appengine.api.channel.ChannelFailureException;
import com.google.appengine.api.channel.ChannelService;
import com.google.appengine.api.channel.ChannelServiceFactory;

/**
 * This servlet creates the channel with the server and gets the token.
 * 
 * @author
 */
@SuppressWarnings("serial")
public class TokenServlet extends HttpServlet {

	private static final Logger logger = Logger.getLogger(TokenServlet.class
			.getCanonicalName());

	private static ChannelService channelService = null;

	/**
	 * Get the token for connecting & listening on the channel
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response)
	throws ServletException, IOException {
		String userId = request.getParameter("userid");
		if (userId != null && !"".equals(userId)) {
			String token = createChannel(userId);
			writeIntoChannel(response,token);
		}
	}

	/**
	 * Creates the Channel token for the user 
	 * @param userId The User whom the token is created for  
	 * @return The token string is returned
	 */
	public String createChannel(String userId){
		try{
			logger.log(Level.INFO, "Creating a channel for {0}",userId);
			return null;
		}catch(ChannelFailureException channelFailureException){
			logger.log(Level.WARNING, "Error creating the channel");
			return null;
		}catch(Exception otherException){
			logger.log(Level.WARNING, "Unknown exception while creating channel");
			return null;
		}
	}

	/**
	 * Writes the token in the response text 
	 * 
	 * @param response The response object to write the response text 
	 * @param token The token which needs to be written in the response
	 * @throws IOException
	 */
	public void writeIntoChannel(HttpServletResponse response, String token){

	}
}
