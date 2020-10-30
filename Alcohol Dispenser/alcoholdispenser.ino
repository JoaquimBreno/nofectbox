/* 
  FASE INICIAL DO PROJETO -> SOFTWARE DO DISPENSER DE ÁLCOOL
  ------------------Alcohol Dispenser-----------------------
    Comented and Developed by Joaquim Breno 
*/


#define echo 4 // define o echo do sensor HC-SR04 no pino 4
#define trig 5 // define o echo do sensor HC-SR04 no pino 5

unsigned long tempo; // variável de tamanho extendido para o tempo medido em echo
double distancia; // mede a distância


int IN1 = 2; // variáveis da ponte h no arduino
int IN2 = 3;

void setup(){
 pinMode(IN1, OUTPUT); // configura as portas de ponte-h como saída
 pinMode(IN2, OUTPUT);
 pinMode(echo, INPUT); // configura o echo como entrada 
 pinMode(trig, OUTPUT); // configura o trigger como entrada 
 Serial.begin(9600); 
}

void loop(){
  ultra(); // função void ultra()

  digitalWrite(IN1, HIGH); // Entradas em VCC ( motor parado )
  digitalWrite(IN2, HIGH);

  if(distancia <= 12){
    //Gira o Motor no sentido horario
    Serial.println("Ligado");
    digitalWrite(IN1, HIGH); // VCC
    digitalWrite(IN2, LOW); // GND
    delay(500);
    digitalWrite(IN1, HIGH); // VCC
    digitalWrite(IN2, HIGH); // VCC
    delay(5000); 
  }
  delay(10);
}

void ultra(){
    digitalWrite(trig, LOW);
    delay(10);

    digitalWrite(trig, HIGH);// Define o trigger como high // envia os 8 sinais de 40kHz
    delayMicroseconds(10);//10 micro segundos 
    digitalWrite(trig, LOW);// Define o trigger como low
    tempo= pulseIn(echo, HIGH);// o tempo é lido pelo echo 
    distancia = tempo/58;//Corrige a distância  
    // 340m/s -> 34000 cm/s --(divide por dois, ida e volta do sinal)-> 17000cm/s
    // 10^6 us ( microsegundos, o equivalente a um segundo) == 17000 cm
    // x us == 1 cm
    // 
    Serial.println(distancia);//ter certeza que tava exibindo a distancia entre o objeto e o sensor 
    delay(500);
}