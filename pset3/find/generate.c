/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
       
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMIT 65536

int main(int argc, string argv[])
{
    // If the wrong amount of arguments are given, 
    // explain the correct syntax, and close. 
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }

    // Turn the ASCII string that was given as the first
    // argument into an int and save it in n. This will 
    // be the amount of random numbers it gives. 
    int n = atoi(argv[1]);

    // If a seed is given in argv[2], set the random seed 
    // to it, casting it as an unsigned int because srand
    // must take an unsigned int as an argument. 
    // Else, set the seed to the time, in seconds from midnight
    // on January 1, 1970, I believe. The man page is useless...
    if (argc == 3)
    {
        srand((unsigned int) atoi(argv[2]));
    }
    else
    {
        srand((unsigned int) time(NULL));
    }

    // Print n random numbers, but don't let them go over the maximum. 
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", rand() % LIMIT);
    }

    // that's all folks
    return 0;
}
