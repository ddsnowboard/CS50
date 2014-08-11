#include <stdio.h>
#include <crypt.h>
#include <string.h>
int main(int argc, char* argv)
{
    if(argc != 2)
	{
		printf("You need to give the encrypted password!");
		return 0;
	}
	string hash = argv[1];
	else
	{
		char password[1];
		for(int i = 1; i<10;i++)
		{
			for(int j = 0; j<i; j++)
			{
				password[j] = 'a';
			}
			if(crypt(password) == hash)
			{
				printf("%s", password);
				return 0;
			}
			// I need to figure out how to rotate the string to brute force it. Check the spec for how to deal with caps. 
			// Maybe also run through the dictionary file first, just in case you get lucky. 
		}
	}	
}