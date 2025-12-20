#include "protein_translation.h"
#include <vector>
#include <string>
#include <unordered_map>

namespace protein_translation {

    std::vector<std::string> proteins(const std::string& codon) {
        std::vector<std::string> res;
        std::unordered_map<std::string,std::string> um={
            {"AUG","Methionine"},{"UUU","Phenylalanine"},{"UUC","Phenylalanine"},
            {"UUA","Leucine"},{"UUG","Leucine"},{"UCU","Serine"},{"UCC","Serine"},{"UCA","Serine"},
             {"UCA","Serine"},{"UCG","Serine"},{"UAU","Tyrosine"},{"UAC","Tyrosine"},{"UGU","Cysteine"},
            {"UGC","Cysteine"},{"UGG","Tryptophan"},{"UAA","STOP"},{"UAG","STOP"},{"UGA","STOP"}
        };
        if (codon.size()<3) {
            return {};

        }
        for (int i=0;i<=(int)codon.size()-3;i+=3) {
            std::string temp=codon.substr(i,3);
            if (um[temp]!="STOP"){
                res.push_back(um[temp]);
            }
            else break;
        }
        return res;

    }


}  // namespace protein_translation
