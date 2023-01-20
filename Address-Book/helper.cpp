#include "helper.h"

int helper::ID = 0;

helper::helper()
{
    this->init();
//    this->fetch();
}

helper::~helper() {
    for (auto it : m_all_adreses) {
        delete it.second;
    }
    for (auto it : save_addres) {
        delete it.first;
    }
}


void helper::init() {
        m_book_add["{"] = key_names::SKOB;
        m_book_add["Name"] = key_names::NAME;
        m_book_add["Phone"] = key_names::PHONE;
        m_book_add["Email"] = key_names::EMAIL;
}


void helper::flush() {
    fs.open("/Users/aa/AddressBook/information.txt", std::ios::out);
    if (!fs.is_open())
    {

              std::runtime_error("Failed to open DataBase/information.txt file");
    }
    if (!(save_addres.empty())) {
        for(auto it : save_addres) {
            fs << "{\n"
            << std::setw(14) <<         "Name  : " << it.first->name << "\n"
            << std::setw(14) <<         "Email : " << it.first->email << "\n"
            << std::setw(14) <<         "Phone : " << it.first->phone << "\n"
            << "}" << std::endl;
        }
    }
    if (!(m_all_adreses.empty())) {
        for (auto it : m_all_adreses)
        {

            fs << "{\n"
            << std::setw(14) <<         "Name  : " << it.second->name << "\n"
            << std::setw(14) <<         "Email : " << it.second->email << "\n"
            << std::setw(14) <<         "Phone : " << it.second->phone << "\n"
            << "}" << std::endl;
        }
    }
    fs.close();
}


void helper::line_cutter(std::string& line)
{

   auto li = line.find(':');
   auto beg = line.begin();
   line.erase(beg + line.find(' '));
   line.erase(beg + line.find(' '));
   line.erase (beg, beg + li);

}


std::vector<std::string> helper::parser(const std::string& str, std::string& spliter)
{
    std::vector<std::string> nstr = {};
    std::string tstr = {};
    for (int i = 0; i < str.size(); ++i)
    {
        if (spliter.find(str[i]) != std::string::npos)
        {
            if (tstr != "")
            {
                nstr.push_back(tstr);
                tstr.clear();
                continue;
            }
            continue;
        }
        tstr.push_back(str[i]);
    }
    nstr.push_back(tstr);
    return nstr;
}

void helper::fetch() {
    fs.open("/Users/aa/AddressBook/information.txt");
        if (!fs.is_open())
        {

            std::runtime_error("Failed to open DataBase/information.txt file");
        }

       if (!fs.eof())
       {
        std::string str;
        std::string spliter = " :}";
        std::string line;
        std::streampos m_value;
        std::vector<std::string> m_vec;


        while (fs.peek() != EOF)
        {
            getline(fs, str);
            auto m_vec = parser(str, spliter);
            m_value = fs.tellg();
            book* tmp_obj = new book();

            if (static_cast<bool>(m_book_add[m_vec[0]]))
            {
                save_addres[tmp_obj] = m_value;

                m_value = fs.tellg();
                std::getline(fs.seekg(m_value), line);
                line_cutter(line);
                tmp_obj->name = line;


                m_value = fs.tellg();
                std::getline(fs.seekg(m_value), line);
                line_cutter(line);
                tmp_obj->email = line;


                m_value = fs.tellg();
                std::getline(fs.seekg(m_value), line);
                line_cutter(line);
                tmp_obj->phone = line;

            }
        }
       }
        fs.close();
}
