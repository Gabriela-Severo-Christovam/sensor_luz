from flask import Flask 

app = Flask(__name__)

@app.route('/')
@app.route("/dashboard")
def pagina_dashboard():
    return "pagina em construção"

@app.route("/lampada/ligada")
def post_lampada_ligada():
    return "pagina em construção"