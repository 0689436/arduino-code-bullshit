import serial
import time
from datetime import datetime

ser = serial.Serial('/dev/ttyACM0', 9600)
time.sleep(2)

while True:
    now = datetime.now()
    time_str = now.strftime('%H:%M:%S')
    date_str = now.strftime('%Y/%m/%d')
    ser.write(f"{time_str}|{date_str}\n".encode())
    time.sleep(1)

