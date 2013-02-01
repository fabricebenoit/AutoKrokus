#include <VirtualWire.h>     // Pour le Kit 433MHz
#include <SoftwareSerial.h>  // Requis pour serLCD
#include <serLCD.h>          // A télécharger et installer

// pin Arduino connecté au Rx de l'écran LCD
int LCDpin = 4;
serLCD lcd(LCDpin);

// Assignation des pins pour le joystick
int pinHaut = 9;
int pinCentre = 8;
int pinGauche = 7;
int pinBas = 6;
int pinDroite = 5;

// Nombre de messages
int nbMessages = 0;

void setup(){
  // Initialisation du port VirtualWire
  // On utilise le pin 12, pin Tx par défaut de la librairie
  //vw_set_ptt_inverted(true); // Required for DR3100
  vw_setup(2000);	 // Bits par sec
  
  // Les pins connectés au joystick sont configurés en entrées
  pinMode(pinHaut, INPUT);
  pinMode(pinCentre, INPUT);
  pinMode(pinGauche, INPUT);
  pinMode(pinBas, INPUT);
  pinMode(pinDroite, INPUT);
  
  // On active les résistances internes des pin Arduino pour avoir des valeurs cohérentes
  digitalWrite(pinHaut, HIGH);
  digitalWrite(pinCentre, HIGH);
  digitalWrite(pinGauche, HIGH);
  digitalWrite(pinBas, HIGH);
  digitalWrite(pinDroite, HIGH);
  
   // Initialisation de l'ecran
  lcd.clear();
  // Laisser le temps au splashscreen de s'afficher 
  delay(1000);
  lcd.display();
  lcd.print("Krokus Remote");
  
  
  
}

void loop(){
  lcd.setCursor(1,16);
  lcd.print("9");
  
  String message433 = String(nbMessages)+"/";
  
  // L'etat du joystick est affiché au début de la deuxième ligne
  //
  
  // Le joystick ne peut prendre qu'une position à la fois -> else if interromp les tests si un des boutons est pressé.
  
  if(digitalRead(pinHaut)){
     message433 += "H";
   }else 
   if(digitalRead(pinCentre)){
     message433 += "C";
   }else 
   if(digitalRead(pinGauche)){
     message433 += "G";
   }else 
   if(digitalRead(pinBas)){
     message433 += "B";
   }else 
   if(digitalRead(pinDroite)){
     message433 += "D";
   }else{
     message433 += "0";
   }
   message433 += "/";
      
   message433 += String(analogRead(A0));
   
   lcd.clearLine(2); 
   lcd.setCursor(2,1);
   lcd.print(message433);
   
   char charBuf[message433.length()+1];
   message433.toCharArray(charBuf, message433.length()+1); 
   
   vw_send((uint8_t *)charBuf, strlen(charBuf));
   vw_wait_tx();
   
   nbMessages++;
   delay(1000);
   
   
   lcd.setCursor(1,16);
   lcd.print("8");
   delay(1000);
   lcd.setCursor(1,16);
   lcd.print("7");
   delay(1000);
   lcd.setCursor(1,16);
   lcd.print("6");
   delay(1000);
   lcd.setCursor(1,16);
   lcd.print("5");
   delay(1000);
   lcd.setCursor(1,16);
   lcd.print("4");
   delay(1000);
   lcd.setCursor(1,16);
   lcd.print("3");
   delay(1000);
   lcd.setCursor(1,16);
   lcd.print("2");
   delay(1000);
   lcd.setCursor(1,16);
   lcd.print("1");
   delay(1000);
   lcd.setCursor(1,16);
   lcd.print("0");
   delay(1000);
   
}
