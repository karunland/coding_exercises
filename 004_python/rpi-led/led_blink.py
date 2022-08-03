# import RPi.GPIO as GPIO # Import Raspberry Pi GPIO library
# from time import sleep # Import the sleep function from the time module
# GPIO.setwarnings(False) # Ignore warning for now
# GPIO.setmode(GPIO.BOARD) # Use physical pin numbering
# GPIO.setup(23, GPIO.OUT, initial=GPIO.LOW) # Set pin 8 to be an output pin and set initial value to low (off)
# while True: # Run forever
# 	GPIO.output(23, GPIO.HIGH) # Turn on
# 	sleep(1) # Sleep for 1 second
# 	GPIO.output(23, GPIO.LOW) # Turn off
# 	sleep(1) # Sleep for 1 second


import RPi.GPIO as GPIO
import time
import sys

Red_PIN = 23
White_PIN = 24

state = False


def gpio_init():
    GPIO.setwarnings(False)
    GPIO.setmode(GPIO.BCM)
    GPIO.setup(White_PIN, GPIO.OUT, initial=False)
    GPIO.setup(Red_PIN, GPIO.OUT, initial=False)

    state = True


def main():
    # pin 23 red light
    # pin 24 white light
    gpio_init()
    # endless loop, on/off for 1 second
    while True:
        # GPIO.output(White_PIN, True)
        # GPIO.output(Red_PIN, False)
        time.sleep(1)
        GPIO.output(White_PIN, False)
        # GPIO.output(Red_PIN, True)
        time.sleep(1)


def red_on():
    GPIO.output(Red_PIN, 0)


def red_off():
    GPIO.output(Red_PIN, 1)


def white_off():
    GPIO.output(White_PIN, 1)


def white_on():
    GPIO.output(White_PIN, 0)


if __name__ == '__main__':

    if not state:
        gpio_init()
# size of args
    if len(sys.argv) < 3:
        print("Usage: python3 led_blink.py --on/off [red|white]")
        # sys.exit(1)

    else:
        if sys.argv[1] == "--on":
            if sys.argv[2] == "red":
                print("red on")
                red_on()
            elif sys.argv[2] == "white":
                print("white on")
                white_on()
            else:
                print("Usage: python3 led_blink.py --on/off [red|white]")
                sys.exit(1)
        elif sys.argv[1] == "--off":
            if sys.argv[2] == "red":
                print("red off")
                red_off()
            elif sys.argv[2] == "white":
                print("white off")
                white_off()
            else:
                print("Usage: python3 led_blink.py --on/off [red|white]")
                sys.exit(1)

        sys.exit(0)
