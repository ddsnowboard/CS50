#include <stdio.h>
#include <crypt.h>
#include <string.h>
string rotate(string password);
int main(int argc, char* argv)
{
    if(argc != 2)
    {
        printf("You need to give the encrypted password, you fool!");
        return 0;
    }
    string hash = argv[1];
    else
    {
        char password[1];
        while (crypt(password) != hash)
		{
		    password = rotate(password);
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
		if(password[i] >= 'a' && < 'z')
		{
			password[i]++;
			return password;
		}
		else if(password[i] == 'z')
		{
			password[i] = 'a';
			if(i == 0)
			{
				return concat('a', password);
			}
		}
	}
}