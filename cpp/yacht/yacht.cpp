#include "yacht.h"

#include <numeric>
#include <string>
#include <array>

namespace yacht {
    category parseCategory(std::string_view s) {
        if (s == "ones") return category::ones;
        if (s == "twos") return category::twos;
        if (s == "threes") return category::threes;
        if (s == "fours") return category::fours;
        if (s == "fives") return category::fives;
        if (s == "sixes") return category::sixes;
        if (s == "full house") return category::full_house;
        if (s == "four of a kind") return category::four_of_a_kind;
        if (s == "little straight") return category::little_straight;
        if (s == "big straight") return category::big_straight;
        if (s == "choice") return category::choice;
        if (s == "yacht") return category::yacht;
        throw std::invalid_argument("unknown category");
    }

    bool isLittleStraight(const int cnt[7]) {
        for (int v = 1; v <= 5; ++v) if (cnt[v] != 1) return false;
        return cnt[6] == 0;
    }

    bool isBigStraight(const int cnt[7]) {
        for (int v = 2; v <= 6; ++v) if (cnt[v] != 1) return false;
        return cnt[1] == 0;
    }

    int score(const std::array<int, 5> &dice, const std::string &s_cat) {
        category cat = parseCategory(s_cat);
        int cnt[7] = {0};
        for (int d: dice) {
            cnt[d]++;
        }
        auto faceScore = [&](int face)-> int {
            return face * cnt[face];
        };

        auto accumulateFaceValues = [&]()-> int {
            return std::accumulate(dice.begin(), dice.end(), 0);
        };

        switch (cat) {
            case category::ones: return faceScore(1);
            case category::twos: return faceScore(2);
            case category::threes: return faceScore(3);
            case category::fours: return faceScore(4);
            case category::fives: return faceScore(5);
            case category::sixes: return faceScore(6);

            case category::choice: {
                int sum = accumulateFaceValues();
                return sum;
            }

            case category::yacht:
                for (int i = 1; i <= 6; i++) {
                    if (cnt[i] == 5) return 50;
                }
                return 0;
            case category::little_straight: {
                return isLittleStraight(cnt) ? 30 : 0;
            }
            case category::big_straight: {
                return isBigStraight(cnt) ? 30 : 0;
            }
            case category::four_of_a_kind: {
                for (int i = 1; i <= 6; ++i) {
                    if (cnt[i] >= 4) return 4 * i;
                }
                return 0;
            }


            case category::full_house: {
                bool has3 = false;
                bool has2 = false;
                for (int i = 1; i <= 6; i++) {
                    if (cnt[i] == 2) has2 = true;
                    if (cnt[i] == 3) has3 = true;
                }
                return (has3 && has2) ? accumulateFaceValues() : 0;
            }
        }
        return 0;
    }
} // namespace yacht
