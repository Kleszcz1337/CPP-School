#include <iostream>
#include <cmath>

//using namespace std;

void zad1(){
    float wzrost,waga;

    std::cout << "Podaj swoj wzrost: ";
    std:: cin >> wzrost;
    std::cout << "Twoj wzrost to: " << wzrost << std::endl;

    std::cout << "Podaj swoja wage: ";
    std:: cin >> waga;
    std::cout << "Twoja waga to: " << waga << std::endl;

    double BMI = waga/(std::pow(wzrost, 2));

    std::cout <<"Twoje bmi to: " << BMI <<std::endl;
}

void zad2(){
    int a,b,c;

    std::cout << "Podaj dane do histogramu: " << std::endl;
    std::cin >> a >> b >> c;

    int maxi = a > b ? (a > c ? a : c) : ( b > c ? b : c);

    for(int i=maxi; i > 0 ; i--){
        if(i <= a)
            std::cout << "*";
        else
            std::cout << " ";
        if(i <= b)
            std::cout << "*";
        else
            std::cout << " ";
        if(i <= c)
            std::cout << "*";
        else
            std::cout << " ";
        std::cout<<std::endl;
    }
}

void zad3(){
    int a=1, b;
    int sumOfDigits = 0;

    int maxSum = 0, maxNum;
    while(a != 0){
        std::cout <<"enter a natural number (0 if done): ";
        std::cin >> a;

        b=a;
        while(b>0){
            sumOfDigits += b%10;
            b/=10;
        }
        if(sumOfDigits > maxSum) {
            maxSum = sumOfDigits;
            maxNum = a;
        }
        sumOfDigits = 0;
    }
    std::cout << "Max sum of digits was " << maxSum << " for " << maxNum << std::endl;
}

void zad4(){
    int couterOfAttemps = 0;
    char userInput;
    int minValue = 0, maxValue = 1000000;
    int guessNum;

    while(userInput != 'y' && couterOfAttemps < 20) {
        guessNum = (minValue + maxValue)/2;

        std::cout << "My guess is :" << guessNum << std::endl;
        std::cout << "Am I right? | b - bigger | s - smaller | y - yes |" << std::endl;
        std::cin >> userInput;

        if(userInput == 'b')
            minValue = guessNum;
        else
            maxValue = guessNum;
        guessNum = (maxValue + minValue) / 2;
        couterOfAttemps++;
    }
    if(couterOfAttemps > 20)
        std::cout << "I lose :/" << std::endl;
    else
        std::cout << "I won :)" << std::endl;
}

int main() {
    //std:: to przestrzen nazw
    //zad1();
    //zad2();
    //zad3();
    zad4();

    return 0;
}
