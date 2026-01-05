#include "armstrong_numbers.h"
#include <cmath>

namespace armstrong_numbers {

    int nbOfDigits(int n) {
        int numberDigits=0;
        while (n>0) {
            n/=10;
            numberDigits++;
        }
        return numberDigits;
    }

    bool is_armstrong_number(int n) {
        int x=n; //Need copy before we destroy n
        int nb=nbOfDigits(n);
        int res=0;
        while (n>0) {
            int ld=n%10;
            n/=10;
            int temp=std::pow(ld,nb);
            res+=temp;

        }
        return res==x;
    }

}  // namespace armstrong_numbers
