int led = 13; //not necessary

void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  Serial.begin(115200);
}

// the loop routine runs over and over again forever:
void loop() {
  if (Serial.available() > 0) {
    int nums[4] = {0};
    int x = 0;
    while (Serial.available()){
      nums[x] = Serial.read() % 48;
      x++;
    }
    //Serial.write(flashes + 48);
    //Serial.write("\n");
    int flashes;
    switch(x){
      case 1:
        flashes = nums[0];
        break;
      case 2:
        flashes = 10*nums[0] + nums[1];
        break;
      case 3:
        flashes = 100*nums[0] + 10*nums[1] + nums[2];
        break;
      case 4:
        flashes = 1000*nums[0] + 100*nums[1] + 10*nums[2] + nums[3];
        break;
      default:
        break;
    }
    for (int i = 0; i < x; i++){
      Serial.write(nums[i]+48);
    }
    Serial.write("\n");
    for (int i = 0; i < flashes; i++) {
      digitalWrite(led, HIGH);
      delay(200);
      digitalWrite(led, LOW);
      delay(200);
    }
  }
}
