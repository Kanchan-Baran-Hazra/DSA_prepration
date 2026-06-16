#include <string>
#include <algorithm>

class Solution {
public:
    string processStr(string s) {
        string result = "";
        
        for (char ch : s) {
            if (ch >= 'a' && ch <= 'z') {
                // Append lowercase letter
                result.push_back(ch);
            } 
            else if (ch == '*') {
                // Remove the last character if it exists
                if (!result.empty()) {
                    result.pop_back();
                }
            } 
            else if (ch == '#') {
                // Duplicate the current result
                result += result;
            } 
            else if (ch == '%') {
                // Reverse the current result
                std::reverse(result.begin(), result.end());
            }
        }
        
        return result;
    }
};