#include <iostream>
#include "string.h"


int main() {
char* _arr2 = new char[10];
std::cin >> _arr2;
String str2(_arr2);
str2.push_back('s');
std::cout << str2;
}