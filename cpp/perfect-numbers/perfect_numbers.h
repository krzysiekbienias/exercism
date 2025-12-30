#pragma once
#include<vector>
namespace perfect_numbers {
    enum class classification{
        perfect,
        abundant,
        deficient
    };
    std::vector<int> allFactors(int n);

    classification classify(int n);
}  // namespace perfect_numbers
