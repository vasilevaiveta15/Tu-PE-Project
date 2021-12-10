#include <iostream>

using namespace std;

class String {
private:
    string str;
    //Pointer for the start of str
    char *start;
    int lenght;

public:
    String(const string &str) : str(str) {
        //set the length
        //set the starting *char
        validateString(str);
        setLenght(str.length());
        setStart( reinterpret_cast<char *>(str.at(0)));
    }

    virtual ~String() {

    }

    String() {}

public:

    const string &getStr() const {
        return str;
    }

    void setStr(const string &str) {
        String::str = str;
        //This is needed when using default constructor to create String
        //set the length
        //set the starting *char
        validateString(str);
        setLenght(str.length());
        setStart( reinterpret_cast<char *>(str.at(0)));
    }

    char *getStart() const {
        return start;
    }

    void setStart(char *start) {
        String::start = start;
    }

    int getLenght() const {
        return lenght;
    }

    void setLenght(int lenght) {
        String::lenght = lenght;
    }

    // Overload(Predefined) + operator to add two String objects.
    String operator+(const String& b) {
        String string;
        string.str = this->str + b.str;
        return string;
    }

    // Overload(predefined) = operator
    String operator=(const String& b){
        String string;
        string.str = b.str;
        return string;
    }

private: void validateString(string str){

        for(int i=0;i<str.length();i++){
            char current = (char)str[i];
            if(current >='A'&&current <= 'Z'){
            }else if(current >='a'&&current<='z'){
            }else if(current>='0'&&current<='9'){
            }else if(current ==' '||current=='.'){
            }else{
                throw invalid_argument("Invalid String!");
            }
        }
    }

};

