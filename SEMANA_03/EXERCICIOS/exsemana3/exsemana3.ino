// https://wokwi.com/projects/346077718503227987

void showLed(int value);

void storeNote();

void updateLed();

void playMusic();

void displayNote(char * noteName);

void countTo(int value);

const int led1Pin = 1;
const int led2Pin = 2;
const int led3Pin = 42;
const int led4Pin = 41;
const int buzzerPin = 5;
const int btn1Pin = 20;
const int btn2Pin = 19;
const int timeout = 300;


int ledValue = 0;
int btn1State = 1;//Botão não pressionado
int btn2State = 1;//Botão não pressionado
int notes[30] = {};//array para armazenar
int notesIndex = 0;

void setup() {
  Serial.begin(115200);

  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(led4Pin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(btn1Pin, INPUT_PULLUP);
  pinMode(btn2Pin, INPUT_PULLUP);
}

void loop() {
  int sensorValue = analogRead(4); //  Função que realiza leitura analógica, o parâmetro é o pino
  /* 1 - Faça uma função que, a cada novo número medido,
  faça a contagem binária nos leds, pausadamente, de 0 até o número medido.
  2 - Acrescente "toque" usando um Buzzer que corresponda a uma nota diferente
  para cada número. Ao contar de 0 até o número, o buzzer irá tocando todas as notas correspondentes.
  ler os dados de luz de um sensor LDR */
  if (ledValue != map(sensorValue, 32, 4063, 0, 15)) {
    ledValue = map(sensorValue, 32, 4063, 0, 15);
    
    showLed(ledValue);
    
    playSound(ledValue);
    
   noTone(buzzerPin);

   delay(timeout);
    
  }
  storeNote();
  playMusic();
  delay(timeout);
}

void updateLed() {
  sensorValue = analogRead(4); // ler input analógico no pino 4

  if (ledValue != map(sensorValue, 32, 4063, 15, 0)) {
    ledValue = map(sensorValue, 32, 4063, 15, 0);
    countTo(ledValue);
  }
}

void showLed(int value) {
  digitalWrite(led1Pin, value & 0b0001); // Número binário correspondente ao led1
  digitalWrite(led2Pin, value & 0b0010); // Número binário correspodentea ao led2
  digitalWrite(led3Pin, value & 0b0100); // Número binário correspodentea ao led42
  digitalWrite(led4Pin, value & 0b1000); // Número binário correspodentea ao led41
}

// Toque do buzzer
void playSound(int value) {
  int note = 0;
  char *noteName = "";
  //Notas músicais retiradas da internet e uso de switch_case porcausa da enorme quantidad de if.
  switch(value) {
    case 0:
      note = 31;
      noteName = "b0";
      break;
      
    case 1:
      note = 33;
      noteName = "c1";
      break;
      
    case 2:
      note = 37;
      noteName = "d1";
      break;
      
    case 3:
      note = 41;
      noteName = "e1";
      break;
      
    case 4:
      note = 44;
      noteName = "f1";
      break;
    case 5:
      note = 49;
      noteName = "g1";
      break;
      
    case 6:
      note = 55;
      noteName = "a1";
      break;
      
    case 7:
      note = 62;
      noteName = "b1";
      break;
    case 8:
      note = 65;
      noteName = "c2";
      break;
      
    case 9:
      note = 73;
      noteName = "d2";
      break;
      
    case 10:
      note = 82;
      noteName = "e2";
      break;
    case 11:
      note = 87;
      noteName = "f2";
      break;
    case 12:
      
      note = 98;
      noteName = "g2";
      break;
    case 13:
      note = 110;
      noteName = "a2";
      break;
      
    case 14:
      note = 123;
      noteName = "b2";
      break;
      
    case 15:
      note = 131;
      noteName = "c3";
      break;
  }
  tone(buzzerPin, note);
}

/
void storeNote() {
  int Btn1State = digitalRead(btn1Pin); // verificar estado do botao 1
  if (Btn1State != btn1State) {

    if (Btn1State == 0) {
      btn1State = 0;
      
      notes[notesIndex] = ledValue;
      
      notesIndex++;
      
      playSound(ledValue);
      
      delay(timeout);
      
      noTone(buzzerPin);
    } 
    
    else {
      btn1State = 1;
    }
  }
}

void playMusic() {
  int Btn2State = digitalRead(btn2Pin);
  if (Btn2State != btn2State) {
    if (Btn2State == 0) {
      btn2State = 0;
      for (int i = 0; i < notesIndex; i++) {
        delay(timeout);
        playSound(notes[i]);
        delay(timeout);
        noTone(buzzerPin);
      }
      // Limpa
      
      for (int i = 0; i < notesIndex; i++) {
        notes[i] = 0;
      }
      
      notesIndex = 0;
    }
      else {
      btn2State = 1;
    }
  }
}
