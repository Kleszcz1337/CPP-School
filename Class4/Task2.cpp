#include <iostream>
#include <cstdio>    // printf
#include <cmath>
#include <vector>

using std::vector;

vector<size_t> smallSum3(const vector<int>& a);

int main () {
    vector<int> a{2, -13, 3, 6, 4, 5, -14, 1, -15};
    auto r = smallSum3(a);

    std::printf("Sum=%d for elements "
                "a[%u]=%d, a[%u]=%d, a[%u]=%d\n",
                a[r[0]]+a[r[1]]+a[r[2]],
                r[0], a[r[0]], r[1], a[r[1]], r[2], a[r[2]]);
}

vector<size_t> smallSum3(const vector<int>& a){
    vector<size_t> r;

    int abs;
    int absPast = std::abs(a[0]+a[1]+a[2]);

    for(size_t i = 1; i < a.size(); i++){
        for(size_t j = 0; j < a.size(); j++){
            if(j != i) {
                for (size_t k = 0; k < a.size(); k++) {
                    if(k != j && k != i) {
                        abs = std::abs(a[i] + a[j] + a[k]);
                        if (abs < absPast){
                            absPast = abs;
                            r.clear();
                            r.push_back(i);
                            r.push_back(j);
                            r.push_back(k);
                        }
                    }
                }
            }
        }
    }
    return r;
}