#include <unordered_map>
#include <algorithm>

class Solution {
public:

    // This solution is very bad in computational terms, because sorting takes a long time


    // std::vector<vector<int>> ret;

    // Sorting is slow
    // void sortByValue(unordered_map<int, int> &hm) {
    
    //     vector<pair<int, int>> list(hm.begin(), hm.end());

    //     sort(list.begin(), list.end(), [](const pair<int, int> &o1, 
    //                                     const pair<int, int> &o2) {
    //         return o1.first < o2.first;
    //     });

    //     unordered_map<int, int> temp;
    //     for (auto &aa : list) {
    //         cout<<aa.first<<": "<<aa.second<<endl;
    //         ret.push_back({aa.first, aa.second});
    //     }
    // }



    // vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
    //     unordered_map<int, int> merged_map;

    //     for (auto item1 : items1) {
    //         merged_map[item1[0]] = item1[1];
    //     }
    //     for (auto item2 : items2) {
    //         if (!merged_map.contains(item2[0])) {
    //          merged_map[item2[0]] = item2[1];    
    //         }
    //         else {
    //             merged_map[item2[0]] += item2[1];
    //         }
    //     }
        
    //     // sortByValue(merged_map);

    //     return ret;
    // }

    // To combat sorting which takes a long time executing
    // We will intialize a list based on the constraints where we know max(items.length) < 1001
    // We initialize with 0's and we add onto the index corresponding to the vector's value


    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<vector<vector<int>>> sorted_vector_list;
        sorted_vector_list.resize(1001);

        for (const auto& item1 : items1) {
            sorted_vector_list[item1[0]].push_back({item1[0], item1[1]});
        }

        for (const auto& item2 : items2) {
            if (sorted_vector_list[item2[0]].empty()) {
                sorted_vector_list[item2[0]].push_back({item2[0], item2[1]});
            } else {
                sorted_vector_list[item2[0]][0][1] += item2[1];
            }
        }

        vector<vector<int>> ret;

        for (const auto& v : sorted_vector_list) {
            if (!v.empty()) {
                for (const auto& inner : v) {
                    ret.push_back(inner);
                }
            }
        }
        return ret;
    }
};
