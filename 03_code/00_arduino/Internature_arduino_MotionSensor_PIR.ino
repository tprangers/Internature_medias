#include <M5Atom.h>
#include <FastLED.h>

// Déclaration d'un seul pixel (LED intégrée)
CRGB mesPixels[1];

// Broche utilisée pour le capteur PIR
const int PIR_PIN = 2;

void setup() {
  M5.begin();
  
  Serial.begin(115200);
  while (!Serial); 


  FastLED.addLeds<WS2812, DATA_PIN, GRB>(mesPixels, 1);
  
  
  pinMode(PIR_PIN, INPUT);

  
  Serial.println("Calibrage");
  delay(60000);
  Serial.println("Capteur PIR calibré, démarrage de la détection.");
}

void loop() {
  M5.update();
  
  // Lecture de l'état du capteur PIR
  int etatPIR = digitalRead(PIR_PIN);
  Serial.print("Valeur lue sur le capteur PIR : ");
  Serial.println(etatPIR);
  
  
  if (etatPIR == HIGH) {
    Serial.println("Mouvement détecté !");
    mesPixels[0] = CRGB::Red;
  } else {
    Serial.println("Aucun mouvement.");
    mesPixels[0] = CRGB::Green;
  }
  
  FastLED.show();
  delay(200);  
}
