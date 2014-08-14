#define _XOPEN_SOURCE
#include <stdio.h>
#include <crypt.h>
#include <string.h>
#include <unistd.h>
char* rotate(char* password);
int main(int argc, char *argv[])
{
    printf("started\n");
    if(argc == 2)
    {
        printf("%d\n", argc);
        printf("Working\n");
        char* hash = argv[1];
        char password[10];
        strcpy(password,"aa");
        char salt[5] = "aa";
        char error[8] = "ERROR";
        while (crypt(password, salt) != hash && strcmp(password, error))
		{
		    strcpy(password,rotate(password));
		    salt[0] = password[0];
		    salt[1] = password[1];
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
			    printf("Added");
			    char* val = strcat(a, pass);
				return val;
			}
		}
	}
	return "ERROR";
}

