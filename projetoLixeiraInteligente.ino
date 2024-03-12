#include <Servo.h>        //incluindo biblioteca do Servo

#define pino_trigger 4    //porta digital 4
#define pino_echo 5       //porta digital 5

//declaração de variáveis 

Servo motor;           //variável para manipular o servo
long tempo = 0;        //variável para calcular distância
int distancia = 0;     //variável que armazena a distância

void setup() {
  // indicando para o arduíno quais portas vamos usar
  pinMode(pino_trigger, OUTPUT);    //trig = saída
  pinMode(pino_echo, INPUT);        //echo = entrada
  
  motor.attach(2);  //sinal no pino 2
  motor.write(0);   //servo inicializa com angulação zero
  
  Serial.begin(9600);
}

//função personalizada para atualizar a distancia
void verificaDistancia(){   
  digitalWrite(pino_trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pino_trigger, LOW);

  tempo = pulseIn(pino_echo, HIGH);
  distancia = tempo * 0.017; 
}

void loop() {

  verificaDistancia();
  
  Serial.print(distancia);  // imprime a distância atual
  Serial.println(" cm");
  delay(100);
  
  int controle = 1; //uma vez que a tampa esteja aberta, o motor não acionará novamente
  
  while(distancia <= 20){
    if(controle == 1){
      for(int i=0; i<=90; i+=30){ //motor (com 0°) rotaciona de 30 em 30°, até 90°
        motor.write(i);
      delay(500);
      } 
    }
    controle = 2;   //para que o motor feche a tampa apenas se ela já foi aberta anteriormente
    verificaDistancia();
  }
  
  if(distancia > 20 && controle == 2){
    delay(5000);
    for(int i=90; i>=0; i-=10){ //motor (com 90°) rotaciona de 10 em 10°, até 0°
      motor.write(i);
        delay(1500);
    }
  }
  
}