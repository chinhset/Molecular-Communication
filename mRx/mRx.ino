
int sume = 0, j = 0, x = 0, a1, a2, b[7];
char c[256];
void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(3, INPUT);
  Serial.begin(9600);
  Serial.println("Start!!!");
}

void loop() {
  if(!digitalRead(3)){
    Serial.println("Start decoder!!!\n");
    delay(900);
    Decoder();
  }
}

void Decoder(){
  while(1){
    for(int i = 0; i < 7; i++){
      a1 = analogRead(A0);
      Serial.print(a1);
      delay(500);
      a2 = analogRead(A0);
      Serial.print(a2);
//      if(i > 0){
        if(a2 > a1 + 10){
          b[i] = 1;
          Serial.print("    bit: ");
          Serial.print(b[i]);
          Serial.print(";    ");
          sume += 1;
        }
        else{
          b[i] = 0;
          Serial.print("    bit: ");
          Serial.print(b[i]);
          Serial.print(";     ");
        }
//      }
      delay(700);
    }
    if(sume){
      Serial.print("\nsume: ");
      Serial.print(sume);
      Serial.print(";     ");
      for(int i =0; i < 7; i++){
        x += (b[i] << (6 - i));
      }
      c[j] = char(x);
      Serial.print("\nchar: ");
      Serial.println(c[j]);
      x = 0;
      sume = 0;
      j++;
    }
    else{
      Serial.print("\nEnd decoder!!!  ");
      Serial.print("Received message: "); 
      for(int i = 0; i < j; i++)
        Serial.print(c[i]);
      j = 0;
      sume = 0;
      break;
    }
  }
}

