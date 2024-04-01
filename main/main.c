/*
 * LED blink with FreeRTOS
 */
#include <FreeRTOS.h>
#include <task.h>
#include <semphr.h>
#include <queue.h>

#include "pico/stdlib.h"
#include <stdio.h>

int main() {
    stdio_init_all();
    printf("oi da ai\n");

    vTaskStartScheduler();

    while (true)
        ;
}
