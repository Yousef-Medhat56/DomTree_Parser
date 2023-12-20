#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string>
#include <vector>
using namespace std;

class StringUtils{
    public:
    //split string to vector of strings by a delimiter
    static vector<string> split(string s,string delimiter);
    // trim new line characters from start and end of string
    static string trimNewline(string s);
    // trim whitespaces from start and end of string
    static string trimSpaces(string s);
    //check if string starts with the given string
    static  bool startsWith(const string s,const string start);
    //trim the first and last characters in the string
    static string trimFirstAndLastChar(string s);
};

#endif