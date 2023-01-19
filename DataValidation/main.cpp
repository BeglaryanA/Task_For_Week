#include "DataValidation.h"

void initilize_date(std::string&, int&);

int main() {
    DataValidation checking;
    std::string date{};
    int format_for_date{};
    std::string email{};
    std::string URL{};
    std::string number{};
    // DataValidation::ValidDate(string, int)
    // DataValidation::ValidEamil(string: email)
    // DataValidation::ValidNumber(string)
    // DataValidation::ValidURL(string: URL)
    // for format call initilize_date

}

void initilize_date(std::string& date, int& format) {
    std::cout << "Select date format" << std::endl;
    std::cout << "1 -> " << "DD/MM/YY" << std::endl;
    std::cout << "2 -> " << "MM/DD/YY" << std::endl;
    std::cout << "3 -> " << "MM/YY/DD" << std::endl;
    std::cout << "4 -> " << "DD/YY/MM" << std::endl;
    std::cout << "5 -> " << "YY/DD/MM" << std::endl;
    std::cout << "6 -> " << "YY/MM/DD" << std::endl;
}