//Priority-Based Alarm System: Create multiple sensor processes that send INFO, WARNING, and CRITICAL alarm messages to a controller. The controller must process higher-priority messages before lower-priority messages.

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <unistd.h>
#include <string.h>

#define QUEUE_NAME "/alarm_queue"

int main()
{
    mqd_t mq;
    pid_t pid;

    struct mq_attr attr;

    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = 100;
    attr.mq_curmsgs = 0;

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

    /* Child process - Sensor */
    if (pid == 0)
    {
        char *messages[] = {
            "INFO: Temperature normal",
            "WARNING: Temperature high",
            "CRITICAL: Temperature extremely high"
        };

        unsigned int priorities[] = {1, 5, 10};

        for (int i = 0; i < 3; i++)
        {
            if (mq_send(mq,
                        messages[i],
                        strlen(messages[i]) + 1,
                        priorities[i]) == -1)
            {
                perror("mq_send");
                exit(1);
            }

            printf("Sensor: Sent -> %s (Priority %d)\n",
                   messages[i], priorities[i]);

            sleep(1);
        }

        mq_close(mq);
        exit(0);
    }

    /* Parent process - Controller */
    else
    {
        char message[100];
        unsigned int priority;

        sleep(2);

        printf("\nController receiving alarms:\n");

        for (int i = 0; i < 3; i++)
        {
            if (mq_receive(mq,
                           message,
                           sizeof(message),
                           &priority) == -1)
            {
                perror("mq_receive");
                return 1;
            }

            printf("Controller: %s (Priority %d)\n",
                   message, priority);
        }

        mq_close(mq);
        mq_unlink(QUEUE_NAME);
    }

    return 0;
}
