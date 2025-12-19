#include "darts.h"
#include <cmath>
namespace darts {

    int score (float a,float b) {
        float position=std::sqrt(a*a+b*b);
        if (position<=1) return 10;
        if (position<=5 && position>1) return 5;
        if (position<=10 && position>5) return 1;
        return 0;
    }

}  // namespace darts
