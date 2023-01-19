#ifndef DATAVALIDATION_H
#define DATAVALIDATION_H

#include <string>

#include "Date.h"


class DataValidation {
public:
    DataValidation();
    ~DataValidation();
public:
    bool ValidEamil(const std::string&);
    bool ValidNumber(const std::string&);
    bool ValidURL(const std::string&);
    bool ValidDate(std::string&, const int);

private:
    bool isValidSymbol(const char);

private:
    bool isValidRecipient(const std::string&);
    bool isValidDomain(const std::string&);

private:
    bool isValidScheme(const std::string&);

private:
    bool checkDotInNumber(const std::string&);

private:
    Date* m_date;
    const char numZero;
    const char  numNine;
    const char at;
    const char dot;
    const char hyphen;
    const std::string schemEnd;
};


#endif // DATAVALIDATION_H