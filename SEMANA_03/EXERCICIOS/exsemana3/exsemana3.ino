#define LED0 19
#define LED1 20
#define LED2 40
#define LED3 41
#define LDR 4
#define BUZZER 9
#define BUTTON_SELECT 2
#define BUTTON_PLAY 1

/*luminosidade).
Os valores lidos pelo sensor LDR devem ser convertidos para uma contagem de até 4 dígitos binários, que por sua vez corresponderão aos 4 LEDs.
Complemente o circuito com:
1 - Buzzer, que deverá tocar um som diferente para cada valor da contagem binária
2 - Dois botões (push button):
--- Um dos botões deve armazenar um valor binário lido pelo LDR em um vetor (dica: acenda os LEDs e toque o som correspondente no momento do armazenamento)
--- O outro botão deve exibir nos LEDs, em sequência, todos os valores armazenados no vetor anterior e, ao mesmo tempo, tocar seu respectivo som através do buzzer. Após a leitura de todos os valores armazenados, o vetor deve ser esvaziado.*/

//Array que armazena 4 dígitos binários
int binary[4];

//Variável para tamanho da array
int count = 0;

//Função da conversão binária no intervalo de 0 a 15

void conv(int value) {
  int i = 0;
  while (i != 4) {
    //O valor da casa binária será dividido por 2, até chegar no quociente 0
    binary[i] = value % 2;  //resto de 2 , 7 % 2 = 1
    value = value / 2;      // valor dividio por 2, value
    i++;
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED0, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LDR, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(BUTTON_SELECT, INPUT_PULLUP);
  pinMode(BUTTON_PLAY, INPUT_PULLUP);
}

// Criando as notas(frequencias) para o buzzer no intervalo de 0 a 15
/*int note = 0;
double notes[15] = {264, 296.2, 332.6, 352.4,
                    395.5, 444, 498.4, 528,
                    592.42, 665.28, 704.88,
                    790.94, 888.1, 996,86}; */
//Armazena a frequencia no intervalo de 0 a 15
//Não funcionou e não sei porque
int notes[100];
void stock(int note) {
  notes[count] = note;
  count += 1;
  tone(BUZZER, note * 120, 250);  //frequencia da nota em uma duração de 250 milisegundos
}


// Função que vê os números da array em binário e caso esteja em 1, liga
void light() {
  if (binary[0] == 1) {
    digitalWrite(LED0, HIGH);
  } else {
    digitalWrite(LED0, LOW);
  }

  if (binary[1] == 1) {
    digitalWrite(LED1, HIGH);
  } else {
    digitalWrite(LED1, LOW);
  }

  if (binary[2] == 1) {
    digitalWrite(LED2, HIGH);
  } else {
    digitalWrite(LED2, LOW);
  }

  if (binary[3] == 1) {
    digitalWrite(LED3, HIGH);
  } else {
    digitalWrite(LED3, LOW);
  }
}
//Toca as músicas armazenadas na array
void play_song() {
  int i = 0;

  while (i < count) {
    conv(notes[i]);  //Converte a frequência do número da array em binario
    tone(BUZZER, notes[i] * 120, 250);
    light();
    delay(1000);
    i += 1;
  }
  //código para limpar as notas, zera o count
  count = 0;
  notes[100] = {};
}

void loop() {
  int ldr = analogRead(LDR);
  int scale = map(ldr, 32, 4063, 0, 15);  // Transformando os valores mínimos e máximos do ldr no intervalo 0 a 15
  conv(scale);  
  Serial.println(scale);                        // Convertendo o intervalo de 0 a 15 em binário
  light();                                //Ligar os leds com binário em 1
  
  //BUTTON_SELECT ARMAZENA O VALOR DO INTERVALO DE 0 A 15
  if (digitalRead(BUTTON_SELECT) == LOW) {
    stock(scale);
    Serial.println(scale);
  }
  //BUTTON_PLAY TOCA A MÚSICA E O VALOR.
  if (digitalRead(BUTTON_PLAY) == LOW) {
    play_song();
  }

  delay(200);
}