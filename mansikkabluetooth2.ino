#include <SoftwareSerial.h>
int val; // variable to receive data from the serial port

int bluetoothTx = 14;
int bluetoothRx = 15;

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);




String inString = "";
String Remote = "b1";
String Moly = "b2";
String Puhallus ="b3";
int StringLength = inString.length();
int red = 9;
int green = 8;
int blue = 7;
int remote = 0;
int moly = 0;
int puhallus = 0;
int pir = 2;
int blow = 3;
int buzzer = 5;


void setup()
{
  //Setup usb serial connection to computer
  Serial3.begin(9600);

    pinMode(red, OUTPUT); 
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
   pinMode(blow, OUTPUT);
  pinMode(pir, INPUT);
  pinMode(buzzer, OUTPUT);
  
  digitalWrite(blow, HIGH);// setting pins default
  digitalWrite(red, LOW);
   digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
  digitalWrite(buzzer, LOW);

  


  //Setup Bluetooth serial connection to android
  bluetooth.begin(115200);
  bluetooth.print("$$$");
  delay(100);
  bluetooth.println("U,9600,N");
  bluetooth.begin(9600);
}

void loop() {
  // Read serial input:
  if (Serial3.available() > 0) {
    val = Serial3.read();
    inString += (char)val; 
  }
  
    
    
  if((inString == Remote) && (remote == 0)){               // Comapred string is with capital as opposed to integer
  int remote = 1;
  }
  else if(inString == Remote) {
 remote = 0;
  }
  
    if( (inString == Moly) && (moly == 0)){             
  int moly = 1;
  }
  else if((inString == Moly)) {
  int moly = 0;
  }
  
    if( (inString == Puhallus) && (puhallus == 0)){               
  puhallus = 1;
  }
  else if(inString == Puhallus) {
  int puhallus = 0;
  }
  val = 0;
  inString = "";

        if(remote == 1) {
        int liike = 0;
        liike = digitalRead(pir);   // read pir
          if(liike != 0) {
            if(moly == 1){

            digitalWrite(buzzer, HIGH);
            }
            else {
              digitalWrite(buzzer, LOW);
            }
              
              if(puhallus == 1) {
                digitalWrite(blow, LOW);
            }
            else {
              digitalWrite(blow, HIGH);
            }
                
        digitalWrite(red, LOW);
        digitalWrite(green, HIGH);
        digitalWrite(blue, HIGH);
     //digitalWrite(blow, LOW); // relay logic is pin low turns device on
delay(100);
 digitalWrite(red, HIGH);
   digitalWrite(green, LOW);
    digitalWrite(blue, HIGH);
    delay(100);
     digitalWrite(red, HIGH);
   digitalWrite(green, HIGH);
    digitalWrite(blue, LOW);
    delay(100);

 
   
 }
 else{
      digitalWrite(red, LOW);
   digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
    digitalWrite(blow, HIGH);
digitalWrite(buzzer, LOW);
 }
 }
    
   else { 
    digitalWrite(red, LOW);   // otherwise turn it OFF
    digitalWrite(green, LOW);   // otherwise turn it OFF
    digitalWrite(blue, LOW);   // otherwise turn it OFF
        digitalWrite(blow, HIGH);
digitalWrite(buzzer, LOW);
  }
  delay(10);                    // wait 10ms for next reading
}
