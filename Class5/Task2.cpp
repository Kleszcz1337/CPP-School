#include <iostream>
#include <vector>

bool sumOfTwo(const std::vector<int>& v,
              int val, int& i, int& j);

int main(){
    std::vector<int> a{ 2, 4, 5, 8, 9, 11, 13, 15 };
    int i, j, val = 21;
    std::cout << sumOfTwo(a,val,i,j) << std::endl;
    std::cout << "i= " << i << " j= " << j;
}

bool sumOfTwo(const std::vector<int>& v,
              int val, int& i, int& j){

    for (i = 0; i < v.size(); ++i) {
        for (j = i+1; j < v.size(); ++j) {
            if((v[i] + v[j]) > val)
                return false;
            if((v[i] + v[j]) == val)
                return true;
        }
    }
    return false;
}