#include "passport.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char const *argv[])
{
    if (argc < 3) {
        std::cout << "Usage: ./solution [task number] [input file]" << std::endl;
        return 1;
    }
    
    bool strict_mode = argv[1][0] == '2';

    std::ifstream fin(argv[2]);
    unsigned valid_passports = 0;

    Passport passport;
    std::string buf, cls, value;
    while(std::getline(fin, buf)) {
        if (buf.empty()) {
            // parsing of a passport ended, evaluate and clear
            if (passport.is_valid(strict_mode)) {
                valid_passports++;
            }

            passport.clear();
        } else {
            // split on whitespaces or \n, parse
            size_t cur = 0;
            size_t next = 0;
            while (cur < buf.length()) {
                // I somehow took a week-long break amid writing this and this all became an entangled mess afterwards
                next = buf.find_first_of(" \n", cur);
                if (next == std::string::npos) {
                    next = buf.length();
                }
                std::string sub(buf.substr(cur, next - cur));
                if (!sub.empty()) {
                    size_t colon = buf.find(':');
                    cls = sub.substr(0, colon);
                    value = sub.substr(colon+1, next);
                    passport.add(cls, value);
                }

                cur = next + 1;
            }
        }
    }

    std::cout << "Number of \"valid\" passports: " << valid_passports << std::endl;

    return 0;
}
