#include "perfect_numbers.h"
#include "vector"
#include "algorithm"
#include "stdexcept"

namespace perfect_numbers {
    std::vector<int> allFactors(int n) {
        std::vector<int> results;
        if (n <= 1) return {1};
        for (int p = 1; p * p <= n; p++) {
            if (n % p == 0) {
                results.push_back(p);
                if (p != n / p) //in c++ it is safer version of n=p*p
                    results.push_back(n / p);
            }
        }
        //to capture the last big prime number
        std::sort(results.begin(), results.end());
        return results;
    }


    classification classify(int n) {
        if (n <= 0)
            throw std::domain_error("Number must be positive");
        int aliquotSum = 0;
        std::vector<int> fac = allFactors(n);
        for (std::size_t i = 0; i + 1 < fac.size(); ++i) {
            aliquotSum += fac[i];
        }
        if (aliquotSum == n) return classification::perfect;
        else if (aliquotSum < n) return classification::deficient;
        else return classification::abundant;
    }
} // namespace perfect_numbers
