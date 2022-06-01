# Proiect-SMP-Limona-Andrei-Codrin
Boloboc digital


Componente utilizate:
-Placuta Arduino Nano  

-Accelerometru MPU 6500  

-Display OLED 128x64 - 0.96'' SPI  

-Breadboard  

-Jumpere  

-Leduri  
  
    
    
Biblioteci utilizate:  

-TinyMPU6050.h pentru interfatarea comunicatiei placutei cu accelerometrului MPU 6500 si prelucrarea datelor oferite de acesta  

-Arduino.h pentru comunicarea I2C  

-SPI.h pentru comunicarea SPI  

-HT_SSD1306.h pentru interfatarea comunicatiei cu diplay-ul OLED si apelarea unor functii specializate de afisare  
  
  

Definim pinii speciali ai placii Arduino NANO pentru comunicatia I2C si SPI (DC, CS, SCK, MOSI) 
Vom folosii pinii digitali 4-10 pentru a aprinde ledurile  

In sectiunea de setup vom initializa display-ul si accelerometrul. Accelerometrul va avea nevoie de o perioada de calibrare de aproximativ 10 secunde, timp in care nu trebuie sa fie miscat.  
Desi nu va fi nevoie decat de unghiul fata de axa OX, vom citi si afisa la fiecare 0.1 secunde valorile unghiurilor fata de axele OX, OY si OZ, urmand sa aprindem ledul corespunzator prin comparatia valorii unghiului format cu axa OX si valorile determinate empiric, luand in considerare zgomotul de masura al accelerometrului de +/- 2 grade.  

## Implementare hardware a proiectului
![Implementare hardware](https://user-images.githubusercontent.com/57183353/171450506-b998dc52-8288-4c2b-896e-59a59fa4f025.jpeg)  
## Calibrare
![Calibrare](https://user-images.githubusercontent.com/57183353/171450795-36f8e6a6-c1df-4353-b1b4-07f551f971fb.jpeg)  
## Inclinare 0 grade
![Inclinare 0 grade](https://user-images.githubusercontent.com/57183353/171450938-53d8a802-1621-4ed0-b51a-ed0af1fc32b6.jpeg)  
## Inclinare 90 grade
![Inclinare 90 grade](https://user-images.githubusercontent.com/57183353/171451221-f326988c-fedb-489b-a15a-144c3a66eeae.jpeg)

