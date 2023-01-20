#include <iostream>
#include <string>
#include <algorithm>

#include "DataValidation.h"


DataValidation::DataValidation()
: numZero{'0'}
, numNine{'9'}
, at{'@'}
, dot{'.'}
, hyphen{'-'}
{}


DataValidation::~DataValidation() {}

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
        if (!isValidSymbol(*it)) {
            if ((*it != hyphen && *it != dot)) { return false; }
        }
        if (!(isValidSymbol(*it) || isValidSymbol(*(it + 1)))) {
            return false;
        }
    }
    return true;
}

bool DataValidation::isValidSymbol(const char sym) {
    return ((sym >= 'a' && sym <= 'z')
            || (sym >= 'A' && sym <= 'Z'))
                                || ((sym <= '9' && sym >= '0'));
}

bool DataValidation::ValidNumber(const std::string& numberForCheck) {
    auto itInNumber = numberForCheck.begin();
    for (auto i = itInNumber; i != numberForCheck.end(); ++i) {
        if ((*i < this->numZero) || (*i > this->numNine)) {
            return false;
        }
    }
    return true;
}

