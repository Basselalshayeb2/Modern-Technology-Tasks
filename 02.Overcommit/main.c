#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>

void print_help(const char *prog_name) {
    printf("Options:\n");
    printf("  -m, --memory_size   Memory size to allocate in MiB (default: 128)\n");
    printf("  -a, --access_mode   Access mode: 'read' or 'write' (default: read)\n");
    printf("  -p, --pause_steps   Steps (4 KiB blocks) before pausing (default: 1000)\n");
    printf("  -d, --pause_time    Pause duration in milliseconds (default: 100)\n");
    printf("  -h, --help          Show this help message and exit\n");
    exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[]) {
    size_t memory_size_mb = 128;
    char *access_mode = "read";
    size_t pause_steps = 1000;
    useconds_t pause_duration = 100 * 1000;

    static struct option long_options[] = {
        {"memory_size", required_argument, 0, 'm'},
        {"access_mode", required_argument, 0, 'a'},
        {"pause_steps", required_argument, 0, 'p'},
        {"pause_time", required_argument, 0, 'd'},
        {"help", no_argument, 0, 'h'},
        {0, 0, 0, 0}
    };

    int opt;
    while ((opt = getopt_long(argc, argv, "m:a:p:d:h", long_options, NULL)) != -1) {
        switch (opt) {
            case 'm':
                memory_size_mb = strtoul(optarg, NULL, 10);
                break;
            case 'a':
                access_mode = optarg;
                break;
            case 'p':
                pause_steps = strtoul(optarg, NULL, 10);
                break;
            case 'd':
                pause_duration = strtoul(optarg, NULL, 10) * 1000;
                break;
            case 'h':
                print_help(argv[0]);
                break;
            default:
                fprintf(stderr, "Unknown option. Use -h for help.\n");
                exit(EXIT_FAILURE);
        }
    }

    int write_mode = 0;
    if (strcmp(access_mode, "write") == 0) {
        write_mode = 1;
    } else if (strcmp(access_mode, "read") != 0) {
        fprintf(stderr, "Invalid access_mode: %s. Use 'read' or 'write'.\n", access_mode);
        exit(EXIT_FAILURE);
    }

    size_t memory_size_bytes = memory_size_mb * 1024 * 1024;
    char *memory = malloc(memory_size_bytes);
    if (!memory) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    printf("Allocated %zu MiB of memory.\n", memory_size_mb);

    size_t page_size = 4096;
    size_t steps = memory_size_bytes / page_size;
    printf("Total steps: %zu (4 KiB each)\n", steps);

    for (size_t i = 0; i < steps; ++i) {
        size_t offset = i * page_size;

        if (write_mode) {
            memset(memory + offset, 0, page_size);
        } else {
            volatile char temp = memory[offset];
            (void)temp;
        }

        if (i > 0 && i % pause_steps == 0) {
            printf("Paused at step %zu of %zu\n", i, steps);
            usleep(pause_duration);
        }
    }

    printf("Memory access completed.\n");

    free(memory);
    return 0;
}
