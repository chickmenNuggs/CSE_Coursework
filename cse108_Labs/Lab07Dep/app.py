from flask import Flask, jsonify, request, render_template
import requests
import json

app = Flask(__name__)

URL = "https://amhep.pythonanywhere.com/grades"

stu = {};

@app.route("/")
def home():
    return render_template("index.html")

def loadStu():
    global students; 
    responce = requests.get(URL);
    students = responce.json();


@app.route('/grades', methods=['GET'])

def expStu():
    return jsonify(students);
@app.route('/grades/<name>', methods = ['GET'])
def GetStudent(name):
    student = students.get(name);
    if students is not None:
        return jsonify({name : student})


# [DRIVER CODE]
if __name__ == "__main__":
    loadStu()
    app.run(debug=True)


# # New functions
# @app.route("/about/")
# def about():
#     return render_template("about.html")

# @app.route("/contact/")
# def contact():
#     return render_template("contact.html")
