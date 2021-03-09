#include<bits/stdc++.h>
using namespace std;
#include "converter.h"

string special_cases[] = {
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", 
    "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"
};
string tens[] = {
    "", "", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"
};
string suffix_name[] = {
    "trillion", "billion", "million", "thousand", "hundred"
};
int suffix_lower_bound[] = {
    12, 9, 6, 3, 2
};
string NumberConverter::read(const BigDecimal& num) {
    if (num.get_length() > 1 and num < 10) {
        return (num.to_int() == 0 ? "" : i18n->get("and") + " " + i18n->get(special_cases[num.to_int()]));
    }
    if (num < 21) {
        return (num.to_int() == 0 ? "" : i18n->get(special_cases[num.to_int()]));
    }

    if (num < 100) {
        return i18n->get(tens[num.at(0)-'0']) +  
            (num.at(1) != '0' ? " " + i18n->get(special_cases[num.at(1)-'0']) : "");
    }

    for(int i = 0; i < sizeof(suffix_lower_bound) / sizeof(int); ++i) {
        if (num.get_length() > suffix_lower_bound[i]) {
            int remain = num.get_length() % suffix_lower_bound[i];
            remain = (not remain ? suffix_lower_bound[i] : remain);
            string prefix = read(num.subnum(0, remain));
            string suffix = read(num.subnum(remain, num.get_length() - remain));
            return prefix + 
                " " + 
                i18n->get(suffix_name[i]) + 
                (suffix != "" ? " " + suffix : "");
        }
    }
    return "";
}

NumberConverter::NumberConverter(){};
NumberConverter::NumberConverter(I18N* i18n): i18n(i18n) {};
string NumberConverter::convert(BigDecimal num) {
    if (num == 0) return i18n->get("zero");
    if (num.get_sign() == -1) return i18n->get("negative") + " " + read(num.subnum(1, num.get_length() - 1));
    return read(num);
}