#include <cs50.h>
#include <stdlib.h>
#include <string.h>

char rotate(char c, int k);
int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("You gave the wrong amount of arguments!");
        return 1;
    }
    else
    {
        int k = atoi(argv[1]);
        printf("Please give your text to be enciphered: ");
        string text = GetString();
        for(int i = 0; i<strlen(text);i++)
        {
            printf(rotate(text[i], k));
        }
    }
}
char rotate(char c, int k)
{
    char[26] lower = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"];
    char[26] upper = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"];
    // This might not work, but give it a try. 
    int i = (int)c;
    if (c >= "a" && c <="z")
    {
        i = i-97;
        return (char)lower[i+(k%26)];
    }
    else if (c>="A" && c <="Z")
    {
        i = i - 65;
        return (char)upper[(i+k)%26];
    } 
}
