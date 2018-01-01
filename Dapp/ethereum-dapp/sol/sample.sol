pragma solidity ^0.4.6;
contract sample {

  uint   num;
                
  event NumberSetEvent(address indexed caller, bytes32 indexed oldNum, bytes32 indexed newNum);

   function getNum()  returns (uint n) {
     return num;
  }
               
   function setNum(uint n) {
      uint old = num;
      num=n;
      NumberSetEvent(msg.sender,bytes32(old),bytes32(num));
   }
               
   function sample(uint x){num=x;}
}

