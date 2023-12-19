#include <string>
#include <algorithm>
#include "../include/string_utils.h"
using namespace std;

vector<string> StringUtils::split(string s, string delimiter)
{
    size_t pos = 0; // index of the current character
    string token;
    vector<string> tokens;

    while ((pos = s.find(delimiter)) != std::string::npos)
    {
        token = s.substr(0, pos);
        tokens.push_back(token);
        s.erase(0, pos + delimiter.length()); // remove the token
    }
    tokens.push_back(s);
    return tokens;
}

string StringUtils::trimNewline(string s)
{
    s.erase(remove(s.begin(), s.end(), '\n'), s.cend());
    return s;
}