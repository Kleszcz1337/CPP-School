#include <iostream>
#include <vector>
#include <cmath>

bool isPrime(int n);
bool allDiff(const int arr[], size_t sz);
bool allDiff(const std::vector<int>& vec);
int numDiff(const int arr[], size_t sz);
int numDiff(const std::vector<int>& vec);
int fillWithPrimes(int arr[], size_t sz);
int fillWithPrimes(std::vector<int>& vec);
int fillGaps(int arr[], size_t sz);
int fillGaps(std::vector<int>& vec);
size_t blockRem(int arr[], size_t sz,
                size_t from, size_t to);
size_t blockRem(std::vector<int>& vec,
                size_t from, size_t to);
int findMin(const int *arr, size_t sz);

int main() {
    using std::cout; using std::vector;

    int a[]{3, 2, 3, 2, 5};
    size_t sza = sizeof(a)/sizeof(*a);
    vector<int> b(a, a+sza);
    cout << "allDiff: " << std::boolalpha
         << "a - " << allDiff(a, sza) << ", "
         << "b - " << allDiff(b) << '\n';
    cout << "numDiff: "
         << "a - " << numDiff(a, sza) << ", "
         << "b - " << numDiff(b) << '\n';

    int c[15];
    size_t szc = sizeof(c)/sizeof(*c);
    vector<int> d(szc,0);
    auto lastc = fillWithPrimes(c, szc);
    cout << "Primes: ";
    for (auto x : c) cout << x << " ";
    cout << "\n  Last: " << lastc << "\n";
    auto lastd = fillWithPrimes(d);
    cout << "Primes: ";
    for (auto x : d) cout << x << " ";
    cout << "\n  Last: " << lastd << "\n";

    int e[]{-3, 3, 5, -2, 8, 5, 8, -2};
    size_t sze = sizeof(e)/sizeof(*e);
    vector<int> f(e, e+sze);
    cout << "Filling gaps: ";
    for (auto x : e) cout << x << " ";
    auto laste = fillGaps(e, sze);
    cout << "\n     becomes: ";
    for (auto x : e) cout << x << " ";
    cout << "\n   max value: " << laste << "\n";
    cout << "Filling gaps: ";
    for (auto x : f) cout << x << " ";
    auto lastf = fillGaps(f);
    cout << "\n     becomes: ";
    for (auto x : f) cout << x << " ";
    cout << "\n   max value: " << lastf << "\n";

    int g[]{1, 2, 3, 4, 5, 6, 7};
    size_t szg = sizeof(g)/sizeof(*g);
    vector<int> h(g, g+szg);
    cout << "Original arr: ";
    for (auto x : g) cout << x << " ";
    auto newDimg = blockRem(g, szg, 2, 5);
    cout << "\nAfter 'removing': ";
    for (size_t i = 0; i < newDimg; ++i)
        cout << g[i] << " ";
    cout << "\n";
    cout << "Original vec: ";
    for (auto x : h) cout << x << " ";
    auto newDimh = blockRem(h, 2, 5);
    cout << "\nAfter   removing: ";
    // vector has been resized by the function
    for (auto x : h) cout << x << " ";
    cout << "\n";
}

bool isPrime(int n){
    if (n <= 1)
        return false;

    double nSqrt = std::sqrt(n);
    for (int i = 2; i <= nSqrt; i++)
        if (n % i == 0)
            return false;

    return true;
}

bool allDiff(const int arr[], size_t sz){
    for (int i = 0; i < sz; ++i) {
        for (int j = i; j < sz; ++j) {
            if(arr[i] == arr[j])
                return false;
        }
    }
    return true;
}

bool allDiff(const std::vector<int> &vec) {
    return allDiff(vec.data(),vec.size());
}

int numDiff(const int *arr, size_t sz) {
    int counter = 0;
    for (int i = 0; i < sz; ++i) {
        bool firstOccurrence = true;
        for (int j = i-1; j >= 0 && firstOccurrence ; --j) {
            if(arr[i] == arr[j])
                firstOccurrence = false;
        }
        if(firstOccurrence)
            counter++;
    }
    return counter;
}

int numDiff(const std::vector<int> &vec) {
    return numDiff(vec.data(),vec.size());
}

int fillWithPrimes(int *arr, size_t sz) {
    int lastPrime = 1;
    for (int i = 0; i < sz; ++i) {
        int value = lastPrime+1;
        while (!isPrime(value)){
            value++;
        }
        arr[i] = value;
        lastPrime = value;
    }
    return lastPrime;
}

int fillWithPrimes(std::vector<int> &vec) {
    return fillWithPrimes(vec.data(), vec.size());
}

int findMin(const int *arr, size_t sz) {
    int result = arr[0];
    for (int i = 0; i < sz; ++i) {
        if(result > arr[0])
            result = arr[0];
    }
    return result;
}

int findValueToChange(int* arr, size_t sz, int currentMin){
    bool valToChangeInit = false;
    int valToChange = 0;
    for (int i = 0; i < sz; ++i) {
        if(currentMin <= arr[i]) {
            if (!valToChangeInit) {
                valToChangeInit = true;
                valToChange = arr[i];
            }
            if (std::abs(currentMin) - std::abs(arr[i]) > std::abs(currentMin) - std::abs(valToChange))
                valToChange = arr[i];
        }
    }
    return valToChange;
}


int fillGaps(int* arr, size_t sz){
    int min = findMin(arr,sz);
    int valNumDiff = numDiff(arr,sz);
    for (int i = 0; i < valNumDiff-1; ++i) {
        int numToChange = findValueToChange(arr,sz,++min);
        for (int j = 0; j < sz; ++j) {
            if(arr[j] == numToChange)
                arr[j] = min;
        }
    }
    return min;
}

int fillGaps(std::vector<int> &vec) {
    return fillGaps(vec.data(),vec.size());
}

size_t blockRem(int *arr, size_t sz, size_t from, size_t to) {
    memcpy(arr+from,arr+to,sizeof arr * (to - from));
    return sz - (to - from);
}

size_t blockRem(std::vector<int> &vec, size_t from, size_t to) {
    size_t result = blockRem(vec.data(),vec.size(),from,to);
    //vec.erase(vec.begin()+to-1,vec.end());
    vec.resize(result);
    return result;
}
