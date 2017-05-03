var mybutton = document.getElementById("loadbutton");
mybutton.onclick = function() {
	var request;
	if(window.XMLHttpRequest) {
		request = new XMLHttpRequest();
	} else {
		request = new ActiveXObject("Microsoft.XMLHTTP");
	}
	request.open('GET', 'data.json');
	request.onreadystatechange = function () {
		if ((request.readyState===4) && (request.status===200)) {
			// txt
			// console.log(request);
			// document.writeln(request.responseText);
			
			// var modify = document.getElementsByTagName('ul')[1].getElementsByTagName('li');
			// modify[2].innerHTML = request.responseText;
			// for (var i = 0; i < modify.length; i++) {
			// 	modify[i].innerHTML = request.responseText;
			// };

			// xml
			// console.log(request.responseXML.getElementsByTagName('name')[1].childNodes[0].nodeValue);
			// var items = request.responseXML.getElementsByTagName('name');
			// var output = '<ul>';
			// for (var i = 0; i < items.length; i++) {
			// 	output += '<li>' + items[i].firstChild.nodeValue + '</li>';
			// };
			// output += '</ul>';

			// document.getElementById('update').innerHTML = output;

			// json
			var items = JSON.parse(request.responseText);
			// console.log(items);
			var output = '<ul>';
			// for (var i = 0; i < items.length; i++) {
			// 	output += '<li>' + items[i].name + '</li>';
			// };
			for (var key in items) {
				output += '<li>' + items[key].name + '</li>';
			};
			output += '</ul>'
			document.getElementById('update').innerHTML = output;
		}
	}
	request.send();
}


