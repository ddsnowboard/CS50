#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char rotate(char c, int k);
int main(int argc, char* argv[])
{
	// Check input. 
    if (argc != 2)
    {
        printf("You gave the wrong amount of arguments!");
        return 1;
    }
	
    else
    {
        int k = atoi(argv[1]);
        string text = GetString();
        for(int i = 0; i<strlen(text);i++)
        {
            printf("%c", rotate(text[i], k));
        }
        printf("\n");
    }
}

char rotate(char c, int k)
{
    char lower[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char upper[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int i = c;
    if (i >= 91 && i <= 122)
    {
        i = i-97;
        return lower[(i+k)%26];
    }
    else if (i >= 65 && i <= 90)
    {
        i = i - 65;
        return (char)upper[(i+k)%26];
    }
    else
    {
        return c;
    }
}
