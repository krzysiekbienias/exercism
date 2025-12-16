#pragma once
#include <string>
#include <unordered_set>

using namespace std;

namespace robot_name {

class robot {
public:
    robot();

    string name() const {
        return m_name;
    }

    void  reset();

private:

    std::string m_name;
    static unordered_set<string> names;
};

}  // namespace robot_name
