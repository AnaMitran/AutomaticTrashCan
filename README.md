# AutomaticTrashCan
using Arduino, OpenCV, Python and WebCam for Face Detection

## Description of the proposed solution
The proposed solution is one of automation. Basically, we start with a basket
classic garbage, but which has 2 compartments, one for each category of
materials: a compartment for plastic and household waste (for example).
In the proposed solution, as can be seen, the responsibility of identification and
sorting materials is up to the user. Ultrasonic sensors will be installed
to detect the distance to each compartment of the basket. Into the
the moment the sensor detects the presence of a person or object
at a sufficiently small distance and the camera identifies the user as a
person, the basket lid will be opened by a servomotor. Into the
as a result of moving away from the sensor or not identifying a person's face after a
shortly after, the lid will be closed again.

## Description of the implemented solution with the presentation of the functionalities
related to the solution
Materials used in the manufacture of the dispenser:
- Arduino UNO board
- 2 HC-SR04 ultrasonic distance sensors for front distance detection
from the trash can
- 2 90 degree servomotors
- USB cable to power the board
- 2 cardboard boxes for trash cans
- A breadboard
- Fire breadboard
- an LED and a 220Ω resistor for troubleshooting
- Additional materials: cardboard, glue, scotch tape, integrated functional camera
laptop

## Tinkercad

![image](https://user-images.githubusercontent.com/89164540/157997098-a5f6e114-3ff1-4e60-9824-b54b488fc991.png)

* The button used instead of face detection triggering

![image](https://user-images.githubusercontent.com/89164540/157997110-0d5614fb-8b0a-4c0b-bd05-837e74dbc413.png)

## Testing the solution
Is used:
- Arduino IDE
- Python IDE (example: Visual Studio Code)
- Command Prompt and Anaconda Prompt
- OpenCV / OpenCV3

Face detection (webcam_cv3.py)
The Command Prompt is running:
python webcam_cv3.py haarcascade_frontalface_default.xml

The built-in webcam and a special window called "Video" open. Into the
the capture data / coordinates are saved in the .xml file. And in the file
"Webcam.txt" also shows the date and time when a face was detected.

The letter "H" is saved in the "file.txt" file when it is identified
one side in the frame, otherwise it is overwritten and the file is empty. Based on this we can
make decisions in .py file to connect to arduino.

## Connecting to the arduino via python (arduino_python_connection.py)
Runs in the Python IDE and can be seen in the terminal (“on…” /
“Off…”).

![image](https://user-images.githubusercontent.com/89164540/157997190-e7aaf1a9-64f9-4a24-86d5-555e38ff1b9e.png)

![image](https://user-images.githubusercontent.com/89164540/157997197-e0075c7f-56f0-470f-9b66-2f236be5871a.png)

## Arduino code (smart_bin_with_webcam.ino)
Here the data from the ultrasonic sensors are read and processed. The information is taken over
from “arduino_python_connection.py” and the servomotors are operated in
consequence.

## Overall testing
Testing the solution is as follows: after loading the code from the Arduino
IDE on Arduino board, I waited a few seconds for it
configure all items. After compiling the code, the person will
it must be positioned in front of the camera and will be able to test the sensors by proximity
of these, following which the servomotors will open the compartments one by one.

![image](https://user-images.githubusercontent.com/89164540/157997203-d66039ca-41d9-443e-9f0c-f48abd61a4cf.png)

If we approach an object at a distance of less than 30 cm from the second
sensor, I set the LED on the left of the image to light up (implementation of
troubleshooting - check if the sensor and distance calculation work
appropriate), but if a person's face is not recognized by
room, basket 2 (black) does not open:

![image](https://user-images.githubusercontent.com/89164540/157997209-c11c5ce7-eabb-4095-97f2-1b853aa1edf1.png)

When the camera also identifies a person, the lid of the basket is
raised by servomotor:

![image](https://user-images.githubusercontent.com/89164540/157997213-c1c36410-12db-4acb-bb82-203fc88b4662.png)

Important references:
https://pythonforundergradengineers.com/python-arduino-LED.html
https://realpython.com/face-detection-in-python-using-a-webcam/
