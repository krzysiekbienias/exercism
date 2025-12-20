#include "binary.h"
#include <string>

namespace binary {

    int convert(const std::string & bin) {
        int res=0;
        int n=bin.size();
        for (int i=0;i<n;++i) {
            if (bin[i]!='0' && bin[i]!='1' ) return 0;
            if (bin[n-1-i]-'0'==1)
            res+=1<<i;
        }
        return res;

    }

}  // namespace binary
