# IR controlled RGB light

Yeah as simple as you can get. Currently can change to a bunch of colors, and includes two timers to set the light off. Also light can finally dim yay

### Current Problems that smol brain can't figure out

#### Can't do rgb fade

So for some reason I can't make the rgb fade. From what I tested, because of the IR library I'm using, only 1 out of the 3 rgb pins can have their color in a constant change, if you try to otherwise change it well, you sort of deadlock yourself. the program can't detect NEC protocol (which is what my little i-Zoom controller uses) and sets it to UNKNOWN, and to top it off, the decoded signal changes entirely. The other prob I have is that once I somehow manage to get the rgb doing its thing, i can't stop it. So now I'm going into event programming extravaganza in hopes that by changing paradigms i could get the damn thing workingßß