#include <iostream>
#include "string.h"
int main()
{
    char *char_Arr = new char[5];
    char *char_Arr1 = new char[5];
    std::cout << "Input first string ";
    std::cin >> char_Arr;
    std::cout << "Input second string ";
    std::cin >> char_Arr1;
    String mystr(char_Arr);
    String mystr1(char_Arr1);
    mystr.print();
    std::cout << std::endl;
    std::cout << "The length is: " << mystr.Str_length();
    String mystr2 = mystr + mystr1;
    mystr2.print();
    std::cout << std::endl;
    std::cout << "The length is: " << mystr2.Str_length();
    mystr2 = mystr2.sub_string(1, 3);
    mystr2.print();
    std::cout << std::endl;
    std::cout << "The length is: " << mystr2.Str_length();
    String str(char_Arr);
    String str1(char_Arr1);
    String str2 = str.insert(2,str1);
    std::cout << std::endl;
    str2.print();
    str2.pop_back();
    str2.print();
    String test1(char_Arr);
    String test2(char_Arr1);
    test1+=test2;
    std::cout << test1;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << test1[5];
}
