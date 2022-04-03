#include <iostream>
#include <cmath>

#define GETMAX; //zostalo zadeklarowane makro getmax
#define GETMIN;

void zad1(){
    int a,b,c;
    std::cout<<"Enter 3 number, click ENTER to send number: ";
    std::cin >> a >> b >> c;

#ifdef GETMAX   //jezeli makro getmax jest zddefiniowane to kod sie wykona
    if (a > b && a > c) {
        std::cout << a << std::endl;
    }
    else if (b > a && b > c) {
        std::cout << b << std::endl;
    }
    else{
        std::cout << c << std::endl;
    }
#endif

#ifdef GETMIN
    if (a < b && a < c) {
        std::cout << a << std::endl;
    }
    else if (b < a && b < c) {
        std::cout << b << std::endl;
    }
    else{
        std::cout << c << std::endl;
    }
#endif
}

void zad2() {
    //ax^2 + bx +c = 0
    float a, b, c;
    std::cout << "Podaj wspolczyniki a,b,c rownania" << std::endl;
    std::cin >> a >> b >> c;
    double delta = b * b - 4 * a * c;

    if (delta > 0) {
        double x1 = (-b - sqrt(delta)) / 2 * a;
        double x2 = (-b + sqrt(delta)) / 2 * a;
        std::cout << "Miejsca zerowe to: x1 = " << x1 << " x2 = " << x2 << std::endl;
    } else if (delta == 0) {
        double x = (-b - sqrt(delta) / 2 * a);
        std::cout << "Miejsce zerowe to: x = " << x << std::endl;
    } else
        std::cout << "Delta ujemna, brak miejsc zerowych" << std::endl;
}

void zad3(){
    int userInput;
    int pastUserInput;
    int couter=1;
    int maxCouter=0;
    int maxNum;

    std::cout << "Wpisuj cyfry: ";
    std::cin >> userInput;
    pastUserInput = userInput;

    while(userInput != 0){
        std::cout << "Wpisuj cyfry: ";
        std::cin >> userInput;
        if(userInput == pastUserInput){
            couter++;
        }
        else {
            if(couter > maxCouter){
                maxCouter = couter;
                maxNum = pastUserInput;
            }
            pastUserInput = userInput;
            couter = 1;
        }
    }
    std::cout << "Ilosc wystapien: " << maxCouter << " Liczba: " << maxNum;
}

void zad4(){
    int couterMax = 1;
    int couterMin = 1;
    int userInput;
    int minNum;
    int maxNum;

    do{
        std::cout << "Podaj kolejna liczbe ciagu: ";
        std::cin >> userInput;

        if(userInput == maxNum)
            couterMax++;
        else if(userInput > maxNum && userInput != 0){
            maxNum = userInput;
            couterMax = 1;
        }

        if(userInput == minNum)
            couterMin++;
        else if(userInput < minNum && userInput != 0){
            minNum = userInput;
            couterMin = 1;
        }
    }while(userInput != 0);

    if(userInput != 0) {
        std::cout << "Najwieksza liczba z ciagu to: " << maxNum << " wystapila: " << couterMax << " razy." << std::endl;
        std::cout << "Najmiejsza liczba z ciagu to: " << minNum << " wystapila: " << couterMin << " razy." << std::endl;
    }
    else
        std::cout << "Zakonczyles program bez podania cyfr, najmniesza i najwieszka to: 0";
}

int gcdRec(int a, int b){
    if(a%b == 0)
        return b;
    else
        return gcdRec(b, a%b);
}

int sumDigits(int n){
    if(n/10 == 0)
        return n;
    else
        return n%10 + sumDigits(n/10);
}

int numDigits(int n){
    if(n/10 == 0)
        return 1;
    else
        return 1 + numDigits(n/10);
}

void printOddEven(int n) {
    if (n == 2)
        std::cout << 2 << " ";
    else if (n == 1)
        std::cout << 1 << " ";
    else {
        printOddEven(n - 2);
        std::cout << n << " ";
    }
}

void hailstone(int n){
    if(n%2 == 0){
        std::cout << n << " ";
        hailstone(n/2);
    }
    else {
        std::cout << n << " ";
        hailstone(3 * n + 1);
    }
}

void zad5(){
    /*
    std::cout << "gcdRec: " << (gcdRec(10,4)) << std::endl;
    std::cout << "sumDigits: " << (sumDigits(1623)) << std::endl;
    std::cout << "numDigits: " << (numDigits(1623111)) << std::endl;
    std::cout << "printOddEven: "; (printOddEven(5)); std::cout << std::endl;
    std::cout << "hailstone(13): ";
    hailstone(13);
     */

    std::cout << "gcdRec(12, 42) = " <<gcdRec(12, 42) << std::endl
              << "gcdRec(12, 25) = " <<gcdRec(12, 25) << std::endl;
    std::cout << "sumDigits(123) = " <<sumDigits(123) << std::endl
              << "sumDigits(971) = " <<sumDigits(971) << std::endl;
    std::cout << "numDigits(12345) = " <<numDigits(12345) << std::endl
              << "numDigits(971) = " <<numDigits(971) << std::endl;
    std::cout << "printOddEven(15): ";
    printOddEven(15);
    std::cout << std::endl;
    std::cout << "printOddEven(14): ";
    printOddEven(14);
    std::cout << std::endl;
    std::cout << "hailstone(13): ";
    hailstone(13);
    std::cout << std::endl;
}

int main() {
#ifndef GETMAX  //sprawdza czy makro zostalo zdefiniowane
    #ifndef GETMIN
            #error define GETMAX or GETMIN //jak bedzie error to wyswietli to nam komunikat
        #endif //konczy ifa
#endif

    //zad1();
    //zad2();
    //zad3();
    //zad4();
    //zad5();

    return 0;
}
