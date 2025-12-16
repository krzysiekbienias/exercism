#include "pangram.h"

namespace pangram {

    bool is_pangram(const std::string & sentence) {
        bool seen[26]={};
        //it is better even to use std::array
        // std::array<bool,26>
        int count=0;
        int n=sentence.size();
        for (int i=0;i<n;++i) {
            if (std::isalpha(sentence[i])) {
                unsigned char us=sentence[i];
                char ls=std::tolower(us);
                int idx=ls-'a';
                if (!seen[idx]) {
                    seen[idx]=true;
                    if (++count==26) return true; //early exit
                }

            }
        }
        return count==26;
    }

}  // namespace pangram
