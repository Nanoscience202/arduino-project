import serial
import ollama

arduino = serial.Serial(port="/dev/cu.usbmodem11101", baudrate=9600, timeout=0)


def multiply(req: str) -> str:
    res = float(req) * 2 * 10
    return str(res)


print("ready")
while True:
    inByte = b""

    # wait until first non empty byte is read
    while inByte == b"":
        inByte = arduino.read()

    req = inByte.decode()

    # read until newline
    while (inByte := arduino.read()) != b"\n":
        req += inByte.decode()

    print("req: " + req)

    # transform request and return response
    stream = ollama.generate("mistral", req, stream=True)

    for chunk in stream:
        res = ""
        if isinstance(chunk, str):
            res = chunk.replace("\n", " ")
        else:
            res = chunk["response"].replace("\n", " ")

        arduino.write(bytes(res, "utf-8"))
        arduino.flush()

    arduino.write(b"\n")
