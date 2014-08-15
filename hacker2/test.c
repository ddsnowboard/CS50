#include <crypt.h>
#include <stdio.h>
#include <string.h>
/*int main(void)*/
/*{*/
/*    printf("%s\n", crypt("bad", "aa"));*/
/*}*/

int main(void)
{
    FILE *f = fopen("/usr/share/dict/words", "r");
    char* line;
    while(fgets(line, 1024, f))
    {
        printf("%s", line);
    }
} 
