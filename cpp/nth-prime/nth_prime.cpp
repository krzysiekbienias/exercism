#include "nth_prime.h"
#include <vector>
#include <stdexcept>

namespace nth_prime {
    std::vector<char> sieve(int n) {
        std::vector<char> isPrime(n+1,1);
        //out of bounds protection
        if (n>=0) isPrime[0]=0;
        if (n>=1) isPrime[1]=0;

        for (int p=2;p*p<=n;++p) {
            if (isPrime[p]) {
                for (int multiple =p*p;multiple<=n;multiple+=p) {
                    isPrime[multiple]=0;
                }
            }
        }
        return isPrime;
    }

    int nth(int n) {
        if (n<=0) {
            throw std::domain_error("n must be >=1 becasue it is nth number");
        }

        int limit=std::max(15,15*n);
        while (true) {
            std::vector<char> isPrime=sieve(limit);
            int count =0; //we will increase counter until we get k
            for (int i=2;i<=limit;++i) {
                if (isPrime[i]) {
                    count++;
                    if (count==n) {
                        return i;
                    }
                }
            }
            limit*=2;
        }
    }



}  // namespace nth_prime
