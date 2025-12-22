#pragma once

namespace Bankaccount {
class Bankaccount {
public:
    bool open();
    bool close();
    bool withdraw(int value);
    bool deposit(int value);
    int balance();
private:
    bool m_status=false;
    int m_balance=0;

};  // class Bankaccount

}  // namespace Bankaccount
