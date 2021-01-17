#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include "questionaire.hpp"

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cout << "Usage: ./solution [1|2] [input file]" << std::endl;
        return 1;
    }

    // task number
    int number = std::stoi(argv[1]);

    // open input file
    std::ifstream input(argv[2]);

    // read file and collect info
    std::string buffer;
    QuestionaireGroup forms(number);
    unsigned int answer_sum = 0;

    while (getline(input, buffer)) {
        if (buffer.length() == 0) {
            answer_sum += forms.report();
            forms.clear(number);
            continue;
        }

        if (number == 2) {
            bool tmp[26] = {false};
            for (char c: buffer) {
                tmp[c-'a'] = true;
            }

            // set all answers not given by everyone to false
            for (int i = 0; i < 26; i++) {
                if (!tmp[i])
                    forms.answers[i] = false;
            }
        } else {
            for (char c: buffer) {
                forms.answers[c-'a'] = true;
            }
        }
    }

    answer_sum += forms.report();

    std::cout << "Sum of YES counts: " << answer_sum << std::endl;

    return 0;
}
