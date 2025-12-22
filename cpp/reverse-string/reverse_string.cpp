#include "reverse_string.h"
#include <string>

namespace reverse_string {

    std::string reverse_string(std::string str) {
        if (str.empty()) return "";
        std::string res=str;
        int l=0;
        int r=res.size()-1;
        while (l<r) {
            std::swap(res[l],res[r]);
            l++;
            r--;
        }
        return res;
    }

}  // namespace reverse_string
