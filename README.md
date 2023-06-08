# ubloxGPS
testing GPS capabilities using uBlox


## serial_console_test.ino
This is a basic arduino script that requires no wiring (except for connecting the arduino via USB to computer). Simply pushing that file to the arduino causes the arduino to send fake data over the serial connection (from the USB), which can be viewed by the serial monitor in the arduino IDE.

To run:
1. push the code to the arduino using the arduino IDE
2. open the serial monitor

## serial_python_test.ino with serial_python_test.py
This script also does not require any wiring (except for USB connection) and instead of the arduino IDE serial monitor to view the data being transmitted, a python script is used to read the data of the serial USB connection and logs it into a .csv.

To run:
1. push the code to the arduino using the arduino IDE
2. run the python script (if WIN command prompt --> navigate to the location of the script, then type the name of the script and hit 'enter')
3. ctrl+c to stop the python logging script


