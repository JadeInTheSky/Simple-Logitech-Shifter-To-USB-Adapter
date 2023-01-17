
# Simple Logitech Shifter to USB adapter

This project consist on making the logitech shifter into a standalone USB Gamepad using the ArduinoJoystickLibrary by MHeironimus. 

In itself, the logitech shifter use a XY plane (0-1000) to know what gear you are into using threshold. I redid the hole process to make it work without the wheelbase.



## What you should already have

* 1x Arduino Leonardo (or any atmega32u4 based arduino)
* 1x Male DB9 Port
* Wires
* Soldering material


## What you should already know

* How to solder
* How to setup the Arduino on VSCODE using [platformIO](https://www.youtube.com/watch?v=dany7ae_0ks&t=280s) / or by using the Arduino IDE
* How to use your brain

## Requirements
* Joystick Library: [MHeironimus/ArduinoJoystickLibrary](https://github.com/MHeironimus/ArduinoJoystickLibrary)
## Diagrams
![Leonardo-x-DB9](https://github.com/JadeInTheSky/Logitech-Shifter-2-USB/blob/main/Leonardo_DB9_Chart.png?raw=true)
## Programming (Visual Studio Code)

1. Open cloned repo in vscode
2. Open PlatformIO home via the extension shortcut
3. Add existing project -> select repo directory
4. (OPTIONAL) change the board configuration to match what you already have
5. Upload to board
## Programming (Arduino IDE)
Soon....
## Troubleshooting
Soon...
## Issues?
You are having issue with my code? Do not hesitate to open an Issue ticket. 

I'm not a messiah, only a normal human being. Make sure to clearly state your issues so I'll be able to help you the best I can.