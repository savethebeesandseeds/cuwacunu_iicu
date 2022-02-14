# Joystick support is enabled

Make sure your computer recognizes the device: 
    (Linux):
        lsusb : the device must be found here (even when nothing is installed yet)
        Install joystick for Linux.
            (fedora) dnf install joystick
            (ubuntu) apt-get install joystick
        cd /dev/input/ : must found jsX : input device
        test with:
            jstest /dev/input/js0
        A util terminal command is xev, but this is shows not the controller 
    (Windows)
        Install drivers for Windows...
        Test device...

# Fonts
Find more fonts at:
    https://fonts.google.com/