#include <stdio.h>
#include<string.h>

#define LINES 323
#define COLS 31
#define SLOPE_COUNT 5

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: ./solution [1|2] [input file]\n");
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
    char map[LINES][COLS+1] = {{0}};

    unsigned int line = 0;
    while(fgets(buf, sizeof(buf), input_file) != NULL) {
        // read and parse the line
        strncpy(map[line], buf, COLS);
        line++;
    }

    if (part == 1) {
        line = 0;
        unsigned int col = 0;
        unsigned int tree_hits = 0;
        while (line < LINES) {
            if (map[line][col] == '#') {
                tree_hits++;
            }

            col = (col + 3) % COLS;
            line++;
        }

        printf("Hopped on %d trees.\n", tree_hits);
    } else {
        // [right, down]
        unsigned int jumps[SLOPE_COUNT][2] = {{1, 1}, {3, 1}, {5, 1}, {7, 1}, {1, 2}};
        unsigned int col, tree_hits;
        unsigned long int product = 1;

        for (int i = 0; i < SLOPE_COUNT; i++) {
            line = 0;
            col = 0;
            tree_hits = 0;

            while (line < LINES) {
                if (map[line][col] == '#') {
                    tree_hits++;
                }

                col = (col + jumps[i][0]) % COLS;
                line += jumps[i][1];
            }

            product *= tree_hits;
        }

        printf("Multiplied tree hits: %ld.\n", product);
    }

    return 0;
}

