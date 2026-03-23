#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

// Pinos SPI de Controle do Display
#define TFT_CS   15
#define TFT_DC   2
#define TFT_RST  4

// Periféricos
#define BTN_NFC  5  
#define JOY_X    35  
#define JOY_Y    34  
#define BUZZER   13 

// LED RGB
#define LED_R    25
#define LED_G    26
#define LED_B    27

// Botões Auxiliares (A/B/X/Y)
#define BTN_A    32
#define BTN_B    33
#define BTN_X    21
#define BTN_Y    22

// Inicialização Limpa: O Hardware SPI do ESP32 já sabe que MOSI é 23 e SCK é 18
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

enum GameState { START_SCREEN, EXPEDIENTE, ATACK_ALERTA };
GameState currentState = START_SCREEN;

int playerX = 160, playerY = 120; 
int hora = 8, minuto = 0;
unsigned long ultimoTempo = 0;
int integridadeRede = 100;

void setup() {
  Serial.begin(115200);
  
  pinMode(BTN_NFC, INPUT_PULLUP);
  pinMode(BTN_A, INPUT_PULLUP);
  pinMode(BTN_B, INPUT_PULLUP);
  pinMode(BTN_X, INPUT_PULLUP);
  pinMode(BTN_Y, INPUT_PULLUP);
  
  pinMode(BUZZER, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);

  setLedStatus(0, 0, 0); 
  
  tft.begin();
  tft.setRotation(1);
  
  showStartScreen();
}

void loop() {
  atualizarRelogio();

  switch (currentState) {
    case START_SCREEN:
      setLedStatus(0, 0, 255); // Azul = Menu
      
      if (digitalRead(BTN_NFC) == LOW) {
        delay(200);
        currentState = EXPEDIENTE;
        desenharMapa();
      }
      break;

    case EXPEDIENTE:
      setLedStatus(0, 255, 0); // Verde = Seguro
      moverJogador();
      
      if (minuto == 15 && hora == 8) { 
        currentState = ATACK_ALERTA;
        dispararAlarme();
      }
      break;

    case ATACK_ALERTA:
      setLedStatus(255, 0, 0); // Vermelho = Ataque
      desenharAlertaRansomware();
      
      if (digitalRead(BTN_NFC) == LOW) { 
        noTone(BUZZER);
        delay(300); 
        currentState = EXPEDIENTE;
        desenharMapa();
      }
      break;
  }
}

void setLedStatus(int r, int g, int b) {
  analogWrite(LED_R, r);
  analogWrite(LED_G, g);
  analogWrite(LED_B, b);
}

void moverJogador() {
  int xVal = analogRead(JOY_X);
  int yVal = analogRead(JOY_Y);

  tft.fillRect(playerX, playerY, 8, 8, 0x4208); 

  if (xVal < 1500) playerX -= 3;
  if (xVal > 2500) playerX += 3;
  if (yVal < 1500) playerY -= 3;
  if (yVal > 2500) playerY += 3;

  playerX = constrain(playerX, 10, 302);
  playerY = constrain(playerY, 10, 202);

  tft.fillRect(playerX, playerY, 8, 8, ILI9341_BLUE);
}

void atualizarRelogio() {
  if (millis() - ultimoTempo >= 2000) { 
    ultimoTempo = millis();
    minuto++;
    if (minuto >= 60) { minuto = 0; hora++; }
    tft.fillRect(240, 220, 70, 20, ILI9341_BLACK);
    tft.setCursor(240, 220);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);
    tft.printf("%02d:%02d", hora, minuto);
  }
}

void showStartScreen() {
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextColor(ILI9341_GREEN);
  tft.setTextSize(3);
  tft.setCursor(40, 80);
  tft.print("DEADLOCK");
  tft.setTextSize(1);
  tft.setCursor(60, 150);
  tft.print("PRESSIONE O BOTAO NFC");
}

void desenharMapa() {
  tft.fillScreen(0x4208); 
  tft.drawRect(10, 10, 140, 100, ILI9341_WHITE); 
  tft.setCursor(20, 20);
  tft.setTextColor(ILI9341_YELLOW);
  tft.setTextSize(1);
  tft.print("SALA SERVIDORES");
  desenharHUD();
}

void desenharHUD() {
  tft.fillRect(0, 210, 320, 30, ILI9341_BLACK);
  tft.setCursor(10, 220);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.printf("INTEGRIDADE: %d%%", integridadeRede);
}

void desenharAlertaRansomware() {
  tft.fillRect(50, 50, 220, 120, ILI9341_RED); 
  tft.setCursor(65, 80);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.print("RANSOMWARE!");
  tft.setTextSize(1);
  tft.setCursor(70, 120);
  tft.print("ESCANEIE CARTA BACKUP");
}

void dispararAlarme() {
  tone(BUZZER, 440); 
}