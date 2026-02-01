// User function Template for C++

int countWords(string s) {
    // code here.
    int count = 0;
    bool inWord = false;

    for (int i = 0; i < s.size(); i++) {

        // detect real whitespace
        bool isSep = isspace((unsigned char)s[i]);

        // detect literal "\n"
        if (s[i] == '\\' && i + 1 < s.size() && s[i + 1] == 'n') {
            isSep = true;
            i++; // skip 'n'
        }
        if (s[i] == '\\' && i + 1 < s.size() && s[i + 1] == 't') {
            isSep = true;
            i++; // skip 'n'
        }

        if (!isSep) {
            if (!inWord) {
                count++;
                inWord = true;
            }
        } else {
            inWord = false;
        }
    }

    return count;
}