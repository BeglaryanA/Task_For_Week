#ifndef CAESARALGORITHM_H
#define CAESARALGORITHM_H

#include <string>
#include <map>

class CaesarAlgorithm {
public:
    CaesarAlgorithm();

public:
    std::string operator() (const std::string&, std::string&, const int);
private:
    using Caesar = std::string(CaesarAlgorithm::*)(std::string&, const int);
    enum class CODE { DECODE = 1, ENDCODE };

    std::map<std::string, CODE> commandConnection;
    std::map<CODE, Caesar> function_ht;

private:
    void initMap();
    bool isSmallLetter(const char);

private:
    std::string decode(std::string&, int);
    std::string encode(std::string&, int);

private:
    const int alphabetSize;
    const char lastSmallLetter;
    const char firstSmallLetter;
    const char lastCapitleLetter;
    const char firstCapitleLetter;
    const char witheSpace;
};

#endif // CAESARALGORITHM_H