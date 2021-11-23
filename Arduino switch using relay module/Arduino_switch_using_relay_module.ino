int buttonPin = 3; // pino D3 para botao
int ledPin = 13; // LED na placa Arduino
int IN1 = 2; // pino D2 para controle do rele
int ledState = LOW; // estado do LED = LOW
int buttonState; // variavel do estado do botao
int lastButtonState = LOW; // estado previo do botao = LOW
unsigned long lastDebounceTime = 0; // ultimo tempo de debounce
unsigned long debounceDelay = 50; // timer do debounce 50 ms
void setup()
{
  pinMode(ledPin, OUTPUT); // pino do LED = saida
  pinMode(buttonPin, INPUT); // pino do botao = entrada
  pinMode(IN1, OUTPUT); // pino de controle do rele = saida
  digitalWrite(ledPin, ledState); // apaga o LED
  digitalWrite(IN1, ledState); // desliga o rele
}

void loop()
{
  int reading = digitalRead(buttonPin); // le o estado do botao
  if (reading != lastButtonState) // se o estado for diferente do anterior
  {
    lastDebounceTime = millis(); // reset do timer debouncing
  }
  if ((millis() - lastDebounceTime) > debounceDelay)
  {
    // se o tempo do botao pressionado for maior do que debounce
    if (reading != buttonState) // se o estado do botao for diferente do anterior
    {
      buttonState = reading; // muda o estado do botao
      if (buttonState == HIGH) // se o botao esta no nivel High
      {
        ledState = !ledState; // muda o estado do LED
      }
    }
  }
  digitalWrite(ledPin, ledState); // seta o LED
  digitalWrite(IN1, ledState); // seta o estado do rele 1
  lastButtonState = reading; // salva a leitura do botao
}
