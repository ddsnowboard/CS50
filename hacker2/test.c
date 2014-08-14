#include <string.h>
#include <stdio.h>
char* saltRotate(char* salt)
{
/*    printf("%i\n", salt[1] >= 'a' && salt[1] < 'z');*/
    if(salt[1] >= 'a' && salt[1] < 'z')
    {
        salt[1]++;
/*        printf("%s", salt);*/
    }
    else if(salt[1] == 'z')
    {
        salt[1] = 'a';
        if(salt[0] >= 'a' && salt[0] < 'z')
            salt[0]++;
        else
            salt = "00";
    }
    return salt;
}


int main(void)
{
    char salt[3] = "aa";
    int n = 0;
    char zero[3] = "00";
    while(n<1000)
    {
        printf("%s\n", salt);
        strcpy(salt, saltRotate(salt));
        printf("%s\n", salt);
        if(!(strcmp(salt, zero)))
        {
            strcpy(salt, "aa");
        }
        n++;
    }   
}
