int buttonState=0;
int buttonState2= 0;
int buttonState3=0;

int prevVal=0;
int tryer =0;

int timepassed= millis();

const int buttonPin =6;   
const int buttonPin2=5;
const int buttonPin3= 4;
const int sensorPin = A0;

const int redPin =9;
const int bluePin= 7;
const int yellowPin= 8;
const int greenPin = 11;
const int buzzer= 13;

 
const int randread =A2;

void setup() {

pinMode(randread, INPUT);
pinMode(redPin,OUTPUT);
pinMode(yellowPin, OUTPUT);
pinMode (greenPin, OUTPUT);
pinMode (bluePin, OUTPUT);

pinMode ( buttonPin, INPUT_PULLUP);
pinMode( buttonPin2, INPUT_PULLUP);
pinMode(buttonPin3, INPUT_PULLUP);
pinMode(sensorPin, INPUT);
pinMode(buzzer, OUTPUT);


// code for the hover game
Serial.begin(9600);

Serial.print("To calibrate your photoresistor scroll down on the code to wear it says int brightness high and set it equal to the following number ->");
int calibration=analogRead(sensorPin);
Serial.println(calibration);
}

void loop()
{
  buttonState=digitalRead(buttonPin);
  buttonState2=digitalRead(buttonPin2);
  buttonState3= digitalRead(buttonPin3);

 if(buttonState3==LOW){
       int brightnessHigh=73;
       int brightnessLow= 5;
       int reading = analogRead(sensorPin);
       int brightness =map(reading,brightnessLow,brightnessHigh,0,100);
       delay(500);

       if (prevVal==0 && tryer==0){
         Serial.println(" ");
         Serial.println("Welcome to the Hover challenge. You are on level 1, which is the easiest level. You have two tries to expose the photoresistor to a interval between 80% and 100% brightness");
         Serial.println(" ");
         prevVal=1;
         tryer=0;
       }
     
       else if (prevVal==1 && tryer==0) {
           if (brightness<=100 && brightness>=80){
           Serial.print("You got a brightness of ");
           Serial.print(brightness);
           Serial.println(" ");
           delay(1000);
           Serial.println("Congratulations you have passed level 1. Now onto level 2 you have two tries to keep the the resistor between 80% and 70% brightness");
           Serial.println(" ");
           prevVal=2;
           tryer=0;
          }
           else {
            Serial.print("Sorry, you got a brightness of ");
            Serial.print(brightness);
            Serial.print(". You have one more attempt.");
            Serial.println(" ");
            prevVal=1;
            tryer=1;  
          }
         }
       else if (prevVal==1 && tryer==1) {
           if (brightness<=100 && brightness>=80){
           Serial.print("You got a brightness of ");
           Serial.print(brightness);
           Serial.println(" ");
           delay(1000);
           Serial.println("Congratulations you have passed level 1. Now onto level 2 you have two tries to keep the the resistor between 80% and 70% brightness");
           Serial.println(" ");
           prevVal=2;
           tryer=0;
          }
           else {
            Serial.print("Sorry, you got a brightness of ");
            Serial.print(brightness);
            Serial.print(". You did not pass the challenge. Better luck next time!");
            Serial.println(" ");
            prevVal=0;
            tryer=0;  
          }
         }

   
       else if (prevVal==2 && tryer==0) {
           if (brightness<=80 && brightness>=70) {
           Serial.print("You got a brightness of ");
           Serial.print(brightness);
           Serial.println(" ");
           delay(1000);
           Serial.println("Congratulations you have passed level 2. Now onto level 3 you have two tries to keep the resistor between 70% and 65% brightness"); 
           Serial.println(" ");
           prevVal=3;
           tryer=0;
         }
           else {
            Serial.print("Sorry, you got a brightness of ");
            Serial.print(brightness);
            Serial.print(". You have one more attempt.");
            Serial.println(" ");
            prevVal=2;
            tryer=1;
         }
        }
        else if (prevVal==2 && tryer==1) {
           if (brightness<=80 && brightness>=70) {
           Serial.print("You got a brightness of ");
           Serial.print(brightness);
           Serial.println(" ");
           delay(1000);
           Serial.println("Congratulations you have passed level 2. Now onto level 3 you have two tries to keep the resistor between 70% and 65% brightness"); 
           Serial.println(" ");
           prevVal=3;
           tryer=0;
         }
           else {
            Serial.print("Sorry, you got a brightness of ");
            Serial.print(brightness);
            Serial.print(". You did not pass the challenge. Better luck next time!");
            Serial.println(" ");
            prevVal=0;
            tryer=0;
         }
        }


        else if (prevVal==3 && tryer==0) {
           if (brightness<=70 && brightness>=65) {
           Serial.print("You got a brightness of ");
           Serial.print(brightness);
           Serial.println(" ");
           delay(1000);
           Serial.println("Congratulations you have passed level 3. Now onto level 4, the hardest one: you have two tries to keep the resistor between 65% and 63% brightness"); 
           Serial.println(" ");
           prevVal=4;
           tryer=0;
         }
           else {
            Serial.print("Sorry, you got a brightness of ");
            Serial.print(brightness);
            Serial.print(". You have one more attempt.");
            Serial.println(" ");
            prevVal=3;
            tryer=1;
         }     
       }

       else if (prevVal==3 && tryer==1) {
           if (brightness<=70 && brightness>=65) {
           Serial.print("You got a brightness of ");
           Serial.print(brightness);
           Serial.println(" ");
           delay(1000);
           Serial.println("Congratulations you have passed level 3. Now onto level 4, the hardest one: you have two tries to keep the resistor between 65% and 63% brightness"); 
           Serial.println(" ");
           prevVal=4;
           tryer=0;
         }
           else {
            Serial.print("Sorry, you got a brightness of ");
            Serial.print(brightness);
            Serial.print(". You did not pass the challenge. Better luck next time!");
            Serial.println(" ");
            prevVal=0;
            tryer=0;
         }     
       }


        else if (prevVal==4 && tryer==0) {
           if (brightness<=65 && brightness>=63) {
           Serial.print("You got a brightness of ");
           Serial.print(brightness);
           Serial.println(" ");
           delay(1000);
           Serial.println("Congratulations you have won the mini game!!!");
           Serial.println(" ");
           prevVal=0;
           tryer=0;
         }
           else {
            Serial.print("Sorry, you got a brightness of ");
            Serial.print(brightness);
            Serial.print(". You have one more attempt.");
            Serial.println(" ");
            prevVal=4;
            tryer=1;
         }
       }
        else if (prevVal==4 && tryer==1) {
           if (brightness<=65 && brightness>=63) {
           Serial.print("You got a brightness of ");
           Serial.print(brightness);
           Serial.println(" ");
           delay(1000);
           Serial.println("Congratulations you have won the mini game!!!");
           Serial.println(" ");
           prevVal=0;
           tryer=0;
         }
           else {
            Serial.print("Sorry, you got a brightness of ");
            Serial.print(brightness);
            Serial.print(". You did not pass the challenge. Better luck next time!");
            Serial.println(" ");
            prevVal=0;
            tryer=0;
         }
       }       
    }


// code for the other task in the game, which is the memory game
if(buttonState==LOW)
{
int i=0;
 
while(i<10)
{
  randomSeed(analogRead(A2));
  int num=rand()%4;
  
if(num==0)
{
  digitalWrite (bluePin,HIGH);
  delay(500);
  digitalWrite(bluePin,LOW);
  delay(500);
  Serial.print("Blue ");
}
else if(num==1)
{
 digitalWrite (redPin,HIGH);
  delay(500);
  digitalWrite(redPin,LOW);
  delay(500);
  Serial.print("Red ");
}
else if(num==2)
{
  digitalWrite (greenPin,HIGH);
  delay(500);
  digitalWrite(greenPin,LOW);
  delay(500); 
  Serial.print("Green ");
}
else if(num==3)
{
  digitalWrite (yellowPin,HIGH);
  delay(500);
  digitalWrite(yellowPin,LOW);
  delay(500); 
  Serial.print("Yellow ");
}
i++;
}
 Serial.println( );
}

else
digitalWrite(yellowPin, LOW);
digitalWrite(greenPin, LOW);
digitalWrite(bluePin, LOW);
digitalWrite (redPin, LOW);


// code for the other challenge in the game, which is the music challenge
if(buttonState2==LOW)
{
Serial.println("This is the wrong program. Please use the Music Challenge Program.");
}
}
