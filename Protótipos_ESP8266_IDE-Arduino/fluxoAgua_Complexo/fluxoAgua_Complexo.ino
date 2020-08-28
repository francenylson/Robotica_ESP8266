/*********************************
 ***Autor: Leonardo Dalla Porta****
 ***********02/08/2014*************
 *************Atenção**************
 ***O Codigo esta livre para uso,**
 *desde que seja mantida sua fonte*
 ********e seu autor.**************
 ********Faça um bom uso***********
 ******Att. Equipe UsinaInfo*******
 *********************************/
 
float vazao; //Variável para armazenar o valor em L/min
float media = 0; //Variável para fazer a média
int contaPulso; //Variável para a quantidade de pulsos
int i = 0; //Variável para segundos
int Min = 00; //Variável para minutos
float Litros = 0; //Variável para Quantidade de agua
float MiliLitros = 0; //Variavel para Conversão
 
void setup()  {
 Serial.begin(9600);
 
 pinMode(2, INPUT);
 attachInterrupt(0, incpulso, RISING); //Configura o pino 2(Interrupção 0) interrupção
}
 
void loop ()  {
 contaPulso = 0;//Zera a variável
 sei(); //Habilita interrupção
 delay (1000); //Aguarda 1 segundo
 cli(); //Desabilita interrupção
 
 vazao = contaPulso / 5.5; //Converte para L/min
 media = media + vazao; //Soma a vazão para o calculo da media
 i++;
 
 MiliLitros = vazao / 60;
 Litros = Litros + MiliLitros;
 
 // Neste conjunto de linhas fizemos a média das leituras obtidas a cada 1 minuto
 if (i == 60)  {
 Min++;
 lcd.print(Min);
 
 if (Min >= 60)  {
 Min = 0;
 }
 media = media / 60; //faz a média
 Serial.print("nMedia por minuto = "); //Imprime a frase Media por minuto =
 Serial.print(media); //Imprime o valor da media
 Serial.println(" L/min - "); //Imprime L/min
 media = 0; //Zera a variável media para uma nova contagem
 i = 0; //Zera a variável i para uma nova contagem
 }
}
 
void incpulso ()  {
 contaPulso++; //Incrementa a variável de pulsos
}
