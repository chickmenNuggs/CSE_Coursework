from flask import Flask, jsonify, request, render_template

app = Flask(__name__)

grades = {}

@app.route("/")
def home():
    return render_template("index.html")

# New functions
@app.route("/about/")
def about():
    return render_template("about.html")

@app.route("/contact/")
def contact():
    return render_template("contact.html")

if __name__ == "__main__":
    app.run(debug=True)