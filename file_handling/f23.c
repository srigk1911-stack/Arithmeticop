//Generate JSON File for IoT Sensor Data

#include <stdio.h>

struct Sensor
{
    int device_id;
    float temperature;
    float humidity;
    float pressure;
};

int main()
{
    FILE *fp;
    struct Sensor s;

    fp = fopen("sensor.json", "w");

    if (fp == NULL)
    {
        printf("File cannot be created\n");
        return 1;
    }

    scanf("%d", &s.device_id);
    scanf("%f", &s.temperature);
    scanf("%f", &s.humidity);
    scanf("%f", &s.pressure);

    fprintf(fp, "{\n");
    fprintf(fp, "    \"device_id\": %d,\n", s.device_id);
    fprintf(fp, "    \"temperature\": %.2f,\n", s.temperature);
    fprintf(fp, "    \"humidity\": %.2f,\n", s.humidity);
    fprintf(fp, "    \"pressure\": %.2f\n", s.pressure);
    fprintf(fp, "}\n");

    fclose(fp);

    printf("Sensor JSON file created successfully\n");

    return 0;
}
