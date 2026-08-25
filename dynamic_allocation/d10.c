//Dynamic student records + union

#include <stdio.h>
#include <stdlib.h>

union Contact
{
    long long phone;
    char email[50];
};

struct Student
{
    int id;
    char *name;
    float marks;
    int choice;
    union Contact contact;
};

int main()
{
    int n, i;
    struct Student *s;

    scanf("%d", &n);

    s = malloc(n * sizeof(struct Student));

    for (i = 0; i < n; i++)
    {
        s[i].name = malloc(30 * sizeof(char));

        scanf("%d", &s[i].id);
        scanf("%s", s[i].name);
        scanf("%f", &s[i].marks);

        scanf("%d", &s[i].choice);

        if (s[i].choice == 1)
            scanf("%lld", &s[i].contact.phone);
        else
            scanf("%s", s[i].contact.email);
    }

    for (i = 0; i < n; i++)
    {
        printf("%d %s %.2f ", s[i].id, s[i].name, s[i].marks);

        if (s[i].choice == 1)
            printf("%lld\n", s[i].contact.phone);
        else
            printf("%s\n", s[i].contact.email);

        free(s[i].name);
    }

    free(s);

    return 0;
}
