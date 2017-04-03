# Arduino Dance Pad

This is a simple project where we recycled an old 3rd party GameCube 
Dance Pad to be re-used for the PC Game Stepmania.

The project involves an Arduino Micro, for the high count of ADC ports
and the USB HID capabilities, and some simple code. Also used were some
wires and a breadboard, a soldering iron, and eventually a perma-proto 
board and some female pins.

The pad itself consists of some 
[Force-Sensitive-Resistors](https://learn.adafruit.com/force-sensitive-resistor-fsr/using-an-fsr)
(or FSR's), and a small Analog-To-Digital IC that outputs to the GameCube
proprietary format. 

## The Code

The Arduino code is very simple. The only library we need to even import
is the standard Keyboard output functionality. Once the wires are connected
properly, the Arduino just reads from the ADC inputs, measures for changes,
keeps a state, and outputs key presses.

## The Build

For those that are new to DIY Electronics or Arduinos, this might be the more
interesting part of this project. Below is what we started with, a generic
3rd party thick-foamed dance pad. Although the pad itself is pretty simple, 
it actually contains 10 buttons.
![001](https://raw.github.com/zortness/arduino-dance-pad/master/img/001.png)

This is the top of the silicon board inside. You can see the FSB traces, which
are a conductive paint on two thin plastic sheets. The outer 10 being the returns
and the inner thick one being the source. There's a thin foam with holes in it 
between the two plastic sheets. When an area of the top plastic sheet touches
the bottom sheet through one of the holes in the foam, an electrical connection
is made. Because the conductive paint has some resistence built-in, the more 
connections are made (due to pushing harder), the more 'value' is read from
that area of the pad.
![002](https://raw.github.com/zortness/arduino-dance-pad/master/img/002.png)

Other things in the image above include capacitors (the orange circles and black/silver tube), 
a frequency crystal for the output to the GameCube (silver pill-shaped thing), 
a pull-down resister setup (top right 2 pills with stripes), and  power regulator 
(top right black cylinder with a bit missing).

Now, onto the more interesting side, the underside shows the traces and connection
points on the circuit board. The black IC at the middle is unlabelled, but must
include an ADC and some logic to output to whatever format the GameCube is expecting.
![003](https://raw.github.com/zortness/arduino-dance-pad/master/img/003.png)

I simply took advantage of the existing circuitry and decided to tap in at the most
logical points. The +5V power supply (red) and ground (white) are at the top (supplied from the
game console under normal circumstances). For the return leads, the most logical point
to tap in would be as close to the IC as possible along the path (marked in blue
for all 10 buttons).
![003 labeled](https://raw.github.com/zortness/arduino-dance-pad/master/img/003_mod.jpg)

Liberated from the plastic housing and original cable, time for some soldering...
![004](https://raw.github.com/zortness/arduino-dance-pad/master/img/004.png)

Power and ground already soldered. I'm also tinning the thin wires to make it much 
easier to solder them to the board AND easier to get them to stick into the 
breadboard. I used a short length of CAT5 cable, it's a cheap way to get lots of
high-grade small wiring (or I just had a huge box of it lying around). Here you
can also see the soldering iron, clippy helper thing, and wire strippers.
![005](https://raw.github.com/zortness/arduino-dance-pad/master/img/005.png)


