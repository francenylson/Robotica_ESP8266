void setup() {
  // put your setup code here, to run once:

}

void loop() {
  oled_1(Temperatura, umidade);

}

void oled_1(String, String)
{
      display.clear();//LIMPA O BUFFER PARA O DISPLAY
      display.display();//ENVIA UM BUFFER PARA O DISPLAY
      display.setTextAlignment(TEXT_ALIGN_LEFT);//DEFINE O ALINHAMENTO DO DISPLAY
      display.setFont(ArialMT_Plain_16);//DEFINE A FONTE E O TAMANHO PARA ESCRITA
      display.drawString(0, 0, {String}" : "+String(temperature)+"°C"); //10=ESPACAMENTO A ESQUERA E 0=LINHA DO TESTO
      display.drawString(2, 10,{String)" : "+String(humidity)+" %"); 
      display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.setFont(ArialMT_Plain_16);
      display.drawString(0, 19,"IRRIGAÇÃO INTELIGENTE");// ESCREVE TEXTO NA POSICAO INDICADA:1=POSICAO HORIZONTAL E 23=POSIC VERTICAL
      display.drawString(5, 36,"INTELIGÊNCIA ARTIFICIAL");// ESCREVE TEXTO NA POSICAO INDICADA:33=POSICAO HORIZONTAL E 35=POSIC VERTICAL
      display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.setFont(ArialMT_Plain_10);
      display.drawString(5, 54, "PET-ALUNO MAKER DIGITAL");// ESCREVE TEXTO NA POSICAO INDICADA:8=POSICAO HORIZONTAL E 50=POSIC VERTICAL
      display.display();
}
