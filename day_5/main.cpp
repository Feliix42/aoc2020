#include <iostream>
#include <fstream>
#include <string>
#include <regex>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: ./solution [input file]" << std::endl;
        return 1;
    }

    // open input file
    std::ifstream input(argv[1]);

    // read file and calculate largest input
    std::string buffer, row, col;
    unsigned int largest = 0;
    unsigned int col_no, row_no, seat_id;
    bool taken_seats[128][8] = {{false}};

    std::regex f_re("F");
    std::regex b_re("B");
    std::regex l_re("L");
    std::regex r_re("R");
    while (getline(input, buffer)) {
        // calculate row
        row = buffer.substr(0, 7);
        row = std::regex_replace(row, f_re, "0");
        row = std::regex_replace(row, b_re, "1");
        row_no = std::strtoul(row.c_str(), nullptr, 2);

        // calculate column
        col = buffer.substr(7, 10);
        col = std::regex_replace(col, l_re, "0");
        col = std::regex_replace(col, r_re, "1");
        col_no = std::strtoul(col.c_str(), nullptr, 2);

        // mark seat as taken
        taken_seats[row_no][col_no] = true;

        // is this the new high?
        seat_id = row_no * 8 + col_no;
        if (seat_id > largest) {
            largest = seat_id;
        }
    }

    std::cout << "Highest seat ID: " << largest << std::endl;

    for (int x = 0; x < 128; x++) {
        for (int y = 0; y < 8; y++) {
            if (!taken_seats[x][y]) {
                int before = y - 1 % 8;
                if (before == 7) {
                    if (!taken_seats[x-1 % 128][before])
                        continue;
                } else {
                    if (!taken_seats[x][before])
                        continue;
                }
                int after = y + 1 % 8;
                if (after == 0) {
                    if (!taken_seats[x+1 % 128][after])
                        continue;
                } else {
                    if (!taken_seats[x][after])
                        continue;
                }
                std::cout << "Empty seat found: [" << x << "|" << y << "] - id: " << x * 8 + y << std::endl;
            }
        }
    }

}
