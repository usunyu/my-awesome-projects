var HOME='home';
var ENTITY_ORDER='order';
var ENTITY_UPLOAD='upload';
var STATUS_PROCESSING='processing';
var STATUS_PROCESSED='processed';
var STATUS_PENDING='pending';

//function to initialize the page
var init = function() {
	//showing the home tab on initializing
	showTab(HOME);
	//adding event listeners to the tabs
	$('#tabs a').click(function(event) {
		showTab(event.currentTarget.id);
	});
}

//function to show the tab
var showTab = function(entity) {
	//remove the active class from all the tabs
	$('.tab').removeClass("active");
	//setting the active class to the selected tab
	$('#'+entity).addClass("active");
	//hiding all the tabs
	$('.g-unit').hide();
	//showing the selected tab
	$('#' + entity + '-tab').show();
	//hiding the message block
	$('.message').hide();
	//hiding the create block
	showHideCreate(entity, false);
	if(entity!=HOME)
		$('#'+entity+'-search-reset').click();
}

//function to show/hide create block for an entity in a tab 
var showHideCreate = function(entity, show) {
	//checking if the block is show or not
	if (show) {
		//hiding the search container
		$('#' + entity + '-search-ctr').hide();
		//hiding the list container
		$('#' + entity + '-list-ctr').hide();
		//showing the create container
		$('#' + entity + '-create-ctr').show();
		
	} else {
		$('#order-search-reset').click();
		//showing the search container
		$('#' + entity + '-search-ctr').show();
		//showing the list container
		$('#' + entity + '-list-ctr').show();
		//hiding the create container
		$('#' + entity + '-create-ctr').hide();
		//checking if the entity is not a home then populating the list of the entity
		if(entity==ENTITY_ORDER)
			populateList(entity,null);
	}
}

//parameter object definition
var param=function(name,value){
	this.name=name;
	this.value=value;
}

//function to search an entity when user inputs the value in the search box
var search = function(entity) {
	$('.message').hide();
	// collecting the field values from the form
	 var formEleList = $('form#'+entity+'-search-form').serializeArray();
	 //assigning the filter criteria
	 var filterParam=new Array();
	 for(var i=0;i<formEleList.length;i++){
		 filterParam[filterParam.length]=new param(formEleList[i].name,formEleList[i].value); 
	 }
	 //calling population of the list through ajax
	 populateList(entity,filterParam);
}

// function to get the data by setting url, filter, success function and error function
var getData=function(url,filterData,successFn,errorFn){
	// making the ajax call
	$.ajax({
		url : url,
		type : "GET",
		data:filterData,
		success : function(resp) {
			//calling the user defined success function
			if(successFn)
			successFn(resp);	
		},
	error:function(e){
		//calling the user defined error function
		if(errorFn)
		 errorFn(e);
	}
	});
}

//function to populate the list of an entity
var populateList=function(entity, filter){
	//specifying the success function. When the ajax response is successful then the following function will be called

	var successFn=function(resp){
		var data='';
		if(resp){
			//getting the data from the response object
			data=resp.data;
		}
		//creating the html content
		var htm='';
		if(data.length > 0){
			for (var i=0;i<data.length;i++){
				//creating a row
				htm+='<tr>';
				htm+='<td>'+data[i].name+'</td><td>'+data[i].itemName+'</td><td>'+data[i].customerName+'</td><td>'+data[i].quantity+'</td><td>'+data[i].price+'</td><td>'+data[i].status+'</td>';
				//htm+='<td><a href="#" class="delete-entity" onclick=\'deleteEntity("'+entity+'","'+data[i].name+'",null)\'>Delete</a> | <a href="#" class="edit-entity" onclick=\'edit("'+entity+'","'+data[i].name+'")\'>Edit</a></td>'
				if(data[i].status == STATUS_PROCESSING || data[i].status == STATUS_PROCESSED){
					htm+='<td><INPUT id="orders" NAME="orders" TYPE="CHECKBOX" DISABLED VALUE="'+data[i].name+'"></td></tr>';
				} else{
					htm+='<td><INPUT id="orders" NAME="orders" TYPE="CHECKBOX" VALUE="'+data[i].name+'"></td></tr>';
				}
			}
		}
		else{
			//condition to show message when data is not available
			var thElesLength=$('#'+entity+'-list-ctr table thead th').length;
			htm+='<tr><td colspan="'+thElesLength+'">No records found</td></tr>';
		}
		$('#'+entity+'-list-tbody').html(htm);
		$('#order-table').tablePagination({});
		
		if($('#q1').val()==STATUS_PROCESSING){
			 $('#process-orders').html("<input type=\"button\" value=\"Process Confirmed Orders\" onClick=\"confirm()\" class=\"gsc-search-button\" />");
		 } else if($('#q1').val()==STATUS_PROCESSED){
			 $('#process-orders').html("");
		 } else if($('#q1').val()==STATUS_PENDING){
			 $('#process-orders').html("<input type=\"button\" value=\"Confirm Orders\" onClick=\"getSelected(this.form.orders)\" class=\"gsc-search-button\" />");
		 }
	}
	getData("/"+entity,filter,successFn,null);
}

var getSelected = function(opt) {
    var selected = new Array();
    var index = 0;
    if(opt.length > 0){
	    for (var intLoop = 0; intLoop < opt.length; intLoop++) {
	       if ((opt[intLoop].selected) ||
	           (opt[intLoop].checked)) {
	          index = selected.length;
	          selected[index] = new Object;
	          selected[index].value = opt[intLoop].value;
	          selected[index].index = intLoop;
	       }
	    }
    } else{
    	if(opt.checked){
    		selected[0] = new Object;
    		selected[0].value = opt.value;
	        selected[0].index = 0;
    	}
    }
    	
    if(selected.length == 0){
    	showMessage('Please choose orders to be processed.', 'order');
    } else
    	add(selected);
}

//function to delete an entity
var add = function(orders) {
	var parameter=new Array();
	for(var num in orders)
		parameter[parameter.length]= new param('id'+num, orders[num].value);
	parameter[parameter.length]=new param('action','PROCESS');
	//making the ajax call
	$.ajax({
			url : "/order",
			type : "POST",
			data:parameter,
			dataType:"html",
			success : function(resp) {
				showHideCreate('order',false);
				if (resp!=''){
					showMessage(resp, 'order');
				}
			},
			error : function(resp){
				showMessage(resp, 'order');
			}
	});
}

var confirm=function(){
	$.ajax({
		url : "http://order-backend.pull2-back.appspot.com/processOrder",
		type : "POST"
	});
	showHideCreate('order', false);
}

var validate=function(){
	var fileName = $('#file').val();
	if(fileName.match(/.xml$/)){
		$('#file-upload').attr("action", "/uploadorder");
		$('#file-upload').attr("enctype", "multipart/form-data");
		$('#file-upload').attr("method","post");
		form.submit();
		return true;
	} else if(fileName==undefined){
		alert('No file selected. Please choose one');
		$('#upload-reset').click();
		return false;
	}else{
		alert('Please select an XML file only');
		$('#upload-reset').click();
		return false;
	}
}

var showMessage=function(message, entity){
	$('#'+entity+'-show-message').show().html('<p><b>'+message+'</b></p>')
}

var fillBody=function(offset){
	 $('#order-list-tbody').html($.ajax({
           	  url: "/pagination",
           	  type: "GET",
           	  data: "offset="+offset,
           	  success: function(resp){
           		  $('#order-list-tbody').html(resp);
           	  }
           	}));
}