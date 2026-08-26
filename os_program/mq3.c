//Multi-Sensor Data Collector: Implement three producer processes representing temperature, pressure, and humidity sensors. Each sends a structure containing sensor_id and value to one consumer process. The consumer identifies the source and displays the data.


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define QUEUE_NAME "/sensor_queue"

struct sensor_data
{
    int sensor_id;
    float value;
};

int main()
{
    mqd_t mq;
    pid_t p1, p2, p3;

    struct mq_attr attr;

    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = sizeof(struct sensor_data);
    attr.mq_curmsgs = 0;

    mq = mq_open(QUEUE_NAME, O_CREAT | O_RDWR, 0666, &attr);

    if (mq == (mqd_t)-1)
    {
        perror("mq_open");
        return 1;
    }

    /* Temperature Sensor */
    p1 = fork();

    if (p1 == 0)
    {
        struct sensor_data data = {1, 28.5};

        mq_send(mq, (char *)&data, sizeof(data), 0);

        printf("Temperature Sensor: %.2f C\n", data.value);

        mq_close(mq);
        exit(0);
    }

    /* Pressure Sensor */
    p2 = fork();

    if (p2 == 0)
    {
        struct sensor_data data = {2, 1013.25};

        mq_send(mq, (char *)&data, sizeof(data), 0);

        printf("Pressure Sensor: %.2f hPa\n", data.value);

        mq_close(mq);
        exit(0);
    }

    /* Humidity Sensor */
    p3 = fork();

    if (p3 == 0)
    {
        struct sensor_data data = {3, 65.5};

        mq_send(mq, (char *)&data, sizeof(data), 0);

        printf("Humidity Sensor: %.2f %%\n", data.value);

        mq_close(mq);
        exit(0);
    }

    /* Parent Process - Consumer */
    else
    {
        struct sensor_data received;

        for (int i = 0; i < 3; i++)
        {
            if (mq_receive(mq,
                           (char *)&received,
                           sizeof(received),
                           NULL) == -1)
            {
                perror("mq_receive");
                return 1;
            }

            switch (received.sensor_id)
            {
                case 1:
                    printf("Consumer: Temperature = %.2f C\n",
                           received.value);
                    break;

                case 2:
                    printf("Consumer: Pressure = %.2f hPa\n",
                           received.value);
                    break;

                case 3:
                    printf("Consumer: Humidity = %.2f %%\n",
                           received.value);
                    break;

                default:
                    printf("Unknown sensor\n");
            }
        }

        wait(NULL);
        wait(NULL);
        wait(NULL);

        mq_close(mq);
        mq_unlink(QUEUE_NAME);
    }

    return 0;
}
