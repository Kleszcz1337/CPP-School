#include <iostream>

unsigned short koduj(int plec, int stan_cyw, int grupa_wiek, int edu, int zam, int region, int odp);
void info(unsigned short kod);

int main(){
    unsigned short value = koduj(0,3,2,3,0,12,6);
    info(value);
}

unsigned short koduj(int plec, int stan_cyw,
                     int grupa_wiek, int edu,
                     int zam, int region,
                     int odp){
    unsigned result = 0;

    result |= plec;
    result <<= 2;
    result |= stan_cyw;
    result <<= 2;
    result |= grupa_wiek;
    result <<= 2;
    result |= edu;
    result <<= 2;
    result |= zam;
    result <<= 4;
    result |= region;
    result <<= 3;
    result |= odp;

    return  result;
}

void info(unsigned short kod){
    int odp = kod & 0b111;
    kod >>= 3;
    int region = kod & 0b1111;
    kod >>= 4;
    int zam = kod & 0b11;
    kod >>= 2;
    int edu = kod & 0b11;
    kod >>= 2;
    int grupa_wiek = kod & 0b11;
    kod >>= 2;
    int stan_cyw = kod & 0b11;
    kod >>= 2;
    int plec = kod & 0b1;

    std::cout << "plec: " << plec << std::endl;
    std::cout << "stan cywilny: " << stan_cyw << std::endl;
    std::cout << "grupa wiekowa: " << grupa_wiek << std::endl;
    std::cout << "wyksztalcenie: " << edu << std::endl;
    std::cout << "miejsce zam.: " << zam << std::endl;
    std::cout << "region: " << region << std::endl;
    std::cout << "odpowiedz: " << odp << std::endl;
}