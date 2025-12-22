#include "luhn.h"
#include <algorithm>

namespace luhn {
    bool valid(std::string str) {
        int res = 0;
        str.erase(std::remove(str.begin(), str.end(), ' '), str.end());

        std::string orginal = str;
        int n = str.size();
        if (n == 1) return false;

        for (char c: str) {
            if (c < '0' || c > '9') return false;
        }

        for (int i = n - 2; i >= 0; i -= 2) {
            int temp = str[i] - '0';
            int d = temp * 2;
            if (d >= 10) {
                d = d - 9;
            }
            str[i] = char('0' + d);
        }
        for (int i = 0; i < n; ++i) {
            res += str[i] - '0';
        }
        return res % 10 == 0;
    }
} // namespace luhn
