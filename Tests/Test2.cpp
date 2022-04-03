#include <iostream>

using namespace std;
/*
 Napisz funkcję

void minMaxRep(int a[], size_t size, int** mn, size_t*& in, int& mx, size_t* ix);

która pobiera tablicę intów a, jej wymiar size oraz, cztery zmienne,
 do których wpisany ma być wynik działania funkcji: mn, in, mx i ix.
Funkcja znajduje wartości najmniejszego i największego elementu tablicy
 i wpisuje je do zmiennych mn i mx, a do in i ix wpisuje,
 odpowiednio, liczbę wystąpień tej najmniejszej i największej wartości w całej tablicy.


Przedstaw wywołanie funkcji na tablicy int a[]{2,3,4,2,7,4,7,2};
 */

void minMaxRep(int a[], size_t size, int* *mn, size_t* &in, int& mx, size_t* ix);

int main() {

    int a[]{2,3,4,2,7,4,7,2};
    size_t size = sizeof(a)/sizeof(*a);


    int valueMn = 0;
    int* mn = &valueMn;

    size_t valueIn = 0;
    size_t* in = &valueIn;

    int mx;
    size_t ix = 0;

    minMaxRep(a, size, &mn, in, mx, &ix);

    cout << "Array: [ ";
    for (size_t i = 0; i < size; ++i)
        cout << a[i] << " ";
    cout << "]\n";

    cout << "Min = " << *mn<<" " << *in << " times\n";
    cout << "Max = " << mx << " " << ix << " times\n";

    return 0;
}

void minMaxRep(int a[], size_t size, int* *mn, size_t* &in, int& mx, size_t* ix){

    mx = a[0];
    *ix = 1;

    *mn = &a[0];
    *in = 1;

    for(size_t i = 1; i < size; i++){
        if(mx == a[i]) //max
            *ix += 1;
        if(**mn == a[i]) //min
            *in +=1;

        if(mx < a[i]){  //max
            mx = a[i];
            *ix = 1;
        }
        if(**mn > a[i]){    //min
            *mn = &a[i];
            *in = 1;
        }
    }
}