#include <crypt.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*int main(void)*/
/*{*/
/*    printf("%s\n", crypt("bad", "aa"));*/
/*}*/

int main(void)
{
    FILE *f = fopen("/usr/share/dict/words", "r");
    char* line;
    char* thisHash;
    char* in = "50popasof";
    char* hash = "50yoN9fp966dU";
    char* salt = "50";
    while(fgets(line, 1024, f))
        {
            line[strlen(line)-1] = 0;
            thisHash = crypt(line, salt);
            if(strcmp(thisHash, hash) == 0)
            {
                printf("%s\n", line);
                return 0;
            }
        }
} 
