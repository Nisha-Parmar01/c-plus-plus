// ===== SELECT ELEMENTS =====
const uname = document.getElementById("uname");
const degree = document.getElementById("degree");
const sname = document.getElementById("sname");

const m1 = document.getElementById("m1");
const m2 = document.getElementById("m2");
const m3 = document.getElementById("m3");
const m4 = document.getElementById("m4");
const m5 = document.getElementById("m5");

const StudentName = document.getElementById("StudentName");
const Total = document.getElementById("Total");
const Average = document.getElementById("Average");
const percentage = document.getElementById("percentage");
const grade = document.getElementById("grade");
const resultCard = document.getElementById("resultCard");

function getGrade(percent) {
    if (percent >= 90) {
      return 'A+';
    }
    else if (percent >= 80) {
      return 'A';
    }
    else if (percent >= 70){
      return 'B';
    } 
    else if (percent >= 50){
      return 'C';
    } 
    else if (percent >= 33){
      return 'D';
    } 
    else {
      return 'Fail';
    }
}


function calculateGrade() {
 
    const universityName = uname.value.trim();
    const degreeName = degree.value.trim();
    const studentName = sname.value.trim();
    const marks = [m1, m2, m3, m4, m5].map(i => Number(i.value));

    if (!universityName || !degreeName || !studentName) {
        alert("Please fill all fields!");
        return;
    }

    if (marks.some(m => isNaN(m) || m < 0 || m > 100)) {
        alert("Marks must be between 0 and 100!");
        return;
    }

    // Calculate
    const total = marks.reduce((a, b) => a + b, 0);
    const average = total / marks.length;
    const perc = (total / 500) * 100;
    const g = getGrade(perc);

    StudentName.innerHTML = `
        🏫 <b>${universityName}</b><br>
        🎓 Degree: ${degreeName}<br>
        👤 ${studentName}
    `;
    Total.innerHTML = `📘 Total Marks: ${total} / 500`;
    Average.innerHTML = `📗 Average: ${average.toFixed(2)}`;
    percentage.innerHTML = `📊 Percentage: ${perc.toFixed(2)}%`;
    grade.innerHTML = `🎖 Grade: ${g}`;
    grade.className = `grade ${g}`;
  
    resultCard.style.display = "block";
}
