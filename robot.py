import serial
import keyboard

# Arduino ile seri iletişim kur
ser = serial.Serial('COM7', 9600)  # Arduino'nun bağlı olduğu port
print("Robot kolu kontrol etmek için: w (yukarı), s (aşağı), a (sol), d (sağ), i (ileri), k (geri), o (tut), l (bırak)")

try:
    while True:
        if keyboard.is_pressed('w'):
            ser.write(b'w')  # Yukarı hareket
        elif keyboard.is_pressed('s'):
            ser.write(b's')  # Aşağı hareket
        elif keyboard.is_pressed('a'):
            ser.write(b'a')  # Sol hareket
        elif keyboard.is_pressed('d'):
            ser.write(b'd')  # Sağ hareket
        elif keyboard.is_pressed('i'):
            ser.write(b'i')  # İleri hareket
        elif keyboard.is_pressed('k'):
            ser.write(b'k')  # Geri hareket
        elif keyboard.is_pressed('o'):
            ser.write(b'o')  # Tut
        elif keyboard.is_pressed('l'):
            ser.write(b'l')  # Bırak
except KeyboardInterrupt:
    print("Çıkılıyor...")
finally:
    ser.close()
