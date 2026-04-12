#include <Wire.h>
#include <Adafruit_VL53L1X.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define INTERRUPT_PIN 7
#define LED_PIN 8
#define BATTERY_PIN A1
#define BUTTON_PIN 6
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT , &Wire, -1);
Adafruit_VL53L1X sensor(-1, INTERRUPT_PIN);

bool useImperial  = false;

float getBatteryVoltage() {
  return((analogRead(BATTERY_PIN) / 4095.0) * 3.3) * 2.0;
}

int batteryPercent() {
  int percent = (int)(((getBatteryVoltage() - 2.7) / 1.8) * 100);
  return percent < 0 ? 0 : percent > 100 ? 100 : percent;
}

void batteryIcon(int x, int y, int percent) {
  oled.drawRect(x, y, 20, 10, WHITE);
  oled.fillRect(x+20, y+3, 2, 4, WHITE);
  oled.fillRect(x+1, y+1, (int)(18.0*percent / 100), 8, WHITE);
}

void oledError(const char* msg) {
  oled.clearDisplay();
  oled.setCursor(0, 24);
  oled.print(msg);
  while(1) {
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    delay(400);
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  analogReadResolution(12);
  Wire.begin();

  if(!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    oledError("Display failed to start");
  }

  oled.clearDisplay();
  oled.setTextColor(WHITE);
  oled.setCursor(30, 28);
  oled.print("Hermes");
  oled.display();
  delay(1200);

  if(!sensor.begin(0x29, &Wire)) {
    oledError("Sensor failed to start");
  }

  sensor.startRanging();
}

void loop() {
  if(digitalRead(BUTTON_PIN) == LOW) {
    useImperial = useImperial;
    delay(500);
  }

  int16_t distance = -1;
  bool reading = false;

  if(sensor.dataReady()) {
    distance = sensor.distance();
    sensor.clearInterrupt();
    reading = distance > 0;
  }

  digitalWrite(LED_PIN, reading && distance < 500);
  int percent = batteryPercent();
  float voltage = getBatteryVoltage();

  oled.clearDisplay();
  oled.setTextSize(1);
  oled.setCursor(0, 0);
  oled.print("Hermes");

  batteryIcon(95, 0, percent);
  oled.setCursor(100, 12);
  oled.print(percent);
  oled.print("%");

  oled.drawLine(0, 16, 127, 16, WHITE);
  oled.setTextSize(2);
  oled.setCursor(0, 24);

  if(reading) {
    if(useImperial) {
      float inches = distance / 25.4;
      if(inches >= 12.0) {
        int feet = (int)(inches / 12);
        float remainingInches = inches - (feet * 12);
        oled.print(feet);
        oled.setTextSize(1);
        oled.print("ft ");
        oled.setTextSize(2);
        oled.print(remainingInches, 1);
        oled.setTextSize(1);
        oled.print("in");
      } else {
        oled.print(inches, 1);
        oled.setTextSize(1);
        oled.print(" in");
      }
    } else {
      if(distance >= 1000) {
        oled.print(distance / 10);
        oled.setTextSize(1);
        oled.print(" cm");
      } else {
        oled.print(distance);
        oled.setTextSize(1);
        oled.print(" mm");
      }
    }
  } else {
    oled.print("---");
  }
  if(percent < 20) {
    oled.setTextSize(1);
    oled.setCursor(0, 54);
    oled.print("Low Battery (");
    oled.print(voltage, 1);
    oled.print("v)");
  }

  oled.display();
  delay(100);
}