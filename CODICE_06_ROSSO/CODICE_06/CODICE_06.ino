#include <Keypad.h>
#include <FastLED.h>
#define NUM_LEDS_DECINE 63  // Numero di LED sulla prima striscia
#define NUM_LEDS_UNITA 63   // Numero di LED sulla seconda striscia
#define DATA_UNITA 4        // Pin dati della prima striscia LED
#define DATA_DECINE 3       // Pin dati della seconda striscia LEDconst byte ROWS = 4; // Numero di righe nel tastierino
#define PHOTO_PIN A0        // Pin analogico per il fotoresistore
const int righe = 4;
const int colonne = 4;
char keys[righe][colonne] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', '4' },
  { '*', '0', '#', 'D' },
};
byte colpin[colonne] = { 9, 8, 7, 6 };
byte rigpin[righe] = { 13, 12, 11, 10 };


Keypad keypad = Keypad(makeKeymap(keys), rigpin, colpin, righe, colonne);
String inputNumero = "";


// Impostazioni per le strisce LED


CRGB leds_DECINE[NUM_LEDS_DECINE];
CRGB leds_UNITA[NUM_LEDS_UNITA];


void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2811, DATA_DECINE, RGB>(leds_DECINE, NUM_LEDS_DECINE);
  FastLED.addLeds<WS2811, DATA_UNITA, RGB>(leds_UNITA, NUM_LEDS_UNITA);
  FastLED.setBrightness(255);  // Imposta la luminosità massima iniziale
}

void loop() {
  int photoValue = analogRead(PHOTO_PIN);
  int brightness = map(photoValue, 0, 1023, 0, 255);
  FastLED.setBrightness(brightness);

  char key = keypad.getKey();

  if (key) {
    if (key >= '0' && key <= '9') {
      inputNumero += key;  // Aggiungi il tasto premuto alla stringa

      // Controlla se hai inserito due cifre
      if (inputNumero.length() == 2) {
        int numero1 = inputNumero.charAt(0) - '0';
        int numero2 = inputNumero.charAt(1) - '0';

        Serial.print("Primo numero: ");
        Serial.println(numero1);
        Serial.print("Secondo numero: ");
        Serial.println(numero2);

        if (numero1 == '1') {
          leds_DECINE[0] = CRGB::Black;
          leds_DECINE[1] = CRGB::Black;
          leds_DECINE[2] = CRGB::Black;
          leds_DECINE[3] = CRGB::Black;
          leds_DECINE[4] = CRGB::Black;
          leds_DECINE[5] = CRGB::Black;
          leds_DECINE[6] = CRGB::Black;
          leds_DECINE[7] = CRGB::Black;
          leds_DECINE[8] = CRGB::Black;
          leds_DECINE[9] = CRGB::red;
          leds_DECINE[10] = CRGB::red;
          leds_DECINE[11] = CRGB::red;
          leds_DECINE[12] = CRGB::red;
          leds_DECINE[13] = CRGB::red;
          leds_DECINE[14] = CRGB::red;
          leds_DECINE[15] = CRGB::Black;
          leds_DECINE[16] = CRGB::Black;
          leds_DECINE[17] = CRGB::Black;
          leds_DECINE[18] = CRGB::Black;
          leds_DECINE[19] = CRGB::Black;
          leds_DECINE[20] = CRGB::Black;
          FastLED.show();
        }
        if (numero1 == '2') {
          leds_DECINE[0] = CRGB::red;
          leds_DECINE[1] = CRGB::red;
          leds_DECINE[2] = CRGB::red;
          leds_DECINE[3] = CRGB::Black;
          leds_DECINE[4] = CRGB::Black;
          leds_DECINE[5] = CRGB::Black;
          leds_DECINE[6] = CRGB::red;
          leds_DECINE[7] = CRGB::red;
          leds_DECINE[8] = CRGB::red;
          leds_DECINE[9] = CRGB::red;
          leds_DECINE[10] = CRGB::red;
          leds_DECINE[11] = CRGB::red;
          leds_DECINE[12] = CRGB::Black;
          leds_DECINE[13] = CRGB::Black;
          leds_DECINE[14] = CRGB::Black;
          leds_DECINE[15] = CRGB::red;
          leds_DECINE[16] = CRGB::red;
          leds_DECINE[17] = CRGB::red;
          leds_DECINE[18] = CRGB::red;
          leds_DECINE[19] = CRGB::red;
          leds_DECINE[20] = CRGB::red;

          FastLED.show();
        }
        if (numero1 == '3') {
          leds_DECINE[0] = CRGB::red;
          leds_DECINE[1] = CRGB::red;
          leds_DECINE[2] = CRGB::red;
          leds_DECINE[3] = CRGB::Black;
          leds_DECINE[4] = CRGB::Black;
          leds_DECINE[5] = CRGB::Black;
          leds_DECINE[6] = CRGB::red;
          leds_DECINE[7] = CRGB::red;
          leds_DECINE[8] = CRGB::red;
          leds_DECINE[9] = CRGB::red;
          leds_DECINE[10] = CRGB::red;
          leds_DECINE[11] = CRGB::red;
          leds_DECINE[12] = CRGB::red;
          leds_DECINE[13] = CRGB::red;
          leds_DECINE[14] = CRGB::red;
          leds_DECINE[15] = CRGB::red;
          leds_DECINE[16] = CRGB::red;
          leds_DECINE[17] = CRGB::red;
          leds_DECINE[18] = CRGB::Black;
          leds_DECINE[19] = CRGB::Black;
          leds_DECINE[20] = CRGB::Black;
          FastLED.show();
        }
        if (numero1 == '4') {
          leds_DECINE[0] = CRGB::red;
          leds_DECINE[1] = CRGB::red;
          leds_DECINE[2] = CRGB::red;
          leds_DECINE[3] = CRGB::red;
          leds_DECINE[4] = CRGB::red;
          leds_DECINE[5] = CRGB::red;
          leds_DECINE[6] = CRGB::Black;
          leds_DECINE[7] = CRGB::Black;
          leds_DECINE[8] = CRGB::Black;
          leds_DECINE[9] = CRGB::red;
          leds_DECINE[10] = CRGB::red;
          leds_DECINE[11] = CRGB::red;
          leds_DECINE[12] = CRGB::red;
          leds_DECINE[13] = CRGB::red;
          leds_DECINE[14] = CRGB::red;
          leds_DECINE[15] = CRGB::Black;
          leds_DECINE[16] = CRGB::Black;
          leds_DECINE[17] = CRGB::Black;
          leds_DECINE[18] = CRGB::Black;
          leds_DECINE[19] = CRGB::Black;
          leds_DECINE[20] = CRGB::Black;
          FastLED.show();
        }
        if (numero1 == '5') {
          leds_DECINE[0] = CRGB::red;
          leds_DECINE[1] = CRGB::red;
          leds_DECINE[2] = CRGB::red;
          leds_DECINE[3] = CRGB::red;
          leds_DECINE[4] = CRGB::red;
          leds_DECINE[5] = CRGB::red;
          leds_DECINE[6] = CRGB::red;
          leds_DECINE[7] = CRGB::red;
          leds_DECINE[8] = CRGB::red;
          leds_DECINE[9] = CRGB::Black;
          leds_DECINE[10] = CRGB::Black;
          leds_DECINE[11] = CRGB::Black;
          leds_DECINE[12] = CRGB::red;
          leds_DECINE[13] = CRGB::red;
          leds_DECINE[14] = CRGB::red;
          leds_DECINE[15] = CRGB::red;
          leds_DECINE[16] = CRGB::red;
          leds_DECINE[17] = CRGB::red;
          leds_DECINE[18] = CRGB::Black;
          leds_DECINE[19] = CRGB::Black;
          leds_DECINE[20] = CRGB::Black;
          FastLED.show();
        }
        if (numero1 == '6') {
          leds_DECINE[0] = CRGB::red;
          leds_DECINE[1] = CRGB::red;
          leds_DECINE[2] = CRGB::red;
          leds_DECINE[3] = CRGB::red;
          leds_DECINE[4] = CRGB::red;
          leds_DECINE[5] = CRGB::red;
          leds_DECINE[6] = CRGB::red;
          leds_DECINE[7] = CRGB::red;
          leds_DECINE[8] = CRGB::red;
          leds_DECINE[9] = CRGB::Black;
          leds_DECINE[10] = CRGB::Black;
          leds_DECINE[11] = CRGB::Black;
          leds_DECINE[12] = CRGB::red;
          leds_DECINE[13] = CRGB::red;
          leds_DECINE[14] = CRGB::red;
          leds_DECINE[15] = CRGB::red;
          leds_DECINE[16] = CRGB::red;
          leds_DECINE[17] = CRGB::red;
          leds_DECINE[18] = CRGB::red;
          leds_DECINE[19] = CRGB::red;
          leds_DECINE[20] = CRGB::red;
          FastLED.show();
        }
        if (numero1 == '7') {
          leds_DECINE[0] = CRGB::Black;
          leds_DECINE[1] = CRGB::Black;
          leds_DECINE[2] = CRGB::Black;
          leds_DECINE[3] = CRGB::Black;
          leds_DECINE[4] = CRGB::Black;
          leds_DECINE[5] = CRGB::Black;
          leds_DECINE[6] = CRGB::red;
          leds_DECINE[7] = CRGB::red;
          leds_DECINE[8] = CRGB::red;
          leds_DECINE[9] = CRGB::red;
          leds_DECINE[10] = CRGB::red;
          leds_DECINE[11] = CRGB::red;
          leds_DECINE[12] = CRGB::red;
          leds_DECINE[13] = CRGB::red;
          leds_DECINE[14] = CRGB::red;
          leds_DECINE[15] = CRGB::Black;
          leds_DECINE[16] = CRGB::Black;
          leds_DECINE[17] = CRGB::Black;
          leds_DECINE[18] = CRGB::Black;
          leds_DECINE[19] = CRGB::Black;
          leds_DECINE[20] = CRGB::Black;
          FastLED.show();
        }
        if (numero1 == '8') {
          leds_DECINE[0] = CRGB::red;
          leds_DECINE[1] = CRGB::red;
          leds_DECINE[2] = CRGB::red;
          leds_DECINE[3] = CRGB::red;
          leds_DECINE[4] = CRGB::red;
          leds_DECINE[5] = CRGB::red;
          leds_DECINE[6] = CRGB::red;
          leds_DECINE[7] = CRGB::red;
          leds_DECINE[8] = CRGB::red;
          leds_DECINE[9] = CRGB::red;
          leds_DECINE[10] = CRGB::red;
          leds_DECINE[11] = CRGB::red;
          leds_DECINE[12] = CRGB::red;
          leds_DECINE[13] = CRGB::red;
          leds_DECINE[14] = CRGB::red;
          leds_DECINE[15] = CRGB::red;
          leds_DECINE[16] = CRGB::red;
          leds_DECINE[17] = CRGB::red;
          leds_DECINE[18] = CRGB::red;
          leds_DECINE[19] = CRGB::red;
          leds_DECINE[20] = CRGB::red;
          FastLED.show();
        }
        if (numero1 == '9') {
          leds_DECINE[0] = CRGB::red;
          leds_DECINE[1] = CRGB::red;
          leds_DECINE[2] = CRGB::red;
          leds_DECINE[3] = CRGB::red;
          leds_DECINE[4] = CRGB::red;
          leds_DECINE[5] = CRGB::red;
          leds_DECINE[6] = CRGB::red;
          leds_DECINE[7] = CRGB::red;
          leds_DECINE[8] = CRGB::red;
          leds_DECINE[9] = CRGB::red;
          leds_DECINE[10] = CRGB::red;
          leds_DECINE[11] = CRGB::red;
          leds_DECINE[12] = CRGB::red;
          leds_DECINE[13] = CRGB::red;
          leds_DECINE[14] = CRGB::red;
          leds_DECINE[15] = CRGB::Black;
          leds_DECINE[16] = CRGB::Black;
          leds_DECINE[17] = CRGB::Black;
          leds_DECINE[18] = CRGB::Black;
          leds_DECINE[19] = CRGB::Black;
          leds_DECINE[20] = CRGB::Black;
          FastLED.show();
        }
        if (numero1 == '0') {
          leds_DECINE[0] = CRGB::Black;
          leds_DECINE[1] = CRGB::Black;
          leds_DECINE[2] = CRGB::Black;
          leds_DECINE[3] = CRGB::red;
          leds_DECINE[4] = CRGB::red;
          leds_DECINE[5] = CRGB::red;
          leds_DECINE[6] = CRGB::red;
          leds_DECINE[7] = CRGB::red;
          leds_DECINE[8] = CRGB::red;
          leds_DECINE[9] = CRGB::red;
          leds_DECINE[10] = CRGB::red;
          leds_DECINE[11] = CRGB::red;
          leds_DECINE[12] = CRGB::red;
          leds_DECINE[13] = CRGB::red;
          leds_DECINE[14] = CRGB::red;
          leds_DECINE[15] = CRGB::red;
          leds_DECINE[16] = CRGB::red;
          leds_DECINE[17] = CRGB::red;
          leds_DECINE[18] = CRGB::red;
          leds_DECINE[19] = CRGB::red;
          leds_DECINE[20] = CRGB::red;
          FastLED.show();
        }
        if (numero1 == 'A') {
          leds_DECINE[0] = CRGB::Black;
          leds_DECINE[1] = CRGB::Black;
          leds_DECINE[2] = CRGB::Black;
          leds_DECINE[3] = CRGB::Black;
          leds_DECINE[4] = CRGB::Black;
          leds_DECINE[5] = CRGB::Black;
          leds_DECINE[6] = CRGB::Black;
          leds_DECINE[7] = CRGB::Black;
          leds_DECINE[8] = CRGB::Black;
          leds_DECINE[9] = CRGB::Black;
          leds_DECINE[10] = CRGB::Black;
          leds_DECINE[11] = CRGB::Black;
          leds_DECINE[12] = CRGB::Black;
          leds_DECINE[13] = CRGB::Black;
          leds_DECINE[14] = CRGB::Black;
          leds_DECINE[15] = CRGB::Black;
          leds_DECINE[16] = CRGB::Black;
          leds_DECINE[17] = CRGB::Black;
          leds_DECINE[18] = CRGB::Black;
          leds_DECINE[19] = CRGB::Black;
          leds_DECINE[20] = CRGB::Black;
          FastLED.show();
        }

        if (numero2 == '1') {
          leds_UNITA[0] = CRGB::Black;
          leds_UNITA[1] = CRGB::Black;
          leds_UNITA[2] = CRGB::Black;
          leds_UNITA[3] = CRGB::Black;
          leds_UNITA[4] = CRGB::Black;
          leds_UNITA[5] = CRGB::Black;
          leds_UNITA[6] = CRGB::Black;
          leds_UNITA[7] = CRGB::Black;
          leds_UNITA[8] = CRGB::Black;
          leds_UNITA[9] = CRGB::red;
          leds_UNITA[10] = CRGB::red;
          leds_UNITA[11] = CRGB::red;
          leds_UNITA[12] = CRGB::red;
          leds_UNITA[13] = CRGB::red;
          leds_UNITA[14] = CRGB::red;
          leds_UNITA[15] = CRGB::Black;
          leds_UNITA[16] = CRGB::Black;
          leds_UNITA[17] = CRGB::Black;
          leds_UNITA[18] = CRGB::Black;
          leds_UNITA[19] = CRGB::Black;
          leds_UNITA[20] = CRGB::Black;
          FastLED.show();
        }
        if (numero2 == '2') {
          leds_UNITA[0] = CRGB::red;
          leds_UNITA[1] = CRGB::red;
          leds_UNITA[2] = CRGB::red;
          leds_UNITA[3] = CRGB::Black;
          leds_UNITA[4] = CRGB::Black;
          leds_UNITA[5] = CRGB::Black;
          leds_UNITA[6] = CRGB::red;
          leds_UNITA[7] = CRGB::red;
          leds_UNITA[8] = CRGB::red;
          leds_UNITA[9] = CRGB::red;
          leds_UNITA[10] = CRGB::red;
          leds_UNITA[11] = CRGB::red;
          leds_UNITA[12] = CRGB::Black;
          leds_UNITA[13] = CRGB::Black;
          leds_UNITA[14] = CRGB::Black;
          leds_UNITA[15] = CRGB::red;
          leds_UNITA[16] = CRGB::red;
          leds_UNITA[17] = CRGB::red;
          leds_UNITA[18] = CRGB::red;
          leds_UNITA[19] = CRGB::red;
          leds_UNITA[20] = CRGB::red;

          FastLED.show();
        }
        if (numero2 == '3') {
          leds_UNITA[0] = CRGB::red;
          leds_UNITA[1] = CRGB::red;
          leds_UNITA[2] = CRGB::red;
          leds_UNITA[3] = CRGB::Black;
          leds_UNITA[4] = CRGB::Black;
          leds_UNITA[5] = CRGB::Black;
          leds_UNITA[6] = CRGB::red;
          leds_UNITA[7] = CRGB::red;
          leds_UNITA[8] = CRGB::red;
          leds_UNITA[9] = CRGB::red;
          leds_UNITA[10] = CRGB::red;
          leds_UNITA[11] = CRGB::red;
          leds_UNITA[12] = CRGB::red;
          leds_UNITA[13] = CRGB::red;
          leds_UNITA[14] = CRGB::red;
          leds_UNITA[15] = CRGB::red;
          leds_UNITA[16] = CRGB::red;
          leds_UNITA[17] = CRGB::red;
          leds_UNITA[18] = CRGB::Black;
          leds_UNITA[19] = CRGB::Black;
          leds_UNITA[20] = CRGB::Black;
          FastLED.show();
        }
        if (numero2 == '4') {
          leds_UNITA[0] = CRGB::red;
          leds_UNITA[1] = CRGB::red;
          leds_UNITA[2] = CRGB::red;
          leds_UNITA[3] = CRGB::red;
          leds_UNITA[4] = CRGB::red;
          leds_UNITA[5] = CRGB::red;
          leds_UNITA[6] = CRGB::Black;
          leds_UNITA[7] = CRGB::Black;
          leds_UNITA[8] = CRGB::Black;
          leds_UNITA[9] = CRGB::red;
          leds_UNITA[10] = CRGB::red;
          leds_UNITA[11] = CRGB::red;
          leds_UNITA[12] = CRGB::red;
          leds_UNITA[13] = CRGB::red;
          leds_UNITA[14] = CRGB::red;
          leds_UNITA[15] = CRGB::Black;
          leds_UNITA[16] = CRGB::Black;
          leds_UNITA[17] = CRGB::Black;
          leds_UNITA[18] = CRGB::Black;
          leds_UNITA[19] = CRGB::Black;
          leds_UNITA[20] = CRGB::Black;
          FastLED.show();
        }
        if (numero2 == '5') {
          leds_UNITA[0] = CRGB::red;
          leds_UNITA[1] = CRGB::red;
          leds_UNITA[2] = CRGB::red;
          leds_UNITA[3] = CRGB::red;
          leds_UNITA[4] = CRGB::red;
          leds_UNITA[5] = CRGB::red;
          leds_UNITA[6] = CRGB::red;
          leds_UNITA[7] = CRGB::red;
          leds_UNITA[8] = CRGB::red;
          leds_UNITA[9] = CRGB::Black;
          leds_UNITA[10] = CRGB::Black;
          leds_UNITA[11] = CRGB::Black;
          leds_UNITA[12] = CRGB::red;
          leds_UNITA[13] = CRGB::red;
          leds_UNITA[14] = CRGB::red;
          leds_UNITA[15] = CRGB::red;
          leds_UNITA[16] = CRGB::red;
          leds_UNITA[17] = CRGB::red;
          leds_UNITA[18] = CRGB::Black;
          leds_UNITA[19] = CRGB::Black;
          leds_UNITA[20] = CRGB::Black;
          FastLED.show();
        }
        if (numero2 == '6') {
          leds_UNITA[0] = CRGB::red;
          leds_UNITA[1] = CRGB::red;
          leds_UNITA[2] = CRGB::red;
          leds_UNITA[3] = CRGB::red;
          leds_UNITA[4] = CRGB::red;
          leds_UNITA[5] = CRGB::red;
          leds_UNITA[6] = CRGB::red;
          leds_UNITA[7] = CRGB::red;
          leds_UNITA[8] = CRGB::red;
          leds_UNITA[9] = CRGB::Black;
          leds_UNITA[10] = CRGB::Black;
          leds_UNITA[11] = CRGB::Black;
          leds_UNITA[12] = CRGB::red;
          leds_UNITA[13] = CRGB::red;
          leds_UNITA[14] = CRGB::red;
          leds_UNITA[15] = CRGB::red;
          leds_UNITA[16] = CRGB::red;
          leds_UNITA[17] = CRGB::red;
          leds_UNITA[18] = CRGB::red;
          leds_UNITA[19] = CRGB::red;
          leds_UNITA[20] = CRGB::red;
          FastLED.show();
        }
        if (numero2 == '7') {
          leds_UNITA[0] = CRGB::Black;
          leds_UNITA[1] = CRGB::Black;
          leds_UNITA[2] = CRGB::Black;
          leds_UNITA[3] = CRGB::Black;
          leds_UNITA[4] = CRGB::Black;
          leds_UNITA[5] = CRGB::Black;
          leds_UNITA[6] = CRGB::red;
          leds_UNITA[7] = CRGB::red;
          leds_UNITA[8] = CRGB::red;
          leds_UNITA[9] = CRGB::red;
          leds_UNITA[10] = CRGB::red;
          leds_UNITA[11] = CRGB::red;
          leds_UNITA[12] = CRGB::red;
          leds_UNITA[13] = CRGB::red;
          leds_UNITA[14] = CRGB::red;
          leds_UNITA[15] = CRGB::Black;
          leds_UNITA[16] = CRGB::Black;
          leds_UNITA[17] = CRGB::Black;
          leds_UNITA[18] = CRGB::Black;
          leds_UNITA[19] = CRGB::Black;
          leds_UNITA[20] = CRGB::Black;
          FastLED.show();
        }
        if (numero2 == '8') {
          leds_UNITA[0] = CRGB::red;
          leds_UNITA[1] = CRGB::red;
          leds_UNITA[2] = CRGB::red;
          leds_UNITA[3] = CRGB::red;
          leds_UNITA[4] = CRGB::red;
          leds_UNITA[5] = CRGB::red;
          leds_UNITA[6] = CRGB::red;
          leds_UNITA[7] = CRGB::red;
          leds_UNITA[8] = CRGB::red;
          leds_UNITA[9] = CRGB::red;
          leds_UNITA[10] = CRGB::red;
          leds_UNITA[11] = CRGB::red;
          leds_UNITA[12] = CRGB::red;
          leds_UNITA[13] = CRGB::red;
          leds_UNITA[14] = CRGB::red;
          leds_UNITA[15] = CRGB::red;
          leds_UNITA[16] = CRGB::red;
          leds_UNITA[17] = CRGB::red;
          leds_UNITA[18] = CRGB::red;
          leds_UNITA[19] = CRGB::red;
          leds_UNITA[20] = CRGB::red;
          FastLED.show();
        }
        if (numero2 == '9') {
          leds_UNITA[0] = CRGB::red;
          leds_UNITA[1] = CRGB::red;
          leds_UNITA[2] = CRGB::red;
          leds_UNITA[3] = CRGB::red;
          leds_UNITA[4] = CRGB::red;
          leds_UNITA[5] = CRGB::red;
          leds_UNITA[6] = CRGB::red;
          leds_UNITA[7] = CRGB::red;
          leds_UNITA[8] = CRGB::red;
          leds_UNITA[9] = CRGB::red;
          leds_UNITA[10] = CRGB::red;
          leds_UNITA[11] = CRGB::red;
          leds_UNITA[12] = CRGB::red;
          leds_UNITA[13] = CRGB::red;
          leds_UNITA[14] = CRGB::red;
          leds_UNITA[15] = CRGB::Black;
          leds_UNITA[16] = CRGB::Black;
          leds_UNITA[17] = CRGB::Black;
          leds_UNITA[18] = CRGB::Black;
          leds_UNITA[19] = CRGB::Black;
          leds_UNITA[20] = CRGB::Black;
          FastLED.show();
        }
        if (numero2 == '0') {
          leds_UNITA[0] = CRGB::Black;
          leds_UNITA[1] = CRGB::Black;
          leds_UNITA[2] = CRGB::Black;
          leds_UNITA[3] = CRGB::red;
          leds_UNITA[4] = CRGB::red;
          leds_UNITA[5] = CRGB::red;
          leds_UNITA[6] = CRGB::red;
          leds_UNITA[7] = CRGB::red;
          leds_UNITA[8] = CRGB::red;
          leds_UNITA[9] = CRGB::red;
          leds_UNITA[10] = CRGB::red;
          leds_UNITA[11] = CRGB::red;
          leds_UNITA[12] = CRGB::red;
          leds_UNITA[13] = CRGB::red;
          leds_UNITA[14] = CRGB::red;
          leds_UNITA[15] = CRGB::red;
          leds_UNITA[16] = CRGB::red;
          leds_UNITA[17] = CRGB::red;
          leds_UNITA[18] = CRGB::red;
          leds_UNITA[19] = CRGB::red;
          leds_UNITA[20] = CRGB::red;
          FastLED.show();
        }
        if (numero2 == 'A') {
          leds_UNITA[0] = CRGB::Black;
          leds_UNITA[1] = CRGB::Black;
          leds_UNITA[2] = CRGB::Black;
          leds_UNITA[3] = CRGB::Black;
          leds_UNITA[4] = CRGB::Black;
          leds_UNITA[5] = CRGB::Black;
          leds_UNITA[6] = CRGB::Black;
          leds_UNITA[7] = CRGB::Black;
          leds_UNITA[8] = CRGB::Black;
          leds_UNITA[9] = CRGB::Black;
          leds_UNITA[10] = CRGB::Black;
          leds_UNITA[11] = CRGB::Black;
          leds_UNITA[12] = CRGB::Black;
          leds_UNITA[13] = CRGB::Black;
          leds_UNITA[14] = CRGB::Black;
          leds_UNITA[15] = CRGB::Black;
          leds_UNITA[16] = CRGB::Black;
          leds_UNITA[17] = CRGB::Black;
          leds_UNITA[18] = CRGB::Black;
          leds_UNITA[19] = CRGB::Black;
          leds_UNITA[20] = CRGB::Black;
          FastLED.show();
        }
        inputNumero = "";  // Reimposta la stringa dell'input
      }
    }
  }
}
