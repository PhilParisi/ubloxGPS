# ubloxGPS
This repo is a testing ground for building a system that logs data from a ubloxGPS receiver.

The approximate links in the chain are as follows:
1. ubloxGPS antenna connects to ublox ZED-F9P PCB via SMA-U.FL connector
2. ublox PCD connects via I2C serial to Arduino (later this is replaced by Jetson?)
3. Arduino uses the pre-made ublox-sparkfun-GNSS toolbox/functions to parse the data
4. Arduino connects to Jetson via USB to the Jetson
5. python script on the Jetson logs the GPS data

## Useful Links
Arduino I2C serial comms https://docs.arduino.cc/learn/communication/wire



### serial_console_test.ino
This is a basic arduino script that requires no wiring (except for connecting the arduino via USB to computer). Simply pushing that file to the arduino causes the arduino to send fake data over the serial connection (from the USB), which can be viewed by the serial monitor in the arduino IDE.

To run:
1. push the code to the arduino using the arduino IDE
2. open the serial monitor

### serial_python_test.ino with serial_python_test.py
This script also does not require any wiring (except for USB connection) and instead of the arduino IDE serial monitor to view the data being transmitted, a python script is used to read the data of the serial USB connection and logs it into a .csv.

To run:
1. push the code to the arduino using the arduino IDE
2. run the python script (if WIN command prompt --> navigate to the location of the script, then type the name of the script and hit 'enter')
3. ctrl+c to stop the python logging script


