int leituraSensor; 
int LedA = 13; //led azul
int LedV = 6; //led vermelho
int LedG = 5; // led verde
int sensor = A0; //sensor umidade
int rele = 2; //rele bomba dagua

bool irrigar = false;


void setup() {
  Serial.begin(9600);

  pinMode(rele, OUTPUT);
  pinMode (sensor, INPUT); 
  pinMode (LedA, OUTPUT);
  pinMode (LedV, OUTPUT);
  pinMode(LedG, OUTPUT);

  leituraSensor = 0;

  digitalWrite(rele, HIGH); // relé é ao contrario, definir HIGH deixa desligado

}

void loop() {
  
 leituraSensor = analogRead(sensor); 
 
 irrigar = digitalRead(sensor);

 if(irrigar){
  digitalWrite(rele,LOW);
 }
 else{
  digitalWrite(rele, HIGH);
 }
 
    if (leituraSensor >850){ // quando sensor estiver seco
        delay(120); //espera em milissegundos
        digitalWrite(LedA, LOW);
        digitalWrite(LedV, HIGH);
        digitalWrite(LedG, LOW);
        delay(100);

    }
    if (leituraSensor >500 && leituraSensor <800){ // sensor meio molhado
        delay(120);
        digitalWrite(LedA, LOW);
        digitalWrite(LedG, HIGH);
        digitalWrite(LedV, LOW);
        delay(100);
      
    }
    if (leituraSensor <500){ // sensor molhado
        delay(120);
        digitalWrite(LedA, HIGH);
        digitalWrite(LedV, LOW);
        digitalWrite(LedG, LOW);
        delay(100);
    }
    Serial.println(leituraSensor);


}
