#include <string>
#include <vector>

namespace election {
    // The election result struct is already created for you:

    struct ElectionResult {
        // Name of the candidate
        std::string name{};
        // Number of votes the candidate has
        int votes{};
    };

    int vote_count(ElectionResult &res) {
        return res.votes;
    }

    void increment_vote_count(ElectionResult &res, int extraVotes) {
        res.votes += extraVotes;
    }

    ElectionResult &determine_result(std::vector<ElectionResult> &final_count) {
        int winnerIndex = 0;
        for (int i = 0; i < final_count.size(); ++i) {
            if (final_count[i].votes > final_count[winnerIndex].votes) {
                winnerIndex = i;
            }
        }
        ElectionResult &winner = final_count[winnerIndex];
        // add prefix to winner's name
        winner.name = "President " + winner.name;
        return winner;
    }
} // namespace election
