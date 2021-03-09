#include <bits/stdc++.h>
using namespace std;
#include "i18n.h"
#include "bdecimal.h"
#include "converter.h"
const string DASH = " --------------------------- ";

void help() {
    cout << "main: illegal option -- -\n";
    cout << "usage: ./a.out [-lh]\n";
    cout << "OPTIONS: \n";
    cout << "-l=<value>" << setw(90) << "Language code (Supported language of current version: en(english), vn(vietnamese)\n";
}
int main(int argc, char** argv) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    I18N *i18n = new I18N();
    if (argc) {
        for(int i = 1; i < argc; ++i) {
            string s = argv[i];
            if (s == "-h") {
                help();
                return 0;
            }
            int delim = s.find("=");
            string opt = s.substr(0, delim);
            if (delim == -1 || opt != "-l") {
                cout << "Invalid arguments. Use [-h] to see the list of available options\n";
                return 0;
            }
            i18n->change_lang(s.substr(delim + 1, s.length() - delim - 1));
        }
    }
    NumberConverter converter = NumberConverter(i18n);
    cout << DASH + i18n->get("Welcome to my number pronunciation training command line app") + DASH << '\n';
    while (true) {
        cout << "> " << i18n->get("Please enter your number") << ": ";
        string num; cin >> num;
        try {
            BigDecimal bd = BigDecimal(num);
            if (!bd.is_normal()) throw "Incorrect input. Please try again";
            string res = converter.convert(bd);
            cout << "> " + res << '\n';
        } catch (const char* msg) {
            string s(msg);
            cout << "> " << i18n->get(s) << '\n';
        }
    }
    
    return 0;
}
