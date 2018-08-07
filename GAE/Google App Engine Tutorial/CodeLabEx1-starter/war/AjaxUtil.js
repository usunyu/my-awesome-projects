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

function displayCreateProductTab(create) {
	cP();
	var createProductContentDiv = document
			.getElementById('createContentProducts');
	var createItemContentDiv = document.getElementById('createContentItems');
	createProductContentDiv.style.display = 'block';
	createItemContentDiv.style.display = "none";
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

function populateCreateProValues(oThis) {
	document.getElementById('category').value = oThis ? oThis.innerHTML : '';
	document.getElementById('description').value = oThis ? oThis.parentNode.nextSibling.innerHTML
			: '';
}

function displayCreateItemTab(create) {
	cI();
	var self = this;
	var createProductContentDiv = document
			.getElementById('createContentProducts');
	var createItemContentDiv = document.getElementById('createContentItems');
	createProductContentDiv.style.display = 'none';
	createItemContentDiv.style.display = "block";

	var listViewDiv = document.getElementById('listView');
	var createViewDiv = document.getElementById('createView');

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
			if (typeof create === 'object') {
				populateCreateItemValues(self);
			} else {
				populateCreateItemValues();
			}
		}
	}
}

function populateCreateItemValues(oThis) {
	document.getElementById('name').value = oThis ? oThis.innerHTML : '';
	document.getElementById('price').value = oThis ? oThis.parentNode.nextSibling.innerHTML : '';
	if (oThis) {
		var selectList = document.getElementById('productList').options;
		for ( var i = 0; i < selectList.length; i++) {
			if (selectList[i].text === oThis.parentNode.nextSibling.innerHTML) {
				selectList[i].selected = true;
			}
		}
	}
}

function displayListView() {
	var welcomeViewDiv = document.getElementById('welcomeView');
	var listViewDiv = document.getElementById('listView');
	var createViewDiv = document.getElementById('createView');

	welcomeViewDiv.style.display = 'none';
	listViewDiv.style.display = 'block';
	createViewDiv.style.display = 'none';
	var xhrObj = createXHR();
	xhrObj.open("GET", "/product", true);
	xhrObj.send();
	xhrObj.onreadystatechange = function() {
		if (xhrObj.readyState == 4 && xhrObj.status == 200) {
			var data = '';
			if (xhrObj.responseText.trim() && xhrObj.responseText != '\r\n') {
				data = eval('(' + xhrObj.responseText + ')');
			}
			var currTab = document.getElementById('listViewProductTBody');
			currTab.innerHTML = '';
			currTab.innerHTML = '';
			for ( var prop in data) {
				var currTrData = data[prop];

				var delLink = document.createElement('div');
				delLink.id = currTrData.name;
				delLink.style.outline = 'none';
				delLink.style.color = 'blue';
				delLink.style.cursor = 'pointer';
				delLink.style.display = 'inline';
				delLink.innerHTML = 'Delete';
				delLink.onclick = deleteProductEntry;

				var oTr = document.createElement('tr');
				var nameTd = document.createElement('td');
				nameTd.innerHTML = currTrData.name;
				oTr.appendChild(nameTd);
				var descTd = document.createElement('td');
				descTd.innerHTML = currTrData.Description;
				oTr.appendChild(descTd);
				var deleteTd = document.createElement('td');
				deleteTd.appendChild(delLink);
				oTr.appendChild(deleteTd);

				currTab.appendChild(oTr);
			}
		}
	}
}

function displayCreateView() {
	var welcomeViewDiv = document.getElementById('welcomeView');
	var listViewDiv = document.getElementById('listView');
	var createViewDiv = document.getElementById('createView');

	welcomeViewDiv.style.display = 'none'
	listViewDiv.style.display = 'none';
	createViewDiv.style.display = 'block';
	displayCreateProductTab(true);
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
			+ "&description=" + document.getElementById('description').value + "&action=PUT");
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

	xmlhttp.open("POST", "/item", true);
	xmlhttp.setRequestHeader("Content-type",
			"application/x-www-form-urlencoded");
	xmlhttp.send("name=" + document.getElementById('name').value + "&price="
			+ document.getElementById('price').value + "&product="
			+ selectedProduct + "&action=PUT");
	
	document.getElementById('name').value = "";
	document.getElementById('price').value = "";
	
	
}

function displayListViewByType(typeStr) {
	if (typeStr == 'products') {
		document.getElementById('products').style.display = "block";
		document.getElementById('items').style.display = "none";
	} else {
		document.getElementById('products').style.display = "none";
		document.getElementById('items').style.display = "block";
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
					nameDiv.onclick = displayCreateItemTab;
					nameTd.appendChild(nameDiv);
					oTr.appendChild(nameTd);
					var priceTd = document.createElement('td');
					priceTd.innerHTML = currTrData.Price;
					oTr.appendChild(priceTd);
					var productTd = document.createElement('td');
					productTd.innerHTML = currTrData.Product;
					oTr.appendChild(productTd);
					var deleteTd = document.createElement('td');
					deleteTd.appendChild(delLink);
					oTr.appendChild(deleteTd);

					currTab.appendChild(oTr);
				}
			}
		}
	}
}

function cP() {
	document.getElementById('createProductTab').className = "normalTab activeTab";
	document.getElementById('createItemTab').className = "normalTab";
}

function cI() {
	document.getElementById('createProductTab').className = "normalTab";
	document.getElementById('createItemTab').className = "normalTab activeTab";
}
