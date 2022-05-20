/*
 *  Mandatory includes
 */
#include <Arduino.h>
#include <TinyMPU6050.h>
#include <SPI.h> // Include SPI if you're using SPI
#include <HT_SSD1306.h> // Include the HT_SSD1306 library
/*
 *  Constructing MPU-6050
 */
MPU6050 mpu (Wire);

/*
 *  Setup
 */
//////////////////////////
// SSD1306 Definition //
//////////////////////////
#define PIN_RESET 3 // Connect RST to pin 9
#define PIN_DC 2 // Connect DC to pin 8
#define PIN_CS 12
#define PIN_SCK 13 // Connect SCL/D0 to pin 13
#define PIN_MOSI 11 // Connect SDA/D1 to pin 11

//////////////////////////////////
// SSD1306 Object Declaration //
//////////////////////////////////
SSD1306 oled(PIN_RESET, PIN_DC, PIN_CS);

const int MIDDLE_Y = oled.getLCDHeight() / 2;
const int MIDDLE_X = oled.getLCDWidth() / 2;

 //Level LEDs==============================================================
int levelLED_neg3 = 4;
int levelLED_neg2 = 5;  
int levelLED_neg1 = 6;
int levelLED_level = 7; 
int levelLED_pos1 = 8;
int levelLED_pos2 = 9;  
int levelLED_pos3 = 10; 
#define buzzer A7
//=========================================================================
void setup() {

  // Initialization
  mpu.Initialize();

  // Calibration
  
  //OLED
  oled.begin();    // Initialize the OLED
  oled.clear(ALL); // Clear the display's internal memory
  oled.display();  // Display what's in the buffer (splashscreen)

  //Calibrare
  oled.setCursor(0,0);
  oled.setFontType(0);
  oled.print("Calibrare");
  oled.setCursor(0,16);
  oled.print("accelerometru...");
  oled.display();
  
  mpu.Calibrate();
  
  oled.clear(PAGE);
  oled.setCursor(0,0);
  oled.setFontType(0);
  oled.print("Calibrare completa!");
  oled.setCursor(0,16);
  oled.print("GyroX Offset = ");
  oled.print(mpu.GetGyroXOffset());
  oled.setCursor(0,32);
  oled.print("Gyroy Offset = ");
  oled.print(mpu.GetGyroYOffset());
  oled.setCursor(0,48);
  oled.print("GyroZ Offset = ");
  oled.print(mpu.GetGyroZOffset());
  oled.display();
  delay(5000);
  
  // SetPins
  pinMode(levelLED_neg3, OUTPUT); 
  pinMode(levelLED_neg2, OUTPUT);
  pinMode(levelLED_neg1, OUTPUT);
  pinMode(levelLED_level, OUTPUT); 
  pinMode(levelLED_pos1, OUTPUT);
  pinMode(levelLED_pos2, OUTPUT);
  pinMode(levelLED_pos3, OUTPUT);  
}
float AngX, AngY, AngZ;


void printOLED()
{
    oled.clear(PAGE);            // Clear the display
    oled.setCursor(0, 0);        // Set cursor to top-left
    oled.setFontType(1);         // Smallest font
    oled.print("AngX: ");                 // 7-segment font
    oled.print(AngX);            // Print a0 reading
    oled.setCursor(0, 16);       // Set cursor to top-middle-left        
    oled.print("AngY: ");
    oled.print(AngY);
    oled.setCursor(0, 32);      // Set cursor to top-right
    oled.print("AngZ: ");
    oled.print(AngZ);
    oled.display();
    delay(100);
}

/*
 *  Loop
 */
void loop() {

  mpu.Execute();
  

  
  AngX = mpu.GetAngX();
  AngY = mpu.GetAngY();
  AngZ = mpu.GetAngZ();
  oled.display(); 

  printOLED();

  if(AngX>=-1.5 && AngX<=0.5)
  {
    digitalWrite(levelLED_neg3, LOW);
    digitalWrite(levelLED_neg2, LOW);
    digitalWrite(levelLED_neg1, LOW);
    digitalWrite(levelLED_level, HIGH);
    digitalWrite(levelLED_pos1, LOW);
    digitalWrite(levelLED_pos2, LOW);
    digitalWrite(levelLED_pos3, LOW);
  }
  else if(AngX<-1.5 && AngX>= -46.5)
  {
    digitalWrite(levelLED_neg3, LOW);
    digitalWrite(levelLED_neg2, LOW);
    digitalWrite(levelLED_neg1, HIGH);
    digitalWrite(levelLED_level, LOW);
    digitalWrite(levelLED_pos1, LOW);
    digitalWrite(levelLED_pos2, LOW);
    digitalWrite(levelLED_pos3, LOW);
  }
  else if(AngX<-45 && AngX>= -87.5)
  {
    digitalWrite(levelLED_neg3, LOW);
    digitalWrite(levelLED_neg2, HIGH);
    digitalWrite(levelLED_neg1, LOW);
    digitalWrite(levelLED_level, LOW);
    digitalWrite(levelLED_pos1, LOW);
    digitalWrite(levelLED_pos2, LOW);
    digitalWrite(levelLED_pos3, LOW);
  }
  else if(AngX<-87.5 && AngX>= -91.5)
  {
    digitalWrite(levelLED_neg3, HIGH);
    digitalWrite(levelLED_neg2, LOW);
    digitalWrite(levelLED_neg1, LOW);
    digitalWrite(levelLED_level, LOW);
    digitalWrite(levelLED_pos1, LOW);
    digitalWrite(levelLED_pos2, LOW);
    digitalWrite(levelLED_pos3, LOW);
  }
  else if(AngX<=45 && AngX>0.5)
  {
    digitalWrite(levelLED_neg3, LOW);
    digitalWrite(levelLED_neg2, LOW);
    digitalWrite(levelLED_neg1, LOW);
    digitalWrite(levelLED_level, LOW);
    digitalWrite(levelLED_pos1, HIGH);
    digitalWrite(levelLED_pos2, LOW);
    digitalWrite(levelLED_pos3, LOW);
  }
  else if(AngX<=87.5 && AngX>=45)
  {
    digitalWrite(levelLED_neg3, LOW);
    digitalWrite(levelLED_neg2, LOW);
    digitalWrite(levelLED_neg1, LOW);
    digitalWrite(levelLED_level, LOW);
    digitalWrite(levelLED_pos1, LOW);
    digitalWrite(levelLED_pos2, HIGH);
    digitalWrite(levelLED_pos3, LOW);
  }
  else if(AngX<=91 && AngX>87.5)
  {
    digitalWrite(levelLED_neg3, LOW);
    digitalWrite(levelLED_neg2, LOW);
    digitalWrite(levelLED_neg1, LOW);
    digitalWrite(levelLED_level, LOW);
    digitalWrite(levelLED_pos1, LOW);
    digitalWrite(levelLED_pos2, LOW);
    digitalWrite(levelLED_pos3, HIGH);
  }
}   
