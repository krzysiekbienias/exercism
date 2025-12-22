#include "bank_account.h"

#include <stdexcept>

namespace Bankaccount {
    bool Bankaccount::open() {
        if (!m_status) {
            m_status = true;
            return true;
        }
        throw std::runtime_error("You cannot open the account that is already open");
    }

    int Bankaccount::balance() {
        if (m_status)
            return m_balance;
        else {
            throw std::runtime_error("You cannot get balance for closed account.");
        }
    }

    bool Bankaccount::deposit(int value) {
        if (value <0)
            throw std::runtime_error("deposit must be positive");
        if (m_status) {
            m_balance += value;
            return true;
        } else throw std::runtime_error("You cannot put deposit for closed account.");
    }

    bool Bankaccount::withdraw(int value) {
        if (value<0)
            throw std::runtime_error("Withdraw must be positive number");
        if (m_status) {
            m_balance -= value;
            if (m_balance>=0)
            return true;
            throw ::std::runtime_error("ERR");

        } else throw std::runtime_error("You cannot withdraw money from closed account.");
        return true;
    }

    bool Bankaccount::close() {
        if (m_status) {
            m_status = false;
            m_balance=0;// reset account balance to zero when we close
            return true;
        }
        throw std::runtime_error("You cannot close account that for closed account.");
    }
}
