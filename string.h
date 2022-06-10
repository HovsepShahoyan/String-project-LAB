#ifndef STRING_H
#define STRING_H
#include <cstring>
#include <iostream>
#include <iterator>

class String {
public:
   class Iterator {
   public:
      Iterator(char* ptr);

   public:
      Iterator& operator++();
      Iterator operator++(int);
      Iterator& operator--();
      Iterator operator--(int);
      char* operator->();
      char& operator*();
      bool operator==(const Iterator& other);
      bool operator!=(const Iterator& other);

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
   friend String operator+(char ch, String& obj) {
       String tmp;
       tmp._arr = new char[obj._size + 1];
       tmp._size = obj._size + 1;
       tmp._cap = tmp._cap + 1;
       tmp._arr[0] = ch;
       for(int i = 1; i < tmp._size; i++) {
 	      tmp._arr[i] = obj._arr[i - 1];
       }
       return tmp;
   }
   void operator+=(String obj);
   bool operator==(String obj);
   bool operator<(String obj);
   bool operator>(String obj);
   bool operator>=(String obj);
   bool operator<=(String obj);
   char& operator[](int pos) const;
   Iterator at(int pos) const;
   String sub_string(Iterator pos, int n);
   String sub_string(int n);
   String& insert(Iterator pos, String& obj);
   String& insert(Iterator pos, char ch);
   Iterator insert(int pos, String& obj);
   void push_back(char ch);
   void pop_back();
   bool empty() const;
   void clear();
   void helper();
   Iterator find(char ch) const;
   String replace(int pos, String& obj);
   String replace(Iterator first, Iterator last, String& obj);
   int get_size() const;
   void resize(int n);
   bool contains(String obj) const;
   bool contains(char ch) const;
   int compare(String obj);
   Iterator end();
   Iterator begin();
   friend std::ostream& operator<<(std::ostream& out, const String& obj) {
      for (int i = 0; i < obj._size; i++) {
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

#endif  // STRING_H
