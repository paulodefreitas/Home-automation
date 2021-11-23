const int sensor_ldr = 10;     // pino de leitura digital do sensor
const int rele =  4;      // pino de comando do modulo rele
 
void setup() {
  // define o pino relativo ao rele de saida
  pinMode(rele, OUTPUT);
  // define o pino relativo ao sensor como entrada digital
  pinMode(sensor_ldr, INPUT);
}
 
void loop() {
  // lê o estado do sensor e armazena na variavel leitura
  int leitura = digitalRead(sensor_ldr);
 
  // verifica se há luz ambiente. Se não houver, aciona rele
  if (leitura == LOW) {
    // aciona rele (obs: este rele é acionado em nivel LOW)
    digitalWrite(rele, LOW);
  } else {
    // desliga rele
    digitalWrite(rele, HIGH);
  }
}
