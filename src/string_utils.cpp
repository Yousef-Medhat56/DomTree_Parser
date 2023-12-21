#include <string>
#include <algorithm>
#include "../include/string_utils.h"
using namespace std;

// split string(by a delimiter) to a vector of strings (but ignore the string between double quatations)
vector<string> StringUtils::split(string s, string delimiter)
{
    vector<string> tokens;
    size_t start = 0;
    bool insideQuotes = false;

    // loop through each character in the string
    for (size_t i = 0; i < s.length(); ++i)
    {
        // check if the character is a quatation character
        if (s[i] == '"' || s[i] == '\'')
        {
            insideQuotes = !insideQuotes;
        }

        if (!insideQuotes && s.substr(i, delimiter.length()) == delimiter)
        {
            string token = s.substr(start, i - start);
            tokens.push_back(token);
            start = i + delimiter.length();
            i = start - 1; // Move i to the end of the current token
        }
    }

    // Add the last token (or the entire string if no delimiter is found)
    string lastToken = s.substr(start);
    tokens.push_back(lastToken);

    return tokens;
}

string StringUtils::trimNewline(string s)
{
    s.erase(remove(s.begin(), s.end(), '\n'), s.cend());
    return s;
}

string StringUtils::trimSpaces(string s)
{
    s = s.erase(s.find_last_not_of(' ') + 1); // suffixing spaces
    s = s.erase(0, s.find_first_not_of(' ')); // prefixing spaces
    return s;
}
bool StringUtils::startsWith(const string s, const string start)
{
    return (s.rfind(start, 0) == 0);
}

string StringUtils::trimFirst(string s){
    s.erase(s.begin());
    return s;
}

string StringUtils::trimFirstAndLastChar(string s)
{
    s.pop_back();
    s.erase(s.begin());
    return s;
}

string StringUtils::extract(string s, const string delimiter1, const string delimiter2)
{
    size_t start = s.find(delimiter1);
    size_t end = s.find(delimiter2);

    start += delimiter1.size();
    end -= (delimiter2.size() + 1);

    //the extracted string
    string extracted = s.substr(start, end);
    return extracted;
}