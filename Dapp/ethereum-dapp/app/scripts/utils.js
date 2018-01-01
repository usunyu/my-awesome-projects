/**
 * Contains utility functions for managing the UI
 */

// Holds the base URL for etherscan.io
var etherscanBaseUrl='https://ropsten.etherscan.io/';


// Since some of the functons/API are not available based on the
// Node type - this function disables certainelements
function    setUIBasedOnNodeType(){
    // Unlock Account - Check the node type
    
    if(nodeType === 'metamask' || nodeType == 'testrpc'){
        setData('lock_unlock_result','Unlock / lock ( ) not supported for '+nodeType,true);
    } else {
        setData('lock_unlock_result','--',false);
    }
    // Compiler options
    if(nodeType === 'geth' || nodeType === 'metamask'){
        // Not supported for geth & metamask
        setData('list_of_compilers','getCompilers ( ) & compileSolidity ( ) not supported for '+nodeType,true);

        // Disable the compile butto
        document.getElementById('button_do_compile').disabled = true;
        //document.getElementById("sourcecode").value="Compile sample contract in Remix | Wallet | solc . Copy & Paste the Bytecode | ABIDefinition for deployment.";
        document.getElementById('sourcecode').disabled=true;
    } else {
        setData('list_of_compilers','--',false);
        document.getElementById('button_do_compile').disabled = false;
        document.getElementById('sourcecode').disabled=false;   
    }

    // This simply creates the JSON for default transaction object
    generateTransactionJSON();
    copyBytecodeInterfaceToUI();
}

// Update the iframe data
function updateIFrameContent(iframe_id, data) {
    var iframe = document.getElementById(iframe_id);
    var iframedoc = iframe.contentDocument || iframe.contentWindow.document;
    iframedoc.body.innerHTML = html;
}

function setData(docElementId, html, errored) {
    document.getElementById(docElementId).innerHTML = html;
    if (errored) document.getElementById(docElementId).classList = 'notready';
    else document.getElementById(docElementId).classList = 'ready';
}

function arrayToMultilineString(arr) {
    var concat = '';
    for (var i = 0; i < arr.length; i++) {
        concat += arr[i] + '<br>'
    }
    return concat;
}

/**
 * Creates a list item for the account in the account list
 */
function addAccountsToList(listId,index,account){
    var li = document.createElement('LI');
    var input = document.createElement('INPUT')
    input.value = account;
    input.id = 'account'+index;
    input.disabled=true;
    li.appendChild(input)
    var list = document.getElementById(listId);
    list.appendChild(li)
}


/**
 * Creates a list item for the balance in the account balance list
 */
function addAccountBalancesToList(listId,index,accountBalance){
    var li = document.createElement('LI');
    li.class='ready'
    var input = document.createElement('P');
    input.class = 'ready';
    input.innerText=accountBalance+' Ether';
    li.appendChild(input);
    var list = document.getElementById(listId);
    list.appendChild(li)
}

/**
 * Removes all of the <li> in List
 */
function removeAllChildItems(elementId){
    var ele = document.getElementById(elementId);
    while (ele.hasChildNodes()) {   
        ele.removeChild(ele.firstChild);
    }
}

/**
 * This populates all <SELECT> boxes with accounts
 */
function    addAccountsToSelects(accounts){
    
    removeAllChildItems('send_from_account');
    removeAllChildItems('send_to_account');
    removeAllChildItems('select_to_unlock_account');
    for (var i = 0; i < accounts.length; i++) {
        addOptionToSelect('send_from_account', accounts[i].substring(0,15)+'...', accounts[i]);
        addOptionToSelect('send_to_account', accounts[i].substring(0,15)+'...', accounts[i]);
        addOptionToSelect('select_to_unlock_account', accounts[i].substring(0,15)+'...', accounts[i]);
    }
}

/**
 * Add options to a <select>
 */
function    addOptionToSelect(selectId, text, value){
    var option = document.createElement('OPTION');
    option.text = text;
    option.value = value;
    var select = document.getElementById(selectId);
    select.appendChild(option)

    // lets try data list add 
    // select = document.getElementById("browsers");
    // option = document.createElement('OPTION');
    // option.text=text
    // select.appendChild(option)
}

/**
 * This function creates the transaction object by reading the input elements
 */
function    createTransactionObjectJson(){
    var transObject = {};
    // get the from and to account 
    transObject.from = document.getElementById('send_from_account').value;
    transObject.to = document.getElementById('send_to_account_value').value;
    // Get the value in ether and convert to wie
    var valueInEther = document.getElementById('send_value_in_ether').value
    var valueInWei = web3.toWei(valueInEther,'ether');
    transObject.value = valueInWei;
    // set the gas and gasPrice
    if(document.getElementById('send_gas').value !== 'default')
        transObject.gas = document.getElementById('send_gas').value;
    if(document.getElementById('send_gas_price').value !== 'default')
        transObject.gasPrice = document.getElementById('send_gas_price').value;
    // set the data
    if(document.getElementById('send_data').value !== 'default'){
        // convert the ascii to hex
        var data = document.getElementById('send_data').value;
        transObject.data = web3.toHex(data);
    }
    // set the nonce
    if(document.getElementById('send_nonce').value !== 'default')
        transObject.nonce = document.getElementById('send_nonce').value;

    return transObject;
}

// The byte code for the 
function copyBytecodeInterfaceToUI(){
    document.getElementById('compiled_bytecode').value=(contract_bytecode);
    document.getElementById('compiled_abidefinition').value=(contract_abidefinition);
}

/**
 * Populates the JSON for transaction object
 */
function    generateTransactionJSON(){
    var tobject = createTransactionObjectJson();
    setData('send_transaction_object_json',JSON.stringify(tobject,undefined,2),false)
}

/**
 * Resets the value in the transaction object input values
 */
function    resetTransactionObjectParameters(){
    document.getElementById('send_gas').value = 'default';
    document.getElementById('send_gas_price').value = 'default';
    document.getElementById('send_data').value = 'default';
    document.getElementById('send_nonce').value = 'default';
    document.getElementById('send_value_in_ether').value = 0;
    generateTransactionJSON();
}

/**
 * Create the etherscan link
 */
function    createEtherscanIoUrl(type,hashOrNumber){

    // For TestRPC - this URL will have no meaning as the
    // Etherscan.io will not know about the Tx Hash

    var url = etherscanBaseUrl;
    if(type === 'tx'){
        url += 'tx/'+hashOrNumber;
    } else if(type === 'block'){
        url += 'block/'+hashOrNumber;
    } else if(type === 'address'){
        url += 'address/'+hashOrNumber;
    } 
    return url;
}

/**
 * Sets the href in the <a> tag for etherscan.io
 */
function   setEtherscanIoLink(aId, type, hashOrNumber){
    var etherscanLinkA=document.getElementById(aId);
    etherscanLinkA.href = createEtherscanIoUrl(type,hashOrNumber);
    if(hashOrNumber)
        etherscanLinkA.innerHTML='etherscan.io';
    else
        etherscanLinkA.innerHTML='';
}

/**
 * Flattens the source code for contract as it needs to be provided as a command line
 * argument to the solidity compiler
 */
function flattenSource(src){
    return src.replace(/\n/g, ' ');
}

/**
 * Windows Solidity Hack
 * On Windows for some reason the contracts in compiled result appear as "<stdin>:Contract" 
 * instead of just "Contract" so this hack simply removes the "<stdin>:" from the contract
 * names. No impact if the compilation result is in a good state.
 * */
function    compileResultWindowsHack(result){
    var cleaned = {}
    for(var prop in result){
        var newProp = prop.replace('<stdin>:','');
        cleaned[newProp] = result[prop];
    }
    return cleaned;
}

/**
 * Reset the deployment result UI
 */
function    resetDeploymentResultUI(){
    console.log('utils.resetDeploymentResultUI() TO BE CODED')
}

/**
 * Sets the Result UI components for the Execute call
 */
function    setExecuteResultUI(callType,functionName, parameter, return_value, txHash, error){
    var detail = callType+':'+functionName+'('+parameter+')';
    if(error)  detail += ' FAILED '+return_value;
    else detail += 'Successful';

    setData('invoke_details',detail,(error));

    setData('invoke_return_value',return_value,(error));

    console.log('return_value=',return_value)

    setData('invoke_contracttransactionhash', txHash, false);
    //invoke_contracttransactionhash_link
    setEtherscanIoLink('invoke_contracttransactionhash_link', 'tx', txHash);
}

/**
 * Generates the filter options array & updates the UI also
 */

function    generateFilterOptions()   {

    var options = {};
    var val = document.getElementById('from_block_filter').value;
    if(val && val.trim().length > 0)
                options['fromBlock'] = val;
    val = document.getElementById('to_block_filter').value;
    if(val && val.trim().length > 0)
                options['toBlock'] =  val;

    var val = document.getElementById('addresses_filter').value;
    // Addresses have multiple addresses separated by new line - need to be changed to comma separated
    val = val.trim();
    
    if(val.length > 0) {
        //val = val.replace('\n',',');
        val = val.split('\n');
        options['address'] = val;
    }
    val = document.getElementById('topics_filter').value;
    // only 3 topics allowed in options; array created with elements each in new line
    val = val.trim();

        console.log('SIG=',getHashEventSignature('NumberSetEvent(address,bytes32,bytes32)'))

    if(val.length > 0 ){
        val = val.split('\n');

        for(var i=0; i < val.length;i++){
            val[i] = val[i].trim()
            if(val[i] === 'null') val[i]=null;
        }
        options['topics'] = val;


    }



    setData('options_filter',JSON.stringify(options,undefined,2),false);
    return options;
}

/**
 * Adds a list element in the 0th position
 * Removes the last element if the length exceeds provided ln
 */
function    addEventListItem(listId, childData, len){
    
    console.log('Event:',childData);

    // check length
    var list = document.getElementById(listId);
    if(list.childNodes.length >= len){
        var i = list.childNodes.length - 1; // last child
        list.removeChild(list.childNodes[i]);
    }
    // Create the List Item for the events list
    var li = document.createElement('LI');

    // Add new event in the 0th position
    li.appendChild(createEventListItem(childData));
    list.insertBefore(li, list.childNodes[0]);
}

// Creates the item in the events list
function    createEventListItem(childData){
    var div = document.createElement('SPAN');
    var p = document.createElement('A');
    p.text = 'Log#'+childData.logIndex+', Txn#'+childData.transactionIndex;
    div.appendChild(p);
    var aLink = document.createElement('A')
    //Add block info link
    aLink.text = ', Blk#'+childData.blockNumber;
    aLink.href = createEtherscanIoUrl('block', childData.blockNumber);
    aLink.target='_blank';
    div.appendChild(aLink);
    // Add txn info link
    if(childData.transactionHash){
        aLink = document.createElement('A')
        aLink.text = ', Txn, ';
        aLink.href = createEtherscanIoUrl('tx', childData.transactionHash);
        aLink.target='_blank';
        div.appendChild(aLink);
    }
    // Address
    if(childData.address){
        aLink = document.createElement('A')
        aLink.text = 'Addr';
        aLink.href = createEtherscanIoUrl('address', childData.address);
        aLink.target='_blank';
        div.appendChild(aLink);
    }
    return div;
}

/**
 * Clears the items from a list element on the HTML page
 */
function    clearList(listId){
    var list = document.getElementById(listId);
    for(var i=list.childNodes.length-1; i>=0 ;i--){
        list.removeChild(list.childNodes[i]);
    }
}

/**
 * Adds the CONTRACT watch event to the list box 
 */
function    addContractEventListItem(listId, childData, len){
    console.log(JSON.stringify(childData))
}


/**
 * Hash signature of the event
 * Utility method to show how to generate the event signature
 * getHashEventSignature('NumberSetEvent(address,bytes32,bytes32)')
 */
function getHashEventSignature(evt){
    return web3.sha3(evt)
}