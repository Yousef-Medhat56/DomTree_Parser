#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string>
#include <vector>
using namespace std;

class StringUtils{
    public:
    static vector<string> split(string s,string delimiter);
};

#endif