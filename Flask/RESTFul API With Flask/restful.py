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

@app.route("/lang", methods=['POST'])
def addOne():
    language = {'name' : request.get_json(force=True)['name']}
    languages.append(language)
    return jsonify({'languages' : languages})

@app.route("/lang/<string:name>", methods=['PUT'])
def editOne(name):
    langs = [language for language in languages if language['name'] == name]
    if len(langs) > 0:
        langs[0]['name'] = request.get_json(force=True)['name']
        lang = langs[0]
    else:
        lang = "Not found!"
    return jsonify({'language' : lang})

@app.route("/lang/<string:name>", methods=['DELETE'])
def removeOne(name):
    langs = [language for language in languages if language['name'] == name]
    if len(langs) > 0:
        languages.remove(langs[0])
    return jsonify({'languages' : languages})

if __name__ == "__main__":
    app.run(debug=True, port=8001)