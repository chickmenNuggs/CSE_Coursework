import requests
from flask import Flask, jsonify, request, render_template
from sqlalchemy import Column, Float, String, create_engine
from sqlalchemy.orm import Session, declarative_base

app = Flask(__name__)
URL = "https://amhep.pythonanywhere.com/grades"

app.config["SQLALCHEMY_DATABASE_URI"] = "sqlite:///students.sqlite"
engine = create_engine('sqlite:///app.db');
base = declarative_base();

class table(base):
    __tablename__ = 'roster';
    Name = Column(String, primary_key= True, nullable= False);
    Grade = Column(Float, nullable= False);
    
base.metadata.create_all(engine);

def getGrades():
    global grades;
    responce = requests.get(URL);
    grades = responce.json();
def createDB():
    try:
        getGrades();
        
        with Session(engine) as session:
            for name, grade in grades.items():
                student = table(Name = name, Grade = grade);
                session.add(student);
            session.commit();
    except Exception as e:
        pass
        # print(f"[)~~~~~~[Error Loading Roster : {e}");
        print("[}~~~~~{[Ran Creation]}~~~~~{]");  

@app.route("/")
def home():
    return render_template("index.html")

# UPDATED
@app.route('/grades')
def expStu():
    with Session(engine) as session:
        rost = session.query(table).all();
        rez = {}
        for s in rost:
            rez.update({s.Name: s.Grade});
    return jsonify(rez);

# UPDATED

@app.route('/grades/<name>', methods=['GET'], strict_slashes=False)
def GetStu(name):
    with Session(engine) as session:
        rost = session.query(table).filter(table.Name == name).first()
    session.close()
    return jsonify({rost.Name: rost.Grade})


@app.route('/grades/<name>', methods = ['POST'],  strict_slashes=False)
def pushStu(name):
    data = request.get_json();
    with Session(engine) as session:
        newStudent = table(Name = data['name'], Grade = data['grade']);
        session.add(newStudent);
        session.commit();
    # grades[name] = data['grade'];
    return jsonify({"message": "Student added successfully"});

#UPDATED
@app.route('/grades/<name>', methods=['PUT'])
def editStu(name):
    data = request.get_json();
    response = requests.put(f"{URL}/{name}", json={"grade":data['grade']})
    if response.ok:
        with Session(engine) as session:
            student = session.query(table).filter(table.Name == name).first()
            student.Grade = data["grade"];
            session.commit();
        # grades[name] = data['grade'];
        return jsonify({"message": "student updated"})
    
# UPDATED
@app.route('/grades/<name>', methods=['DELETE'], strict_slashes=False)
def DeleteStudent(name):
    print("[}~~~~~{[Deletion Processing]}~~~~~{]");
    
    with Session(engine) as session:
        student = session.query(table).filter(table.Name == name).first()
        session.delete(student);
        session.commit();
        print("[}~~~~~{[Deletion Approved]}~~~~~{]");
    return jsonify({"message": "do i even need to put this here?"})

# UPDATED
if __name__ == "__main__":
    createDB()
    app.run(debug=True)