#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
void cpu_task(void *p){
    uint8_t CPU_RunInfo[400];
    while(1){
        memset(CPU_RunInfo, 0, 400);
        vTaskList((char *)&CPU_RunInfo);

        printf("------------------------\r\n");
        printf("task_name      task_status priority     stack task_id\r\n");
        printf("%s", CPU_RunInfo);
        printf("------------------------\r\n");

        memset(CPU_RunInfo, 0, 400);

        vTaskGetRunTimeStats((char *)&CPU_RunInfo);

        printf("task_num            run cnt             usage_rate\r\n");
        printf("%s", CPU_RunInfo);
        printf("----------------------------------------\r\n");
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}

void app_main(void)
{
    xTaskCreate(cpu_task, "cpu_task", 2360, NULL, 1, NULL);
}