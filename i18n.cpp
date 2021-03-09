#include <bits/stdc++.h>
using namespace std;
#include "i18n.h"
void I18N::init() {
    // FILE* f = fopen(("./resources-" + lang).c_str(), "r");
    ifstream file(("./resources-" + lang).c_str());
    string translation;
    translator.clear();
    while (getline(file, translation)) {
        int pos_delim = translation.find(DELIMITER);
        string before = translation.substr(0, pos_delim);
        string after = translation.substr(pos_delim + 1, translation.length() - pos_delim - 1);
        translator[before] = after;
    }
    file.close();
    // cerr << "END OF FILE\n";
}
void I18N::change_lang(string code) {
    Utils::to_lowercase(code);
    lang = LANGS.count(code) ? code : DEFAULT_LANG;
    init();
}
string I18N::get(string before) {
    return (translator.count(before) ? translator[before] : before);
}