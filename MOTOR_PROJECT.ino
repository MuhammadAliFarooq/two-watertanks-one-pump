

#include <DS1302.h>
const int floatswitch_upstairs = 51;
const int floatswitch_downstairs = 53;
const int valve_switch_clockwise = 31;
const int valve_switch_anticlockwise = 33;
const int motor_pump_upstairs = 35;
const int motor_pump_downstairs = 37;



DS1302 rtc(5, 6, 7);
 
void setup()
{
  
  rtc.halt(false);
  rtc.writeProtect(false);
  
  
  Serial.begin(9600);

  
  //rtc.setDOW(FRIDAY);        //Set Day-Of-Week
  rtc.setTime(05, 07, 45);   //Set Time in 24-hour Format
  //rtc.setDate(8, 7, 2020);   
}

void loop()
{
 int Float_Switch = 53;
 pinMode(Float_Switch,INPUT);


 String T = rtc.getTimeStr(FORMAT_SHORT);           //Recieve time string
 String t = "xx";                        
 t.setCharAt(0,T.charAt(3));                        //Extract hours string
 t.setCharAt(1,T.charAt(4));
 int h = t.toInt();                                 //Convert hours string to integer

  while(6< h < 8){                                  //while loop to control time


   String T = rtc.getTimeStr(FORMAT_SHORT); 
   String t = "xx";
   t.setCharAt(0,T.charAt(3));
   t.setCharAt(1,T.charAt(4));
   h = t.toInt();
     if(h < 4){
        break;
     }
     if(h > 14) {
        break;
       }
     
 
    //Serial.print(m);
    //delay(15000);
   }
  
digitalRead(floatswitch_upstairs);                      
if ( digitalRead(floatswitch_upstairs) == HIGH){
  
  digitalWrite(valve_switch_anticlockwise, HIGH);
  delay(15000);
  digitalWrite(valve_switch_anticlockwise, LOW);
   
    while (digitalRead(floatswitch_upstairs) == HIGH){
      
      digitalWrite(motor_pump_upstairs,HIGH);
      delay(350000);
      digitalRead(floatswitch_upstairs);} 
  
  digitalWrite(motor_pump_downstairs, LOW);    
  digitalWrite(valve_switch_clockwise, HIGH);
  delay(15000);
  digitalWrite(valve_switch_clockwise, LOW);
      }

digitalRead(floatswitch_downstairs);
if ( digitalRead(floatswitch_downstairs) == HIGH){      
  
  while (digitalRead(floatswitch_downstairs) == HIGH){
      
      digitalWrite(motor_pump_downstairs,HIGH);
      delay(350000);
      digitalRead(floatswitch_downstairs);} 
}

  digitalWrite(motor_pump_downstairs, LOW);
}
