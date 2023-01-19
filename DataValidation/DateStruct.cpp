#include "DateStruct.h"

Day::Day(const std::string& rhs) 
: m_day{rhs}
{   
    int day = std::stoi(rhs);
    if (day <= 0 || day > 31) {
        throw std::invalid_argument("Day can't be in range of 1-31");
    } 
}

Month::Month(const std::string& rhs) 
: m_month{rhs}
{   
    int month = std::stoi(rhs);
    if ((month <= 0 || month > 12)) {
        throw std::invalid_argument("Day can't be in range of 1-12");
    }
}

Year::Year(const std::string& rhs) 
: m_year{rhs}
{
    if (m_year.size() > 4) {
        throw std::invalid_argument("Year can't be low than 1000");
    }
}