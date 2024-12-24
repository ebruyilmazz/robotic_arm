#include <Servo.h>

Servo servoX; // Sol-sağ ekseni
Servo servoY; // İleri-geri ekseni
Servo servoZ; // Yukarı-aşağı ekseni
Servo servoGrip; // Tutma mekanizması

void setup() {
  Serial.begin(9600); // Seri iletişim başlat
  servoX.attach(6);   // X ekseni servo pini
  servoY.attach(3);  // Y ekseni servo pini
  servoZ.attach(9);  // Z ekseni servo pini
  servoGrip.attach(5); // Tutma mekanizması servo pini

  // Başlangıç pozisyonları
  servoX.write(90); 
  servoY.write(90);
  servoZ.write(90);
  servoGrip.write(0); // Açık pozisyon
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read(); // Bilgisayardan gelen komutu oku

    switch (command) {
      case 'w': servoZ.write(servoZ.read() - 10); break; // Yukarı
      case 's': servoZ.write(servoZ.read() + 10); break; // Aşağı
      case 'a': servoX.write(servoX.read() - 10); break; // Sol
      case 'd': servoX.write(servoX.read() + 10); break; // Sağ
      case 'i': servoY.write(servoY.read() - 10); break; // İleri
      case 'k': servoY.write(servoY.read() + 10); break; // Geri
      case 'o': servoGrip.write(45); break; // Tut
      case 'l': servoGrip.write(0); break; // Bırak
    }
  }
}
