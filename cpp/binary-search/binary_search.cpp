#include "binary_search.h"
#include <vector>
#include <stdexcept>

namespace binary_search {
    int find(std::vector<int> data, int val) {
        //assume that data is already sorted.
        int left = 0;
        int right = data.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (data[mid] == val) return mid;
            if (data[mid] > val) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        throw std::domain_error("There is no element we are looking for in the array.");
    }
} // namespace binary_search
