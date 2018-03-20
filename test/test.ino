

HardwareTimer timerFour(4);//timerfour will generate the Carrier of 20KHz, i.e 50us
HardwareTimer timerThree(3);
// void setupTimers(){
    // timerFour.setPeriod();
// }
int ovf;
void setup(){
    Serial.begin();
    
    ovf=timerFour.setPeriod(50);//set timer period in microseconds
    timerFour.setOverflow(1200);
    timerFour.setPrescaleFactor(3);
    timerFour.refresh();
    ovf=timerFour.getOverflow();
    pinMode(PB6,PWM);
    pwmWrite(PB6,ovf/2);
    while(!Serial);
}
void loop(){
    Serial.println(ovf);
    delay(100);
}