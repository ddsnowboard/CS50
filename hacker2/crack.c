#define _XOPEN_SOURCE
#include <stdio.h>
#include <crypt.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
char* rotate(char* password);
char* saltRotate(char* salt);
int main(int argc, char *argv[])
{
    char* hash = argv[1];
    if(argc == 2)
    {
        char password[10];
        FILE *f = fopen("/usr/share/dict/words", "r");
        char* line;
        strcpy(password,"aa");
        char salt[3] = {argv[1][0], argv[1][1]};
        char* thisHash;
        int done = 0;
        int counter = 0;
        char error[8] = "ERROR";
        while(fgets(line, 1024, f))
        {
            line[strlen(line)-1] = 0;
            thisHash = crypt(line, salt);
            if(strcmp(thisHash, hash) == 0)
            {
                printf("%s", line);
                return 0;
            }
        }
        while (done == 0)
		{
            if (strcmp(thisHash, hash) == 0)
            {
                done = 1;
            }
            else
            {
				strcpy(password, rotate(password));
                thisHash = crypt(password, salt);
            }
            if (counter == 100000)
            {
                 printf("%s\n", password);
                 counter = 0;
            }
            else
                counter++;
		}
		printf("%s\n", password);
		return 0;
    }
    else
    {
        printf("You need to give the encrypted password, you fool!\n");
        return 1;
    }    
}

char* rotate(char* pass)
{
	int len = strlen(pass);
	char a[2] = "a";
	for(int i = len-1;i >= 0; i--)
	{
		if(pass[i] >= 'a' && pass[i] < 'z')
		{
			pass[i] = pass[i] + 1;
			return pass;
		}
		else if(pass[i] == 'z')
		{
			pass[i] = 'a';
			if(i == 0)
            {
			    char* val = strcat(a, pass);
				return val;
			}
		}
	}
	return "ERROR";
}

char* saltRotate(char* salt)
{
    if((salt[1] >= 'a' && salt[1] < 'z') || (salt[1] >='A' && salt[1] < 'Z') || (salt[1] >= '0' && salt[1] < '9'))
    {
        salt[1]++;
    }
    else if(salt[1] == '/')
    {
        if((salt[0] >= 'a' && salt[0] < 'z') || (salt[0] >= 'A' && salt[0] < 'Z') || (salt[0] >= '0' && salt[0] < '9'))
        {
            salt[0]++;
            salt[1] = 'a';
        }
        else if (salt[0] == 'z')
        {
            salt[0] = 'A';
            salt[1] = 'a';
        }
        else if (salt[0] == 'Z')
            salt[0] = '0';
        else if (salt[0] == '9')
            salt[0] = '.';
        else if (salt[0] == '.')
            salt[0] = '/';
        else if(strcmp(salt, "//") == 0)
            salt = "--";
    }
    else if (salt[1] == 'z')
        salt[1] = 'A';
    else if (salt[1] == 'Z')
        salt[1] = '0';
    else if (salt[1] == '9')
        salt[1] = '.';
    else if (salt[1] == '.')
        salt[1] = '/';
    return salt;
}
