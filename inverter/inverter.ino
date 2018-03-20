#include "lookupTable_SINE.h"


HardwareTimer timerFour(4); //timerfour will generate the Carrier of 20KHz, i.e 50us
HardwareTimer timerThree(3);
int ovf4;
void setupTimers()
{
    //for timer 4, having PWM on PB6:8
    //this sets timerFour with a 20KHz frequency and 1200 overflow

    ovf4 = timerFour.setPeriod(50); //set timer period in microseconds
    timerFour.setOverflow(1200);
    timerFour.setPrescaleFactor(3);

    ovf4 = timerFour.getOverflow();
    //timerfour setup complete
    //the duty cycle will be updated on the compare match interrupt of the specific phase channel
    timerThree.setPeriod(25);
    timerThree.setChannel1Mode(TIMER_OUTPUT_COMPARE);
    timerThree.setCompare(TIMER_CH1, timerThree.getOverflow());  // Interrupt 1 count after each update
    timerThree.attachCompare1Interrupt(load_from_table);
    
    timerFour.refresh();
    timerThree.refresh();
}
unsigned int positionInarray=0;

void load_from_table(){
    pwmWrite(PB6, sineLookup[positionInarray] );
    positionInarray++;

}
void setup()
{
    Serial.begin();

    setupTimers();

    pinMode(PB6, PWM);
    pwmWrite(PB6, ovf4 / 2);
    while (!Serial)
        ;
    
}
void loop()
{
    Serial.println(ovf4);
    delay(100);
}