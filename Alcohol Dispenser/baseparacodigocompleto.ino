#define echoA 4 // echo do alcool
#define trigA 5 // trig do alcool

#define echoM 8 // echo da mascara
#define trigM 9 // trig da mascara

#define IN1 2 // entradas do motor do alcool
#define IN2 3

#define IN3 6 // entradas do motor da máscara
#define IN4 7

unsigned long int tempoPassadoA = 0;//armazena o período entre o inicio do Arduino até a última atividade do motor do alcool
unsigned long int tempoPassadoM = 0;//armazena o período entre o inicio do Arduino até a última atividade do motor do alcool

int distanciaCm(int trig, int echo){//função que verifica a distância entre o sensor e a mão
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
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(echoA, INPUT);
    pinMode(trigA, OUTPUT);
    pinMode(echoM, INPUT);
    pinMode(trigM, OUTPUT);
}

void loop(){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);   
    alcooldispenser();
    maskdispenser();
}

void alcooldispenser(){// função que verifica se teve alguma atividade nos últimos 3 segundos e algum objeto a 12 cm de distância 
    if(distanciaCm(trigA, echoA) <= 12 && millis() - tempoPassadoA >= 3000){// quando as condições acima descritas são aceitas, liga o motor do álcool
      //Gira o Motor no sentido horario
      digitalWrite(IN2, LOW);
      delay(500);
      //Desliga o motor
      digitalWrite(IN2, HIGH);
      delay(100);
      tempoPassadoA=millis();// registra o tempo da última atividade do motor
    }
     delay(10);
}

void maskdispenser(){// função que verifica se teve alguma atividade nos últimos 3 segundos e algum objeto a 12 cm de distância 
    if(distanciaCm(trigM, echoM) <= 12 && millis() - tempoPassadoA >= 3000){// quando as condições acima descritas são aceitas, liga o motor da mácara
      //Gira o Motor no sentido horario
      digitalWrite(IN4, LOW);
      delay(x);
      //Desliga o motor
      digitalWrite(IN4, HIGH);
      lcd();// função para calcular o número de máscaras do lcd
      delay(100);
      tempoPassadoA=millis();// registra o tempo da última atividade do motor
    }
     delay(10);
}

void lcd(){
    
}
