/*==============================================================================
 Project: Intro-1-Input-Output
 Date:    March 1, 2022
 
 This example UBMP4.1 input and output program demonstrates pushbutton input,
 LED (bit) output, port latch (byte) output, time delay functions, and simple
 'if' condition structures.
 
 Additional program analysis and programming activities demonstrate byte output,
 logical condition operators AND and OR, using delay functions to create sound,
 and simulated start-stop button functionality.
==============================================================================*/

#include    "xc.h"              // Microchip XC8 compiler include file
#include    "stdint.h"          // Include integer definitions
#include    "stdbool.h"         // Include Boolean (true/false) definitions

#include    "UBMP410.h"         // Include UBMP4.1 constant and function definitions

// TODO Set linker ROM ranges to 'default,-0-7FF' under "Memory model" pull-down.
// TODO Set linker code offset to '800' under "Additional options" pull-down.

// The main function is required, and the program begins executing from here.

int main(void)
{
    // Configure oscillator and I/O ports. These functions run once at start-up.
    OSC_config();               // Configure internal oscillator for 48 MHz
    UBMP4_config();             // Configure on-board UBMP4 I/O devices
	
    // Code in this while loop runs repeatedly.
    while(1)
	{
        if(SW4 == 0)
        {
            LED1 = 0;
            __delay_ms(100);
            LED1 = 1;
            __delay_ms(100);
        }  

        // If SW2 is pressed, make a flashy light pattern
                                                                                                                                         


        // Add code for your Program Analysis and Programming Activities here:
       // Nested if 'AND' code
        
        // Activate bootloader if SW1 is pressed.
        if(SW1 == 0)
        {
            RESET();
        }
    }
}

/* Learn More - Program Analysis Activities
 *  
 * 1. How many times do the LEDs flash if SW2 is quickly pressed and released?
 *    Do the LEDs keep flashing when SW2 is held? Look at the program and
 *    explain why this happens when SW2 is held.
 * the LEDs will repeat the same patern aslong as SW2 is held
 * 
 * 2. Explain the difference between the statements: LED3 = 0; and LED3 = 1;
 *  1 is on and 0 is off
 * 
 * 3. What voltage do you expect the microcontroller to output to LED D3 when
 *    the statement LED3 = 0; runs? What voltage do you expect the output to be
 *    when the statement LED3 = 1; runs?
 * 
 *    You can confirm the output voltage with a voltmeter if you have access
 *    to one. If you tried that, did the voltage match your prediction?
 * 
 * 4. The statement 'if(SW2 == 0)' uses two equal signs, while the statement
 *    'LED3 = 1;' uses a single equal sign. What operation is performed by one
 *    equal sign? What operation is performed by two equal signs?
 * two equal signs means equal to and one assins somthing 
 *  
 * 5. The following program code includes instructions that write to the PORTC
 *    output latches directly. Try it by copying and pasting this code below
 *    the existing SW2 'if' structure, at the location shown by the comment.

        if(SW3 == 0)
        {
            LATC = 0b00000000;
            __delay_ms(100);
            LATC = 0b11110000;
            __delay_ms(100);
        }

 *    What happens when pushbutton SW3 is pressed? 
        all the LEDs stay on
      Identify at least one advantage and one disadvantage of controlling the LEDs using 'LATC' writes
 *    rather than through individual 'LEDn = x;' statements.
  it's more space effient 
 * 
 * 6. Next, compare the operation of 'if' and 'while' structures to simulate
 *    momentary buttons. Replace the code you added in 5, above, with this code:

        // Momentary button using if structure
        if(SW3 == 0)
                                                         {
            LED4 = 1;
        }
        else
        {
            LED4 = 0;
        }

        // Momentary button using while structure
        while(SW4 == 0)
        {
            LED5 = 1;
        }
        LED5 = 0;

 *    First, try pressing and releasing SW3 and SW4 one at a time.
 * 
 *    Next, press and hold SW3 while pressing and releasing SW4. Does it work
 *    as expected?
 * 
 *    Next, try press and holding SW4 while pressing and releasing SW3. Does it
 *    work as expected? Explain the difference in operation between the 'if' and
 *   an if statment checkes if something is true and dose an oporation 
 *   a while statment dose something well it's true 
 *    'while' structures making up the momentary button code.
 * 
 * 7. Let's explore logical conditions using 'if' statements. Replace the code
 *    added in 6, above, with this nested if code to make a logical AND
 *    condition that will light LED D4 only if both SW3 and SW4 are pressed:

        // Nested if 'AND' code
         if(SW3 == 0)
        {
            if(SW4 == 0)
            {
                LED4 = 1;
            }
            else
            {
                LED4 = 0;
            }
        }
        else
        {
            LED4 = 0;
        }

 *    Test the code to ensure it works as expected. Does the order of the if
 *    conditions matter? (eg. swap the conditional checks for SW3 and SW4)
 * both sw3 and sw4 have to be on for led4 to be on 
 * 
 * 8. Next, replace the code from 7 with the following code which implements a
 *    logical AND conditional operator composed of two ampersands '&&':
 
        // Conditional 'AND' code
        if(SW3 == 0 && SW4 == 0)
        {
            LED4 = 1;
        }
        else
        {
            LED4 = 0;
        }

 *    Does '&&' work the same way as the nested if structures? Can you think of
 *    at least one advantage of using a logical conditional operator instead of
 *    nested if structures?
 *      it works the same as the code in 7 and && is uses less memory then two if stements 
 * 9. Replace the double ampersand '&&' with double vertical bars '||)' to make
 *    a logical OR conditional operator. Your code should look like this:
  
        // Conditional 'OR' code
        if(SW3 == 0 || SW4 == 0)
        {
            LED4 = 1;
        }
        else
        {
            LED4 = 0;
        }

 *    Describe the conditions under which LED4 turns on.
 *      led4 turns on if sw3 or 4 is pushed 
 * 
 * Programming Activities
 * 
 * 1. The statement '__delay_ms(100);' creates a 100ms delay. Try changing one
 *    or more of the delay values in the program to 500ms and see what happens.
 * 
 *    Can the delay be made even longer? Try 1000 ms. How big can the delay be
 *    before MPLAB-X produces an error message? (Hint: can you think of a fast
 *    and efficient way of guessing an unknown number?)
 *  you can use a number bigger then the 32bit integer or you can just hold your 9 key
 * 2. The '__delay_ms();' function only accepts integers as delay values. To
 *    make delays shorter than 1ms, specify a delay in microseconds using the
 *    '__delay_us();' function. You won't be able to see such short LED flashes
 *    with your eyes, but you could measure them using an oscilloscope, or hear
 *    them if they are used to turn the piezo beeper on and off. Try this code:
 
        // Make a tone while SW5 is held
        if(SW5 == 0)
        {
            BEEPER = 1;
            __delay_us(567);
            BEEPER = 0;
            __delay_us(567);
        }

 *    Try changing the delay values in both of the __delay_us(); functions.
 *    Does the pitch of the tone increase or decrease if the delay value is
 *    made smaller?
 * 
 * 3. This code demonstrates a more compact way of toggling the beeper output
 *    using a logical NOT operator '!'. Replace the code above, with this code:
 
        // Make a tone while SW5 is held
        if(SW5 == 0)
        {
            BEEPER = !BEEPER;
            __delay_us(567);
        }

 *    One difference between this code and the code in 2, above, is the state
 *    of the BEEPER pin when SW5 is released. What state will the BEEPER output
 *    be in after this code runs? While one advantage of this method is smaller
 *    code, can you think of one or more disadvantages based on its output when
 *    the button is released?
 * 
 * 4. Using modified versions of the original SW2 'if' structure, create a
 *    program that makes a unique LED flashing pattern for each pushbutton.
 * 
 *     if(SW2 == 0)
        {
            LED3 = 1;
            __delay_ms(50);
            LED4 = 1;
            __delay_ms(100);
            LED5 = 1;
            __delay_ms(100);
            LED6 = 1;
            __delay_ms(100);
            LED3 = 1;
            __delay_ms(100);
            LED4 = 0;
            __delay_ms(100);
            LED5 = 0;
            __delay_ms(200);
            LED4 = 0;
            __delay_ms(100);
            LED3 = 1;
            __delay_ms(50);
            LED4 = 1;
            __delay_ms(100);
            LED5 = 1;
            __delay_ms(100);
            LED6 = 1;
            __delay_ms(100);
            LED3 = 0;
            __delay_ms(100);
            LED4 = 1;
            __delay_ms(100);
            LED5 = 0;
            __delay_ms(300);
            LED6 = 0;
            __delay_ms(100);
             LED4 = 0;
            __delay_ms(200);


            
        }
        
        if(SW3 == 0)
        {
            LED4 = 0;
            __delay_ms(100);
            LED5 = 1;
            __delay_ms(200);
            LED4 = 0;
            __delay_ms(100);
            LED3 = 1;
            __delay_ms(50);
            LED4 = 1;
            __delay_ms(100);
            LED5 = 0;
            __delay_ms(1);
        }

        if(SW4 == 0)
        {
            LED3 = 0;
            __delay_ms(100);
            LED4 = 0;
            __delay_ms(200);
            LED5 = 0;
            __delay_ms(400);
            LED6 = 0;
            __delay_ms(800);
            
            LED3 = 1;
            __delay_ms(100);
            LED4 = 1;
            __delay_ms(200);
            LED5 = 1;
            __delay_ms(400);
            LED6 = 1;
            __delay_ms(800);

        }

        if(SW5 == 0)
        {
            LED6 = 0;
            __delay_ms(50);
            LED4 = 0;
            __delay_ms(50);
            LED6 = 1;
            __delay_ms(50);
            LED4 = 1;
            __delay_ms(50);
            LED6 = 0;
            __delay_ms(50);
            LED4 = 0;
            __delay_ms(50);
            LED6 = 1;
            __delay_ms(50);
            LED4 = 1;
            __delay_ms(50);
            //2
            LED3 = 0;
            __delay_ms(50);
            LED5 = 0;
            __delay_ms(50);
            LED3 = 1;
            __delay_ms(50);
            LED5 = 1;
            __delay_ms(50);
            LED3 = 0;
            __delay_ms(50);
            LED5 = 0;
            __delay_ms(50);
            LED3 = 1;
            __delay_ms(50);
            LED5 = 1;
            __delay_ms(50);
        }

 *    Test each of your flashing patterns. Describe what happens when more than
 *    one button is held. Do all of the patterns try to flash the LEDs at the
 *    same time, or sequentially? Explain why this is.
 *   all the paterns start to play at onecs wich relsatl in most of the leds being off
 *                                         
 * 5. Create a program that makes a different tone for each pushbutton.
 *      if(SW5 == 0)
        {
            BEEPER = 1;
            __delay_us(345);
            BEEPER = 0;
            __delay_us(567);
        }

        if(SW4 == 0)
        {
            BEEPER = 1;
            __delay_us(873);
            BEEPER = 0;
            __delay_us(235);
        }

        if(SW3 == 0)
        {
            BEEPER = 1;
            __delay_us(567);
            BEEPER = 0;
            __delay_us(567);
        }

        if(SW2 == 0)
        {
            BEEPER = 1;
            __delay_us(432);
            BEEPER = 0;
            __delay_us(921);
        }      
 * 
 *    Test each tone by pressing each button individually. Next, press two or
 *    more buttons at the same time. Describe what the tone waveform would look
 *    like when more than one button is held.
 * 
 * 6. Use individual 'if' structures to simulate 'Start' and 'Stop' buttons for
 *    an industrial machine. LED D4 should turn on when SW3 is pressed, stay on
 *    even after SW3 is released, and turn off when SW4 is pressed. Test your
 *    program to make sure it works.
 *        if(SW5 == 0)
        {
           LED4 = 0;
           
        }

       if(SW4 == 0)
       {
           LED4 = 1;

       }     
 * 
 * 7. Running your program from 6, above, describe what happens when both SW3
 *    and SW4 are pressed. Does LED D4 stay on? If so, how does the brightness
 *    of LED D4 compare between its normal on state following SW3 being pressed
 *    to this new state when both SW3 and SW4 are bing held? Can you explain
 *    why it changes?
 *    the led stays on but it get's dimer
 * 
 * 8. As you can imagine, an industrial machine that is able to turn on even
 *    while its 'Stop' button is pressed represents a significant safety hazard.
 *    Using a logical conditional operator, modify the start-stop program from
 *    activity 5 to make it safer. SW3 should only turn on LED D4 if SW4 is
 *    released.
 *   if(SW4 == 0 && SW5 == 1)
        {
           LED4 = 0;
        }

        if(SW4 == 0)
        {
            LED4 = 1;

        }  

 * 9. LED D1 is normally used to indicate that a program is running, but it can
 *    be controlled by your program as well. If you take a look at the UBMP4
 *    schematic, you will see that LED D1's cathode (or negative) pin is
 *    connected to the microcontroller instead of the anode (positive) pin as
 *    with the other LEDs. This means that you need to make D1's output a zero
 *    to turn D1 on. Try it! Make a program that controls or flashes LED D1.
 *if(SW4 == 0)
        {
            LED1 = 0;
            __delay_ms(100);
            LED1 = 1;
            __delay_ms(100);
        }  
