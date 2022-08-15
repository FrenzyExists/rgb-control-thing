# IR controlled RGB light

Yeah as simple as you can get. Currently can change to a bunch of colors, and includes two timers to set the light off and lights can dim by using a counter.

### Challenges

For this project I used the IR library, which allows you to read or send IR signals under many different protocols. Because of some reason I would never understand, the IR library messes up the analogWrite function, specifically if one of the three outputs are not 255, 0, or 125. When I did, the program deadlocks itself or the NEC protocol changes completely to some random unknown protocol, so I had to use a counter to get it working.
