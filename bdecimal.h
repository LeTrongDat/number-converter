#ifndef BIG_DECIMAL_H
#define BIG_DECIMAL_H
#include "utils.h"
struct BigDecimal {
    private:
        const regex INTEGER = regex("^[-]?\\d+$");
        string num;
        int sign;
    public:
        BigDecimal();
        BigDecimal(string num);
        BigDecimal(int num);
        int get_length() const;
        char at(int index) const;
        int to_int() const;
        int get_sign() const;
        bool is_normal();
        BigDecimal subnum(int begin, int len) const;
        bool operator < (const BigDecimal& rhs) const;
        bool operator < (const int &rhs) const;
        bool operator == (const BigDecimal& rhs) const;
        bool operator == (const int &rhs) const;
};
#endif 