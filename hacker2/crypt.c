#define _XOPEN_SOURCE
#include <stdio.h>
#include <crypt.h>
#include <string.h>
#include <cs50.h>
#include <unistd.h>
string rotate(string password);

int main(int argc, char *argv[])
{
    printf("started\n");
    printf("%d\n", argc);
    if(argc == 2)
    {
        printf("Working");
        string hash = argv[1];
        string password = "aa";
        string salt = "aa";
        string error = "ERROR";
        while (crypt(password, salt) != hash && password != error)
		{
		    password = rotate(password);
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

string rotate(string pass)
{
	int len = strlen(pass);
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
				return strcat("a", pass);
			}
		}
	}
	return "ERROR";
}