#include "trinary.h"
#include <string>

namespace trinary {

int to_decimal(std::string nb) {
    int res=0;
    int n=nb.size();
    int pow3=1; //---> 3^0
    for (int i=0;i<n;++i) {
        char ch=nb[n-1-i];
        if (ch<'0' || ch>'2') {
            return 0;
        }
        int digit=ch-'0';
        res+=digit*pow3;
        pow3*=3;
    }
    return res;
}

}  // namespace trinary
