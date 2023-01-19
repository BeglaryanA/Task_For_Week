#include <iostream>
#include <string>
#include <algorithm>

#include "DataValidation.h"


DataValidation::DataValidation()
: at{'@'}
, dot{'.'}
, hyphen{'-'}
, schemEnd{"://"}
, numZero{'0'}
, numNine{'9'}
, m_date{nullptr}
{}


DataValidation::~DataValidation() {
    delete m_date;
}

bool DataValidation::ValidEamil(const std::string& emailForCheck) {
    auto atIt = std::find(emailForCheck.begin(), emailForCheck.end(), this->at);
    if (atIt == emailForCheck.end()) { return false; }
    if ((emailForCheck.begin() ==  atIt)) { return false; }

    std::string RecipientName(emailForCheck.begin(), atIt);
    if (!isValidRecipient(RecipientName)) { 
        return false; 
    }

    std::string DomainName(atIt + 1, emailForCheck.end());
    if (*DomainName.begin() == hyphen
                || *DomainName.begin() == dot) { return false; }
    if (*(DomainName.end() - 1) == hyphen
                || *(DomainName.end() - 1) == dot) { return false; }
    
    if (!isValidDomain(DomainName)) { return false; }
    return true;
}

bool DataValidation::isValidRecipient(const std::string& RecipientName) {
    if (!(isValidSymbol(*RecipientName.begin()))) {
        return false;
    }
    if (!(isValidSymbol(*(RecipientName.end() - 1)))) {
        return false;
    }
    for (auto it = RecipientName.begin(); it < RecipientName.end() - 1; ++it) {
        if (!(isValidSymbol(*it) || isValidSymbol(*(it + 1)))) {
            return false;
        }
    }
    return true;
}

bool DataValidation::isValidDomain(const std::string& DomainName) {
    for (auto it = DomainName.begin(); it < DomainName.end() - 1; ++it) {
        if (!(isValidSymbol(*it) || isValidSymbol(*(it + 1)))) {
            return false;
        } 
        if (!isValidSymbol(*it)) {
            if ((*it != hyphen || *it != dot)) { return false; }
        }
    }
    return true;
}

bool DataValidation::isValidSymbol(const char sym) {
    return ((sym >= 'a' && sym <= 'z') 
            || (sym >= 'A' && sym <= 'Z')) 
                                || ((sym <= '9' && sym >= '0')); 
}

bool DataValidation::ValidURL(const std::string& URL) {
    int pos = URL.find(schemEnd);
    if (pos == std::string::npos) { return false; }
    std::string scheme(URL.begin(), URL.begin() + pos);

    if (!(isValidScheme(scheme))) {
        return false;
    }

    if (URL.find(".") == std::string::npos) {
        return false;
    }

    if (URL.find("/") == std::string::npos) {
        return false;
    }
    return true;
}


bool DataValidation::isValidScheme(const std::string& scheme) {
    for (auto it = scheme.begin(); it < scheme.end(); ++it) {
        if (!(isValidSymbol(*it))) {
            return false;
        }
    }
    return true;
}


bool DataValidation::ValidNumber(const std::string& numberForCheck) {

    auto itInNumber = numberForCheck.begin();
    if (*itInNumber == this->hyphen 
                    && (*(++itInNumber) <= '0' || *(itInNumber) > '9')) {
            return false;
    }
    if (!this->checkDotInNumber(numberForCheck)) {
        return false;
    }
    for (auto i = itInNumber; i != numberForCheck.end(); ++i) {
        if (*i == dot) {
            continue;
        } else if ((*i < this->numZero) || (*i > this->numNine)) {            
            return false;
        }
    }
    return true;
}

bool DataValidation::checkDotInNumber(const std::string& number) {
    if (((*number.begin()) == this->numZero )
                          && (*(number.begin() + 1) != dot)) {
            return false;
    }
    auto search_dot = std::find(number.begin(), number.end(), '.');
    if ((search_dot == number.begin()) || (search_dot == number.end() - 1)) {
        return false;
    }
    else if (search_dot == number.end()) {
        return true;
    }
    auto for_other_dot = std::find(++search_dot, number.end(), '.');
    if (for_other_dot != number.end()) {
        return false;
    }
    return true;
}


bool DataValidation::ValidDate(std::string& date, const int format) {
    try {
        this->m_date = new Date(date, format);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
    return true;
}