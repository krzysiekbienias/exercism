#include "acronym.h"
#include <string>
#include <vector>
#include <sstream>
#include <set>

namespace acronym {
    std::string acronym(std::string str) {
        std::string res = "";
        auto tokenize = [](const std::string &str, char delim = ' ')-> std::vector<std::string> {
            std::vector<std::string> out;
            std::istringstream iss(str);
            std::string token;
            while (std::getline(iss, token, delim)) {
                if (!token.empty()) out.emplace_back(token);
            }
            return out;
        };
        //unify delimiter
        for (char &ch: str) {
            if (ch == '-' || ch == '_') ch = ' ';
        }
        std::vector<std::string> tokens = tokenize(str);
        for (std::string &item: tokens) {
            unsigned char us = item[0];
            res += std::toupper(us);
        }
        return res;
    }
} // namespace acronym
