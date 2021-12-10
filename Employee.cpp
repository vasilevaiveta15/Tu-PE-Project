#include <iostream>
#include <cctype>
#include <sstream>


using namespace std;

class Employee : public error_code {
private:
    string firstName;
    string middleName;
    string lastName;
    string egn;
    string code;


/*      Constructors      */
public:
    Employee() = default;

public:
    Employee(string firstName, string middleName, string lastName,
             string egn) {
        this->setFirstName(firstName);
        this->setMiddleName(middleName);
        this->setLastName(lastName);
        this->setEgn(egn);
    }
public:
    Employee(string firstName, string middleName, string lastName,
             string egn, string code) {
        this->setFirstName(firstName);
        this->setMiddleName(middleName);
        this->setLastName(lastName);
        this->setEgn(egn);
        this->setCode(code);
    }

/*      Destructor      */
    ~Employee()
    {
    }


/*      Check for numbers in string       */
    bool isNumber(const string& s)
    {
        char current;
        for (int i=0;i<s.length();i++) {
           current = (char)s[i];
            if (current>='0'&&current<='9') {
                return false;
            }
        }
        return true;
    }

    const string &getFirstName() const {
        return firstName;
    }

    void setFirstName(const string &firstName)
    {
/*          Assert for invalid first name            */
        if (!isNumber(firstName))
        {
            throw invalid_argument("In first name there should be no numbers!");
        }
        Employee::firstName = firstName;
    }

    const string &getMiddleName() const
    {
        return middleName;
    }

    void setMiddleName(const string &middleName)
    {
/*          Assert for invalid middle name            */
        if (!isNumber(middleName))
        {
            throw invalid_argument("In middle name there should be no numbers!");

        }
        Employee::middleName = middleName;
    }

    const string &getLastName() const {
        return lastName;
    }

    void setLastName(const string &lastName)
    {
/*          Assert for invalid last name            */
        if (!isNumber(lastName))
        {
            throw invalid_argument("In last name there should be no numbers!");

        }
        Employee::lastName = lastName;

    }

    const string &getEgn() const
    {
        return egn;
    }

    void setEgn(const string &egn)
    {
/*          Assert for invalid egn size            */
        if (egn.size() != 10)
        {
            throw invalid_argument("Invalid size of EGN!");
        }
        for(int i = 0; i < egn.size(); i++)
        {
            char symbol = egn.at(i);
            if(isalpha(symbol))
            {
                throw invalid_argument("Invalid EGN!");
            }
        }
        Employee::egn = egn;
    }

    const string &getCode() const
    {
        return code;
    }

    void setCode(const string &code)
    {
/*          Assert for invalid code size            */
        if (code.size() != 4)
        {
            throw invalid_argument("Size of code must be exact 4 symbols!");
        }
        for(int i = 0; i < code.size(); i++)
        {
            char symbol = code.at(i);
            if(isalpha(symbol))
            {
                throw invalid_argument("Invalid input of code!");
            }
        }
        Employee::code = code;
    }

    std::string toString() {
        std::ostringstream strout;
        strout<< "First name: " << firstName << "\n Middle name: " << middleName << "\n Last name: " << lastName
              << "\n Egn: " << egn << "\n Code: " << code << "\n\n";
        return strout.str();
    }
};