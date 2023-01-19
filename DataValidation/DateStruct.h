#ifndef DATESTRUCT_H
#define DATESTRUCT_H

#include <iostream>
#include <string>

struct Day {
    std::string m_day;
    Day(const std::string&);
}; 

struct Month {
    std::string m_month;
    Month(const std::string&);
};

struct Year {
    std::string m_year;
    Year(const std::string&);
};

#endif // DATESTRUCT_H