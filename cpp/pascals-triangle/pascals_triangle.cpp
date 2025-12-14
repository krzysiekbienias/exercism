#include "pascals_triangle.h"
#include <vector>

namespace pascals_triangle {
    std::vector<std::vector<int> > generate_rows(int numRows) {
        if (numRows == 0) return {};
        std::vector<std::vector<int> > pt;
        //pierwszy wiersz sklada sie tylko z {{1}}
        pt.push_back({1});
        for (int i = 1; i < numRows; ++i) {
            // potrzebujemy poprzedni wiersz bo to building block dla kolejnego
            //moze byc const bo nie bedziemy go zmieniac tylko jako punkt odniesienia
            const std::vector<int> &prev = pt.back();
            //kotener na nowy wiersz
            std::vector<int> row(i + 1);
            row[0] = 1;
            row[i] = 1;
            for (int j = 1; j < i; ++j) {
                row[j] = prev[j - 1] + prev[j];
            }
            pt.push_back(std::move(row));
        }
        return pt;
    }
} // namespace pascals_triangle
