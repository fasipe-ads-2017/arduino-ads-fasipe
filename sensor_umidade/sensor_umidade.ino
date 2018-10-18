
#define sensorUmidade A0 // Sensor de umidade de solo do módulo
int maximo = 60 * 5;
int contador = maximo;

void setup() {
  Serial.begin(9600); // Inicialização da comunicação serial 
}

void loop() {

  if (contador > maximo) {
    contador = 0;
    
    int leitura = analogRead(sensorUmidade); // Leitura dos dados analógicos vindos do sensor de umidade de solo
    leitura = constrain(leitura, 400, 1023);
    leitura = map(leitura, 400, 1023, 100, 0);
  
    char leituraString[3];
    sprintf(leituraString, "%03d", leitura);
    
    String dado = "UMIDADE:";
    dado = dado + leituraString;
    dado = dado + ";";
    
    Serial.print(dado);
  }

  contador++;
  
  delay(1000);
}
