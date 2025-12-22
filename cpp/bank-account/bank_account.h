#pragma once
#include <mutex>

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
    std::mutex m_mutex;

};  // class Bankaccount

}  // namespace Bankaccount
