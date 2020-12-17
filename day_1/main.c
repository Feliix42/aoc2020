#include <stdio.h>
#include <stdlib.h>

// definition of input element count
#define SIZE 200

long int part1(int numbers[]) {
    int elem0 = 0;
    int elem1 = 0;
    int done = 0;
    while (!done) {
        if (numbers[elem0] + numbers[elem1] == 2020) {
            done = 1;
        } else {
            elem1 = (elem1 + 1) % SIZE;
            if (elem1 == 0) {
                elem0++;
            }
        }
    }

    return numbers[elem0] * numbers[elem1];
}

long int part2(int numbers[]) {
    int elem0 = 0;
    int elem1 = 0;
    int elem2 = 0;

    int done = 0;
    while (!done) {
        if (numbers[elem0] + numbers[elem1] + numbers[elem2] == 2020) {
            done = 1;
        } else {
            elem2 = (elem2 + 1) % SIZE;
            if (elem2 == 0) {
                elem1 = (elem1 + 1) % SIZE;
                if (elem1 == 0) {
                    elem0++;
                }
            }
        }
    }

    return numbers[elem0] * numbers[elem1] * numbers[elem2];
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: ./day_1 [1|2] [input file]\n");
        return 1;
    }

    FILE *input_file = fopen(argv[2], "r");
    if (!input_file) {
        printf("[error] Could not read input file!\n");
        return 1;
    }

    char buf[50];
    int numbers[SIZE];
    int cur = 0;
    while(fgets(buf, sizeof(buf), input_file) != NULL) {
        // read and parse the integer
        // TODO: test for length 0?
        numbers[cur] = atoi(buf);
        cur++;
    }

    long int result;
    if (argv[1][0] == '1') {
        result = part1(numbers);
    } else if (argv[1][0] == '2') {
        result = part2(numbers);
    } else {
        printf("[error] Illegal task part specifier, choose either 1 or 2.\n");
        return 1;
    }

    printf("The result is: %ld\n", result);

    return 0;
}

