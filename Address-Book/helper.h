#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <map>
#include <fstream>
#include <iomanip>
#include <vector>


struct book {
    std::string name;
    std::string email;
    std::string phone;
    int status = 0;
};



class helper
{
public:
    helper();
    ~helper();

public:
    void init();
    void flush();
    void fetch();
    void line_cutter(std::string& line);
    std::vector<std::string>parser(const std::string& str, std::string& spliter);
    static int ID;

public:
    book* addres;
    std::map<int, book*> m_all_adreses;
    std::map<book*, std::streampos> save_addres;

private:
    enum key_names { SKOB = 1, NAME , EMAIL, PHONE};
    std::map<std::string,key_names> m_book_add;
    std::fstream fs;

};

#endif // HELPER_H
