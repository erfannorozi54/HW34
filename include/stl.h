#ifndef STL_H
#define STL_H
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>


inline void initial_vector_with_3_mutiplies(std::vector<int>& v, size_t size)
{
    int i { 1 };
    v = std::vector<int>(size);
    std::generate(v.begin(), v.end(), [v, &i]() {;return 3*(i++); });
}

inline int count_unique_above(std::vector<int> v, int n)
{
    std::vector<int> temp {};
    int counts {};
    counts = std::count_if(v.begin(), v.end(), [&temp, n](int x) {if((x > n) && std::find(temp.begin(),temp.end(),x) ==temp.end()){
        temp.push_back(x);
        return true;

    }else
        return false; });
    return counts;
}

inline std::string vector_to_string(std::vector<int> v, char separator)
{
    std::reverse(v.begin(), v.end());
    std::string x {};
    x = std::accumulate(v.begin() + 1, v.end(), std::to_string(v[0]),
        [&separator](const std::string& a, int b) {
            return a + separator + std::to_string(b);
        });
    // std::accumulate(v.end(), v.begin(), x);

    return x;
}
#endif // STL_H