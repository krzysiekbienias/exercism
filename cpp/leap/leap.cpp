#include "leap.h"

namespace leap {

bool is_leap_year(int n) {
    //condition orders matters
    if (n%400==0) return true;
    if (n%100==0) return false;
    return n%4==0;
}

}  // namespace leap
