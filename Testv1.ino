int Leftled1 = 9;     // LED connected to digital pin 9
int Leftled2 = 8;     // LED connected to digital pin 8

int Rightled1 = 6;    // LED connected to digital pin 6
int Rightled2 = 7;    // LED connected to digital pin 7

int LeftPin = A0;     // Twisty thing connected to digital pin A0
int RightPin = A1;    // Twisty thing connected to digital pin A1

int leftValue = 0;    // variable to store the read value of left side
int RightValue = 0;   // variable to store the read value of right side

void setup()
{
  pinMode(Leftled1, OUTPUT);      // sets the digital pin A0 as output
  pinMode(Leftled2, OUTPUT);

  pinMode(LeftPin, INPUT);
  
  pinMode(Rightled1, OUTPUT);
  pinMode(Rightled2, OUTPUT);

  pinMode(RightPin, INPUT);

  Serial.begin(115200);
  
}

void loop()
{
  if(Serial.available() > 0) 
  {
    leftValue = analogRead(LeftPin);
    RightValue = analogRead(RightPin);

    Serial.print("I got: ");
    Serial.print(leftValue, DEC);
    Serial.print(RightValue, DEC);
  }
  leftValue = digitalRead(LeftPin);     // read the input pin
  digitalWrite(Leftled1, leftValue);    // sets the LED to the button's value
  digitalWrite(Leftled2, leftValue);    // sets the LED to the button's value


  RightValue = digitalRead(RightPin);
  digitalWrite(Rightled1, RightValue);
  digitalWrite(Rightled2, RightValue);

}
