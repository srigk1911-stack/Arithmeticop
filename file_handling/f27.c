//Simple Logging Library

#include <stdio.h>
#include <time.h>

void logMessage(const char level[], const char message[])
{
    FILE *fp;
    time_t currentTime;
    struct tm *localTime;

    fp = fopen("application.log", "a");

    if (fp == NULL)
    {
        printf("Log file cannot be opened\n");
        return;
    }

    currentTime = time(NULL);
    localTime = localtime(&currentTime);

    fprintf(fp, "[%02d-%02d-%04d %02d:%02d:%02d] [%s] %s\n",
            localTime->tm_mday,
            localTime->tm_mon + 1,
            localTime->tm_year + 1900,
            localTime->tm_hour,
            localTime->tm_min,
            localTime->tm_sec,
            level,
            message);

    fclose(fp);
}

int main()
{
    logMessage("INFO", "Application started");
    logMessage("WARNING", "Low memory");
    logMessage("ERROR", "File could not be opened");

    printf("Log messages written successfully\n");

    return 0;
}
