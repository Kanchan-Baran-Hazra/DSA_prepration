#include <bits/stdc++.h>
using namespace std;


unordered_map<int,string> generateNumberWordsMap() {
    unordered_map<int, string> numberMap;

    vector<string> ones = {
        "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
        "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
        "seventeen", "eighteen", "nineteen"
    };

    vector<string> tens = {
        "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
    };

    // 0 is a special case
    numberMap[0] = "zero";

    // 1 to 19
    for (int i = 1; i <= 19; ++i) {
        numberMap[i] = ones[i];
    }

    // 20 to 99
    for (int i = 20; i <= 99; ++i) {
        int tensDigit = i / 10;
        int onesDigit = i % 10;
        numberMap[i] = tens[tensDigit] + ones[onesDigit];
    }

    // 100
    numberMap[100] = "hundred";

    return numberMap;
}

int main() {
    unordered_map<int, string> numToWord = generateNumberWordsMap();

    // Print values from 0 to 100
    for (int i = 0; i <= 100; ++i) {
        cout << i << " -> " << numToWord[i] << "\n";
    }

    

    return 0;
}