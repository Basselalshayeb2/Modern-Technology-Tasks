#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void default_example() {
    puts("STDOUT\n");
    fflush(stdout);
    fputs("STDERR\n", stderr);
    fflush(stderr);
}

void newline_example() {
    puts("STDOUT\n");
    fputs("STDERR\n", stderr);
}

void no_flush_example() {
    puts("STDOUT\n");
    fputs("STDERR\n", stderr);
}

void redirect_example() {
    puts("STDOUT\n");
    fputs("STDERR\n", stderr);
}

int main(int argc, char *argv[])
{
    
     int opt;
    int scenario = 0;

    while ((opt = getopt(argc, argv, "dnsr")) != -1) {
        switch (opt) {
            case 'd': // default
                scenario = 1;
                break;
            case 'n': // with \n
                scenario = 2;
                break;
            case 's': // without fflush
                scenario = 3;
                break;
            case 'r': // redirect
                scenario = 4;
                break;
            default:
                fprintf(stderr, "Usage: %s [-d] [-n] [-s] [-r]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
        
    }
     switch (scenario) {
        case 1:
            default_example();
            break;
        case 2:
            newline_example();
            break;
        case 3:
            no_flush_example();
            break;
        case 4:
            redirect_example();
            break;
        default:
            fprintf(stderr, "No scenario selected. Use -d, -n, -s, or -r.\n");
            exit(EXIT_FAILURE);
    }
    return 0;
}
