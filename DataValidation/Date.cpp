#include "Date.h"


bool Date::isNotNubmer(const char sym) {
    return sym < '0' || sym > '9';
}

Date::Date(std::string& date, int format) 
: m_day{nullptr}
, m_month{nullptr}
, m_year{nullptr}
, m_flag{}
{
    init_forms();
    do {
        std::cin >> format;
    } while (format <= 0 || format > 6);
    auto it = std::find_if(forms.begin(), forms.end(),
                [&] (auto args) { return static_cast<int>(args.second) == format; });
    std::cout << "Format " << (it)->first << std::endl;
    std::cout << "Enter date : ";
    std::cin >> date;

    auto splited = this->splite(date);

}


Date::~Date() {
    delete m_day;
    delete m_month;
    delete m_year;
    m_day = nullptr;
    m_month = nullptr;
    m_year = nullptr;
}

std::vector<std::string> Date::splite(std::string& date) {
    std::vector<std::string> spilted;
    int j = 0;
    std::string tmp = "";
    int i{};
    for (i = 0; i < date.size(); ++i) {
        if (isNotNubmer(date[i])) {
            tmp += date.substr(j, i - j);
            j = i + 1;
            if (tmp.empty()) {
                throw std::invalid_argument("Invalid syntax dublicate symbol next to each other");                 
            }
            spilted.push_back(tmp);
            tmp.clear();
        }
    }
    tmp.clear();
    tmp += date.substr(j, i - j);
    if (!tmp.empty()) {
        spilted.push_back(tmp);
    }
    return spilted;
}


void Date::init_forms() {
    forms["DD/MM/YY"] = DateFormat::F1;
    forms["MM/DD/YY"] = DateFormat::F2;
    forms["MM/YY/DD"] = DateFormat::F3;
    forms["DD/YY/MM"] = DateFormat::F4;
    forms["YY/DD/MM"] = DateFormat::F5;
    forms["YY/MM/DD"] = DateFormat::F6;
}

void Date::switch_(const int format, const std::vector<std::string>& splited) {
    switch(format) {
        case static_cast<int>(DateFormat::F1):
            std::cout << "F1" << std::endl;
            this->m_day = new Day(*splited.begin());
            this->m_month = new Month(*++splited.begin());
            this->m_year = new Year(*++splited.begin());
        break;
        case static_cast<int>(DateFormat::F2):
            std::cout << "F2" << std::endl;
            this->m_month = new Month(*splited.begin());
            this->m_day = new Day(*++splited.begin());
            this->m_year = new Year(*++splited.begin());
        break;
        case static_cast<int>(DateFormat::F3):
            std::cout << "F3" << std::endl;
            this->m_month = new Month(*splited.begin());
            this->m_year = new Year(*++splited.begin());
            this->m_day = new Day(*++splited.begin());
        break;
        case static_cast<int>(DateFormat::F4):
            std::cout << "F4" << std::endl;
            this->m_day = new Day(*splited.begin());
            this->m_year = new Year((*++splited.begin()));
            this->m_month = new Month(*++splited.begin());
        break;
        case static_cast<int>(DateFormat::F5):
            this->m_year = new Year(*splited.begin());
            this->m_day = new Day(*++splited.begin());
            this->m_month = new Month(*(++splited.begin()));
        break;
        case static_cast<int>(DateFormat::F6):
            this->m_year = new Year((*splited.begin()));
            this->m_month = new Month(*++splited.begin());
            this->m_day = new Day(*++splited.begin());
        break;
    }
}