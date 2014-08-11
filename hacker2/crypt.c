#include <stdio.h>
#include <crypt.h>
#include <string.h>
#include <cs50.h>
#define _XOPEN_SOURCE
#include <unistd.h>
string rotate(string password);
int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("You need to give the encrypted password, you fool!\n");
        return 1;
    }
    else
    {
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
}

string rotate(string password)
{
	int len = strlen(password);
	for(int i = len-1;i >= 0; i--)
	{
		if(password[i] >= 'a' && password[i] < 'z')
		{
			password[i]++;
			return password;
		}
		else if(password[i] == 'z')
		{
			password[i] = 'a';
			if(i == 0)
			{
				return strcat("a", password);
			}
		}
	}
	return "ERROR";
}
