from flask import Flask, redirect, render_template, request

app = Flask(__name__)

@app.route('/')
# @app.route("/dashboard")
def pagina_dashboard():
    
    return render_template("index.html")

@app.route("/lampada/ligada")
def post_lampada_ligada():
    return "pagina em construção"

app.run(host="0.0.0.0", port=8080)