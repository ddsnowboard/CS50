#include <crypt.h>
#include <stdio.h>
int main(void)
{
	printf("%s\n", crypt("apples", "aa"));
}
