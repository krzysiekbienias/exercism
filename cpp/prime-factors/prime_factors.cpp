#include "prime_factors.h"

#include <vector>
namespace prime_factors {

    std::vector<long long> of(long long n){
        if (n<=1) return {};
        std::vector<long long>res;
        while (n%2==0) {
            res.push_back(2);
            n/=2;
        }
        for (int p=3;p*p<=n;p+=2) {
            while (n%p==0) {
                res.push_back(p);
                n/=p;
            }

        }
        if (n>1) res.push_back(n);
        return res;
    }

}  // namespace prime_factors
