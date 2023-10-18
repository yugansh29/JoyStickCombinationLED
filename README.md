# JoyStickCombinationLED
It is a basic implementation of a simple security system. It reads input from the X and Y axes and checks if a predefined password sequence (in this case, a series of sensor readings) matches the input from the sensors. If there's a match, it activates an LED.

# Working 
  Variable Declarations:
        X_pin and Y_pin are defined as the analog pins connected to X and Y outputs, respectively.
        An integer array Read of size 4 is declared to store sensor readings.
        Pointers head and tail are initialized to the Read array for managing the data.
        ctr is used to keep track of the number of elements in the queue.
        pass is an array containing a predefined password sequence for comparison.
        LED is defined as pin 13 for controlling an LED.

   Setup Function:
        Sets up the SW_pin as an input and configures it with an internal pull-up resistor.
        Initializes serial communication at a baud rate of 115,200.
        Sets the LED pin as an output.

  Queue Functions:
        enqueue adds a value to the queue by updating the tail pointer and incrementing ctr.
        dequeue retrieves and removes a value from the queue, updating the head pointer and decrementing ctr.
        resetQueue resets the queue by moving the head and tail pointers back by four positions.

   Loop Function:
        Continuously reads the state of SW_pin and the X and Y analog pins (A0 and A1).
        Enqueues values (1 or -1 for X, 2 or -2 for Y) into the queue based on the analog readings from X_pin and Y_pin.
        Checks if the queue contains four elements (ctr == 4) and, if so, compares the values in the queue with the predefined pass array. If they match, it turns on the LED at pin 13 (digitalWrite(13, HIGH)) and then resets the queue.
