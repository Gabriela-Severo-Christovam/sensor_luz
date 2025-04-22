from flask import Flask, redirect, render_template, request

app = Flask(__name__)

@app.route('/')
# @app.route("/dashboard")
def pagina_dashboard():
    
    return render_template("index.html")

@app.route("/lampada/ligada")
def post_lampada_ligada():
    lightResult = "desligada"
    
    if lightResult=="desligada":
        lightResult="ligada"
    else:
        lightResult="ligada"
    return render_template("index.html", lightState = lightResult)

app.run()
