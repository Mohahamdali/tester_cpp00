#ifndef header_cpp
#define header_cpp
#include <sstream>
#include <iostream>
#include <iomanip>

class contact
{
    private:
      std::string name;
      std::string last_name;
      std::string number;
      std::string nickname;
      std::string darkest_secret;
    public:
      void set_fullname_and_number (const std::string &name1,const std::string &num,const std::string &nick, \
        const std::string &secret, const std::string &last_name1);
      void print ();
      std::string get_name()const;
      std::string get_last_name()const;
      std::string get_number()const;
      std::string get_nick()const;
      std::string get_secret()const;
};

class PhoneBook
{
  private:
    contact contacts[8];
    int     contact_count;
  
  public:
    PhoneBook(){contact_count = 0;};
    void add_contact (std::string &fullname,std::string &number, std::string &nickname, std::string & secret_field, std::string &last_name);
    void search_contact();
};
 std::string truncut (std::string &str);
#endif
