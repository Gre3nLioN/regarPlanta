/*
 * TimeAlarmExample.pde
 *
 * This example calls alarm functions at 8:30 am and at 5:45 pm (17:45)
 * and simulates turning lights on at night and off in the morning
 * A weekly timer is set for Saturdays at 8:30:30
 *
 * A timer is called every 15 seconds
 * Another timer is called once only after 10 seconds
 *
 * At startup the time is set to Jan 1 2011  8:29 am
 */
 
#include <Time.h>
#include <TimeAlarms.h>

int buzzer =9;
#define PIN_WATER 43

void setup()
{
  Serial.begin(9600);
  
  setTime(1,10,0,1,1,11); // set time to Saturday 8:29:00am Jan 1 2011
  // create the alarms 
  Alarm.alarmRepeat(8,30,0, MorningAlarm);  // 8:30am every day
  Alarm.alarmRepeat(8,31,0,CloseMorningAlarm);  // 5:45pm every day 
  
  Alarm.alarmRepeat(20,30,30, NightAlarm);  // 8:30am every day
  Alarm.alarmRepeat(20,31,0,CloseNightAlarm);  // 5:45pm every day 
 
  Alarm.timerRepeat(15, Repeats);            // timer for every 15 seconds    
  pinMode(PIN_WATER,OUTPUT);
  digitalWrite(PIN_WATER,LOW); 
}

void  loop(){  
  digitalClockDisplay();
  Alarm.delay(1000); // wait one second between clock display
}

// functions to be called when an alarm triggers:
void MorningAlarm(){
  Serial.println("Alarm: - turn lights off");   
  digitalWrite(PIN_WATER,HIGH); 
}

void CloseMorningAlarm(){
  Serial.println("Alarm: - turn lights on"); 
  digitalWrite(PIN_WATER,LOW);  
}

// functions to be called when an alarm triggers:
void NightAlarm(){
  Serial.println("Alarm: - turn lights off");   
  digitalWrite(PIN_WATER,HIGH);
}

void CloseNightAlarm(){
  Serial.println("Alarm: - turn lights on"); 
  digitalWrite(PIN_WATER,LOW);  
}


void Repeats(){
  Serial.println("15 second timer");    
  tone(buzzer, 50, 500);  
}

void digitalClockDisplay()
{
  // digital clock display of the time
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.println(); 
}

void printDigits(int digits)
{
  Serial.print(":");
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);
}

