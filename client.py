import serial

arduino = serial.Serial(port="/dev/cu.usbmodem11101", baudrate=9600, timeout=0)

print("ready")
while True:
    inByte = b""

    # wait until non empty byte is read
    while inByte == b"":
        inByte = arduino.read()

    req = inByte.decode()

    # read until newline
    while (inByte := arduino.read()) != b"\n":
        req += inByte.decode()

    print("req: " + req)

    # transform request and return response
    res = str(float(req) * 2 * 10)

    print("res: " + res + "\n")

    # send the response to arduino
    arduino.write(bytes(res, "utf-8"))

    # wait until all bytes are written
    arduino.flush()
