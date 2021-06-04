#include <Wire.h>
#include "MAX30100_PulseOximeter.h"
#include "RandomForest.h"
#include "SensorSuhu.h"
#include "MonitorLCD.h"

#define S0 8
#define S1 9
#define S2 10
#define S3 11
#define sensorOut 12

#define FLEX_PIN A0
#define FLEX_MAX_READ 30
#define FLEX_READ_INTERVAL 100

#define LCD_ADDRESS 0x27
#define LCD_ROWS 2
#define LCD_COLS 16

#define BUTTON_NEXT 2
#define BUTTON_BACK 3
#define BUTTON_RESET 4

#define RED_MIN_VAL 65
#define RED_MAX_VAL 310
#define GREEN_MIN_VAL 62
#define GREEN_MAX_VAL 250
#define BLUE_MIN_VAL 40
#define BLUE_MAX_VAL 180

#define MAX_STATE 9

#define LCD_REFRESH_INTERVAL 500

IRTherm therm;
Eloquent::ML::Port::RandomForest classifier;
SensorSuhu* sensorSuhu;
MonitorLCD* monitorLCD;
PulseOximeter pox;

int redFrequency = 0, greenFrequency = 0, blueFrequency = 0;
int redColor = 0, greenColor = 0, blueColor = 0;

uint8_t spO2, active_state = 1, prev_state = 1;
float heartRate;
int flex, flexes[FLEX_MAX_READ], flexPivot = 0;
bool nextButton, currentNextButton, backButton, currentBackButton, resetButton, currentResetButton;
double suhuBadan;
String prediction_result, line1, line2;
String spO2Text, rgbText, suhuText, flexText;

unsigned long t_start = 0, t_current = 0, t_flex_last_checked = 0, prediction_time_taken = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("Begin");
  monitorLCD = new MonitorLCD(LCD_ADDRESS, LCD_COLS, LCD_ROWS);
  setupSPO2();
  sensorSuhu = new SensorSuhu(&therm);
  setupWarna();
  setupFlex();
}

void loop() {
  t_current = millis() - t_start;

  nextButton = digitalRead(BUTTON_NEXT);
  backButton = digitalRead(BUTTON_BACK);
  resetButton = digitalRead(BUTTON_RESET);

  // If next button pressed
  if (currentNextButton == 0 && nextButton == 1) {
    active_state++;
  }

  // If back button pressed
  if (currentBackButton == 0 && backButton == 1) {
    active_state--;
  }

  // If reset button pressed
  if (currentResetButton == 0 && resetButton == 1) {
    active_state = 1;
  }

  if (active_state > MAX_STATE || active_state < 1) active_state = 1;

  if (prev_state != active_state) {
    end_state(prev_state);
    setup_state(active_state);
  }

  loop_state();

  if (t_current >= LCD_REFRESH_INTERVAL) {
    monitorLCD->clear();
    monitorLCD->showText(0, 0, line1.c_str());
    monitorLCD->showText(1, 0, line2.c_str());
    t_start = millis();
  }

  currentNextButton = nextButton;
  currentBackButton = backButton;
  currentResetButton = resetButton;
  prev_state = active_state;
}

void setup_state(int state) {
  switch (state) {
    case 1:
      state_1_setup();
      break;
    case 2:
      state_2_setup();
      break;
    case 3:
      state_3_setup();
      break;
    case 4:
      state_4_setup();
      break;
    case 5:
      state_5_setup();
      break;
    case 6:
      state_6_setup();
      break;
    case 7:
      state_7_setup();
      break;
    case 8:
      state_8_setup();
      break;
    case 9:
      state_9_setup();
      break;
  }
}

void loop_state() {
  switch (active_state) {
    case 1:
      state_1_loop();
      break;
    case 2:
      state_2_loop();
      break;
    case 3:
      state_3_loop();
      break;
    case 4:
      state_4_loop();
      break;
    case 5:
      state_5_loop();
      break;
    case 6:
      state_6_loop();
      break;
    case 7:
      state_7_loop();
      break;
    case 8:
      state_8_loop();
      break;
    case 9:
      state_9_loop();
      break;
  }
}

void end_state(int state) {
  switch (state) {
    case 1:
      state_1_end();
      break;
    case 2:
      state_2_end();
      break;
    case 3:
      state_3_end();
      break;
    case 4:
      state_4_end();
      break;
    case 5:
      state_5_end();
      break;
    case 6:
      state_6_end();
      break;
    case 7:
      state_7_end();
      break;
    case 8:
      state_8_end();
      break;
    case 9:
      state_9_end();
      break;
  }
}

// STATE 1
void state_1_setup() {
  pox.resume();
}

void state_1_loop() {
  max30100();
  spO2Text = (String) spO2;
  line1 = "Kadar Oksigen";
  line2 = "SpO2: " + spO2Text;
}

void state_1_end() {
  pox.shutdown();
}

// STATE 2
void state_2_setup() {
  line1 = "Anda yakin?";
  line2 = "SpO2: " + spO2Text;
}

void state_2_loop() {}

void state_2_end() {}

// STATE 3
void state_3_setup() {
  line1 = "Warna Kuku";
}

void state_3_loop() {
  readColor();
  rgbText = String(redColor) + "," + String(greenColor) + "," + String(blueColor);
  line2 = "RGB: " + rgbText;
}

void state_3_end() {}

// STATE 4
void state_4_setup() {
  line1 = "Anda yakin?";
  line2 = "RGB: " + rgbText;
}

void state_4_loop() {}

void state_4_end() {}

// STATE 5
void state_5_setup() {
  line1 = "Suhu Badan";
}

void state_5_loop() {
  suhuBadan = sensorSuhu->getObjectTemperature();
  suhuText = String(suhuBadan, 2);
  line2 = "Suhu: " + suhuText;
}

void state_5_end() {}

// STATE 6
void state_6_setup() {
  line1 = "Anda yakin?";
  line2 = "Suhu: " + suhuText;
}

void state_6_loop() {}

void state_6_end() {}

// STATE 7
void state_7_setup() {
  line1 = "Respirasi";
}

void state_7_loop() {
  readFlex();
  flexText = (String) flex;
  line2 = "Flex: " + flexText;
}

void state_7_end() {}

// STATE 8
void state_8_setup() {
  line1 = "Anda yakin?";
  line2 = "Flex: " + flexText;
}

void state_8_loop() {}

void state_8_end() {}

// STATE 9
void state_9_setup() {
  monitorLCD->clear();
  monitorLCD->showText(0, 0, "Memprediksi");
  monitorLCD->showText(1, 0, "...");

  prediction_result = prediction(redColor, greenColor, blueColor, spO2, suhuBadan, flex);

  Serial.print("Red: ");
  Serial.println(redColor);
  Serial.print("Green: ");
  Serial.println(greenColor);
  Serial.print("Blue: ");
  Serial.println(blueColor);
  Serial.print("SpO2: ");
  Serial.println(spO2);
  Serial.print("Suhu: ");
  Serial.println(suhuBadan);
  Serial.print("Flex: ");
  Serial.println(flex);
  Serial.print("Hasil Prediksi: ");
  Serial.println(prediction_result);
  Serial.print("Waktu klasifikasi: ");
  Serial.println(prediction_time_taken);

  line1 = "Hasil prediksi: ";
  line2 = prediction_result.c_str();
}

void state_9_loop() {}

void state_9_end() {}

String prediction(int r, int g, int b, int spO2, float temperature, int flex) {
  float data[] = {r, g, b, spO2, temperature, flex};
  prediction_time_taken = micros();
  int predict_result = classifier.predict(data);
  prediction_time_taken = micros() - prediction_time_taken;
  switch (predict_result) {
    case 0:
      return "Normal";
      break;
    case 1:
      return "Pneumonia";
      break;
    case 2:
      return "TB";
      break;
    default:
      return "Unknown";
      break;
  }
}

void setupSPO2() {
  Serial.print("Initializing pulse oximeter..");
  if (!pox.begin()) {
    Serial.println("FAILED");
    for (;;);
  } else {
    Serial.println("SUCCESS");
  }
  pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
}

void max30100() {
  pox.update();
  spO2 = pox.getSpO2();
}

void setupWarna() {
  // Setting the outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  // Setting the sensorOut as an input
  pinMode(sensorOut, INPUT);
  
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
}

void readColor() {
  // Read red color
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  redFrequency = pulseIn(sensorOut, LOW);
  redColor = map(redFrequency, RED_MIN_VAL, RED_MAX_VAL, 255, 0);
  if (redColor > 255) redColor = 255;
  else if (redColor < 0) redColor = 0;

  // Read green color
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  greenFrequency = pulseIn(sensorOut, LOW);
  greenColor = map(greenFrequency, GREEN_MIN_VAL, GREEN_MAX_VAL, 255, 0);
  if (greenColor > 255) greenColor = 255;
  else if (greenColor < 0) greenColor = 0;

  // Read blue color
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  blueFrequency = pulseIn(sensorOut, LOW);
  blueColor = map(blueFrequency, BLUE_MIN_VAL, BLUE_MAX_VAL, 255, 0);
  if (blueColor > 255) blueColor = 255;
  else if (blueColor < 0) blueColor = 0;
}

void setupFlex() {
  pinMode(FLEX_PIN, INPUT);
}

void readFlex() {
  if (millis() - t_flex_last_checked > FLEX_READ_INTERVAL) {
    int rawVal = analogRead(FLEX_PIN);
    flexes[flexPivot] = map(rawVal, 0, 756, 0, 1023);
    Serial.println(flexes[flexPivot]);
    flexPivot++;
    if (flexPivot == FLEX_MAX_READ) {
      flexPivot = 0;
      int high = flexes[0];
      int low = flexes[0];
      for (int i = 0; i < 10; i++) {
        if (high < flexes[i]) {
          high = flexes[i];
        } else if (low > flexes[i]) {
          low = flexes[i];
        }
      }
      flex = high - low;
      Serial.print("High: ");
      Serial.print(high);
      Serial.print(", Low: ");
      Serial.print(low);
      Serial.print(", Flex: ");
      Serial.println(flex);
    }

    t_flex_last_checked = millis();
  }
}
