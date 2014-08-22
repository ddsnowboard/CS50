/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int sorted = 1;
    int temp = 85;
    int passes = 0;
    do{
        sorted = 1;
        for(int i = 1;i<n-passes;i++)
        {
            if(values[i-1]>values[i])
            {
                temp = values[i-1];
                values[i-1] = values[i];
                values[i] = temp;
                sorted = 0;
            }
        }
        passes++;
    }while(sorted == 0);
    return;
}

