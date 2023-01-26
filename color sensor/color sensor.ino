// TCS230 or TCS3200 pins wiring to Arduino

#define s0 4
#define s1 5
#define s2 6
#define s3 7
#define outPin 8

// Variables
int red = 0;
int grn = 0;
int blu = 0;
String color ="";

void setup ()
{
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(outPin, INPUT); //out from sensor becomes input to arduino

    // Setting frequency scaling to 100%
  digitalWrite(s0,HIGH);
  digitalWrite(s1,HIGH);
  
  Serial.begin(9600);
}


/* Based on RGB components ==> Determine color */
void loop()
{  
  if (red < 10 && grn < 10 && blu < 10) color = "WHITE";
  else if (red > 50 && red < 80 && grn > 70 && grn < 100 && blu > 50 && blu < 80) color = "MBLACK"; /*WAS BLACK*/
  else if (red < 30 && red < grn && red < blu) color = "YELLOW"; /*WAS RED*/
  else if (grn < 30 && grn < (red + 5) && grn < blu) color = "GREEN";
  else if (blu < 30 && blu < red && blu < grn) color = "BLACK"; /*WAS BLUE */
  else  color = "NO_COLOR";
  
  red = 0;
  grn = 0;
  blu = 0;
  int n = 10;

  for (int i = 0; i < n; ++i)
  {
    //read red component
    digitalWrite(s2, LOW);
    digitalWrite(s3, LOW);
    red = red + pulseIn(outPin, LOW);
  
   //read green component
    digitalWrite(s2, HIGH);
    digitalWrite(s3, HIGH);
    grn = grn + pulseIn(outPin, LOW);
    
   //let's read blue component
    digitalWrite(s2, LOW);
    digitalWrite(s3, HIGH);
    blu = blu + pulseIn(outPin, LOW);
  }

  Serial.print("red= ");
  Serial.print(red);
  Serial.print("   green= ");
  Serial.print(grn);
  Serial.print("   blue= ");
  Serial.print(blu);
  Serial.print (" - ");
  Serial.print (color);
  Serial.println (" detected!");

  red = red/n;
  grn = grn/n;
  blu = blu/n;
}





