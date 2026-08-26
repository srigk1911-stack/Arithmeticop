

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define QUEUE_NAME "/event_queue"

int main()
{
    mqd_t mq;
    pid_t pid;

    struct mq_attr attr;

    attr.mq_flags = O_NONBLOCK;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = 100;
    attr.mq_curmsgs = 0;

    mq = mq_open(QUEUE_NAME, O_CREAT | O_RDWR | O_NONBLOCK,
                 0666, &attr);

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

    /* Child Process - Event Sender */
    if (pid == 0)
    {
        sleep(3);

        char message[] = "New Event Received";

        if (mq_send(mq,
                    message,
                    strlen(message) + 1,
                    1) == -1)
        {
            perror("mq_send");
            exit(1);
        }

        printf("Sender: Event sent\n");

        mq_close(mq);
        exit(0);
    }

    /* Parent Process - Non-Blocking Monitor */
    else
    {
        char message[100];
        unsigned int priority;

        for (int i = 0; i < 8; i++)
        {
            ssize_t result;

            result = mq_receive(mq,
                                message,
                                sizeof(message),
                                &priority);

            if (result == -1)
            {
                if (errno == EAGAIN)
                {
                    printf("Monitor: No message. Doing other task...\n");
                }
                else
                {
                    perror("mq_receive");
                    break;
                }
            }
            else
            {
                printf("Monitor: Received -> %s\n", message);
                break;
            }

            sleep(1);
        }

        mq_close(mq);
        mq_unlink(QUEUE_NAME);
    }

    return 0;
}
