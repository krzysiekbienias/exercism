#include "robot_name.h"
#include <random>
#include <string>
#include <unordered_set>
#include <sstream>
#include <iomanip>

using namespace std;

namespace robot_name {
    robot::robot() { reset(); };

    std::unordered_set<string> robot::names{};

    void robot::reset() {
        static mt19937 rng(std::random_device{}());
        static uniform_int_distribution<int> letter(0, 25);
        static uniform_int_distribution<int> digit3(0, 999);
        while (true) {
            char a = 'A' + letter(rng);
            char b = 'A' + letter(rng);
            int digits = digit3(rng);
            std::ostringstream os;
            os << a << b << std::setw(3) << setfill('0') << digits;
            string newName = os.str();
            m_name = newName;
            if (names.insert(newName).second) {
                return;
            }
        }
    }
} // namespace robot_name
