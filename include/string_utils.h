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
};

#endif