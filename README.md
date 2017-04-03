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

After tinning the wires, trim them as short as possible to solder onto the existing
solder pads of the circuit board.
![006](https://raw.github.com/zortness/arduino-dance-pad/master/img/006.png)

First two button leads soldered.
![007](https://raw.github.com/zortness/arduino-dance-pad/master/img/007.png)

All done soldering onto the existing PCB.
![008](https://raw.github.com/zortness/arduino-dance-pad/master/img/008.png)

Wiring up the Arduino on a solderless breadboard. The pins and wires just push into
the holes. Positive and negative channels run the whole vertical length of the board.
The numbered rows run horizontally toward the middle, but the two sides are split at
the middle. **Note: the wires in the top half of this picture are in the wrong
slots, I was looking at the incorrect pinout diagram for the Arduino Micro.**
![009](https://raw.github.com/zortness/arduino-dance-pad/master/img/009.png)

First pass at what it looks like while connected. The wires are still not in the
correct places on the top half of the breadboard. It took me a few tries to figure
that out.
![010](https://raw.github.com/zortness/arduino-dance-pad/master/img/010.png)

Starting work on the programming while my kids are eating lunch. Note the outdated 
pinout diagram. The correct one is actually 
[here](https://www.arduino.cc/en/uploads/Main/ArduinoMicro_Pinout3.png).
![012](https://raw.github.com/zortness/arduino-dance-pad/master/img/012.png)

I think the whole thing is working at this point. I can read the keyboard inputs
on the laptop for all 10 buttons.
![013](https://raw.github.com/zortness/arduino-dance-pad/master/img/013.png)

Testing! It's alliiiiive. I actually had one bug in the first pass of the code
that caused the left pad output to stick, but found that pretty quickly during
testing.
![014](https://raw.github.com/zortness/arduino-dance-pad/master/img/014.png)

Ok, now let's make this a little more durable. After all, I have two small children
who want to play with this thing. I'm going to use an Adafruit Perma-Proto board. 
One which I previously took a chunk from. I could actually just use it in the other
direction without an issue, but the first 3 pins on either side are unused in my 
final layout, and numbering makes it easier to transfer from the breadboard. I'm
using a Panavise to hold the board while soldering.
![015](https://raw.github.com/zortness/arduino-dance-pad/master/img/015.png)

Lining up the Arduino with some female header pins (these are actually extra long
for building stackable boards, which we are not doing in this case). These type
of connectors mean I don't have to permanently solder my Arduino to the board.
You can use the Arduino to hold the pins in the correct orientation, as long as 
you solder quickly and don't get them too hot.
![016](https://raw.github.com/zortness/arduino-dance-pad/master/img/016.png)

Female pins soldered on.
![018](https://raw.github.com/zortness/arduino-dance-pad/master/img/018.png)

All wires soldered in.
![019](https://raw.github.com/zortness/arduino-dance-pad/master/img/019.png)

The backside with the wires and pins sticking through. I cut these down with some
flat wire-cutters to keep them from touching anything and shorting out (at least
after the board is mounted somewhere relatively safe).
![020](https://raw.github.com/zortness/arduino-dance-pad/master/img/020.png)

Top side. All wires in their final places.
![021](https://raw.github.com/zortness/arduino-dance-pad/master/img/021.png)

Here it is, mounted somewhere relatively safe (with a self tapping screw onto the
original plastic housing). It's not pretty, but much more durable than with the
solderless breadboard. 
![022](https://raw.github.com/zortness/arduino-dance-pad/master/img/022.png)

For the next phase, if you really wanted to go crazy, you could get a 
[ATMega32u4 breakout board](https://www.adafruit.com/products/296)
or something a bit smaller, and solder it up permanently in a configuration that
would fit inside of the original plastic housing. I, however, stopped my build
at this point (at least for now).
