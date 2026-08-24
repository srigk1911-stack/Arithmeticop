//address
#include <stdio.h>

struct Address
{
    int door;
    char street[50];
    char city[50];
    int pin;
};

int main()
{
    struct Address address;

    scanf("%d", &address.door);
    scanf("%s", address.street);
    scanf("%s", address.city);
    scanf("%d", &address.pin);

    printf("%d\n", address.door);
    printf("%s\n", address.street);
    printf("%s\n", address.city);
    printf("%d\n", address.pin);

    return 0;
}
