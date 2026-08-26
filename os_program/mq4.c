//Robot Command Controller: Implement a robot-control system where one process sends commands such as MOVE_FORWARD, MOVE_BACKWARD, TURN_LEFT, TURN_RIGHT, and STOP to a controller process using a message queue. Give the STOP command the highest priority.



#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <unistd.h>
#include <string.h>

#define QUEUE_NAME "/robot_queue"

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

    /* Child Process - Robot Command Sender */
    if (pid == 0)
    {
        char *commands[] = {
            "MOVE_FORWARD",
            "TURN_LEFT",
            "MOVE_BACKWARD",
            "TURN_RIGHT",
            "STOP"
        };

        unsigned int priorities[] = {
            1,
            2,
            1,
            2,
            10
        };

        for (int i = 0; i < 5; i++)
        {
            if (mq_send(mq,
                        commands[i],
                        strlen(commands[i]) + 1,
                        priorities[i]) == -1)
            {
                perror("mq_send");
                exit(1);
            }

            printf("Sender: %s (Priority %d)\n",
                   commands[i], priorities[i]);

            sleep(1);
        }

        mq_close(mq);
        exit(0);
    }

    /* Parent Process - Robot Controller */
    else
    {
        char command[100];
        unsigned int priority;

        sleep(2);

        printf("\nRobot Controller:\n");

        for (int i = 0; i < 5; i++)
        {
            if (mq_receive(mq,
                           command,
                           sizeof(command),
                           &priority) == -1)
            {
                perror("mq_receive");
                return 1;
            }

            printf("Executing: %s (Priority %d)\n",
                   command, priority);
        }

        mq_close(mq);
        mq_unlink(QUEUE_NAME);
    }

    return 0;
}
