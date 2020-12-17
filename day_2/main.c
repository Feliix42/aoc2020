#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: ./day_2 [1|2] [input file]\n");
        return 1;
    }

    int part = 0;
    if (argv[1][0] == '1') {
        part = 1;
    } else if (argv[1][0] == '2') {
        part = 2;
    } else {
        printf("[error] Specified invalid †ask part! Expected 1 or 2.\n");
        return 1;
    }

    FILE *input_file = fopen(argv[2], "r");
    if (!input_file) {
        printf("[error] Could not read input file!\n");
        return 1;
    }

    char buf[50];

    int assigned = 0;
    int lower = 0;
    int upper = 0;
    char c = ' ';
    char password[40];

    int valid_count = 0;
    while(fgets(buf, sizeof(buf), input_file) != NULL) {
        // read and parse the line
        assigned = sscanf(buf, "%d-%d %c: %s\n", &lower, &upper, &c, password);
        if (assigned != 4) {
            printf("Read invalid number of items.\n");
            return 1;
        }
        size_t len = strlen(password);

        if (part == 1) {
            int count = 0;
            for (size_t i = 0; i < len; i++) {
                if (password[i] == c) {
                    count++;
                }
            }

            // test if boundaries are met
            if (lower <= count && count <= upper) {
                valid_count++;
            }
        } else {
            int hits = 0;
            if (lower <= len && password[lower-1] == c) {
                hits++;
            }

            if (upper <= len && password[upper-1] == c) {
                hits++;
            }

            if (hits == 1) {
                valid_count++;
            }
        }
    }

    printf("Found %d valid passwords.\n", valid_count);

    return 0;
}

