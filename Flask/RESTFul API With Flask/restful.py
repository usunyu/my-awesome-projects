from flask import Flask, jsonify, request
app = Flask(__name__)

languages = [{'name' : 'Javascript'}, {'name' : 'Python'}, {'name' : 'Ruby'}]

@app.route("/", methods=['GET'])
def test():
    return jsonify({'message' : 'It works!'})

@app.route("/lang", methods=['GET'])
def returnAll():
    return jsonify({'languages' : languages})

@app.route("/lang/<string:name>", methods=['GET'])
def returnOne(name):
    langs = [language for language in languages if language['name'] == name]
    if len(langs) > 0:
        lang = langs[0]
    else:
        lang = "Not found!"
    return jsonify({'language' : lang})

if __name__ == "__main__":
    app.run(debug=True, port=8001)