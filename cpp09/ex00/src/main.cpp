#include "../include/BitcoinExchange.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

int open_required_files(std::ifstream &data_file, std::ifstream &provided_file, char *argv)
{
    data_file.open("data.csv", std::ios::in);
    if (!data_file) {
        std::cerr << "Error: Could not open the .csv file." << std::endl;
        return 1;
    }

    provided_file.open(argv, std::ios::in);
    if (!provided_file) {
        data_file.close();
        std::cerr << "Error: Could not open the provided file." << std::endl;
        return 1;
    }
    return 0;
}

bool is_only_spaces(const std::string &str)
{
    for (size_t i = 0; i < str.size(); i++) {
        if (!std::isspace(str[i])) {
            return false;
        }
    }
    return true;
}

Date extract_date(const std::string &line, size_t spliting_character_index, bool from_provided)
{
    unsigned int year = 0;
    unsigned int month = 0;
    unsigned int day = 0;

    size_t i = 0;
    while (i < spliting_character_index && std::isspace(line[i]))
        i++;
    if (i == spliting_character_index) {
        std::cout << "At this line: " << line << std::endl;
        throw InvalidFileFormat();
    }

    std::string date = line.substr(i, spliting_character_index - i);
    std::stringstream ss(date);
    std::string token;

    if (std::getline(ss, token, '-')) {
        year = static_cast<unsigned int>(std::strtol(token.c_str(), NULL, 10));
    }
    if (std::getline(ss, token, '-')) {
        month = static_cast<unsigned int>(std::strtol(token.c_str(), NULL, 10));
    }
    if (std::getline(ss, token, '-')) {
        day = static_cast<unsigned int>(std::strtol(token.c_str(), NULL, 10));
    }
    if (year == 0 || month == 0 || day == 0) {
        if (!from_provided) {
            std::cout << "At this line: " << line << std::endl;
            throw InvalidFileFormat();
        }
        throw Date::InvalidDateException();
    }

    Date newDate(year, month, day);
    return newDate;
}

double extract_value(const std::string &line, size_t spliting_character_index, bool from_provided)
{
    size_t i = spliting_character_index + 1;
    while (line[i] && std::isspace(line[i]))
        i++;

    size_t end = i;
    while (line[end] && !std::isspace(line[end]))
        end++;

    std::string value = line.substr(i, end - i);

    std::istringstream ss(value);
    double double_value;
    if (!(ss >> double_value)) {
        if (!from_provided) {
            std::cout << "At this line: " << line << std::endl;
            throw InvalidFileFormat();
        }
        throw BadValue();
    }
    if (double_value < 0) {
        throw NegativeValue();
    } else if (from_provided && double_value > 1000) {
        throw TooLargeNumber();
    }
    
    return double_value;
}

void parse_csv_file(std::map<Date, double> &data, std::ifstream &data_file)
{
    std::string line;
    std::getline(data_file, line);
    while (std::getline(data_file, line)) {
        if (is_only_spaces(line))
            continue ;
        size_t comma = line.find(",");
        if (comma == std::string::npos) {
            std::cout << "At this line: " << line << std::endl;
            throw InvalidFileFormat();
        }
        Date date = extract_date(line, comma, false);
        double value = extract_value(line, comma, false);
        data[date] = value;
    }
}

void display_provided_values(std::map<Date, double> &data, std::ifstream &provided_file)
{
    std::string line;

    std::getline(provided_file, line);
    while (std::getline(provided_file, line)) {
        if (is_only_spaces(line))
            continue ;
        size_t pipe = line.find("|");
        if (pipe == std::string::npos) {
            std::cout << "Error: bad input on this line => " << line << std::endl;
            continue ;
        }
        try {
            Date date = extract_date(line, pipe, true);
            double value = extract_value(line, pipe, true);
            std::map<Date, double>::iterator it = data.lower_bound(date);
            if (it == data.end() || it->first != date) {
                if (it != data.begin()) {
                    it--;
                    std::cout << date << " => " << value << " = " << value * it->second << std::endl;
                } else {
                    std::cout << "Error: Date too old => " << date << std::endl;
                }
            } else {
                std::cout << date << " => " << value << " = " << value * it->second << std::endl;
            }
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Error: Invalid arguments." << std::endl;
        std::cerr << "You should use the program like so: ./btc valid.txt" << std::endl;
        return 1;
    }

    std::ifstream       data_file;
    std::ifstream       provided_file;
    std::map<Date, double> data;

    if (open_required_files(data_file, provided_file, argv[1]) != 0)
        return 1;

    try {
        parse_csv_file(data, data_file);
        display_provided_values(data, provided_file);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        data_file.close();
        provided_file.close();
        return 1;
    }

    data_file.close();
    provided_file.close();

    return 0;
}
