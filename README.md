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

![image](https://user-images.githubusercontent.com/89164540/157997364-b25c58ac-02d8-4a38-a25e-adb268fd144a.png)

* The button used instead of face detection triggering

![image](https://user-images.githubusercontent.com/89164540/157997382-9955e2d8-2b9b-4106-819d-4430bc026d9b.png)

## Testing the solution
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

![image](https://user-images.githubusercontent.com/89164540/157997394-c193288f-a14e-4c46-9377-f0bdef74d2c3.png)

![image](https://user-images.githubusercontent.com/89164540/157997405-faf18489-9860-4ddd-afe3-cd16daa971d4.png)

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

![image](https://user-images.githubusercontent.com/89164540/157997420-17195f2c-189e-4a80-98a9-723a4465f3be.png)

If we approach an object at a distance of less than 30 cm from the second
sensor, I set the LED on the left of the image to light up (implementation of
troubleshooting - check if the sensor and distance calculation work
appropriate), but if a person's face is not recognized by
room, basket 2 (black) does not open:

![image](https://user-images.githubusercontent.com/89164540/157997429-2133e777-6044-4b1a-92d8-9c44e36c19af.png)

When the camera also identifies a person, the lid of the basket is
raised by servomotor:

![image](https://user-images.githubusercontent.com/89164540/157997441-57aa3374-6ec6-4726-871f-7ca6cfd337da.png)

Important references:
https://pythonforundergradengineers.com/python-arduino-LED.html

https://realpython.com/face-detection-in-python-using-a-webcam/
