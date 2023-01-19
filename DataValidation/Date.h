#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include "DateStruct.h"


class Date {
public:
    Date(std::string&, const int);
    ~Date();
public:
    bool get_flag();

private:
    enum class DateFormat { F1 = 1, F2, F3, F4, F5, F6 };

    std::map<std::string, DateFormat> forms;
private:
    void init_forms();
    bool isNotNubmer(const char sym);
    void switch_(const int, const std::vector<std::string>&);
private:
    std::vector<std::string> splite(std::string&);

private:
    Day* m_day;
    Month* m_month;
    Year* m_year;
    bool m_flag;
};
// ["YY/MM/DD"] F6


#endif // DATE_H