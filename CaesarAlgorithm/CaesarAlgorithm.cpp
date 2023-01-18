#include "CaesarAlgorithm.h"

CaesarAlgorithm::CaesarAlgorithm() 
: lastSmallLetter {'z'}
, firstSmallLetter {'a'}
, alphabetSize {26}
, lastCapitleLetter {'Z'}
, firstCapitleLetter {'A'}
, witheSpace{' '}
{
    this->initMap();
}

void CaesarAlgorithm::initMap() {
    commandConnection["decode"] = CODE::DECODE;
    commandConnection["encode"] = CODE::ENDCODE;

    function_ht[CODE::ENDCODE] = &CaesarAlgorithm::encode;
    function_ht[CODE::DECODE] = &CaesarAlgorithm::decode;
}

std::string CaesarAlgorithm::operator() (const std::string& command, std::string& to_code, const int step) {
    return (this->*function_ht[commandConnection[command]]) (to_code, step); 
}

bool CaesarAlgorithm::isSmallLetter(const char sym) {
    return ((sym >= 'a') && (sym <= 'z'));
}

std::string CaesarAlgorithm::decode(std::string& to_code, int step) {
    if (step >= alphabetSize) {
        step -= ((step / alphabetSize) * alphabetSize);
    }
    for (int i = 0; i < to_code.size(); ++i) {
        if (to_code[i] == witheSpace) {
            continue;
        }
        if (isSmallLetter(to_code[i])) {
            if ((to_code[i] - step) < firstSmallLetter) {

                to_code[i] = lastSmallLetter - (firstSmallLetter - (to_code[i] - step)) + 1;
                continue;
            }
        } else {
            if ((to_code[i] - step) < firstCapitleLetter) {
                to_code[i] = lastCapitleLetter - (firstCapitleLetter - (to_code[i] - step)) + 1;
                continue;
            }
        }
        to_code[i] -= step;
    }
    return to_code;
}

std::string CaesarAlgorithm::encode(std::string& to_code, int step) {
    if (step >= alphabetSize) {
        step -= ((step / alphabetSize) * alphabetSize);
    }
    for (int i = 0; i < to_code.size(); ++i) {
        if (to_code[i] == witheSpace) {
            continue;
        }
        if (isSmallLetter(to_code[i])) {
            if ((to_code[i] + step) > lastSmallLetter) {
                to_code[i] = firstSmallLetter + (to_code[i] + step) - lastSmallLetter - 1;
                continue;
            }   
        } else {
            if ((to_code[i] + step) > lastCapitleLetter) {
                to_code[i] = firstCapitleLetter + (to_code[i] + step) - lastCapitleLetter - 1;
                continue;
            }
        }
        to_code[i] += step;
    }
    return to_code;
}



