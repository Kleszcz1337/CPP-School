#include <iostream>

size_t length(const char* cstr);
bool   isLetter(char c);
char*  reverse(char* cstr);
size_t words(const char* cstr);
size_t words2(const char* cstr);
char*  concat(char* t, const char* s);

int main() {
    using std::cout; using std::endl;
    char s1[] = "Alice in Wonderland";
    cout << "reverse: " << reverse(s1) << endl;
    cout << "length : " << length(s1)  << endl;

    char s2[] = " ... for (int i = 0; i < n; ++i){...} ...";
    cout << "words  : " << words(s2)  << endl;
    cout << "words2 : " << words2(s2) << endl;

    char s3[100] = "Hello";
    cout << "concat : "
         << concat(concat(s3,", world"),"!") << endl;
}

size_t length(const char* cstr){
    int counter = 0;

    while(cstr[counter] != '\0')
        counter++;

    return counter;
}

bool   isLetter(char c){
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

char*  reverse(char* cstr){
    size_t size = length(cstr)-1;

    char tmp;
    for(size_t i = 0; i < size/2; i++){
        tmp = cstr[i];
        cstr[i] = cstr[size-i];
        cstr[size-i] = tmp;
    }
    return cstr;
}

size_t words(const char* cstr){
    size_t size = length(cstr);
    size_t result = 0;
    size_t index = 0;

    while (index < size) {
        if (!isLetter(cstr[index]) && index + 1 < size) {
            index++;
            if (isLetter(cstr[index])) {
                result++;
                while (isLetter(cstr[index]) && index < size) {
                    index++;
                }
            }
        }
        else {
            index++;
        }
    }
    return result;
}

size_t words2(const char* cstr) {
    size_t size = length(cstr);
    size_t result = 0;

    size_t index = 0;
    while (index < size) {
        if (!isLetter(cstr[index]) && index + 1 < size) {
            index++;
            if (isLetter(cstr[index])) {
                size_t counter = 0;
                while (isLetter(cstr[index]) && index < size) {
                    index++;
                    counter++;
                }
                if (counter >= 2) {
                    result++;
                }
            }
        }
        else {
            index++;
        }
    }
    return result;
}

char*  concat(char* t, const char* s){
    size_t sizeT = length(t);
    size_t sizeS = length(s);

    for(size_t i = 0; i < sizeS; i++){
        t[sizeT] = s[i];
        sizeT++;
    }
    t[sizeT+sizeS+1] = '\0';

    return t;
}
