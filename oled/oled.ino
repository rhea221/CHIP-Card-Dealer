#include <Adafruit_GFX.h>    
#include <Adafruit_ST7735.h> 
#include <SPI.h>
#include <Wire.h>
#include <Fonts/FreeSans9pt7b.h>

#define TFT_CS    9
#define TFT_RES   7
#define TFT_DC    8

#define TFT_SCK 13   
#define TFT_SDA 11   

#define BLACK 0x0000
#define NAVY 0x000F
#define DARKGREEN 0x03E0
#define DARKCYAN 0x03EF
#define MAROON 0x7800
#define PURPLE 0x780F
#define OLIVE 0x7BE0
#define LIGHTGREY 0xC618
#define DARKGREY 0x7BEF
#define BLUE 0x001F
#define GREEN 0x07E0
#define CYAN 0x07FF
#define RED 0xF800
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF
#define ORANGE 0xFD20
#define GREENYELLOW 0xAFE5
#define PINK 0xF81F

// Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_SDA, TFT_SCK, TFT_RES);

int gameType = 3;

void setup(void) {

  tft.initR(INITR_BLACKTAB);  
  tft.fillScreen(YELLOW);
  tft.fillCircle(70, 120, 10, BLACK);
  tft.fillCircle(70, 40, 10, BLACK);

  // FACE DESIGN ----------
  for (uint16_t a = 0; a < 8; a++) {
    tft.drawLine(40 + a, 65, 50 + a, 55, BLACK);}
  for (uint16_t a = 0; a < 8; a++) {
    tft.drawLine(40 + a, 65, 50 + a, 80, BLACK);}
  for (uint16_t a = 0; a < 8; a++) {
    tft.drawLine(40 + a, 95, 50 + a, 80, BLACK);}
  for (uint16_t a = 0; a < 8; a++) {
    tft.drawLine(40 + a, 95, 50 + a, 108, BLACK);}
  
  for (int n = 0; n < 2000; n++) {
   }
}


//UNO DESIGN ------
// tft.setRotation(1);

// tft.fillScreen(RED);  
// tft.setCursor(45, 50);
// tft.setTextColor(WHITE);
// tft.setTextSize(4);
// tft.print("UNO"); 

//POKER DESIGN -------
// tft.setRotation(1);

// tft.fillScreen(GREEN);  
// tft.setCursor(22, 48);
// tft.setTextColor(WHITE);
// tft.setTextSize(4);
// tft.print("POKER"); 

//BLACKJACK DESIGN ------
// tft.setRotation(1);

// tft.fillScreen(BLACK); 
// tft.setTextColor(WHITE); 
// tft.setCursor(22, 30);
// tft.setTextSize(4);
// tft.println("BLACK"); 

// tft.setCursor(30, 70);
// tft.println("JACK");
 


// void shake(){
//   for (int i = 0; i < 480; i++) {
//       tft.vertScroll(0, 480, i);
//       delay(2);
//       if (i > 20) {
//         break;
//       }
//     }
//     for (int i = 0; i < 480; i++) {
//       tft.vertScroll(480, 0, i);
//       delay(2);
//       if (i > 20) {
//         break;
//       }
//     }
// } 

void loop() {

delay(5000);
tft.setRotation(1);
tft.fillScreen(YELLOW);

tft.setCursor(35, 45);
tft.setTextColor(BLACK);
tft.setTextSize(2);
tft.print("Choose a");
tft.setCursor(55,65);
tft.print("game!");
delay(5000);  

if (gameType == 1) {
  delay(5000);
  tft.setRotation(1);
  tft.fillScreen(RED);  
  tft.setCursor(45, 50);
  tft.setTextColor(WHITE);
  tft.setTextSize(4);
  tft.print("UNO"); 
  delay(5000);

} else if (gameType == 2) {
  delay(5000); 
  tft.setRotation(1);
  tft.fillScreen(GREEN);  
  tft.setCursor(22, 48);
  tft.setTextColor(WHITE);
  tft.setTextSize(4);
  tft.print("POKER"); 
  delay(5000);

} else if (gameType == 3) {
  delay(5000); 
  tft.setRotation(1);
  tft.fillScreen(BLACK); 
  tft.setTextColor(WHITE); 
  tft.setCursor(22, 30);
  tft.setTextSize(4);
  tft.println("BLACK"); 
  tft.setCursor(30, 70);
  tft.println("JACK");
  delay(5000);
}
}


//   tft.drawCircle(int16_t x, int16_t y, int16_t r, uint16_t t)
//   tft.fillCircle(x,y,r,t); //fillCircle(int16_t x, int16_t y, int16_t r, uint16_t t)
//   for (int p = 0; p < 4000; p++) 
// {  j = 120 * (sin(PI * p / 2000));
//    i = 120 * (cos(PI * p / 2000));  
//    j2 = 60 * (sin(PI * p / 2000));  
//    i2 = 60 * (cos(PI * p / 2000));  
//   tft.drawLine(i2 + 160, j2 + 160, i + 160, j + 160, col[n]);
// }
