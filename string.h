#ifndef STRING_H
#define STRING_H
#include <iostream>
#include <iterator>
#include <cstring>

class String {
    public: 
    class Iterator {
    public: 
        Iterator(char* ptr);
    public:
        Iterator& operator++();
        Iterator& operator++(int) ;
        Iterator& operator--();
        Iterator& operator--(int);
        char* operator->();
        char& operator*();
        bool operator ==(const Iterator& other);
        bool operator !=(const Iterator& other);
    private:
        char* m_ptr;
    };    
public: 
    String() = default;
    String(char* m_arr);
    String(const String& obj);
    String(String&& obj);
    String& operator=(const String& obj);
    String& operator=(String&& obj);
    ~String();

public: 
    String operator+(String obj);
    String operator+(char ch);
    void operator+=(String obj);
    bool operator==(String obj);
    bool operator<(String obj);
    bool operator>(String obj);
    bool operator>=(String obj);
    bool operator<=(String obj);
    Iterator operator[](int pos);
    String sub_string(Iterator pos, int n);
    String sub_string(int n);
    void insert(int pos, String obj);
    void insert(int pos, char ch);
    void push_back(char ch);
    void pop_back();
    bool empty() const;
    void clear();
    Iterator find(char ch);
    void replace(int pos, String obj);
    int get_size() const;
    void resize(int n);
    bool contains(String obj);
    bool contains(char ch);
    int compare(String obj);
    Iterator end();
    Iterator begin();
    friend std::ostream &operator<<(std::ostream &out, const String &obj)
    {
        for(int i = 0; i < obj._size; i++) {
        out << obj._arr[i];
        }
        std::cout << std::endl;
        return out;
    }
private:
    char* _arr;
    int _size;
    int _cap;
};

#endif //STRING_H

