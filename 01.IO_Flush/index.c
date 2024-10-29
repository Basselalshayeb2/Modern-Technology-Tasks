#include <stdio.h>

int main()
{
    puts("STDOUT\n");
    //fflush(stdout);
    fputs("STDERR\n", stderr);
    //fflush(stderr);
    return 0;
}
