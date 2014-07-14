#include <stdio.h>
#include <cs50.h>

/* A program that, given a height, writes a pyramid of that height, as per 
the spec: 
https://d2o9nyf4hwsci4.cloudfront.net/2014/spring/psets/1/pset1/pset1.html#_itsa_mario */
int main(void)
{
    // Ask for height
    printf("Height: ");
    int height = GetInt();
    // If it's wrong, keep asking. GetInt() handles non-ints automatically.
    while (!(height >= 0 && height <= 23)) 
    {
        printf("Try again: ");
        height = GetInt();
    }
	
    for (int i = 0; i < height; i++) 
    {
	    // This height-1 would be height-2, but there is always one more #  
		// tacked on the end of every line, so that adds one, so height-1. 
		// These are the spaces that move the #'s from the side so the
		// first # on the last line can be in the corner of the terminal, 
		// per the spec.
        for (int j = 0; j < (height - 1) - i; j++) 
        {
            printf(" ");
        }
		// At line 0, there are 2, and one more per line after that, so i+2
        for (int j = 0; j < i + 2; j++) 
        {
            printf("#");
        }
		// Put a new line character at the end of every line. 
        printf("\n");
    }
    return 0;
}
