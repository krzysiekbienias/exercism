#include "isogram.h"

#include <regex>
#include <string>
#include <unordered_map>

namespace isogram {

    bool is_isogram(std::string str) {
        std::unordered_map<char,int> um;
        for (char ch:str) {
            ch=std::tolower(ch);
            if (++um[ch]>1 && ch!='-' && ch!=' ') return false;
        }
        return true;
    }

}  // namespace isogram
