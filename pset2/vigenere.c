#import <cs50.h>
#import <stdio.h>
#import <string.h>

char rotate(char c, int k);
int main(int argc, char* argv[])
{
    // Input checking
    if (argc != 2)
    {
        printf("You gave the wrong number of arguments! You fool!");
        return 1;
    }
    int len = strlen(argv[1]);
    for (int i = 0; i<len;i++)
    {   
        int c = argv[1][i];
        if (!((c >= 91 && c <=122) || (c >= 65 && c <= 90)))
        {
            printf("You gave the wrong kind of argument! You fool!");
            return 1;
        }
    }
    
    int arr[len];
    for (int i = 0; i<len; i++)
    {
        if(argv[1][i]>=65 && argv[1][i] <= 90)
            argv[1][i] = argv[1][i] + 32;
        arr[i] = argv[1][i] - 97;
    }
    string input = GetString();
    int offset = 0;
    for (int i = 0; i<strlen(input);i++)
    {
        char c = input[i];
        if ((c >= 91 && c <=122) || (c >= 65 && c <= 90))
            printf("%c", rotate(c, argv[1][(i-offset)%len]-97));
        else
        {
            printf("%c", c);
            offset++;
        }
    }
    printf("\n");
}

char rotate(char c, int k)
{
    char lower[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char upper[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int i = c;
//    printf("%i\n", k);
    if (i >= 91 && i <= 122)
    {
        i = i-97;
//		printf("%i", i);
//		printf("%c", lower[i]);
        return lower[(i+k)%26];
    }
    else if (i >= 65 && i <= 90)
    {
        i = i - 65;
	//	printf("%i", i);
	//	printf("%c", upper[i]);
        return upper[(i+k)%26];
    }
    else
    {
      //  printf("%c", c);
        return c;
    }
}
