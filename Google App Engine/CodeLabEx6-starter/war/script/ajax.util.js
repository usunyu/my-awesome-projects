var HOME='home';
var ENTITY_PRODUCT='product';
var ENTITY_ITEM='item';

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
		//showing the search container
		$('#' + entity + '-search-ctr').show();
		//showing the list container
		$('#' + entity + '-list-ctr').show();
		//hiding the create container
		$('#' + entity + '-create-ctr').hide();
		//checking if the entity is not a home then populating the list of the entity
		if(entity!=HOME)
			populateList(entity,null);
	}
}

//parameter object definition
var param=function(name,value){
	this.name=name;
	this.value=value;
}

//function to add an entity when user clicks on the add button in UI
var add = function(entity) {
	$('.message').hide();
	$('#'+entity+'-reset').click();
	//display the create container
	showHideCreate(entity, true);
	$("span.readonly input").attr('readonly', false);
	$("select[id$=item-product-list] > option").remove();
	//checking the entity to populate the select box
	if (entity == ENTITY_ITEM) {
		//populating the product and contact by making an ajax call
		populateSelectBox('item-product-list', '/product');
	}
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

var showMessage = function(message, entity){
	$('#'+entity+'-show-message').show().html('<p><b>'+message+'</b></p>');
}

var formValidate = function(entity){
	var key;
	var formEleList = $('form#'+entity+'-create-form').serializeArray();
	key=formEleList[0].value;
	switch(entity){
		case ENTITY_ITEM:
			var valueProduct = $('#item-product-list').val();
			if(valueProduct == "" || key == ""){
				showMessage('please check the key and Product values in the form', entity);
				return;
			}
			break;
		default :
			if(key==""){
				showMessage('please check the values in the form', entity);
				return;
			}
			break;
	}
	save(entity);
	$('#'+entity+'-show-message').hide();
}

//function to save an entity
var save = function(entity) {
	$('#'+entity+'-show-message').hide();
	// creating the data object to be sent to backend
	 var data=new Array();
	// collecting the field values from the form
	 var formEleList = $('form#'+entity+'-create-form').serializeArray();
	 for(var i=0;i<formEleList.length;i++){
		data[data.length]=new param(formEleList[i].name,formEleList[i].value);
	 }
	 //setting action as PUT
	 data[data.length]=new param('action','PUT');
	 //making the ajax call
	 $.ajax({
			url : "/"+entity,
			type : "POST",
			data:data,
			success : function(data) {
				showHideCreate(entity,false);
			}
		});
	 $('#'+entity+'-reset').click();
	 $('#item-product-list').reset();//='';
}

//function to edit entity
var edit = function(entity, id){
	var parameter=new Array();
	parameter[parameter.length]=new param('q',id);
	$.ajax({
		url : "/"+entity,
		type : "GET",
		data:parameter,
		success : function(resp) {
			var data=resp.data[0];
			var formElements = $('form#'+entity+'-create-form :input');
			for(var i=0;i<formElements.length;i++){
				if(formElements[i].type !="button"){
					var ele=$(formElements[i]);
					if(ele.attr('name')=="product"){						
						$("select[id$=item-product-list] > option").remove();
						ele.append('<option value="'+eval('data.'+ele.attr('name'))+'">'+eval('data.'+ele.attr('name'))+'</option>');	
					}
					else
						ele.val(eval('data.'+ele.attr('name')));
				}
			}
			showHideCreate(entity, true);
			$("span.readonly input").attr('readonly', true);
		}
	});

}

//function called when user clicks on the cancel button
var cancel = function(entity) {
	$('.message').hide();
	//hiding the create container in the tab
	showHideCreate(entity, false);
}

//function to delete an entity
var deleteEntity = function(entity,id,parentid) {
	var parameter=new Array();
	parameter[parameter.length]=new param('id',id);
	parameter[parameter.length]=new param('parentid', parentid);
	parameter[parameter.length]=new param('action','DELETE');
	//making the ajax call
	$.ajax({
		url : "/"+entity,
		type : "POST",
		data:parameter,
		dataType:"html",
		success : function(resp) {
			showHideCreate(entity,false);
			if (resp!=''){
				showMessage(resp, entity);
			}
		},
		error : function(resp){
			showMessage(resp, entity);
		}
	});
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

//function to populate the select box which takes input as id of the selectbox element and url to get the data
var populateSelectBox = function(id, url) {
	//specifying the success function. When the ajax response is successful then the following function will be called
	var successFn=function(resp){
		//getting the select box element
		var selectBox=$('#'+id);
		//setting the content inside as empty
		selectBox.innerHTML = '';
		//getting the data from the response object
		var data=resp.data; 
		//appending the first option as select to the select box
		selectBox.append('<option value="">Select</option>');
		//adding all other values
		for (var i=0;i<data.length;i++) {
			selectBox.append('<option value="'+data[i].name+'">'+data[i].name+'</option>');
		}
	}
	//calling the getData function with the success function
	getData(url,null,successFn,null);
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
				switch(entity)
				{
				case ENTITY_PRODUCT:
					htm+='<td>'+data[i].name+'</td><td>'+data[i].description+'</td>';
					break;
				case ENTITY_ITEM:
					htm+='<td>'+data[i].name+'</td><td>'+data[i].price+'</td><td>'+data[i].product+'</td>';
					break;
				default:
					htm+=""; 
				}
				if(entity == ENTITY_ITEM)
					htm+='<td><a href="#" class="delete-entity" onclick=\'deleteEntity("'+entity+'","'+data[i].name+'","'+data[i].product+'")\'>Delete</a> | <a href="#" class="edit-entity" onclick=\'edit("'+entity+'","'+data[i].name+'")\'>Edit</a></td></tr>';
				else
					htm+='<td><a href="#" class="delete-entity" onclick=\'deleteEntity("'+entity+'","'+data[i].name+'")\'>Delete</a> | <a href="#" class="edit-entity" onclick=\'edit("'+entity+'","'+data[i].name+'")\'>Edit</a></td></tr>';
			}
		}
		else{
			//condition to show message when data is not available
			var thElesLength=$('#'+entity+'-list-ctr table thead th').length;
			htm+='<tr><td colspan="'+thElesLength+'">No items found</td></tr>';
		}
		$('#'+entity+'-list-tbody').html(htm);
	}
	getData("/"+entity,filter,successFn,null);
}