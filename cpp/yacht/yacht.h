#pragma once
#include<string>
#include <unordered_map>
#include <vector>
#include <iostream>
namespace yacht {

    enum class category {
        ones,twos,threes,fours,fives,sixes,full_house,
        four_of_a_kind,little_straight,big_straight,choice,yacht
    };

    category parseCategory(std::string_view s);

    int score(const std::array<int,5>&dice, const std::string& s_cat);


}  // namespace yacht
