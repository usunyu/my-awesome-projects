function createXHR() {
	var xmlhttp;
	if (window.XMLHttpRequest) {
		xmlhttp = new XMLHttpRequest();
	} else {
		xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
	}
	return xmlhttp;
}

function deleteProductEntry() {
	var delXhrObj = createXHR();
	delXhrObj.onreadystatechange = function() {
		if (delXhrObj.readyState == 4 && delXhrObj.status == 200) {
			displayListView();
		}
	}
	delXhrObj.open("POST", "/product", true);
	delXhrObj.setRequestHeader("Content-type",
			"application/x-www-form-urlencoded");
	delXhrObj.send("category=" + this.id + "&action=DELETE");
	displayListViewByType('products');
}

function deleteItemEntry() {
	var delXhrObj = createXHR();
	delXhrObj.onreadystatechange = function() {
		if (delXhrObj.readyState == 4 && delXhrObj.status == 200) {
			displayListViewByType('items');
		}
	}
	delXhrObj.open("POST", "/item", true);
	delXhrObj.setRequestHeader("Content-type",
			"application/x-www-form-urlencoded");
	delXhrObj.send("name=" + this.id + "&action=DELETE");
}

function deleteOrderEntry() {
	var delXhrObj = createXHR();
	delXhrObj.onreadystatechange = function() {
		if (delXhrObj.readyState == 4 && delXhrObj.status == 200) {
			displayListViewByType('orderLists');
		}
	}
	delXhrObj.open("POST", "/order", true);
	delXhrObj.setRequestHeader("Content-type",
			"application/x-www-form-urlencoded");
	delXhrObj.send("orderid=" + this.id + "&action=DELETE");
}

function displayCreateProductTab(create) {
	cP();
	var createProductContentDiv = document
			.getElementById('createContentProducts');
	var createItemContentDiv = document.getElementById('createContentItems');
	var createContactContentDiv = document
			.getElementById('createContentContacts');
	var createUserContentDiv = document.getElementById('createContentUsers');
	createProductContentDiv.style.display = 'block';
	createItemContentDiv.style.display = "none";
	createContactContentDiv.style.display = 'none';
	createUserContentDiv.style.display = 'none';

	var listViewDiv = document.getElementById('listView');
	var createViewDiv = document.getElementById('createView');
	var placeOrderViewDiv = document.getElementById('placeOrderView');

	listViewDiv.style.display = 'none';
	createViewDiv.style.display = 'block';
	placeOrderViewDiv.style.display = 'none';
	if (typeof create === 'object') {
		populateCreateProValues(this);
	} else {
		populateCreateProValues();
	}
}

function displayCreateContactTab(create) {
	cC();
	var createProductContentDiv = document
			.getElementById('createContentProducts');
	var createItemContentDiv = document.getElementById('createContentItems');
	var createContactContentDiv = document
			.getElementById('createContentContacts');
	var createUserContentDiv = document.getElementById('createContentUsers');
	createProductContentDiv.style.display = 'none';
	createItemContentDiv.style.display = 'none';
	createContactContentDiv.style.display = 'block';
	createUserContentDiv.style.display = 'none';

	var listViewDiv = document.getElementById('listView');
	var createViewDiv = document.getElementById('createView');
	var placeOrderViewDiv = document.getElementById('placeOrderView');
	placeOrderViewDiv.style.display = 'none';
	listViewDiv.style.display = 'none';
	createViewDiv.style.display = 'block';

	if (typeof create === true) {
	} else {
		editContact(this.innerHTML);
	}
}

function displayCreateUserTab(create) {
	cU();
	var createProductContentDiv = document
			.getElementById('createContentProducts');
	var createItemContentDiv = document.getElementById('createContentItems');
	var createContactContentDiv = document
			.getElementById('createContentContacts');
	var createUserContentDiv = document.getElementById('createContentUsers');
	createProductContentDiv.style.display = 'none';
	createItemContentDiv.style.display = 'none';
	createContactContentDiv.style.display = 'none';
	createUserContentDiv.style.display = 'block';
	var placeOrderViewDiv = document.getElementById('placeOrderView');
	placeOrderViewDiv.style.display = 'none';

	var listViewDiv = document.getElementById('listView');
	var createViewDiv = document.getElementById('createView');

	listViewDiv.style.display = 'none';
	createViewDiv.style.display = 'block';
	if (typeof create === 'object') {
		populateCreateProValues(this);
	} else {
		populateCreateProValues();
	}
}

function displayCreateItemTab(create) {
	cI();
	var self = this;
	var createProductContentDiv = document
			.getElementById('createContentProducts');
	var createItemContentDiv = document.getElementById('createContentItems');
	var createContactContentDiv = document
			.getElementById('createContentContacts');
	var createUserContentDiv = document.getElementById('createContentUsers');
	createProductContentDiv.style.display = 'none';
	createItemContentDiv.style.display = 'block';
	createContactContentDiv.style.display = 'none';
	createUserContentDiv.style.display = 'none';

	var listViewDiv = document.getElementById('listView');
	var createViewDiv = document.getElementById('createView');
	var placeOrderViewDiv = document.getElementById('placeOrderView');
	placeOrderViewDiv.style.display = 'none';
	listViewDiv.style.display = 'none';
	createViewDiv.style.display = 'block';

	var ajaxobj = createXHR();
	ajaxobj.open("GET", "/product", true);
	ajaxobj.send();
	ajaxobj.onreadystatechange = function() {
		if (ajaxobj.readyState == 4 && ajaxobj.status == 200) {
			var response = eval('(' + ajaxobj.responseText + ')');
			var selectBox = document.getElementById('productList');
			selectBox.innerHTML = '';
			for (entry in response) {
				var optData = response[entry];
				var option = new Option(optData.name, "name");
				selectBox.options.add(option);
			}
		}
	}
	var ajaxobj2 = createXHR();
	ajaxobj2.open("GET", "/contact", true);
	ajaxobj2.send();
	ajaxobj2.onreadystatechange = function() {
		if (ajaxobj2.readyState == 4 && ajaxobj2.status == 200) {
			var response = eval('(' + ajaxobj2.responseText + ')');
			var selectBox = document.getElementById('contactList');
			selectBox.innerHTML = '';
			for (entry in response) {
				var optData = response[entry];
				var option = new Option(optData.name, "contact");
				selectBox.options.add(option);
			}
			if (typeof create === true) {
			} else {
				editItem(self.innerHTML);
			}
		}
	}
}

function populateCreateProValues(oThis) {
	document.getElementById('name').value = oThis ? oThis.innerHTML : '';
	document.getElementById('price').value = oThis ? oThis.parentNode.nextSibling.nextSibling.innerHTML
			: '';
}

function populateCreateContactValues(oThis) {
	document.getElementById('contactName').value = oThis ? oThis.innerHTML : '';
	if (oThis) {
		var selectList = document.getElementById('contactList').options;
		for ( var i = 0; i < selectList.length; i++) {
			if (selectList[i].text === oThis.parentNode.nextSibling.innerHTML) {
				selectList[i].selected = true;
			}
		}
	}
}

function populateCreateItemValues(oThis) {
	document.getElementById('name').value = oThis ? oThis.innerHTML : '';
	if (oThis) {
		var selectList = document.getElementById('productList').options;
		for ( var i = 0; i < selectList.length; i++) {
			if (selectList[i].text === oThis.parentNode.nextSibling.innerHTML) {
				selectList[i].selected = true;
			}
		}
	}
}

function populateCreateProdItemValues(oThis) {
	document.getElementById('category').value = oThis ? oThis.innerHTML : '';
	// category needs to change to based on database value.
	if (oThis) {
		var selectList = document.getElementById('ddlItem').options;
		for ( var i = 0; i < selectList.length; i++) {
			if (selectList[i].text === oThis.parentNode.nextSibling.innerHTML) {
				selectList[i].selected = true;
			}
		}
	}
}

function displayListView() {
	document.getElementById('typeList').value = "products";
	var welcomeViewDiv = document.getElementById('welcomeView');
	var listViewDiv = document.getElementById('listView');
	var createViewDiv = document.getElementById('createView');
	var placeOrderViewDiv = document.getElementById('placeOrderView');

	placeOrderViewDiv.style.display = 'none';
	welcomeViewDiv.style.display = 'none';
	listViewDiv.style.display = 'block';
	createViewDiv.style.display = 'none';

	var xhrObj = createXHR();
	xhrObj.open("GET", "/product", true);
	xhrObj.send();
	xhrObj.onreadystatechange = function() {
		if (xhrObj.readyState == 4 && xhrObj.status == 200) {
			var data = '';
			if (xhrObj.responseText != '\r\n') {
				data = eval('(' + xhrObj.responseText + ')');
			}
			var currTab = document.getElementById('listViewProductTBody');
			currTab.innerHTML = '';
			for ( var prop in data) {
				var currTrData = data[prop];

				var oTr = document.createElement('tr');
				var nameTd = document.createElement('td');
				nameTd.innerHTML = currTrData.name;
				oTr.appendChild(nameTd);
				var descTd = document.createElement('td');
				descTd.innerHTML = currTrData.Description;
				oTr.appendChild(descTd);				

				currTab.appendChild(oTr);
			}
		}
	}
	displayListViewByType('products');
}

function displayCreateView() {
	document.getElementById('divSearch').style.display = 'none';
	var welcomeViewDiv = document.getElementById('welcomeView');
	var listViewDiv = document.getElementById('listView');
	var createViewDiv = document.getElementById('createView');
	var placeOrderViewDiv = document.getElementById('placeOrderView');

	placeOrderViewDiv.style.display = 'none';
	welcomeViewDiv.style.display = 'none'
	listViewDiv.style.display = 'none';
	createViewDiv.style.display = 'block';
	displayCreateProductTab(true);

	document.getElementById('category').value = "";
	document.getElementById('name').value = "";
	document.getElementById('price').value = "";
	document.getElementById('contactName').value = "";
	document.getElementById('address').value = "";
	document.getElementById('city').value = "";
	document.getElementById('state').value = "";
	document.getElementById('country').value = "";
	document.getElementById('zip').value = "";
	document.getElementById('phone').value = "";
	document.getElementById('contactEmail').value = "";
	document.getElementById('userName').value = "";
	document.getElementById('userId').value = "";
	document.getElementById('password').value = "";
	document.getElementById('userEmailId').value = "";
	document.getElementById('orderUserId').value = "";

	displayCreateUserTab(true);
}

function displayPlaceOrderView() {
	document.getElementById('divSearch').style.display = 'none';
	var welcomeViewDiv = document.getElementById('welcomeView');
	var listViewDiv = document.getElementById('listView');
	var createViewDiv = document.getElementById('createView');
	var placeOrderViewDiv = document.getElementById('placeOrderView');

	placeOrderViewDiv.style.display = 'block';
	welcomeViewDiv.style.display = 'none'
	listViewDiv.style.display = 'none';
	createViewDiv.style.display = 'none';
	
	var ajaxobj2 = createXHR();
	ajaxobj2.open("GET", "/customer", true);
	ajaxobj2.send();
	ajaxobj2.onreadystatechange = function() {
		if (ajaxobj2.readyState == 4 && ajaxobj2.status == 200) {
			var response = eval('(' + ajaxobj2.responseText + ')');
			var selectBox = document.getElementById('ddluserId');
			selectBox.innerHTML = '';
			for (entry in response) {
				var optData = response[entry];
				var option = new Option(optData.CustomerName, "orderUserId");
				selectBox.options.add(option);
			}
		}
	}
	
	var ajaxobj = createXHR();
	ajaxobj.open("GET", "/item", true);
	ajaxobj.send();
	ajaxobj.onreadystatechange = function() {
		if (ajaxobj.readyState == 4 && ajaxobj.status == 200) {
			var response = eval('(' + ajaxobj.responseText + ')');
			var selectBox = document.getElementById('ddlItem');
			selectBox.innerHTML = '';
			for (entry in response) {
				var optData = response[entry];
				var option = new Option(optData.name, "item");
				selectBox.options.add(option);
			}
			if (typeof create === 'object') {
				populateCreateProdItemValues(self);
			} else {
				populateCreateProdItemValues();
			}
		}
	}
}

function saveProduct() {
	var xmlhttp = createXHR();
	xmlhttp.onreadystatechange = function() {
		if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
			displayListView();
		}
	}
	xmlhttp.open("POST", "/product", true);
	xmlhttp.setRequestHeader("Content-type",
			"application/x-www-form-urlencoded");
	xmlhttp.send("category=" + document.getElementById('category').value
			+ "&description="+ document.getElementById('description').value+ "&action=PUT");
	
	document.getElementById('description').value = "";
}

function saveItem() {
	var xmlhttp = createXHR();
	xmlhttp.onreadystatechange = function() {
		if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
			var listViewDiv = document.getElementById('listView');
			var createViewDiv = document.getElementById('createView');
			listViewDiv.style.display = 'block';
			createViewDiv.style.display = 'none';
			displayListViewByType('items');
		}
	}
	var selectedProduct = '', opts = document.getElementById('productList').options;
	for ( var i = 0; i < opts.length; i++) {
		if (opts[i].selected) {
			selectedProduct = opts[i].text;
		}
	}

	var selectedContact = '', opt = document.getElementById('contactList').options;
	for ( var i = 0; i < opt.length; i++) {
		if (opt[i].selected) {
			selectedContact = opt[i].text;
		}
	}
	xmlhttp.open("POST", "/item", true);
	xmlhttp.setRequestHeader("Content-type",
			"application/x-www-form-urlencoded");
	xmlhttp.send("name=" + document.getElementById('name').value + "&price="
			+ document.getElementById('price').value + "&product="
			+ selectedProduct + "&contact=" + selectedContact + "&action=PUT");
}

function saveContact() {
	var xmlhttp = createXHR();
	xmlhttp.onreadystatechange = function() {
		if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
			displayListView();
		}
	}
	xmlhttp.open("POST", "/contact", true);
	xmlhttp.setRequestHeader("Content-type",
			"application/x-www-form-urlencoded");
	var obj = "name=" + document.getElementById('contactName').value;
	obj = obj + "&address=" + document.getElementById('address').value;
	obj = obj + "&city=" + document.getElementById('city').value;
	obj = obj + "&state=" + document.getElementById('state').value;
	obj = obj + "&country=" + document.getElementById('country').value;
	obj = obj + "&zip=" + document.getElementById('zip').value;
	obj = obj + "&phone=" + document.getElementById('phone').value;
	obj = obj + "&email=" + document.getElementById('contactEmail').value;
	xmlhttp.send(obj + "&action=PUT");
}

function saveUser() {
	var xmlhttp = createXHR();
	xmlhttp.onreadystatechange = function() {
		if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
			displayListView();
		}
	}
	xmlhttp.open("POST", "/customer", true);
	xmlhttp.setRequestHeader("Content-type",
			"application/x-www-form-urlencoded");
	var obj = "name=" + document.getElementById('userName').value;
	obj = obj + "&userid=" + document.getElementById('userId').value;
	obj = obj + "&email=" + document.getElementById('userEmailId').value;
	xmlhttp.send(obj + "&action=PUT");
}

function saveOrder() {
	var xmlhttp = createXHR();
	xmlhttp.onreadystatechange = function() {
		if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
			displayListView();
			displayListViewByType('orderLists');
		}
	}
	xmlhttp.open("POST", "/order", true);
	xmlhttp.setRequestHeader("Content-type",
			"application/x-www-form-urlencoded");
	var e = document.getElementById("ddlItem");
	var itemName = e.options[e.selectedIndex].text;
	var user = document.getElementById("ddluserId");
	var userId = user.options[e.selectedIndex].text;
	var obj = "name=" + itemName;
	obj = obj + "&userid=" + userId +
			"&quantity=" + document.getElementById('quantity').value + 
			"&price=" + document.getElementById('oprice').value + 
			"&shipto="+ document.getElementById('shipto').value;
	xmlhttp.send(obj + "&action=PUT");
	
	
	document.getElementById('quantity').value = "";
	document.getElementById('oprice').value = "";
	document.getElementById('shipto').value = "";
}

function displayListViewByType(typeStr) {
	if (typeStr == 'products') {
		document.getElementById('products').style.display = "block";
		document.getElementById('divSearch').style.display = 'none';
		document.getElementById('items').style.display = "none";
		document.getElementById('orderLists').style.display = "none";
	} else if (typeStr == 'orderLists') {
		document.getElementById('orderLists').style.display = "block";
		document.getElementById('divSearch').style.display = 'none';
		document.getElementById('products').style.display = "none";
		document.getElementById('items').style.display = "none";

		var xhrObj = createXHR();
		xhrObj.open("GET", "/order", true);
		xhrObj.send();
		xhrObj.onreadystatechange = function() {
			if (xhrObj.readyState == 4 && xhrObj.status == 200) {
				var data = '';
				if (xhrObj.responseText != '\r\n') {
					data = eval('(' + xhrObj.responseText + ')');
				}
				var currTab = document.getElementById('listViewOrderTBody');
				currTab.innerHTML = '';
				for (prop in data) {
					var currTrData = data[prop];

					var delLink = document.createElement('div');
					delLink.id = currTrData.name;
					delLink.style.outline = 'none';
					delLink.style.color = 'blue';
					delLink.style.cursor = 'pointer';
					delLink.style.display = 'inline';
					delLink.innerHTML = 'Delete';
					delLink.onclick = deleteOrderEntry;

					var oTr = document.createElement('tr');
					var nameTd = document.createElement('td');
					nameTd.innerHTML = currTrData.name;
					oTr.appendChild(nameTd);
					var itemTd = document.createElement('td');
					itemTd.innerHTML = currTrData.ItemName;
					oTr.appendChild(itemTd);
					var userTd = document.createElement('td');
					userTd.innerHTML = currTrData.UserId;
					oTr.appendChild(userTd);
					var shiptoTd = document.createElement('td');
					shiptoTd.innerHTML = currTrData.ShipTo;
					oTr.appendChild(shiptoTd);
					var quantityTd = document.createElement('td');
					quantityTd.innerHTML = currTrData.Quantity;
					oTr.appendChild(quantityTd);
					var priceTd = document.createElement('td');
					priceTd.innerHTML = currTrData.Price;
					oTr.appendChild(priceTd);
					var deleteTd = document.createElement('td');
					deleteTd.appendChild(delLink);
					oTr.appendChild(deleteTd);

					currTab.appendChild(oTr);
				}
			}
		}
	} else {
		document.getElementById('searchfor').value = "";
		document.getElementById('items').style.display = "block";
		document.getElementById('divSearch').style.display = 'block';
		document.getElementById('products').style.display = "none";
		document.getElementById('orderLists').style.display = "none";
		document.getElementById('typeList').options[1].selected = true;
		var xhrObj2 = createXHR();
		xhrObj2.open("GET", "/item", true);
		xhrObj2.send();
		xhrObj2.onreadystatechange = function() {
			if (xhrObj2.readyState == 4 || xhrObj2.status == 200) {
				var data = '';
				if (xhrObj2.responseText != '\r\n') {
					data = eval('(' + xhrObj2.responseText + ')');
				}
				var currTab = document.getElementById('listViewItemTBody');
				currTab.innerHTML = '';
				for (prop in data) {
					var currTrData = data[prop];

					var oTr = document.createElement('tr');
					var nameTd = document.createElement('td');
					var nameDiv = document.createElement('div');
					nameDiv.innerHTML = currTrData.name;
					nameDiv.style.display = 'inline';
					nameDiv.style.color = 'blue';
					nameDiv.style.cursor = 'pointer';
					nameDiv.onclick = displayCreateItemTab;
					nameTd.appendChild(nameDiv);
					oTr.appendChild(nameTd);
					var priceTd = document.createElement('td');
					priceTd.innerHTML = currTrData.Price;
					oTr.appendChild(priceTd);
					var productTd = document.createElement('td');
					productTd.innerHTML = currTrData.Product;
					oTr.appendChild(productTd);
					var contactTd = document.createElement('td');
					var contactDiv = document.createElement('div');
					contactDiv.innerHTML = currTrData.Contact;
					contactDiv.style.display = 'inline';
					contactDiv.style.color = 'blue';
					contactDiv.style.cursor = 'pointer';
					contactDiv.onclick = displayCreateContactTab;
					contactTd.appendChild(contactDiv);
					oTr.appendChild(contactTd);

					currTab.appendChild(oTr);
				}
			}
		}
	}
}

function cP() {
	document.getElementById('createProductTab').style.backgroundColor = "#ffffff";
	document.getElementById('createProductTab').style.borderTop = "1px";
	document.getElementById('createProductTab').style.borderLeft = "1px";
	document.getElementById('createProductTab').style.borderRight = "1px";
	document.getElementById('createProductTab').style.borderBottom = "0px";
	document.getElementById('createProductTab').style.borderStyle = "solid";
	document.getElementById('createProductTab').style.borderColor = "#e9e9e9";
	document.getElementById('createProductTab').style.fontWeight = "bold";
	document.getElementById('createProductTab').style.paddingBottom = "9px";
	document.getElementById('createItemTab').style.backgroundColor = "#e9e9e9";
	document.getElementById('createItemTab').style.fontWeight = "normal";

	document.getElementById('createContactTab').style.backgroundColor = "#e9e9e9";
	document.getElementById('createContactTab').style.fontWeight = "normal";

	document.getElementById('createUserTab').style.backgroundColor = "#e9e9e9";
	document.getElementById('createUserTab').style.fontWeight = "normal";
}

function cI() {
	document.getElementById('createProductTab').style.backgroundColor = "#e9e9e9";
	document.getElementById('createProductTab').style.fontWeight = "normal";

	document.getElementById('createContactTab').style.backgroundColor = "#e9e9e9";
	document.getElementById('createContactTab').style.fontWeight = "normal";

	document.getElementById('createUserTab').style.backgroundColor = "#e9e9e9";
	document.getElementById('createUserTab').style.fontWeight = "normal";

	document.getElementById('createItemTab').style.backgroundColor = "#ffffff";
	document.getElementById('createItemTab').style.borderTop = "1px";
	document.getElementById('createItemTab').style.borderLeft = "1px";
	document.getElementById('createItemTab').style.borderRight = "1px";
	document.getElementById('createItemTab').style.borderBottom = "0px";
	document.getElementById('createItemTab').style.borderStyle = "solid";
	document.getElementById('createItemTab').style.borderColor = "#e9e9e9";
	document.getElementById('createItemTab').style.fontWeight = "bold";
	document.getElementById('createItemTab').style.paddingBottom = "9px";
}

function cC() {
	document.getElementById('createProductTab').style.backgroundColor = "#e9e9e9";
	document.getElementById('createProductTab').style.fontWeight = "normal";

	document.getElementById('createItemTab').style.backgroundColor = "#e9e9e9";
	document.getElementById('createItemTab').style.fontWeight = "normal";

	document.getElementById('createUserTab').style.backgroundColor = "#e9e9e9";
	document.getElementById('createUserTab').style.fontWeight = "normal";

	document.getElementById('createContactTab').style.backgroundColor = "#ffffff";
	document.getElementById('createContactTab').style.borderTop = "1px";
	document.getElementById('createContactTab').style.borderLeft = "1px";
	document.getElementById('createContactTab').style.borderRight = "1px";
	document.getElementById('createContactTab').style.borderBottom = "0px";
	document.getElementById('createContactTab').style.borderStyle = "solid";
	document.getElementById('createContactTab').style.borderColor = "#e9e9e9";
	document.getElementById('createContactTab').style.fontWeight = "bold";
	document.getElementById('createContactTab').style.paddingBottom = "9px";
}

function cU() {
	document.getElementById('createProductTab').style.backgroundColor = "#e9e9e9";
	document.getElementById('createProductTab').style.fontWeight = "normal";

	document.getElementById('createItemTab').style.backgroundColor = "#e9e9e9";
	document.getElementById('createItemTab').style.fontWeight = "normal";

	document.getElementById('createContactTab').style.backgroundColor = "#e9e9e9";
	document.getElementById('createContactTab').style.fontWeight = "normal";

	document.getElementById('createUserTab').style.backgroundColor = "#ffffff";
	document.getElementById('createUserTab').style.borderTop = "1px";
	document.getElementById('createUserTab').style.borderLeft = "1px";
	document.getElementById('createUserTab').style.borderRight = "1px";
	document.getElementById('createUserTab').style.borderBottom = "0px";
	document.getElementById('createUserTab').style.borderStyle = "solid";
	document.getElementById('createUserTab').style.borderColor = "#e9e9e9";
	document.getElementById('createUserTab').style.fontWeight = "bold";
	document.getElementById('createUserTab').style.paddingBottom = "9px";

}

function search() {
	document.getElementById('items').style.display = "block";
	document.getElementById('divSearch').style.display = 'block';
	document.getElementById('products').style.display = "none";
	document.getElementById('orderLists').style.display = "none";

	var searchFor = document.getElementById('searchfor').value;
	var searchBy = document.getElementById('searchList').value;
	var xhrObj = createXHR();
	xhrObj.open("GET", "/item?" + "searchby=" + searchBy + "&searchfor="
			+ searchFor, true);
	xhrObj.send();
	xhrObj.onreadystatechange = function() {
		if (xhrObj.readyState == 4 || xhrObj.status == 200) {
			var data = '';
			if (xhrObj.responseText != '\r\n') {
				data = eval('(' + xhrObj.responseText + ')');
			}
			var currTab = document.getElementById('listViewItemTBody');
			currTab.innerHTML = '';
			for (prop in data) {
				var currTrData = data[prop];

				var delLink = document.createElement('div');
				delLink.id = currTrData.name;
				delLink.style.outline = 'none';
				delLink.style.color = 'blue';
				delLink.style.cursor = 'pointer';
				delLink.style.display = 'inline';
				delLink.innerHTML = 'Delete';
				delLink.onclick = deleteItemEntry;

				var oTr = document.createElement('tr');
				var nameTd = document.createElement('td');
				var nameDiv = document.createElement('div');
				nameDiv.innerHTML = currTrData.name;
				nameDiv.style.display = 'inline';
				nameDiv.style.color = 'blue';
				nameDiv.style.cursor = 'pointer';
				nameDiv.onClick = displayCreateItemTab;
				nameTd.appendChild(nameDiv);
				oTr.appendChild(nameTd);
				var priceTd = document.createElement('td');
				priceTd.innerHTML = currTrData.Price;
				oTr.appendChild(priceTd);
				var productTd = document.createElement('td');
				productTd.innerHTML = currTrData.Product;
				oTr.appendChild(productTd);
				var contactTd = document.createElement('td');
				var contactDiv = document.createElement('div');
				contactDiv.innerHTML = currTrData.Contact;
				contactDiv.style.display = 'inline';
				contactDiv.style.color = 'blue';
				contactDiv.style.cursor = 'pointer';
				contactDiv.onclick = displayCreateContactTab;
				contactTd.appendChild(contactDiv);
				oTr.appendChild(contactTd);
				var deleteTd = document.createElement('td');
				deleteTd.appendChild(delLink);
				oTr.appendChild(deleteTd);

				currTab.appendChild(oTr);
			}
		}
	}
}

function editContact(contactName) {
	var xhrObj = createXHR();
	if (contactName != null) {
		xhrObj.open("GET", "/contact?" + "name=" + contactName, true);
		xhrObj.send();
		xhrObj.onreadystatechange = function() {
			if (xhrObj.readyState == 4 && xhrObj.status == 200) {
				var response = eval('(' + xhrObj.responseText + ')');
				document.getElementById('contactName').value = response[0].name;
				document.getElementById('address').value = response[0].Address;
				document.getElementById('city').value = response[0].City;
				document.getElementById('state').value = response[0].State;
				document.getElementById('country').value = response[0].Country;
				document.getElementById('zip').value = response[0].Zip;
				document.getElementById('phone').value = response[0].Phone;
				document.getElementById('contactEmail').value = response[0].Email;
			}
		}
	}
}

function editItem(itemName) {
	var xhrObj = createXHR();
	if (itemName != null) {
		xhrObj.open("GET", "/item?" + "searchby=Name" + "&searchfor="
				+ itemName, true);
		xhrObj.send();
		xhrObj.onreadystatechange = function() {
			if (xhrObj.readyState == 4 && xhrObj.status == 200) {
				var response = eval('(' + xhrObj.responseText + ')');
				document.getElementById('name').value = response[0].name;
				document.getElementById('price').value = response[0].Price;
				document.getElementById('productList').value = response[0].Product;
				document.getElementById('contactList').value = response[0].Contact;

				var opts = document.getElementById('productList').options;
				for ( var i = 0; i < opts.length; i++) {
					if (opts[i].text == response[0].Product) {
						opts[i].selected = true;
					}
				}

				var opt = document.getElementById('contactList').options;
				for ( var i = 0; i < opt.length; i++) {
					if (opt[i].text == response[0].Contact) {
						opt[i].selected = true;
					}
				}
			}
		}
	}
}