#include <Arduino.h>


const int led1 = 2; // Pin of the LED

void toggleLED(void * parameter)
{
    for(;;)
    {   // infinite loop
        // Turn the LED on
        digitalWrite(led1, HIGH);
        // Pause the task for 500ms
        vTaskDelay(500 / portTICK_PERIOD_MS);
        // Turn the LED off
        digitalWrite(led1, LOW);
        // Pause the task again for 500ms
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}


void setup()
{
    pinMode(led1, OUTPUT);
    Serial.begin(112500);
    /* we create a new task here */
    xTaskCreate(
        toggleLED, // Function that should be called
        "Toggle LED", // Name of the task (for debugging)
        1000, // Stack size (bytes)
        NULL, // Parameter to pass
        1, // Task priority
        NULL // Task handle
    );
}

/* the forever loop() function is invoked by Arduino ESP32 loopTask */
void loop()
{
    Serial.println("this is ESP32 Task");
    delay(1000);
}







