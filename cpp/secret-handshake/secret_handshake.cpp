#include "secret_handshake.h"
#include <vector>
#include <string>
#include <bitset>
#include <deque>
#include <iostream>

using namespace std;


namespace secret_handshake {
    vector<string> commands(int x) {
        vector<string> res;
        bitset<5> bin(x);
        std::cout << bin << '\n';
        vector<string> action = {
            "wink", "double blink", "close your eyes", "jump",
            "Reverse the order of the operations in the secret handshake"
        };
        if (x & 16) {
            for (int i = 3; i >= 0; --i) {
                if (x & (1 << i)) res.push_back(action[i]);
            }
        } else {
            for (int i = 0; i < 4; ++i) {
                if (x & (1 << i)) res.push_back(action[i]);
            }
        }
        return res;
    }
} // namespace secret_handshake
