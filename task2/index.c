#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User
{
    char username[20];
    char password[20];
    union
    {
        int flag;
        char flag_string[4];
    } flag;
};

struct User users[10];
int userCount = 0;

void addUser(char *username, char *password);
void registerUser();
int login(char *username, char *password);

int main()
{
    registerUser();

    char username[20];
    char password[20];

    printf("ادخل الاسم ");
    scanf("%s", username);

    printf("ادخل الرقم السرى");
    scanf("%s", password);

    if (login(username, password) == 1)
    {
        printf("تم التسجيل بنجاح \n");
    }
    else
    {
        printf(" هناك خطا فى الرقم السرى\n");
    }

    return 0;
}

void addUser(char *username, char *password)
{
    if (userCount >= 10)
    {
        printf("لقد تجاوز الحد الادنى \n");
        return;
    }

    strcpy(users[userCount].username, username);
    strcpy(users[userCount].password, password);
    userCount++;
}

void registerUser()
{
    char username[20];
    char password[20];
    char flag_string[4];

    printf("ادخل الالسم للتسجيل");
    scanf("%s", username);

    printf("ادخل الرقم السرى ");
    scanf("%s", password);

    printf("Enter 'true' or '1' to activate the account, or 'false' or '0' to deactivate it: ");
    scanf("%s", flag_string);

    if (strcmp(flag_string, "true") == 0 || strcmp(flag_string, "1") == 0)
    {
        users[userCount].flag.flag = 1;
    }
    else if (strcmp(flag_string, "false") == 0 || strcmp(flag_string, "0") == 0)
    {
        users[userCount].flag.flag = 0;
    }
    else
    {
        printf("خطا ف القيمه\n");
        return;
    }

    addUser(username, password);
}

int login(char *username, char *password)
{
    for (int i = 0; i < userCount; i++)
    {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0 && users[i].flag.flag == 1)
        {
            return 1;
        }
    }
        return 0;
}
