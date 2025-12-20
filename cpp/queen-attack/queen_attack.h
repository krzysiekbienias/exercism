#pragma once
#include <utility>

namespace queen_attack {

class chess_board {
public:
    using position=std::pair<int,int>;
    chess_board(position white,position black);
    //simple getter
    position white() const {return m_white;}
    position black() const  {return m_black;}

    bool can_attack() const;
private:

    position m_white;
    position m_black;

};

}  // namespace queen_attack
