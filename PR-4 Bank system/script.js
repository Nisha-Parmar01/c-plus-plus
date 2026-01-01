var savingBalance = 0;
var currentBalance = 10000;

function gettype(){
  var choice = document.getElementById("choice").value;
  var t = `
    <select id="trans" onchange="getTransition()">
      <option value="">Select Transaction</option>
      <option value="1">💸 Withdraw</option>
      <option value="2">➕ Deposit</option>
      <option value="3">📊 Check Balance</option>
    </select>`;
  document.getElementById("Ttype").innerHTML = t;
  document.getElementById("result").innerHTML="";
}

function getTransition(){
  var choice = document.getElementById("choice").value;
  var trans = document.getElementById("trans").value;
  var r = document.getElementById("result");

  if(trans==1){
    r.innerHTML = `
      <input type="number" id="amt" placeholder="Enter Amount">
      <button onclick="${choice==1?'withdrawSaving()':'withdrawCurrent()'}">Withdraw</button>`;
  }
  else if(trans==2){
    r.innerHTML = `
      <input type="number" id="amt" placeholder="Enter Amount">
      <button onclick="${choice==1?'depositSaving()':'depositCurrent()'}">Deposit</button>`;
  }
  else if(trans==3){
    r.style.color="green";
    r.innerHTML = choice==1
      ? "Saving Balance : ₹ " + savingBalance
      : "Current Balance : ₹ " + currentBalance;
  }
}

function withdrawSaving(){
  var amt = Number(document.getElementById("amt").value);
  if(amt>savingBalance){
    result.style.color="red";
    result.innerHTML="Insufficient Balance";
  }else{
    savingBalance-=amt;
    result.style.color="green";
    result.innerHTML="Withdraw Successful <br> Balance : ₹ "+savingBalance;
  }
}

function depositSaving(){
  var amt = Number(document.getElementById("amt").value);
  savingBalance+=amt;
  result.style.color="green";
  result.innerHTML="Deposit Successful <br> Balance : ₹ "+savingBalance;
}

function withdrawCurrent(){
  var amt = Number(document.getElementById("amt").value);
  if(amt>currentBalance){
    result.style.color="red";
    result.innerHTML="Insufficient Balance";
  }else{
    currentBalance-=amt;
    result.style.color="green";
    result.innerHTML="Withdraw Successful <br> Balance : ₹ "+currentBalance;
  }
}

function depositCurrent(){
  var amt = Number(document.getElementById("amt").value);
  currentBalance+=amt;
  result.style.color="green";
  result.innerHTML="Deposit Successful <br> Balance : ₹ "+currentBalance;
}