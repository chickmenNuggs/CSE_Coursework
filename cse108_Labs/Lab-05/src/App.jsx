
import './App.css'

function App() {
  return (
    <>
      <h1>Student Grade Manager</h1>
      <div class = "uI">
        <div id = "stuRost">
            <h1>Student Roster</h1>
            <ul id = "stuList">
              
            </ul>
        </div>
        <div id = "uI">
          <div id = "gSpace"> 
            <table id = "stuTable">
              <tr>
                <td><input class = "stuDat" id = "fName" type = "text" ></input></td>
                <td><input class = "stuDat" id = "lName" type = "text" ></input></td>
              </tr>
              <tr>
                <th> Student First Name</th>
                <th> Student Last Name</th>
              </tr>
              <tr>
                <td><input class = "stuDat" id = "lGrade" type = "text" value = "" ></input></td>
                <td><input class = "stuDat" id = "pGrade" type = "text"></input></td>
              </tr>  
              <tr>
                <th> Student Grade Letter</th>
                <th> Student Grade Percent</th>
              </tr>
            </table>
          </div>
          <div id = "bSpace">
            <button class = "bBoard" id='Load' onClick={()=> loadRoster()}>Load Roster</button>
            <button class = "bBoard" id='Disp' onClick={() => displayGrade()}>Display Grade</button>
            <button class = "bBoard" id='Chng' onClick={() => changeGrade()}>Change Grade</button>
            <button class = "bBoard" id='adNS' onClick={() => addStudent()}>Add new Student</button>
            <button class = "bBoard" id='DelG' onClick={() => deleteGrade()}>Delete Grade</button>
            <button class = "bBoard" id='CLRC' onClick={() => clearData()} >Clear Roster</button>

          </div>
        </div>
      </div>
    </>
  )
}

export default App

  var data;
  var tData;
  var pTemp;
  var nTemp;
  const url = 'https://amhep.pythonanywhere.com/grades'


async function loadRoster(){
  const response = await fetch(url);
  data = await response.json();
    
  for(var students in data){
    const shell = document.getElementById("stuList");
    const newLI = document.createElement("li");
    newLI.id = "jsCreated";
    const btn = document.createElement('button');
    btn.value = data[students];
    btn.textContent = students;
    btn.addEventListener("click", () =>{
      tData = {
        wName : btn.textContent,
        fName : btn.textContent.trim().split(/\s+/)[0],
        lName : btn.textContent.trim().split(/\s+/)[1],
        pGrade : btn.value,
      }  
      console.log(tData)
    });
    newLI.appendChild(btn);
    shell.appendChild(newLI);
  }
};

// async function getGrade(){
//   const response = await fetch(url+"/"+tData.wName, {
//     method: 'GET',
//     headers: {
//      'Accept': 'application/json',
//      'Content-Type': 'application/json'
//     }
    
//   })
// }

function displayGrade(){
  var pntr = document.getElementById("fName");
  pntr.value = tData.fName;
  var pntr = document.getElementById("lName");
  pntr.value = tData.lName;
  var pntr = document.getElementById("pGrade");
  pntr.value = tData.pGrade;
  var pntr = document.getElementById("lGrade");
  if(tData.pGrade <= 100.0){
    pntr.value = 'A'
  }
  if(tData.pGrade <= 90.0){
    pntr.value = "B"
  }
  if(tData.pGrade <= 70.0){
    pntr.value = "C"
  }
  if(tData.pGrade <= 60.0){
    pntr.value = "D"
  }
  if(tData.pGrade <= 59.0){
    pntr.value = "F"
  }
};

async function changeGrade(){
  console.log("[}~~ Changing Grades ~~{]")
  
  const fName = document.getElementById('fName') 
  const lName = document.getElementById('lName'); 
  const pGrade = document.getElementById('pGrade');

  var name = fName.value + " " + lName.value;
  var grade = pGrade.value ;
  pTemp = {name : name, grade:grade};

  const response = await fetch(url+"/"+tData.wName, {
    method: 'PUT',
    headers: {
     'Accept': 'application/json',
     'Content-Type': 'application/json'
    },
    body: JSON.stringify(pTemp)
  })
  uDat();
};

async function addStudent(){

  const fName = document.getElementById('fName') 
  const lName = document.getElementById('lName'); 
  const pGrade = document.getElementById('pGrade');

  var name = fName.value + " " + lName.value;
  var grade = pGrade.value ;
  pTemp = {name : name, grade:grade};

  const response = await fetch(url, {
    method: 'POST',
    headers: {
     'Accept': 'application/json',
     'Content-Type': 'application/json'
    },
    body: JSON.stringify(pTemp)
  })
  
  // post
  uDat();
};

async function deleteGrade(){
  console.log("[}~~ Deleting Grades ~~{]")
  try{
    const response = await fetch(url+'/'+tData.wName, {
      method: 'DELETE',
      headers:{
        'Accept': 'application/json',
        'Content-Type': 'application/json'
      }
    });
    if(response.ok){
      alert(`Student ${tData.wName} removed sucessfully`)
    }
    else{
      alert(`Failed to remove student ${tData.wName}`)
    }
  } catch (error)
  {
    alert('Error removing student:', error);
  }
  uDat();
};

async function clearData(){
  console.clear()
  for(var students in data){
    const aD = document.getElementById("jsCreated");
    aD.remove()
  }
  console.log("[}~~ Data Cleared ~~{]")
}

async function uDat() {
  cDat();
  loadRoster();
}

async function cDat() {
  for(var students in data){
    const aD = document.getElementById("jsCreated");
    aD.remove()
  }
}