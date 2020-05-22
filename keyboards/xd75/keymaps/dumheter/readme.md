# Swedish keymap for XD75 with LED controls

## Build & Flash
To build and flash the keyboard, run:

```
sudo make xd75:dumheter:dfu
```
It will then enter the flashing stage, saying "no device present". This is where you reset the keyboard, then it should automatically flash.

## Deps
sudo apt install gcc-avr avr-libc dfu-programmer
