#include <bits/stdc++.h>
using namespace std;
#include "utils.h"
void Utils::to_lowercase(string &s) {
    for(int i = 0; i < s.length(); ++i)
        s[i] = char(tolower(s[i]));
}
string Utils::normalize(string s) {
    int i = 0;
    while (i < s.length() && s[i] == '0' || s[i] == '-') i ++;
    string tmp = s.substr(i, s.length() - i);
    return (tmp == "" ? "0" : tmp);
}