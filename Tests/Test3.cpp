#include <iostream>
#include <vector>

using namespace std;

void minMaxRep(int a[], size_t size, int* mn, size_t& in, int* &mx, size_t* *ix);
size_t countMinNumbers(int arr[], size_t size);
size_t countMinNumbers(vector<int> a);
void erase_n_biggest(vector<int> &vec, int n);

int main() {

    int myArray[]{6,6,6,2,3,4,2,7,4,7,2};
    vector<int> vector = {6,6,6,2,3,4,2,7,4,7,2};

    size_t size = sizeof(myArray)/sizeof(*myArray);

    int mn;
    size_t in = 0;

    int *mx;
    size_t valueIx = 0;
    size_t* ix = &valueIx;

    minMaxRep(myArray, size, &mn, in, mx, &ix);

    cout << "Array: [ ";
    for (size_t i = 0; i < size; ++i)
        cout << myArray[i] << " ";
    cout << "]\n";

    //zad1
    cout << "Min = " << mn<<" " << in << " times\n";
    cout << "Max = " << mx << " " << ix << " times\n";

    //zad2
    cout << "Tablicowa = " << countMinNumbers(myArray, size) << endl;
    cout << "Vektorowa = " << countMinNumbers(vector) << endl;

    //zad3
    cout << " przed  = ";
    for(int i = 0; i < vector.size(); i++)
        cout << vector[i] << " ";

    cout << endl;
    erase_n_biggest(vector, 3);

    cout << " po  = ";
    for(int i = 0; i < vector.size(); i++)
        cout << vector[i] << " ";
    return 0;
}

void minMaxRep(int a[], size_t size, int* mn, size_t& in, int* &mx, size_t** ix){

    *mx = a[0];
    **ix = 1;

    *mn = a[0];
    in = 1;

    for(size_t i = 1; i < size; i++){
        if(*mx == a[i]) //max
            *ix += 1;
        if(*mn == a[i]) //min
            in += 1;

        if(*mx < a[i]){  //max
            *mx = a[i];
            **ix = 1;
        }
        if(*mn > a[i]){    //min
            *mn = a[i];
            in = 1;
        }
    }
}

size_t countMinNumbers(int *arr, size_t size){
    size_t counter = 1;
    int past = arr[0];
    for(size_t i = 1; i < size; i++){
        if(past == arr[i])
            counter++;

        if(arr[i] < past){
            past = arr[i];
            counter = 1;
        }
    }
    return counter;
}
size_t countMinNumbers(vector<int> a){
    size_t counter = 1;
    int past = a[0];

    for(size_t i = 1; i < a.size(); i++){
        if(past == a[i])
            counter++;

        if(a[i] < past){
            past = a[i];
            counter = 1;
        }
    }
    return counter;
}

void erase_n_biggest(vector<int> &vec, int n){
    if(vec.size() <= n)
        vec.clear();
    else{
        int past=vec[0];
        int index=0;
        for(size_t i = 0; i < n; i++){
            for(size_t j = 1; j < vec.size(); j++) {
                if (past < vec[i]) {
                    past = vec[i];
                    index = i;
                }
            }
            vec.erase(vec.begin()+index);
        }
    }
}

