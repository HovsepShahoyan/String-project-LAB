#include "string.h"

int main()
{
    char* _arr2 = new char[10];
    std::cin >> _arr2;
    char* _arr1 = new char[20];
    std::cin >> _arr1;
    String obj1(_arr2);
    String obj2(_arr1);
    String obj3(_arr1);
    String obj4(obj1 + obj2);
    std::cout << "obj2" << obj2 << std::endl;
    std::cout << "obj1" <<  obj1 << std::endl;
    std::cout << "obj3" << obj3 << std::endl;
    std::cout << "obj4" << obj4 << std::endl;
    for (int i = 0; i < 90; i++) {
        obj1.push_back('h');
    }
    std::cout << "obj1(push)" << obj1 << std::endl;
    for(int i = 0; i < 90; i++) {
        obj1.pop_back();
    }
    std::cout << "obj1(pop)" << obj1 << std::endl;
    obj3 = obj4;
    std::cout << "obj3" << obj3 << std::endl;
    std::cout << "compare" <<  obj1.compare(obj3) << std::endl;
    std::cout << "size" << obj1.get_size() << std::endl;
    std::cout << "sub_string" << obj1.sub_string(5) << std::endl;
    std::cout << "obj2" << obj2 << "obj1(insert)" << obj1 << std::endl;
    std::cout << "obj2" << obj2 << "obj1(+=)" << obj1 << std::endl;
    std::cout << "==" << obj1.operator==(obj3) << std::endl;
    std::cout << ">=" << obj1.operator>=(obj3) << std::endl; 
    std::cout << "<=" << obj1.operator<=(obj3) << std::endl;
    std::cout << ">" << obj1.operator>(obj3) << std::endl;
    std::cout << "<" << obj1.operator<(obj3) << std::endl;
    obj1 += obj2;
    std::cout << obj1;
    String::Iterator it = obj1.begin();
    for(it; it != obj1.end(); ++it) {
        std::cout << *it << std::endl;
    }
    it = obj1.begin();
    std::cout << obj1.sub_string(it, 7);
    std::cout << obj2.sub_string(4);
    std::cout << obj1.operator>(obj2) << std::endl;
    std::cout << obj1.operator<(obj2) << std::endl;
    std::cout << obj1.operator>=(obj2) << std::endl;
    std::cout << obj1.operator<=(obj2) << std::endl;
    std::cout << *(obj1.find('H')) <<  std::endl;
    std::cout << obj1.compare(obj2);
}