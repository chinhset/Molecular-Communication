int b[7];
char sume = 0, c[256];
void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  Serial.begin(9600);
  Serial.print("Start!!!\n");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    char data = Serial.read();
    Serial.print(Serial.available());
    if(data == '!'){
      Encoder();
      Serial.print("\nSended message: ");
      for(int i = 0; i < sume; i++)
        Serial.print(c[i]);
      sume = 0;
    }
    else{
      c[sume] = data;
      sume++;
    }
  }
}
  // Convert char to binary and crate pwm
void Encoder(){
  digitalWrite(2, 1);
  delay(200);
  digitalWrite(2, 0);
  delay(1000);
  for(int i = 0; i < sume; i++){
    for(int j = 6; j >= 0; j--){
      b[j] = (c[i] >> j) & 1;
      digitalWrite(2, b[j]);
      Serial.print(b[j]);
      delay(200);
      digitalWrite(2, 0);
      delay(1000);
    }
    Serial.println(c[i]);
  }
  digitalWrite(2, 0);
}
