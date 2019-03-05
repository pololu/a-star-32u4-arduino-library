# AStar32U4 library

Version: 1.1.0<br/>
Release date: 2019-03-05<br/>
[![Build Status](https://travis-ci.org/pololu/a-star-32u4-arduino-library.svg?branch=master)](https://travis-ci.org/pololu/a-star-32u4-arduino-library)<br/>
[www.pololu.com](http://www.pololu.com/)

## Summary

This is a C++ library for the Arduino IDE that helps access the on-board hardware of the [A-Star 32U4 controllers](http://www.pololu.com/category/149), which is a family of programmable controllers from Pololu based on the ATmega32U4. You can program an A-Star 32U4 directly from the Arduino IDE without using this library, but this library makes it easy to:

* display information on the LCD
* play sounds and music on the buzzer
* read the battery voltage level
* control the three user LEDs
* use the three user pushbuttons
* use the on-board motor drivers

(Not all of these features are available on every A-Star 32U4. For more information about each particular A-Star controller, please refer to their documentation and respective product pages.)

## Installing the library

If you are using version 1.6.2 or later of the [Arduino software (IDE)](http://www.arduino.cc/en/Main/Software), you can use the Library Manager to install this library:

1. In the Arduino IDE, open the "Sketch" menu, select "Include Library", then "Manage Libraries...".
2. Search for "AStar32U4".
3. Click the AStar32U4 entry in the list.
4. Click "Install".

If this does not work, you can manually install the library:

1. Download the [latest release archive from GitHub](https://github.com/pololu/a-star-32u4-arduino-library) and decompress it.
2. Rename the folder "a-star-32u4-arduino-library-master" to "AStar32U4".
3. Move the "AStar32U4" folder into the "libraries" directory inside your Arduino sketchbook directory.  You can view your sketchbook location by opening the "File" menu and selecting "Preferences" in the Arduino IDE.  If there is not already a "libraries" folder in that location, you should make the folder yourself.
4. After installing the library, restart the Arduino IDE.

## Examples

Several example sketches are available that show how to use the library.  You can access them from the Arduino IDE by opening the "File" menu, selecting "Examples", and then selecting "AStar32U4".  If you cannot find these examples, the library was probably installed incorrectly and you should retry the installation instructions above.

## Classes and functions

The main classes and functions provided by the library are listed below:

* AStar32U4ButtonA
* AStar32U4ButtonB
* AStar32U4ButtonC
* AStar32U4Buzzer
* AStar32U4LCD
* AStar32U4Motors
* ledGreen()
* ledRed()
* ledYellow()
* readBatteryMillivoltsLV4()
* readBatteryMillivoltsLV3()
* readBatteryMillivoltsSV()
* usbPowerPresent()

## Component libraries

This library also includes copies of several other Arduino libraries inside it which are used to help implement the classes and functions above:

* [FastGPIO](https://github.com/pololu/fastgpio-arduino)
* [PololuBuzzer](https://github.com/pololu/pololu-buzzer-arduino)
* [PololuHD44780](https://github.com/pololu/pololu-hd44780-arduino)
* [Pushbutton](https://github.com/pololu/pushbutton-arduino)
* [USBPause](https://github.com/pololu/usb-pause-arduino)

The Pushbutton and FastGPIO libraries are generally useful and you might want to use them directly in your sketch.  You can use these libraries automatically without any extra installation steps and without needing to add any extra `#include` lines to your sketch.

You should avoid adding extra `#include` lines such as `#include <Pushbutton.h>` because then the Arduino IDE might try to use the standalone %Pushbutton library (if you previously installed it), and it would conflict with the copy of the Pushbutton code included in the AStar32U4 library.  The only `#include` line needed to access all features of this library is:

~~~{.cpp}
#include <AStar32U4.h>
~~~

## Documentation

For complete documentation, see
https://pololu.github.io/a-star-32u4-arduino-library.  If you are already on that page, then click on the links in the "Classes and functions" section above.

## Version history

* 1.1.0 (2019-03-05): Added `readBatteryMillivoltsLV4` and `readBatteryMillivoltsLV3` functions to support both A-Star 32U4 Prime LV (ac03e) and existing LV A-Stars. Deprecated `readBatteryMillivoltsLV`.
* 1.0.5 (2016-10-12): Fixed a bug that caused the buzzer's `isPlaying` method to malfunction sometimes when link time optimization is enabled.
* 1.0.4 (2016-04-06): Fixed PrimeDemo and Keyboard examples so they can compile with the latest version of the Arduino IDE (1.6.8).
* 1.0.3 (2015-09-15): Fixed PrimeDemo example to display >4GB SD card capacity correctly.
* 1.0.2 (2015-08-31): Renamed Demo example to PrimeDemo and updated comments in examples.
* 1.0.1 (2015-08-13): Corrected commented motor flip code in Motors example.
* 1.0.0 (2015-08-06): Original release, adapted from version 1.1.2 of AStar32U4Prime library in a-star repository.
