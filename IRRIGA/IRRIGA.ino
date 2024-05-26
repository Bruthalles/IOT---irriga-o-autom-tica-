int rele = 7;

void setup(){
  Serial.begin(9600);
  pinMode(A0, INPUT); //sensor 
  pinMode(rele, OUTPUT); 
}
void loop (){
  
  int leituraSensor = analogRead(A0);
  int dadoRele = digitalRead(rele);

  if(leituraSensor > 900){ // sensor seco
    
    delay(1000);    
    digitalWrite(8, HIGH); //led on
    digitalWrite(7, LOW); // rele on
  }
  else{
  
    digitalWrite(8, LOW);   //led on
    digitalWrite(7, HIGH); // rele off
    delay(5000); // após molhar, espera 5 segundos para ler de novo
  }
  
  Serial.print("Umidade: ");
  Serial.println(leituraSensor);
  Serial.println("___________");
  Serial.print("rele: ");
  Serial.println(dadoRele); 
}