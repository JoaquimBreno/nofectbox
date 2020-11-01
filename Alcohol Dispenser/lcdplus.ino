#define echoA 4 // echo do alcool
#define trigA 5 // trig do alcool

#define echoM x // echo da mascara
#define trigM x // trig da mascara

#define IN1 2
#define IN2 3

unsigned long int tempoAtual = 0;
unsigned long int tempoPassado = 0;

int distanciaCm(int trig, int echo){
    digitalWrite(trig, LOW);
    delay(10);

    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    int tempo = pulseIn(echo, HIGH);
    int distancia = tempo/58;

    delay(500);
    return distancia;
}

void setup(){

    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(echoA, INPUT);
    pinMode(trigA, OUTPUT);
}

void loop(){

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);

    tempoAtual = millis();

    if(distanciaCm(trigA, echoA) <= 12 && tempoAtual - tempoPassado >= 3000){
      //Gira o Motor no sentido horario
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      delay(500);
      //Desliga o motor
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, HIGH);
      delay(100);
      tempoPassado = tempoAtual;
    }
    delay(10);
}