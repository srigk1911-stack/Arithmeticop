//Temperature Monitoring System: Create two processes: a temperature sensor process and a monitoring process. The sensor generates a temperature value every second and sends it to the monitoring process through a POSIX message queue. The monitoring process receives and displays the value.


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <unistd.h>
#include <string.h>

#define QUEUE_NAME "/temperature_queue"

int main()
{
    mqd_t mq;
    pid_t pid;
    char message[100];

    struct mq_attr attr;

    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = 100;
    attr.mq_curmsgs = 0;

    // Create message queue
    mq = mq_open(QUEUE_NAME, O_CREAT | O_RDWR, 0666, &attr);

    if (mq == (mqd_t)-1)
    {
        perror("mq_open");
        return 1;
    }

    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }

    // Child process - Temperature Sensor
    if (pid == 0)
    {
        int temperature;

        for (int i = 0; i < 5; i++)
        {
            temperature = 25 + i;

            sprintf(message, "Temperature: %d C", temperature);

            if (mq_send(mq, message, strlen(message) + 1, 0) == -1)
            {
                perror("mq_send");
                exit(1);
            }

            printf("Sensor: Sent -> %s\n", message);

            sleep(1);
        }

        mq_close(mq);
        exit(0);
    }

    // Parent process - Monitoring
    else
    {
        unsigned int priority;
        ssize_t bytes_received;

        for (int i = 0; i < 5; i++)
        {
            bytes_received = mq_receive(
                mq,
                message,
                sizeof(message),
                &priority
            );

            if (bytes_received == -1)
            {
                perror("mq_receive");
                return 1;
            }

            printf("Monitor: Received -> %s\n", message);
        }

        mq_close(mq);
        mq_unlink(QUEUE_NAME);
    }

    return 0;
}
