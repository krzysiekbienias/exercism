#include "collatz_conjecture.h"

#include <stdexcept>

namespace collatz_conjecture {

int steps(int x) {
    if (x<=0) {
        throw std::domain_error("DE");
    }
    int count=0;
    if (x==1) return 0;
    while (x>1) {
        if (x%2==0) {
            x/=2;
            count++;
        }
        else {
            x=x*3+1;
            count++;
        }
    }

    return count;
}

}  // namespace collatz_conjecture
