// BLOCO DE DEFINIÇÕES INICIAIS
// definindo pinos do Semáforo 1
#define vermelho_1 D0
#define amarelo_1 D1
#define verde_1 D2

// definindo pinos do Semáforo 2
#define vermelho_2 D3
#define amarelo_2 D4
#define verde_2 D5

// definindo pinos do aviso sonoro para deficiente visual
#define bip D6


//BLOCO DE CONFIGURAÇÕES
void setup() {
  // configurando todos pinos como de saída de sinal para ligar ou desligar os leds/buzina
  pinMode(vermelho_1, OUTPUT);
  pinMode(vermelho_2, OUTPUT);
  pinMode(amarelo_1, OUTPUT);
  pinMode(amarelo_2, OUTPUT);
  pinMode(verde_1, OUTPUT);
  pinMode(verde_2, OUTPUT);
  pinMode(bip, OUTPUT);
}

//BLOCO DE DEFINIÇÕES DO QUE VAI FICAR EM REPETIÇÃO 
void loop() {
  // semáforo 1 aberto e 2 fechado e bip para deficiente ligado para passagem no semáforo 2
  digitalWrite(vermelho_1, LOW);
  digitalWrite(vermelho_2, HIGH);
  digitalWrite(amarelo_1, LOW);
  digitalWrite(amarelo_2, LOW);
  digitalWrite(verde_1, HIGH);
  digitalWrite(verde_2, LOW);
  digitalWrite(bip, HIGH);

  // semáforo 1 atenção e 2 fechado e bip para deficiente ligado para passagem no semáforo 2
  digitalWrite(vermelho_1, LOW);
  digitalWrite(vermelho_2, HIGH);
  digitalWrite(amarelo_1, HIGH);
  digitalWrite(amarelo_2, LOW);
  digitalWrite(verde_1, LOW);
  digitalWrite(verde_2, LOW);
  digitalWrite(bip, LOW);
  
  
}
