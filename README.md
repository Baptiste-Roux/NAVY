# NAVY

###### EPITECH PROJECT
With this game in C, you will be able to play the rules and concepts of the famous game Battleship, directly in the terminal.

The two players (terminals) are communicating with signals (SIGUSR1 and SIGUSR2).
With a 8x8 map, you're able to create your own gameplay.
 

### USE :

Create or use a positions file, (you have an example with this repo : pos1 and pos2) with the length of the ships, and their coordinates. In turn, give the position you want to shoot and have an overview at the end of each turn on the maps.

Good luck, do not have seasickness ! ;)

**PLAYER ONE START**
```
~/B-PSU-200> make
~/B-PSU-200> ./navy [file]
my_pid: [xxx]
waiting for enemy connection...

enemy connected
 ```
**PLAYER TWO START**
```
~/B-PSU-200> make
~/B-PSU-200> ./navy [player one PID] [file]
my_pid: [xxx]
successfully connected
```
