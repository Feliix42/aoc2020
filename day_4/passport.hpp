#include <string>
#include <regex>

class Passport {
    public:
        std::string byr; // (Birth Year)
        std::string iyr; // (Issue Year)
        std::string eyr; // (Expiration Year)
        std::string hgt; // (Height)
        std::string hcl; // (Hair Color)
        std::string ecl; // (Eye Color)
        std::string pid; // (Passport ID)
        std::string cid; // (Country ID)
        
        bool is_valid(bool strict);
        void clear(void);
        void add(std::string key, std::string value);
};
