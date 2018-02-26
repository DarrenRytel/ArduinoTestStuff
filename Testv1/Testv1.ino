int Leftled1 = 9;     // LED connected to digital pin 9
int Leftled2 = 8;     // LED connected to digital pin 8

int Rightled1 = 6;    // LED connected to digital pin 6
int Rightled2 = 7;    // LED connected to digital pin 7

int LeftPin = A0;     // Twisty thing connected to digital pin A0
int RightPin = A1;    // Twisty thing connected to digital pin A1

int leftValue = 0;    // variable to store the read value of left side
int RightValue = 0;   // variable to store the read value of right side

int inByte;
int pot1 = 0;
int pot2 = 0;

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
    inByte = Serial.read();

    if (inByte == 'P') sensorPositions();

  }

  delay(20);
}

void sensorPositions(){
  pot1 = analogRead(A0);
  pot2 = analogRead(A1);
  
  Serial.print(getPadded(pot1));
  Serial.print("-");
  Serial.println(getPadded(pot2));
}

String getPadded(int num){
  
  char buff[5];
  char padded[6];

  sprintf(buff, "%.4u", num);

  padded[0] = buff[0];
  padded[1] = buff[1];
  padded[2] = buff[2];
  padded[3] = buff[3];
  padded[4] = buff[4];
  padded[5] = '\0';

  return String(padded);
}
