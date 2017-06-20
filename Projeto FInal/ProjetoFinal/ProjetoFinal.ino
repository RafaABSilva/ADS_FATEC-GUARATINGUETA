//Mirillis
    long tempo=millis();
    bool controle=false;

//DHT 
    #include "DHT.h"
    #define DHTPIN 2
    #define DHTTYPE DHT11
    DHT dht(DHTPIN, DHTTYPE);

//LCD
    #include <Wire.h>
    #include <LiquidCrystal_I2C.h>
    LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7,3, POSITIVE);

//Portas
    int botao01 = 13;
    int botao02 = 12;
    int relay = 10;
    int sensorO = 9;

//Variáveis de Controle
    bool porta = false;
    bool relayControl = true;
    float tempEXT = 0;
    int relayON, relayOFF;
    int relayTipo = 1;
    int tempSet = -9;
    int menu= 1;
    int b1Estado;
    int b2Estado;


//Array que desenha o simbolo de grau
    byte a[8]= {B00110,B01001,B00110,B00000,B00000,B00000,B00000,B00000}; 
    byte barra[8] = {B11111,B11111,B11111,B11111,B11111,B11111,B11111,B11111};

void setup(){
    
    //Alteração do Tipo de Relay
    if(relayTipo==1){
         relayON=HIGH;
         relayOFF=LOW;
    }else{
         relayON=LOW;
         relayOFF=HIGH;
    }

    //Inicialização do Serial Monitor
    Serial.begin(9600);
    Serial.println("Iniciando!");

    //Inicialização do Sensor DHT
    dht.begin();
  
    //Inicialização do LCD 
    lcd.begin (16,2);
    lcd.setBacklight(HIGH);
    
    //Criando os símbolos para referenciar
    lcd.createChar(1, a); 
    lcd.createChar(2, barra); 

    //Definições de Entrada e Saída
    pinMode(botao01, INPUT);
    pinMode(botao02, INPUT);
    pinMode(sensorO, INPUT);
    pinMode(relay, OUTPUT);

   
    if(menu==0){      //Menu de Configuração (MENU 0)
        //Escrevendo o primeiro Setor
        lcd.setCursor(0,0);
        lcd.print("Temp:");
        lcd.setCursor(0,1);
        lcd.print("--");
        lcd.setCursor(2,1);
        lcd.write(1); //Escreve o simbolo de grau
        lcd.setCursor(3,1);
        lcd.print("C ");

        //Escreve as barras
        lcd.setCursor(8,0);
        lcd.write(2); 
        lcd.setCursor(8,1);
        lcd.write(2);

        //MENU de Apresentação (MENU 1)
        lcd.setCursor(2,0);
        lcd.print("Temperatura:");
        lcd.setCursor(6,1);
        lcd.print("--");
        lcd.setCursor(8,1);
        lcd.write(1); //Escreve o simbolo de grau
        lcd.setCursor(9,1);
        lcd.print("C ");  
}
}
void loop(){
    //Verificando Sensor da Porta
    int acionamento = digitalRead(sensorO);

    if(acionamento == HIGH){     //Caso: Porta Aberta
        if(porta==false){    //Controle de Repetição
          digitalWrite(relay,relayOFF);
          delay(100);
          lcd.clear();
          lcd.setCursor(6,0);
          lcd.print("Porta");
          lcd.setCursor(5,2);
          lcd.print("Aberta!");
          relayControl=true;
          porta=true;
        }

        //Troca de MENUs
        //Detectando os estados dos botões
        b1Estado = digitalRead(botao01);
        b2Estado = digitalRead(botao02);

        //Alternando entre os MENUs
        if(menu!=1){
            if(b1Estado == HIGH){
                menu = 1;
                Serial.print("Menu 1\n");
            }
        }else{
            if(b2Estado == HIGH){
                menu = 0;
                Serial.print("Menu 0\n");
            }
        }
       
    }else{     //Caso: Porta Fechada
        if(porta==true){
          
         lcd.clear();
         
         if(menu==0){     //MENU de Apresentação (MENU 0)     
             //Escrevendo o Primeiro Setor
             lcd.setCursor(0,0);
             lcd.print("Temp:");
             lcd.setCursor(0,1);
             lcd.print("--");
             lcd.setCursor(2,1);
             lcd.write(1);
             lcd.setCursor(3,1);
             lcd.print("C ");

             //Escreve as barras
             lcd.setCursor(8,0);
             lcd.write(2);
             lcd.setCursor(8,1);
             lcd.write(2);

             //Adequação da interface com base na temperatura padrão
             if(tempSet<10 && tempSet>=0){     //Para temps de 0 a 9
                  lcd.setCursor(12,0);
                  lcd.print(" ");   
                  lcd.setCursor(13,0);
                  lcd.print(tempSet);
                  lcd.setCursor(14,0);
                  lcd.write(1);
                  lcd.setCursor(15,0);
                  lcd.print("C");
             }else if(tempSet>=-9 && tempSet<0){     //Para temps de 0 a 9
                  lcd.setCursor(11,0);
                  lcd.print(" ");   
                  lcd.setCursor(12,0);
                  lcd.print(tempSet);
                  lcd.setCursor(14,0);
                  lcd.write(1);
                  lcd.setCursor(15,0);
                  lcd.print("C");
             }else if(tempSet<=-10){     //Para temps menores que -10 
                  lcd.setCursor(11,0);
                  lcd.print(tempSet);
                  lcd.setCursor(14,0);
                  lcd.write(1);
                  lcd.setCursor(15,0);
                  lcd.print("C");
             }else{     //Para as demais temps
                  lcd.setCursor(12,0);
                  lcd.print(tempSet);
                  lcd.setCursor(14,0);
                  lcd.write(1);
                  lcd.setCursor(15,0);
                  lcd.print("C");
             }

             lcd.setCursor(12,1);
             lcd.print("<  >");
             porta=false;
             
         }else{     //MENU de Apresentação (MENU 0)
             //Escrevendo o Segundo Setor
             lcd.setCursor(2,0);
             lcd.print("Temperatura:");
             lcd.setCursor(6,1);
             lcd.print("--");
             lcd.setCursor(8,1);
             lcd.write(1);
             lcd.setCursor(9,1);
             lcd.print("C ");
             porta=false;
         }
        }

        //Monitorando a temperatura
        if(millis()-tempo>200){
              if(controle==false){
                   tempEXT = dht.readTemperature();

                   if (isnan(tempEXT)) {
                       Serial.println("Falha ao Ler o Sensor DHT!");
                       lcd.setCursor(0,0);
                       lcd.print("Ferrou!");
                       return;
                   }else{
                       Serial.print("Temperatura: ");
                       Serial.print(tempEXT);
                       Serial.print(" ºC\n");

                       if(menu==0){
                           lcd.setCursor(0,0);
                           lcd.print("Temp:");
                           lcd.setCursor(0,1);
                           lcd.print(tempEXT);
                           lcd.setCursor(2,1);
                           lcd.write(1); //Escreve o simbolo de grau
                           lcd.setCursor(3,1);
                           lcd.print("C ");
                           controle=true;
                       }else{
                           lcd.setCursor(2,0);
                           lcd.print("Temperatura:");
                           lcd.setCursor(6,1);
                           lcd.print(tempEXT);
                           lcd.setCursor(8,1);
                           lcd.write(1); //Escreve o simbolo de grau
                           lcd.setCursor(9,1);
                           lcd.print("C ");
                           controle=true;
                       }
                  }
             }else{
                  controle=false;
             }
             tempo=millis();
       }

       b1Estado = digitalRead(botao01);
       b2Estado = digitalRead(botao02);
  
       if(b1Estado == HIGH){
             if(menu==0){
                Serial.print("b1 ape\n");
                tempSet--;
                if(tempSet<10 && tempSet>=0){
                     lcd.setCursor(12,0);
                     lcd.print(" ");
                     lcd.setCursor(13,0);
                     lcd.print(tempSet);
                     lcd.setCursor(14,0);
                     lcd.write(1); //Escreve o simbolo de grau
                     lcd.setCursor(15,0);
                     lcd.print("C");   
                }else if(tempSet<-9){
                     lcd.setCursor(11,0);
                     lcd.print(tempSet);
                     lcd.setCursor(14,0);
                     lcd.write(1); //Escreve o simbolo de grau
                     lcd.setCursor(15,0);
                     lcd.print("C");
                }else{
                     lcd.setCursor(12,0);
                     lcd.print(tempSet);
                     lcd.setCursor(14,0);
                     lcd.write(1); //Escreve o simbolo de grau
                     lcd.setCursor(15,0);
                     lcd.print("C");
                }
                 lcd.setCursor(12,1);
                 lcd.print("<  >");
                 delay(200);
             }
       }
  
       if(b2Estado == HIGH ){
             if(menu==0){
                Serial.print("b2 ape\n");
                tempSet++;
                if(tempSet<10 && tempSet>=0){
                     lcd.setCursor(12,0);
                     lcd.print(" ");   
                     lcd.setCursor(13,0);
                     lcd.print(tempSet);
                     lcd.setCursor(14,0);
                     lcd.write(1); //Escreve o simbolo de grau
                     lcd.setCursor(15,0);
                     lcd.print("C");
                }else if(tempSet>=-9 && tempSet<0){
                     lcd.setCursor(11,0);
                     lcd.print(" ");   
                     lcd.setCursor(12,0);
                     lcd.print(tempSet);
                     lcd.setCursor(14,0);
                     lcd.write(1); //Escreve o simbolo de grau
                     lcd.setCursor(15,0);
                     lcd.print("C");
                }else if(tempSet<=-10){ 
                     lcd.setCursor(11,0);
                     lcd.print(tempSet);
                     lcd.setCursor(14,0);
                     lcd.write(1); //Escreve o simbolo de grau
                     lcd.setCursor(15,0);
                     lcd.print("C");
                }else{
                     lcd.setCursor(12,0);
                     lcd.print(tempSet);
                     lcd.setCursor(14,0);
                     lcd.write(1); //Escreve o simbolo de grau
                     lcd.setCursor(15,0);
                     lcd.print("C");
                }
                 lcd.setCursor(12,1);
                 lcd.print("<  >");
                 delay(200);
             }
        }

        if(tempEXT>tempSet){
            if(relayControl==true){
                digitalWrite(relay,relayON);
                Serial.print("ralay on \n");
                relayControl=false;
            }
        }else{
            if(relayControl==false){
                digitalWrite(relay,relayOFF);
                Serial.print("ralay off \n");
                relayControl=true;
            }
        }
    }
 }
