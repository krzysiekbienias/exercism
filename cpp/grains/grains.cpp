#include "grains.h"

namespace grains {
    using ull = unsigned long long;

    ull square(int square) {
        ull exp = static_cast<ull>(square - 1);
        ull base = 2ULL;
        ull res = 1ULL;

        while (exp > 0) {
            if (exp & 1ULL) {
                res = res * base;
            }
            base = base * base;
            exp >>= 1ULL;
        }
        return res;
    }

    ull total() {
        ull result=0ULL;
        for (int i=1;i<=64;++i) {
            result+=square(i);
        }
        return result;
    }
} // namespace grains
