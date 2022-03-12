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

## Schema Tinkercad

! [image] (https://user-images.githubusercontent.com/89164540/157996785-c6916246-6f61-41e9-b598-3f6cadd2999b.png)

* The button takes the place of the camera

! [image] (https://user-images.githubusercontent.com/89164540/157996829-621157ac-39b3-4607-a1d0-6233c5b58e02.png)

## Testing the solution
Is used:
● Arduino IDE
● Python IDE (example: Visual Studio Code)
● Command Prompt and Anaconda Prompt
● OpenCV / OpenCV3

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

! [image] (https://user-images.githubusercontent.com/89164540/157996895-1fd72315-4aa5-4611-9a4e-12ba2aa39f84.png)

! [image] (https://user-images.githubusercontent.com/89164540/157996906-4cd99dcc-0be5-4086-8064-1edf16ba45c4.png)

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

! [image] (https://user-images.githubusercontent.com/89164540/157996971-7ed36333-8b1d-4140-a703-76c9885a35ee.png)

If we approach an object at a distance of less than 30 cm from the second
sensor, I set the LED on the left of the image to light up (implementation of
troubleshooting - check if the sensor and distance calculation work
appropriate), but if a person's face is not recognized by
room, basket 2 (black) does not open:

! [image] (https://user-images.githubusercontent.com/89164540/157996986-8268f418-bdaa-41ec-9426-306eb8d922c4.png)

When the camera also identifies a person, the lid of the basket is
raised by servomotor:

! [image] (https://user-images.githubusercontent.com/89164540/157996998-34ac8824-3092-44f0-a7df-6b89d02af66e.png)

Important references:
https://pythonforundergradengineers.com/python-arduino-LED.html
https://realpython.com/face-detection-in-python-using-a-webcam/
