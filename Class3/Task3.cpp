#include <iostream>
#include <cmath>

using std::cout; using std::endl;

void ord3(double& a, double& b, double& c);
void ord3(double* a, double* b, double* c);
void getMinMax(const double &a, const double& b, const double& c, const double*& pMin, const double*& pMax);
void getMinMax(const double *a, const double* b, const double* c, const double** pMin, const double** pMax);
void printOrd(const double* a, const double* b, const double* c);
void printMinMax(const double* pmn, const double* pmx);

int main () {
    double a, b, c;
    const double *pMin, *pMax;

    a = 2; b = 1; c = 3;
    ord3(a,b,c);
    printOrd(&a, &b, &c);

    a = 3; b = 2; c = 1;
    ord3(&a,&b,&c);
    printOrd(&a, &b, &c);

    a = -1; b = -1; c = 1;
    ord3(&a,&b,&c);
    printOrd(&a, &b, &c);

    //--------------------------------------------------

    a = 2; b = 3; c = 1;
    getMinMax(a,b,c,pMin,pMax);
    printMinMax(pMin, pMax);

    a = 3; b = 1; c = 2;
    getMinMax(&a,&b,&c,&pMin,&pMax);
    printMinMax(pMin, pMax);

    a = 3; b = 3; c = -1;
    getMinMax(&a,&b,&c,&pMin,&pMax);
    printMinMax(pMin, pMax);
}

void ord3(double& a, double& b, double& c){
    if(a > b)
        std::swap(a,b);
    if(b > c) {
        std::swap(b, c);
        if(a > b)
            std::swap(a,b);
    }
}
void ord3(double* a, double* b, double* c){
    if(*a > *b)
        std::swap(*a,*b);
    if(*b > *c) {
        std::swap(*b, *c);
        if(*a > *b)
            std::swap(*a,*b);
    }
}


void getMinMax(const double &a, const double& b, const double& c, const double* &pMin, const double* &pMax){
    //min
    if(b > a && c > a)
        pMin = &a;
    else if(b < c)
        pMin = &b;
    else
        pMin = &c;

    //max
    if(b < a && c < a)
        pMax = &a;
    else if(b > c)
        pMax = &b;
    else
        pMax = &c;
}
void getMinMax(const double *a, const double* b, const double* c, const double* *pMin, const double* *pMax){
    //min
    if(*b > *a && *c > *a)
        *pMin = a;
    else if(*b < *c)
        *pMin = b;
    else
        *pMin = c;

    //max
    if(*b < *a && *c < *a)
        *pMax = a;
    else if(*b > *c)
        *pMax = b;
    else
        *pMax = c;
}

void printOrd(const double* a, const double* b, const double* c) {
    using std::cout; using std::endl;
    cout << *a << " " << *b << " " << *c << endl;
}
void printMinMax(const double* pmn, const double* pmx) {
    using std::cout; using std::endl;
    std:: cout << "Min = " << *pmn << "; "
               << "Max = " << *pmx << std::endl;
}