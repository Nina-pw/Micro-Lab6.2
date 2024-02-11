#define tran 33
#define Button 25
hw_timer_t *My_timer = NULL;
bool check = true;
double acc = 1;
// This is the Timer ISR. It is automatically called
// on a timer alarm event.
void IRAM_ATTR onTimer(){
  if(check) digitalWrite(tran, !digitalRead(tran));
  else digitalWrite(tran, LOW);
}
void IRAM_ATTR IO_INT_ISR(){
  acc = acc*1.5;
  if(acc > 6) {
    acc = 1;
  }
}


void setup() {
  pinMode(tran, OUTPUT);
  pinMode(Button, INPUT);
 My_timer = timerBegin(0, 80, true);  // use tiemr 0 and set prescale to 80 so 1 tick is 1 uSec
  timerAttachInterrupt(My_timer, &onTimer, true); // point to the ISR  // set alarm every 1 sec
  timerAlarmWrite(My_timer, 1000000, true);
  timerAlarmEnable(My_timer);  // enable the alarm
  attachInterrupt(Button, IO_INT_ISR, RISING);
}

void loop() {
  if(digitalRead(Button) == HIGH){
    IO_INT_ISR(); 
  }
  check = true;
  timerAlarmWrite(My_timer, 1000000/(1319*2), true);
  delay(200*acc);
  timerAlarmWrite(My_timer, 1000000/(1397*2), true);
  delay(200*acc);
  timerAlarmWrite(My_timer, 1000000/(1568*2), true);
  delay(300*acc);
  timerAlarmWrite(My_timer, 1000000/(1568*2), true);
  delay(300*acc);
  check = false;
  delay(300);
  check = true;
  timerAlarmWrite(My_timer, 1000000/(1175*2), true);
  delay(200*acc);
  check = false;
  delay(100);
  check = true;
  timerAlarmWrite(My_timer, 1000000/(1175*2), true);
  delay(200*acc);
  timerAlarmWrite(My_timer, 1000000/(1760*2), true);
  delay(300*acc);
  timerAlarmWrite(My_timer, 1000000/(1760*2), true);
  delay(300*acc);
  check = false;
  delay(300);
  check = true;

  timerAlarmWrite(My_timer, 1000000/(1568*2), true);
  delay(200*acc);
  timerAlarmWrite(My_timer, 1000000/(1319*2), true);
  delay(100*acc);
  check = false;
  delay(100);
  check = true;
  timerAlarmWrite(My_timer, 1000000/(1319*2), true);
  delay(100*acc);
  check = false;
  delay(100);
  check = true;
  timerAlarmWrite(My_timer, 1000000/(1319*2), true);
  delay(100*acc);
  check = false;
  delay(100);
  check = true;
  timerAlarmWrite(My_timer, 1000000/(1319*2), true);
  delay(100*acc);
  timerAlarmWrite(My_timer, 1000000/(1397*2), true);
  delay(100*acc);
  check = false;
  delay(100);
  check = true;
  timerAlarmWrite(My_timer, 1000000/(1568*2), true);
  delay(300*acc);
  check = false;
  delay(1500);
  if(digitalRead(Button) == HIGH){
    IO_INT_ISR(); 
  }
}