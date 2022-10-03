# include <set>
# include <map>
# include <vector>
# include <iostream>
# include <unordered_map>
# include <unordered_set>
# include <algorithm>
# include <cmath>

using namespace std;

string reverseWords_my(string s) {
    vector<string> words;
    string res;
    string word;
    int count = 0;
    while (count < s.size()) {

        while (count < s.size() && s[count] == ' ') {
            count++;
        }

        while (count < s.size() && s[count] != ' ') {
            word += s[count];
            count++;
        }
        if (word != "")
            words.push_back(word);

        word.clear();


    }
    for (int i = words.size() - 1; i >= 0; --i) {
        res += ' ';
        res += words[i];
    }
    res.erase(0, 1);
    return res;
}

string reverseWords(string s) {
    vector<string> words;
    string res;
    string word;
    int count = 0;
    while (count < s.size()) {

        while (count < s.size() && s[count] == ' ') {
            count++;
        }

        while (count < s.size() && s[count] != ' ') {
            word += s[count];
            count++;
        }
        if (word != "")
            words.push_back(word);

        word.clear();


    }
    for (int i = words.size() - 1; i >= 0; --i) {
        res += ' ';
        res += words[i];
    }
    res.erase(0, 1);
    return res;
}

int main() {
    string s = "  hello world  ";
    reverseWords(s);
}
