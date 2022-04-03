#include <iostream>
#include <cmath>

using std::cout; using std::endl;

const double* aver(const double* arr, size_t size, double& average) {

    for(size_t i = 0; i < size; i++)
        average += arr[i];
    average = average/size;

    size_t index = 0;

    for(size_t i = 1; i < size; i++){
        if(std::abs(arr[i] - average) < std::abs(arr[index] - average)){
            index = i;
        }
    }
    return arr+index; //arr in our function is already a pointer but to get our value of arr[index] we need to add some ints
                        //arr (*arr) will gives us arr[0]   arr+1 will gives us arr[1] etc...
}

int main () {

    double arr[] = {1, 2, -1.5 , 3.25, 5.5, 7.75, -0.25, 5.75};
    size_t size = std::size(arr);
    // or
    // size_t size = sizeof(arr)/sizeof(arr[0]);
    double average = 0;

    const double* p = aver(arr, size, average);

    cout <<  p  << " " << &p << endl;       // p prints out an address of a value of double p, but &p prints out an address of our pointer
    cout << *p << " " << average << endl;   //
}