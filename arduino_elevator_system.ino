#include <Adafruit_LiquidCrystal.h> //Adicionando a biblioteca do LCD
#define T 13 //Definindo variaveis com botões
#define AA1 12 //Definindo variaveis com botões
#define AA2 11 //Definindo variaveis com botões
#define AA3 10 //Definindo variaveis com botões
#define PAT 7 //Definindo variaveis com botões
#define PA1 6 //Definindo variaveis com botões
#define PA2 5 //Definindo variaveis com botões
#define PA3 4 //Definindo variaveis com botões
#define MD 3 //Definindo variaveis com botões
#define MS 2 //Definindo variaveis com botões

int aux, aux1, aux2, aux3; //Declaração das variaveis

Adafruit_LiquidCrystal lcd_1(0);// Nomeando o LCD

void setup()
{//Definição de pinos como entradas ou saídas
  pinMode(13, INPUT); //Pino de Seleção do Terreo
  pinMode(12, INPUT); //Pino de Seleção do Andar 1
  pinMode(11, INPUT); //Pino de Seleção do Andar 2
  pinMode(10, INPUT); //Pino de Seleção do Andar 3
  pinMode(7, INPUT); //Pino do Sensor do Terreo
  pinMode(6, INPUT); //Pino do Sensor do Andar 1
  pinMode(5, INPUT); //Pino do Sensor do Andar 2
  pinMode(4, INPUT); //Pino do Sensor do Andar 3
  pinMode(3, OUTPUT); //Pino Sentido Anti-Horário do Motor
  pinMode(2, OUTPUT); //Pino Sentido Horário do Motor
  lcd_1.begin(16, 2);//liga o LCD
}

void loop()
{
  if(digitalRead(PAT)==1  && aux==0 && aux1==0 && aux2==0 && aux3==0) //Se o sensor do térreo estiver acionado e as variaveis estiverem em 0 irá fazer a seguinte condição
  {
   lcd_1.setCursor(1, 0); //Seta o cursor
   lcd_1.print("Terreo"); //Indica qual andar está
   lcd_1.setCursor(1, 1); //Seta o cursor na linha 2
   lcd_1.print("Qual andar ?");
   aux=0;
  }
    
   if(digitalRead(T)==1 && digitalRead(PAT)==1) //Se o sensor do térreo e do botão térreo estiver acionado irá fazer a seguinte condição
   {
   lcd_1.setCursor(1, 0); //Seta o cursor na linha 1
   lcd_1.print("Terreo"); //Indica qual andar está
   lcd_1.setCursor(1, 1); //Seta o cursor na linha 2
   lcd_1.print("Ja esta no T");
   }
    
   if(digitalRead(PAT)==1 && digitalRead(12)==1) //Térreo para andar 1
   {
   aux=1; //Selo
   }
  if(aux==1) //Condição do Selo
  {
   lcd_1.setCursor(1, 0); //Seta o cursor na linha 1
   lcd_1.print("Terreo"); //Indica qual andar está
   lcd_1.setCursor(1, 1); //Seta o cursor na linha 2
   lcd_1.print("Subindo"); //Indica se está subindo ou descendo
   digitalWrite(2, HIGH); //Sentido para o motor subir
   digitalWrite(3, LOW); //Sentido para o motor subir
   if(digitalRead(PA1)==1) //chegou ao andar 1?
   {
   lcd_1.clear(); //Limpa o LCD
   lcd_1.setCursor(1, 0); //Seta o cursor na linha 1
   lcd_1.print("Primeiro Andar"); //Indica qual andar está
   lcd_1.setCursor(1, 1); //Seta o cursor na linha 2
   lcd_1.print("Qual andar ?");
   digitalWrite(3, LOW); //Faz o motor parar
   digitalWrite(2, LOW); //Faz o motor parar
   aux=0; //Deixa em zero a variavel de selo
   }
  }  
  
   if(digitalRead(PAT)==1 && digitalRead(11)==1)//terreo para andar 2
   {
    aux=2; //Selo
   }
   if(aux==2) //Condição do Selo
   {
   lcd_1.setCursor(1, 0); //Seta o cursor na linha 1
   lcd_1.print("Terreo"); //Indica qual andar está
   lcd_1.setCursor(1, 1); //Seta o cursor na linha 2
   lcd_1.print("Subindo"); //Indica se está subindo ou descendo
   digitalWrite(2, HIGH); //Sentido para o motor subir
   digitalWrite(3, LOW); //Sentido para o motor subir
   if(digitalRead(PA2)==1)//chegou ao andar 2?
   {
   lcd_1.clear(); //Limpa o LCD //Limpa o LCD
   lcd_1.setCursor(1, 0); //Seta o cursor na linha 1
   lcd_1.print("Segundo Andar"); //Indica qual andar está
   lcd_1.setCursor(1, 1); //Seta o cursor na linha 2
   lcd_1.print("Qual andar ?");
   digitalWrite(3, LOW); //Faz o motor parar 
   digitalWrite(2, LOW); //Faz o motor parar 
   aux=0; //Deixa em zero a variavel de selo
   } 
   }
   if(digitalRead(PAT)==1 && digitalRead(10)==1)//terreo para andar 3
   {
    aux=3; //Selo
   }
   if(aux==3) //Condição do Selo
   {
   lcd_1.clear(); //Limpa o LCD
   lcd_1.setCursor(1, 0); //Seta o cursor na linha 1
   lcd_1.print("Terreo"); //Indica qual andar está
   lcd_1.setCursor(1, 1); //Seta o cursor na linha 2
   lcd_1.print("Subindo"); //Indica se está subindo ou descendo
   digitalWrite(2, HIGH); //Sentido para o motor subir
   digitalWrite(3, LOW); //Sentido para o motor subir
   if(digitalRead(PA3)==1)//chegou ao andar 3?
   {
   lcd_1.clear(); //Limpa o LCD
   lcd_1.setCursor(1, 0); //Seta o cursor na linha 1
   lcd_1.print("Terceiro Andar"); //Indica qual andar está
   lcd_1.setCursor(1, 1); //Seta o cursor na linha 2
   lcd_1.print("Qual andar ?");
   digitalWrite(3, LOW); //Faz o motor parar
   digitalWrite(2, LOW); //Faz o motor parar
   aux=0; //Deixa em zero a variavel de selo
   } 
   }
  
 //Primeiro Andar
  if(digitalRead(PA1)==1 && aux==0 && aux1==0 && aux2==0 && aux3==0) //Se o sensor do primeiro andar estiver acionado e as variaveis estiverem em 0 irá fazer a seguinte condição
  {
   lcd_1.setCursor(1, 0); //Seta o cursor na linha 1
   lcd_1.print("Primeiro Andar"); //Indica qual andar está
   lcd_1.setCursor(1, 1); //Seta o cursor na linha 2
   lcd_1.print("Qual andar ?");
  }
  
  if(digitalRead(PA1)==1 && digitalRead(13)==1) //andar 1 para terreo
  {
   aux1=1; //Selo
  }
  if(aux1==1) //Condição do Selo
   {
   lcd_1.clear(); //Limpa o LCD
   lcd_1.setCursor(1, 0); //Seta o cursor na linha 1
   lcd_1.print("Primeiro Andar"); //Indica qual andar está
   lcd_1.setCursor(1, 1); //Seta o cursor na linha 2
   lcd_1.print("Descendo"); //Indica se está subindo ou descendo
   digitalWrite(3, HIGH); //Sentido para o motor subir
   digitalWrite(2, LOW); //Sentido para o motor subir
   if(digitalRead(PAT)==1) //chegou ao andar t?
   {
   lcd_1.clear(); //Limpa o LCD
   lcd_1.setCursor(1, 0); //Seta o cursor na linha 1
   lcd_1.print("Primeiro Andar"); //Indica qual andar está
   lcd_1.setCursor(1, 1); //Seta o cursor na linha 2 //Seta o cursor na linha 2
   lcd_1.print("Qual andar ?");
   digitalWrite(3, LOW); //Faz o motor parar
   digitalWrite(2, LOW); //Faz o motor parar
   aux1=0; //Deixa em zero a variavel de selo
   }
   }
  if(digitalRead(PA1)==1 && digitalRead(11)==1) //andar 1 para andar 2
   {
    aux1=2; //Selo
  }
  if(aux1==2) //Condição do Selo
   {
   lcd_1.clear(); //Limpa o LCD //Limpa o LCD
   lcd_1.setCursor(1, 0); //Seta o cursor na linha 1
   lcd_1.print("Primeiro Andar"); //Indica qual andar está
   lcd_1.setCursor(1, 1); //Seta o cursor na linha 2
   lcd_1.print("Subindo"); //Indica se está subindo ou descendo
   digitalWrite(2, HIGH); //Sentido para o motor subir
   digitalWrite(3, LOW); //Sentido para o motor subir
   if(digitalRead(PA2)==1) //chegou ao andar t?
   {
   lcd_1.clear(); //Limpa o LCD //Limpa o LCD
   lcd_1.setCursor(1, 0); //Seta o cursor na linha 1
   lcd_1.print("Segundo Andar"); //Indica qual andar está
   lcd_1.setCursor(1, 1); //Seta o cursor na linha 2
   lcd_1.print("Qual andar ?");
   digitalWrite(3, LOW); //Faz o motor parar
   digitalWrite(2, LOW); //Faz o motor parar 
   aux1=0; //Deixa em zero a variavel de selo
   }
   }
   if(digitalRead(PA1)==1 && digitalRead(10)==1) //andar 1 para andar 3
   {
    aux1=3; //Selo
  }
  if(aux1==3) //Condição do Selo
   {
   lcd_1.clear(); //Limpa o LCD //Limpa o LCD //Limpa o LCD
   lcd_1.setCursor(1, 0); //Seta o cursor na linha 1
   lcd_1.print("Primeiro Andar"); //Indica qual andar está
   lcd_1.setCursor(1, 1); //Seta o cursor na linha 2
   lcd_1.print("Subindo"); //Indica se está subindo ou descendo
   digitalWrite(2, HIGH); //Sentido para o motor subir
   digitalWrite(3, LOW); //Sentido para o motor subir
   if(digitalRead(PA3)==1) //chegou ao andar t?
   {
   lcd_1.clear(); //Limpa o LCD //Limpa o LCD //Limpa o LCD
   lcd_1.setCursor(1, 0); //Seta o cursor na linha 1
   lcd_1.print("Terceiro Andar"); //Indica qual andar está
   lcd_1.setCursor(1, 1); //Seta o cursor na linha 2
   lcd_1.print("Qual andar ?");
   digitalWrite(3, LOW); //Faz o motor parar
   digitalWrite(2, LOW); //Faz o motor parar
   aux1=0; //Deixa em zero a variavel de selo
   }
   }
 
  //Segundo Andar
  if(digitalRead(PA2)==1  && aux==0 && aux1==0 && aux2==0 && aux3==0) //Se o sensor do segundo andar estiver acionado e as variaveis estiverem em 0 irá fazer a seguinte condição
  {
   lcd_1.setCursor(1, 0); //Seta o cursor na linha 1
   lcd_1.print("Segundo Andar"); //Indica qual andar está
   lcd_1.setCursor(1, 1); //Seta o cursor na linha 2
   lcd_1.print("Qual andar ?");
  }
  
  if(digitalRead(PA2)==1 && digitalRead(13)==1) //andar 2 para terreo
  {
   aux2=1; //Selo
  }
  if(aux2==1) //Condição do Selo
   {
   lcd_1.clear(); //Limpa o LCD //Limpa o LCD //Limpa o LCD //Limpa o LCD
   lcd_1.setCursor(1, 0); //Seta o cursor na linha 1
   lcd_1.print("Segundo Andar"); //Indica qual andar está
   lcd_1.setCursor(1, 1); //Seta o cursor na linha 2
   lcd_1.print("Descendo"); //Indica se está subindo ou descendo
   digitalWrite(3, HIGH); //Sentido para o motor subir
   digitalWrite(2, LOW); //Sentido para o motor subir
   if(digitalRead(PAT)==1) //chegou ao andar t?
   {
   lcd_1.clear(); //Limpa o LCD //Limpa o LCD //Limpa o LCD //Limpa o LCD
   lcd_1.setCursor(1, 0); //Seta o cursor na linha 1
   lcd_1.print("Terreo"); //Indica qual andar está
   lcd_1.setCursor(1, 1); //Seta o cursor na linha 2
   lcd_1.print("Qual andar ?");
   digitalWrite(3, LOW); //Faz o motor parar
   digitalWrite(2, LOW); //Faz o motor parar
   aux2=0; //Deixa em zero a variavel de selo
   }
   }
  if(digitalRead(PA2)==1 && digitalRead(12)==1) //andar 2 para andar 1
  {
   aux2=2; //Selo
  }
  if(aux2==2) //Condição do Selo
   {
   lcd_1.clear(); //Limpa o LCD //Limpa o LCD //Limpa o LCD //Limpa o LCD //Limpa o LCD
   lcd_1.setCursor(1, 0); //Seta o cursor na linha 1
   lcd_1.print("Segundo Andar"); //Indica qual andar está
   lcd_1.setCursor(1, 1); //Seta o cursor na linha 2
   lcd_1.print("Descendo"); //Indica se está subindo ou descendo
   digitalWrite(3, HIGH); //Sentido para o motor subir
   digitalWrite(2, LOW); //Sentido para o motor subir
   if(digitalRead(PA1)==1) //chegou ao andar 1?
   {
   lcd_1.clear(); //Limpa o LCD //Limpa o LCD //Limpa o LCD //Limpa o LCD //Limpa o LCD
   lcd_1.setCursor(1, 0); //Seta o cursor na linha 1
   lcd_1.print("Primeiro Andar"); //Indica qual andar está
   lcd_1.setCursor(1, 1); //Seta o cursor na linha 2
   lcd_1.print("Qual andar ?");
   digitalWrite(3, LOW); //Faz o motor parar
   digitalWrite(2, LOW); //Faz o motor parar
   aux2=0; //Deixa em zero a variavel de selo
   }
   }
  if(digitalRead(PA2)==1 && digitalRead(10)==1) //andar 2 para andar 3
  {
   aux2=3; //Selo
  }
  if(aux2==3) //Condição do Selo
   {
   lcd_1.clear(); //Limpa o LCD //Limpa o LCD //Limpa o LCD //Limpa o LCD //Limpa o LCD //Limpa o LCD
   lcd_1.setCursor(1, 0); //Seta o cursor na linha 1
   lcd_1.print("Segundo Andar"); //Indica qual andar está
   lcd_1.setCursor(1, 1); //Seta o cursor na linha 2
   lcd_1.print("Subindo"); //Indica se está subindo ou descendo
   digitalWrite(2, HIGH); //Sentido para o motor subir
   digitalWrite(3, LOW); //Sentido para o motor subir
   if(digitalRead(PA3)==1) //chegou ao andar 3?
   {
   lcd_1.clear(); //Limpa o LCD //Limpa o LCD //Limpa o LCD //Limpa o LCD //Limpa o LCD //Limpa o LCD
   lcd_1.setCursor(1, 0); //Seta o cursor na linha 1
   lcd_1.print("Terceiro Andar"); //Indica qual andar está
   lcd_1.setCursor(1, 1); //Seta o cursor na linha 2
   lcd_1.print("Qual andar ?");
   digitalWrite(3, LOW); //Faz o motor parar
   digitalWrite(2, LOW); //Faz o motor parar
   aux2=0; //Deixa em zero a variavel de selo
   }
   }
  
  //Terceiro Andar
  if(digitalRead(PA3)==1  && aux==0 && aux1==0 && aux2==0 && aux3==0) //Se o sensor do terceiro andar estiver acionado e as variaveis estiverem em 0 irá fazer a seguinte condição
  {
   lcd_1.setCursor(1, 0); //Seta o cursor na linha 1
   lcd_1.print("Terceiro Andar"); //Indica qual andar está
   lcd_1.setCursor(1, 1); //Seta o cursor na linha 2
   lcd_1.print("Qual andar ?");
  }
   if(digitalRead(PA3)==1 && digitalRead(13)==1) //andar 3 para terreo
  {
   aux3=1; //Selo
  }
  if(aux3==1) //Condição do Selo
   {
   lcd_1.clear(); //Limpa o LCD //Limpa o LCD //Limpa o LCD //Limpa o LCD //Limpa o LCD //Limpa o LCD //Limpa o LCD
   lcd_1.setCursor(1, 0); //Seta o cursor na linha 1
   lcd_1.print("Terceiro Andar"); //Indica qual andar está
   lcd_1.setCursor(1, 1); //Seta o cursor na linha 2
   lcd_1.print("Descendo"); //Indica se está subindo ou descendo
   digitalWrite(3, HIGH); //Sentido para o motor subir
   digitalWrite(2, LOW); //Sentido para o motor subir
   if(digitalRead(PAT)==1) //chegou ao andar t?
   {
   lcd_1.clear(); //Limpa o LCD //Limpa o LCD //Limpa o LCD //Limpa o LCD //Limpa o LCD //Limpa o LCD //Limpa o LCD
   lcd_1.setCursor(1, 0); //Seta o cursor na linha 1
   lcd_1.print("Terreo"); //Indica qual andar está
   lcd_1.setCursor(1, 1); //Seta o cursor na linha 2
   lcd_1.print("Qual andar ?");
   digitalWrite(3, LOW); //Faz o motor parar
   digitalWrite(2, LOW); //Faz o motor parar
   aux3=0; //Deixa em zero a variavel de selo
   }
   }
   if(digitalRead(PA3)==1 && digitalRead(12)==1) //andar 3 para andar 1
   {
   aux3=2; //Selo
   }
   if(aux3==2) //Condição do Selo
   {
   lcd_1.clear(); //Limpa o LCD //Limpa o LCD //Limpa o LCD //Limpa o LCD //Limpa o LCD //Limpa o LCD //Limpa o LCD //Limpa o LCD
   lcd_1.setCursor(1, 0); //Seta o cursor na linha 1
   lcd_1.print("Terceiro Andar"); //Indica qual andar está
   lcd_1.setCursor(1, 1); //Seta o cursor na linha 2
   lcd_1.print("Descendo"); //Indica se está subindo ou descendo
   digitalWrite(3, HIGH); //Sentido para o motor subir
   digitalWrite(2, LOW); //Sentido para o motor subir
   if(digitalRead(PA1)==1) //chegou ao andar 1?
   { 
   lcd_1.clear(); //Limpa o LCD
   lcd_1.setCursor(1, 0); //Seta o cursor na linha 1
   lcd_1.print("Primeiro Andar"); //Indica qual andar está
   lcd_1.setCursor(1, 1); //Seta o cursor na linha 2
   lcd_1.print("Qual andar ?");
   digitalWrite(3, LOW); //Faz o motor parar
   digitalWrite(2, LOW); //Faz o motor parar
   aux3=0; //Deixa em zero a variavel de selo
   }
   }
   if(digitalRead(PA3)==1 && digitalRead(11)==1) //andar 3 para andar 2
   {
   aux3=3; //Selo
   }
   if(aux3==3) //Condição do Selo
   {
   lcd_1.clear(); //Limpa o LCD
   lcd_1.setCursor(1, 0); //Seta o cursor na linha 1
   lcd_1.print("Terceiro Andar"); //Indica qual andar está
   lcd_1.setCursor(1, 1); //Seta o cursor na linha 2
   lcd_1.print("Descendo"); //Indica se está subindo ou descendo
   digitalWrite(3, HIGH); //Sentido para o motor subir
   digitalWrite(2, LOW); //Sentido para o motor subir
   if(digitalRead(PA2)==1) //chegou ao andar 2?
   {
   lcd_1.clear(); //Limpa o LCD
   lcd_1.setCursor(1, 0); //Seta o cursor na linha 1
   lcd_1.print("Segundo Andar"); //Indica qual andar está
   lcd_1.setCursor(1, 1); //Seta o cursor na linha 2
   lcd_1.print("Qual andar ?"); //Indica se está subindo ou descendo
   digitalWrite(3, LOW); //Faz o motor parar
   digitalWrite(2, LOW); //Faz o motor parar
   aux3=0; //Deixa em zero a variavel de selo
   }
   }
}