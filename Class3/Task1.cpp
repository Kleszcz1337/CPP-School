#include <iostream>

void minMaxRep(int a[], size_t size, int& mn, size_t& in, int& mx, size_t& ix);

int main(){

    int a[] = {1,5,8,3,5,2,7,7,6,3,8,2,};
    size_t size = sizeof(a)/sizeof(*a);

    int    mn, mx;
    size_t in, ix;

    minMaxRep(a, size, mn, in, mx, ix);

    std::cout << "Array: [ ";
    for (size_t i = 0; i < size; ++i)
        std::cout << a[i] << " ";
    std::cout << "]\n";
    std::cout << "Min = " << mn << " " << in << " times\n";
    std::cout << "Max = " << mx << " " << ix << " times\n";

    return 0;
}

void minMaxRep(int a[], size_t size, int& mn, size_t& in, int& mx, size_t& ix){
    mn = a[0];
    mx = a[0];
    in = 1;
    ix = 1;

    for(int i=1; i<size; i++){
        if(mn == a[i])
            in++;
        if(mx == a[i])
            ix++;

        if(mn > a[i]){
            mn = a[i];
            in = 1;
        }
        if(mx < a[i]){
            mx = a[i];
            ix = 1;
        }
    }
}