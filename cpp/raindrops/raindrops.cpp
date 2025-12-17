#include "raindrops.h"

namespace raindrops {

    std::string convert(int x) {
        std::string out;
        if (x%3==0)  out+= "Pling";
        if (x%5==0)  out+= "Plang";
        if (x%7==0)  out+= "Plong";

        if (out.empty()) return std::to_string(x);

        return  out;
    }

}  // namespace raindrops
