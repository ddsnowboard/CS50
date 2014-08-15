#include <crypt.h>
#include <stdio.h>
#include <string.h>
char* crimson(void)
{
    return "crimson";
}
int main(int argc, char* argv[])
{
    char* hash = argv[1];
    printf("%s", hash);
    char* crim;
    strcpy(crim, crimson());
    char* fifty = "50";
    char* test = crypt(crim, fifty);
	printf("%s\n", test);
}
