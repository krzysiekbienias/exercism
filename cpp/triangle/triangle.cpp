#include "triangle.h"

#include <stdexcept>

namespace triangle {

    flavor kind(double a,double b, double c) {
        if (a+b>=c && a+c>=b && b+c>=a and a>0 && b>0 && c>0) {
            if (a==b && b==c) return flavor::equilateral;
            if ((a==b) || (a==c) || (b==c)) return flavor::isosceles;
            return flavor::scalene;
        }
        throw std::domain_error("Cannot build ");
    }

}  // namespace triangle
