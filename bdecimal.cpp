#include <bits/stdc++.h>
using namespace std;
#include "bdecimal.h"
bool BigDecimal::is_normal() {
    if (!regex_match(num, INTEGER)) return false;
    sign = num[0] == '-' ? -1 : 1;
    num = Utils::normalize(num);
    if (num == "0") sign = 1;
    return true;
}
BigDecimal::BigDecimal(){};
BigDecimal::BigDecimal(string num) : num(num) {};
BigDecimal::BigDecimal(int num) : BigDecimal(to_string(num)) {};
int BigDecimal::get_length() const { return num.length(); }
char BigDecimal::at(int index) const { return num[index]; }
int BigDecimal::to_int() const { return stoi(num); }
int BigDecimal::get_sign() const { return sign; }
BigDecimal BigDecimal::subnum(int begin, int len) const {
    return BigDecimal(num.substr(begin, len));
}
bool BigDecimal::operator < (const BigDecimal& rhs) const {
    string tmp = Utils::normalize(num);
    if (tmp.length() != rhs.get_length()) return tmp.length() < rhs.get_length();
    for(int i = 0; i < get_length(); ++i) 
        if (tmp[i] != rhs.at(i)) return tmp[i] < rhs.at(i);
    return false;
}
bool BigDecimal::operator < (const int &rhs) const {
    return BigDecimal(num) < BigDecimal(rhs);
}
bool BigDecimal::operator == (const BigDecimal& rhs) const {
    return not (BigDecimal(num) < rhs) and not (rhs < BigDecimal(num));
}
bool BigDecimal::operator == (const int &rhs) const {
    return not (BigDecimal(num) < BigDecimal(rhs)) and not (BigDecimal(rhs) < BigDecimal(num));
}