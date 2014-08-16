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
	// Declare hash so I don't have to type "argv[1]" all the time.
    char* hash = argv[1];
	// If there is one extra argument...
    if(argc == 2)
    {
		// This gets rotated so it is always the password we're trying, except 
		// for the dictionary attack portion. 
        char password[10];
		// Set password to start at "aa". I can't imagine a one-letter password,
		// so I'm not going to worry about it. 
		strcpy(password,"aa");
		// The dictionary file. 
        FILE *f = fopen("/usr/share/dict/words", "r");
		// The line from the dictionary file. This could be simplified, but I'll 
		// do that later. 
        char* line = malloc(500);
		// The salt. I figured out in some crypt() man page somewhere that the 
		// first 2 letters of the hash are the salt, so I made the salt those. 
        char salt[3] = {argv[1][0], argv[1][1]};
		// thisHash is the hash of the password currently being tried. 
        char* thisHash;
		// If I've got it, this turns to 1.
        int done = 0;
		// I only print every 100,000 so not to harm performance too much. In 
		// the final version, the printing will be gone. 
        int counter = 0;
		// I was told not to use "magic numbers", and I thought that applied here. 
        char error[8] = "ERROR";
		// While there's still file left...
        while(fgets(line, 1024, f))
        {
			// Set the last character to 0 instead of \n. 
            line[strlen(line)-1] = 0;
			// See if the hash of this line is the right one, making it the password. 
            thisHash = crypt(line, salt);
            if(strcmp(thisHash, hash) == 0)
            {
                printf("%s\n", line);
                return 0;
            }
        }
		// Close the gigantic file to free up memory. 
		fclose(f);
		
        while (done == 0)
		{
			// If this is the hash...
            if (strcmp(thisHash, hash) == 0)
            {
				// We're done. 
                done = 1;
            }
            else
            {
				// Rotate the password with rotate(). 
				strcpy(password, rotate(password));
				// And get its new hash. 
                thisHash = crypt(password, salt);
            }
            if (counter == 100000)
            {
				// Every 100,000, print out the one we're on, just so I know it's working. 
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
		// "Error handling"
        printf("You need to give the encrypted password, you fool!\n");
        return 1;
    }    
}

// My rotation function
char* rotate(char* pass)
{
	int len = strlen(pass);
	// Magic numbers thing again. 
	char a[2] = "a";
	// Go through the string backwards
	for(int i = len-1;i >= 0; i--)
	{
		// If it's just a regular letter, increment one and move on. 
		if(pass[i] >= 'a' && pass[i] < 'z')
		{
			pass[i] = pass[i] + 1;
			return pass;
		}
		// But if it's at the end of the alphabet...
		else if(pass[i] == 'z')
		{
			// Make it back to 'a' and, if necessary, add one more to the 
			// beginning of the string. 
			// If I don't return, it will do the same thing with the next 
			// letter, so that's nice. It will rotate until it gets to something
			// that's not z, or if it never does, it'll add a new letter on the 
			// end and start over. 
			pass[i] = 'a';
			if(i == 0)
            {
			    char* val = strcat(a, pass);
				return val;
			}
		}
	}
	// If none of that works, like we have some weird letters in the password for 
	// some reason, return "ERROR". Also, clang was complainging that it might not
	// return anything. 
	return "ERROR";
}
