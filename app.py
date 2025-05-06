from flask import Flask, redirect, render_template, request, jsonify

app = Flask(__name__)

situacao_sala=None

@app.route("/lampada/ligada")
def post_lampada_ligada():
    global situacao_sala
    situacao_sala="LIGADO"
    return jsonify ({"mensagem":"Alterado para LIGADO"})

@app.route("/lampada/desligada")
def post_lampada_desligada():
    global situacao_sala
    situacao_sala="DESLIGADO"
    return jsonify ({"mensagem":"Alterado para DESLIGADO"})

@app.route("/get/estado_lampada")
def get_estado_lampada():
    global situacao_sala
    return jsonify ({"ESTADO_LAMPADA": situacao_sala})




app.run( host= '0.0.0.0', port=8080)
