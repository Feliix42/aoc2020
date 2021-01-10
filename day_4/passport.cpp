#include "passport.hpp"

bool Passport::is_valid(bool strict) {
    // TODO: Could we optimize this? Definitely! By not constructing the same regexes aat every call and stopping evaluation as soon as `valid_data` is false
    bool all_fields_present = !byr.empty() && !iyr.empty() && !eyr.empty() && !hgt.empty() && !hcl.empty() && !ecl.empty() && !pid.empty();
    if (!strict) {
        return all_fields_present;
    } else if (!all_fields_present) {
        return false;
    }

    bool valid_data = true;

    // Birth Year
    int year = std::stoi(byr);
    valid_data = valid_data && (year >= 1920 && year <= 2002) && byr.length() == 4;

    // Issue Year
    int issue_year = std::stoi(iyr);
    valid_data = valid_data && (issue_year >= 2010 && issue_year <= 2020) && iyr.length() == 4;

    // Expiration Year
    int expiry = std::stoi(eyr);
    valid_data = valid_data && (expiry >= 2020 && expiry <= 2030) && eyr.length() == 4;

    // height
    int height = std::stoi(hgt);
    if (hgt.find("cm") != std::string::npos) {
        valid_data = valid_data && (height >= 150 && height <= 193);
    } else if (hgt.find("in") != std::string::npos) {
        valid_data = valid_data && (height >= 59 && height <= 76);
    } else {
        valid_data = false;
    }

    // Hair color
    std::regex hair_colors("^#([0-9a-z]){6}$", std::regex::icase);
    valid_data = valid_data && std::regex_match(hcl, hair_colors);

    // Eye color
    std::regex eye_color("^amb|blu|brn|gry|grn|hzl|oth$");
    valid_data = valid_data && std::regex_match(ecl, eye_color);

    // Passport ID
    std::regex passport_id("^[0-9]{9}$");
    valid_data = valid_data && std::regex_match(pid, passport_id) && pid.length() == 9;

    return all_fields_present && valid_data;
}

void Passport::clear(void) {
    byr = "";
    iyr = "";
    eyr = "";
    hgt = "";
    hcl = "";
    ecl = "";
    pid = "";
    cid = "";
}

void Passport::add(std::string key, std::string value) {
    if (key == "byr") {
        byr = value;
    } else if (key == "iyr") {
        iyr = value;
    } else if (key == "eyr") {
        eyr = value;
    } else if (key == "hgt") {
        hgt = value;
    } else if (key == "hcl") {
        hcl = value;
    } else if (key == "ecl") {
        ecl = value;
    } else if (key == "pid") {
        pid = value;
    } else if (key == "cid") {
        cid = value;
    }
}
