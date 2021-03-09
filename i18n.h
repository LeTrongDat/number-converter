#ifndef I18N_H
#define I18N_H
#include "utils.h"
struct I18N {
    private:
        const set<string> LANGS = { "en", "vn" };
        const string DELIMITER = "=";
        const string DEFAULT_LANG = "en";
        map<string, string> translator;
        string lang = DEFAULT_LANG;
        void init();
    public:
        void change_lang(string code);
        string get(string before);
};
#endif