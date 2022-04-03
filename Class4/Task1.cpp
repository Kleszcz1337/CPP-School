#include <iostream>

void merge(const int* a, size_t dima, const int* b, size_t dimb, int* c);
void printArr(const int* a, size_t dima, const char* m);

int main() {
    int a[] = {1,4,4,5,8};
    int b[] = {1,2,2,4,6,6,9};
    constexpr size_t dima = std::size(a);
    constexpr size_t dimb = std::size(b);
    constexpr size_t dimc = dima + dimb;
    int c[dimc];

    merge(a,dima,b,dimb,c);

    printArr(a,dima,"a");
    printArr(b,dimb,"b");
    printArr(c,dimc,"c");
}

void merge(const int* a, size_t dima, const int* b, size_t dimb, int* c){
    size_t dimC = dima+dimb;
    size_t indexA=0, indexB=0;

    for(size_t i = 0; i < dimC; i++){
       if(indexA < dima && indexB < dimb)
           c[i] = a[indexA] < b[indexB] ? a[indexA++] : b[indexB++];
       else if(indexA >= dima)
           c[i] = b[indexB++];
       else
           c[i] = a[indexA];
    }
}

void printArr(const int* a, size_t dima, const char* m) {
    std::cout << m << " [ ";
    for (size_t i = 0; i < dima; ++i)
        std::cout << a[i] << " ";
    std::cout << "]\n";
}