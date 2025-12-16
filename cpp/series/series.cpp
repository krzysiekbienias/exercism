#include "series.h"
#include<vector>
#include<string>
#include <stdexcept>


using namespace std;

namespace series {
    vector<string> slice(const string &str, int len) {
        if (len <= 0 || str.empty() || len > static_cast<int>(str.size())) {
            throw domain_error("Len cannot be negative and string cannot be empty");
        }
        vector<string> res;
        int n = str.size();
        for (int i = 0; i <= n - len; i++) {
            string part = "";
            for (int j = i; j < i + len; ++j) {
                part.push_back(str[j]);
            }
            res.emplace_back(part);
        }

        return res;
    }


    // more idiomatic way
    vector<string> sliceCppIdiomatic(const string& str, int len) {
        const int n = static_cast<int>(str.size());
        if (len <= 0 || len > n) {
            throw domain_error("invalid series length");
        }

        vector<string> res;
        res.reserve(n - len + 1);

        for (int i = 0; i <= n - len; ++i) {
            res.emplace_back(str.substr(i, len));
        }
        return res;
    }
} // namespace series
