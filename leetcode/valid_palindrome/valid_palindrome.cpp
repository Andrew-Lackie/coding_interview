#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:

    char toUpper(char c) {
        if (isupper(c)) {

            return toupper(c);
        }

        else if (islower(c)) {

            return toupper(c);
        }
    }

    bool isPalindrome(string s) {

        string str;

        for (size_t i = 0; i < s.size(); i++) {
            s[i] = toUpper(s[i]);
        }

    }
};
