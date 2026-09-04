
  var data;
  var tData;
  var pTemp;
  var nTemp;
  const url = 'http://127.0.0.1:5000/grades'

async function loadRoster(){
  console.log("[}-- Loaded Roster --{]")
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
function displayGrade(){
  console.log("[}-- Displayed Grades --{]")

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

  console.log("[}-- Added Student --{]")

  const fName = document.getElementById('fName') 
  const lName = document.getElementById('lName'); 
  const pGrade = document.getElementById('pGrade');

  var name = fName.value + " " + lName.value;
  var grade = pGrade.value ;
  pTemp = {name : name, grade:grade};

  const response = await fetch(url + "/" + name, {
    method: 'POST',
    headers: {
     'Accept': 'application/json',
     'Content-Type': 'application/json'
    },
    body: JSON.stringify({name, grade})
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

document.getElementById( "Load" ).addEventListener( "click", loadRoster() );
document.getElementById( "Disp " ).addEventListener( "click", displayGrade() );
document.getElementById( "Chng" ).addEventListener( "click", changeGrade() );
document.getElementById( "adNS" ).addEventListener( "click", addStudent() );
document.getElementById( "DelG" ).addEventListener( "click", deleteGrade() );
document.getElementById( "CLRC" ).addEventListener( "click", clearData() );