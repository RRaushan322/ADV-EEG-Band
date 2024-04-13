  #include "BluetoothSerial.h" 
  

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#define ledPIN 2
 #define SAMPLE_RATE 256 
#define BAUD_RATE 115200
#define INPUT_PIN A0  

BluetoothSerial SerialBT;
byte BTData;
void setup() {
  pinMode(ledPIN, OUTPUT);
  Serial.begin(BAUD_RATE); 
   SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() { 
  
  if(SerialBT.available())
  {
    BTData = SerialBT.read();
    Serial.write(BTData);
  }

  /* If received Character is 1, then turn ON the LED */
  /* You can also compare the received data with decimal equivalent */
  /* 48 for 0 and 49 for 1 */
  /* if(BTData == 48) or if(BTData == 49) */
  if(BTData == '1')
  {
    digitalWrite(ledPIN, HIGH);
  }
  
  /* If received Character is 0, then turn OFF the LED */
  if(BTData == '0')
  {
    digitalWrite(ledPIN, LOW);
  }


  
  // Calculate elapsed time
  static unsigned long past = 0;
  unsigned long present = micros();
  unsigned long interval = present - past;
  past = present;

  // Run timer
  static long timer = 0;
  timer -= interval;

  // Sample
  if(timer < 0){
    timer += 1000000 / SAMPLE_RATE;
    float sensor_value = analogRead(INPUT_PIN);
    float signal = EEGFilter(sensor_value);
    Serial.println(signal);
    SerialBT.print(signal);

SerialBT.print(";");
  }
}

// Band-Pass Butterworth IIR digital filter, generated using filter_gen.py.
// Sampling rate: 256.0 Hz, frequency: [0.5, 29.5] Hz.
// Filter is order 4, implemented as second-order sections (biquads).
// Reference: 
// https://docs.scipy.org/doc/scipy/reference/generated/scipy.signal.butter.html
// https://courses.ideate.cmu.edu/16-223/f2020/Arduino/FilterDemos/filter_gen.py
float EEGFilter(float input) {
  float output = input;
  {
    static float z1, z2; // filter section state
    float x = output - -0.95391350*z1 - 0.25311356*z2;
    output = 0.00735282*x + 0.01470564*z1 + 0.00735282*z2;
    z2 = z1;
    z1 = x;
  }
  {
    static float z1, z2; // filter section state
    float x = output - -1.20596630*z1 - 0.60558332*z2;
    output = 1.00000000*x + 2.00000000*z1 + 1.00000000*z2;
    z2 = z1;
    z1 = x;
  }
  {
    static float z1, z2; // filter section state
    float x = output - -1.97690645*z1 - 0.97706395*z2;
    output = 1.00000000*x + -2.00000000*z1 + 1.00000000*z2;
    z2 = z1;
    z1 = x;
  }
  {
    static float z1, z2; // filter section state
    float x = output - -1.99071687*z1 - 0.99086813*z2;
    output = 1.00000000*x + -2.00000000*z1 + 1.00000000*z2;
    z2 = z1;
    z1 = x;
  }
  return output;
} 
