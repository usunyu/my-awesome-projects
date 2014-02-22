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

import javax.servlet.ServletException;

/**
 * This servlet pre populates some data into customers and products
 * 
 * @author
 */
@SuppressWarnings("serial")
public class PrePopulateDataServlet extends BaseServlet {

  @Override
  public void init() throws ServletException {
    populateProduct();
    populateCustomer();
  }

  private void populateProduct() {
    
  }
  
  private void populateCustomer() {
    
  }
}
