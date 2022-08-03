from flask import Flask, request
import subprocess
import jsonify
import json


def run_cpp(cmd):
    p = subprocess.Popen(cmd, stdout=subprocess.PIPE, shell=True,
                         stderr=subprocess.PIPE, universal_newlines=True)
    out, err = p.communicate()
    print(f'{type(out)} {type(err)}')

    return out, err


def blink_led(light_pin):

    cmd = f'python3 blink_led.py {light_pin}'
    p = subprocess.Popen(cmd, stdout=subprocess.PIPE, shell=True,
                         stderr=subprocess.PIPE, universal_newlines=True)
    out, err = p.communicate()
    print(f'{type(out)} {type(err)}')

    return out, err


HOST = '192.168.10.120'
# HOST = '127.0.0.1'
PORT = 5001
app = Flask(__name__)


def convert_json(out):

    dict = {}
    for line in out.split('\n'):
        if ':' in line:
            key, value = line.split(':')
            dict[key] = value

    jsono = json.dumps(dict, indent=4)

    return jsono.replace('\\t', '')


@app.route('/', methods=['GET'])
def index():

    user_data = request.args.get('params')

    if user_data == 'data':
        out, err = run_cpp(f'./spec --data')

        return convert_json(out)

    elif user_data == 'info':
        out, err = run_cpp(f'./spec --info')

        return convert_json(out)

    else:

        return 'Hello World!'


if __name__ == '__main__':
    app.run(debug=True, host=HOST, port=PORT)
