let expenses = JSON.parse(localStorage.getItem("expenses"));
if (expenses === null) {
  expenses = [];
}

function addExpense() {
  let type = document.getElementById("type").value;
  let name = document.getElementById("name").value;
  let amount = parseInt(document.getElementById("amount").value);
  let date = document.getElementById("date").value;

  if (!name || !amount || !date) {
    alert("Please fill all fields!");
    return;
  }

  expenses.push({ type, name, amount, date });
  localStorage.setItem("expenses", JSON.stringify(expenses));

  document.getElementById("name").value = "";
  document.getElementById("amount").value = "";
  document.getElementById("date").value = "";

  showExpenses();
}

function deleteExpense(index) {
  expenses.splice(index, 1);
  localStorage.setItem("expenses", JSON.stringify(expenses));
  showExpenses();
}

function showExpenses() {
  let expenseList = document.getElementById("expenseList");
  expenseList.innerHTML = "";

  let incomeTotal = 0;
  let expenseTotal = 0;

  expenses.forEach((e, i) => {
    let typeSymbol = e.type === "Income" ? "↘" : "↗";

    if (e.type === "Income") {
      incomeTotal += e.amount;
    } else {
      expenseTotal += e.amount;
    }

    expenseList.innerHTML += `
      <tr>
        <td>${i + 1}</td>
        <td>${e.name}</td>
        <td>${e.amount}</td>
        <td>${e.type}</td>
        <td><button onclick="deleteExpense(${i})">X</button></td>
      </tr>
    `;
  });

  document.getElementById("balance").innerText = incomeTotal - expenseTotal;
  document.getElementById("income").innerText = incomeTotal;
  document.getElementById("expenses").innerText = expenseTotal;
}

showExpenses();
