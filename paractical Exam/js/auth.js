
function signup() {
  let name = document.getElementById("name").value;
  let email = document.getElementById("email").value;
  let password = document.getElementById("password").value;

  if (!name || !email || !password) {
    alert("All fields required");
    return;
  }

  let users = JSON.parse(localStorage.getItem("users")); 

  if (users) { 
    if (users.find(u => u.email === email)) {
      alert("User already exists");
      return;
    }
    users.push({ name, email, password });
  } else { 
    users = [{ name, email, password }];
  }

  localStorage.setItem("users", JSON.stringify(users));
  alert("Signup successful!");
  window.location.href = "login.html";
}


function login() {
  let name = document.getElementById("name").value;
  let password = document.getElementById("password").value;

  let users = JSON.parse(localStorage.getItem("users")); 

  if (!users) {
    alert("No users found. Please signup first!");
    return;
  }

  let user = users.find(u => u.name === name && u.password === password);

  if (!user) {
    alert("Invalid login");
    return;
  }

  localStorage.setItem("loggedUser", JSON.stringify(user));
  window.location.href = "Expense.html";
}
