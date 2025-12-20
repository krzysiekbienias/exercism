#include <string>

namespace log_line {
std::string message(std::string line) {
    auto sep=line.find(':');
    std::string suff=line.substr(sep+2);
    std::string pref=line.substr(1,sep-2);
    return suff;
}

std::string log_level(std::string line) {
    auto sep=line.find(':');
    std::string suff=line.substr(sep+1);
    std::string pref=line.substr(1,sep-2);
    return pref;
}

std::string reformat(std::string line) {
    auto sep=line.find(':');
    std::string suff=line.substr(sep+2);
    std::string pref=line.substr(1,sep-2);

    return suff+" ("+pref+")";
}
}  // namespace log_line
