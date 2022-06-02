#include "string.h"

int main()
{
    char* _arr2 = new char[10];
    std::cin >> _arr2;
    String obj(_arr2);
    String obj2(_arr2);
    for(StringIterator it = obj2.begin(); it != obj2.end(); it++){
        std::cout << *it << std::endl;
    }
}