//Create Application Log File

#include <stdio.h>
#include <time.h>

int main()
{
    FILE *fp;
    time_t currentTime;
    struct tm *localTime;

    fp = fopen("application.log", "a");

    if (fp == NULL)
    {
        printf("Log file cannot be opened\n");
        return 1;
    }

    currentTime = time(NULL);
    localTime = localtime(&currentTime);

    fprintf(fp, "Operation: Application Started\n");
    fprintf(fp, "Time: %02d-%02d-%04d %02d:%02d:%02d\n",
            localTime->tm_mday,
            localTime->tm_mon + 1,
            localTime->tm_year + 1900,
            localTime->tm_hour,
            localTime->tm_min,
            localTime->tm_sec);
    fprintf(fp, "Status: SUCCESS\n\n");

    fclose(fp);

    printf("Application log created successfully\n");

    return 0;
}
