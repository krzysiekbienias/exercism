#include "queen_attack.h"

#include <stdexcept>

namespace queen_attack {
    chess_board::chess_board(position white, position black) : m_white(white), m_black(black) {
        if (white.first < 0 or white.second < 0 or white.first > 7 or white.second > 7) {
            throw std::domain_error("White queen beyond the chessboard");
        }

        if (black.first < 0 or black.second < 0 or black.first > 7 or black.second > 7) {
            throw std::domain_error("Black queen beyond the chessboard");
        }

        if (black == white) {
            throw std::domain_error("Queen positions must be distinct");
        }
    };


    bool chess_board::can_attack() const {
        if (m_white.first == m_black.first) return true;
        if (m_white.second == m_black.second) return true;
        int dr = abs(m_white.first - m_black.first);
        int dc = abs(m_white.second - m_black.second);
        return dc == dr;
    }
} // namespace queen_attack
