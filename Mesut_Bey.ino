// Created by Gökhan TERCAN, SCHOTT Orim

const int TOUCH_SENSOR_PIN  = 2; // Arduino üzerinden Dokunma Sensörünün bağlı olduğu dijital pin
const int RELAY_PIN         = 3; // Röle'yi bağladığımız digital pin

int relayState = LOW;    // LED'in mevcut durumu
int lastTouchState;    // dokunma sensörünün bir önceki durumu
int currentTouchState; // dokunma sensörün mevcut durumu

void setup() {
  Serial.begin(9600);               // Serial haberleşme başlatıyoruz, monitrden izleyebiliriz.
  pinMode(TOUCH_SENSOR_PIN, INPUT); // Dokunmatik sensörü giriş olarak tanımlıyoruz.
  pinMode(RELAY_PIN, OUTPUT);         // Çıkış olarak da LED tanımlıyoruz.

  currentTouchState = digitalRead(TOUCH_SENSOR_PIN);
}

void loop() {
  lastTouchState    = currentTouchState;             // Bir önceki durumunu kaydettiriyoruz. 
  currentTouchState = digitalRead(TOUCH_SENSOR_PIN); // Yeni durumu okutuyoruz. 

  if(lastTouchState == LOW && currentTouchState == HIGH) {
    Serial.println("Sensöre dokunuldu.");

    // rölenin değişkenli durumunu yazdırıyoruz.
    relayState = !relayState;

    // Anahtar durumuna göre rölenin sağlıyoruz.
    digitalWrite(RELAY_PIN, relayState); 
  }
}
