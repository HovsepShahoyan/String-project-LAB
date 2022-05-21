#include <iostream>
#ifndef string
#define string
class String
{
public:
    String(char *char_Arr);

    void print();

    int Str_length();

    String sub_string(int pos, int n);

    String operator+(String str1);

    bool empty();

    void clear();

    String insert(int pos, String str1);

    void pop_back();

    bool compare(String str1);

    void append(char ch);

    bool operator==(String str1);

    bool operator!=(String str1);

    void operator+=(String str1);

    char operator[](int pos);

    bool operator<(String str1);

    bool operator>(String str1);

    bool operator<=(String str1);

    bool operator>=(String str1);

    int find(char ch);

    friend std::ostream &operator<<(std::ostream &out, const String &str1)
    {
        out << str1.char_arr << '\n';
        return out;
    }
    // ~Str()                        // Destructor called
    // {
    //     std::cout << std::endl ;
    //     std::cout << "Destructor called" << std::endl;
    // }

private: // Our private variables
    char *char_arr;
    int length = 0;
};

String String::insert(int pos, String str1)
{
    int helper = 0;
    int new_length = length + str1.Str_length();
    char *char_arr_copy = new char[new_length];
    for (int i = 0; i < pos; i++)
    {
        char_arr_copy[i] = this->char_arr[i];
    }
    for (int i = pos; i < pos + str1.Str_length(); i++)
    {
        char_arr_copy[i] = str1.char_arr[helper];
        helper++;
    }
    for (int i = pos; i < this->length; i++)
    {
        char_arr_copy[helper + i] = this->char_arr[i];
    }
    String newStr(char_arr_copy);
    return newStr;
}

String::String(char *char_Arr)
{ //  Main constructor
    this->char_arr = char_Arr;
    for (int i = 0; true; i++)
    {
        if (char_Arr[i] != '\0')
        {
            this->length++;
        }
        else
        {
            break;
        }
    }
}

void String::print()
{ // print function
    std::cout << std::endl;
    std::cout << "The string is: " << char_arr;
}

int String::Str_length()
{ // function to return length of string
    return length;
}

String String::sub_string(int pos, int n)
{ // function for substring
    char *sub_String = new char[n];
    int helper = 0;
    for (int i = pos; i < pos + n; i++)
    {
        sub_String[helper] = this->char_arr[i];
        helper++;
    }
    String newStr(sub_String);
    return newStr;
}

String String::operator+(String str1)
{ // Overloading the operator plus
    int helper = 0;
    char *plus = new char[this->Str_length() + str1.Str_length()];
    for (int i = 0; i < this->Str_length(); i++)
    {
        plus[i] = this->char_arr[i];
    }
    for (int i = this->Str_length(); i < this->Str_length() + str1.Str_length(); i++)
    {
        plus[i] = str1.char_arr[helper];
        helper++;
    }
    String newStr(plus);
    return newStr;
}

bool String::empty()
{
    if (char_arr[0] == '\0')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void String::clear()
{
    char *char_arr_copy = new char[1];
    char_arr_copy[0] = '\0';
    this->char_arr = char_arr_copy;
}

void String::pop_back()
{
    char *char_arr_copy = new char[length - 1];
    for (int i = 0; i < length - 1; i++)
    {
        char_arr_copy[i] = char_arr[i];
    }
    this->char_arr = char_arr_copy;
}

bool String::compare(String str1)
{
    int max = 0;
    if (str1.length > this->length)
    {
        max = str1.length;
    }
    else
    {
        max = this->length;
    }
    for (int i = 0; i < max; i++)
    {
        if (str1.char_arr[i] != this->char_arr[i])
        {
            return false;
        }
    }
    return true;
}

void String::append(char ch)
{
    char *char_arr_copy = new char[length + 1];
    char_arr_copy[length] = ch;
    this->char_arr = char_arr_copy;
}

bool String::operator==(String str1)
{
    int max = 0;
    if (str1.length > this->length)
    {
        max = str1.length;
    }
    else
    {
        max = this->length;
    }
    for (int i = 0; i < max; i++)
    {
        if (str1.char_arr[i] != this->char_arr[i])
        {
            return false;
        }
    }
    return true;
}

bool String::operator!=(String str1)
{
    int max = 0;
    if (str1.length > this->length)
    {
        max = str1.length;
    }
    else
    {
        max = this->length;
    }
    for (int i = 0; i < max; i++)
    {
        if (str1.char_arr[i] != this->char_arr[i])
        {
            return true;
        }
    }
    return false;
}

void String::operator+=(String str1)
{
    int helper = 0;
    char *plus = new char[this->Str_length() + str1.Str_length()];
    for (int i = 0; i < this->Str_length(); i++)
    {
        plus[i] = this->char_arr[i];
    }
    for (int i = this->Str_length(); i < this->Str_length() + str1.Str_length(); i++)
    {
        plus[i] = str1.char_arr[helper];
        helper++;
    }
    char_arr = plus;
}

char String::operator[](int pos)
{
    return *(this->char_arr + pos);
}
bool String::operator<(String str1)
{
    for (int i = 0, j = 0; i < this->length && j < str1.length; i++, j++)
    {
        if (this->char_arr[i] < str1.char_arr[i])
        {
            return true;
        }
    }
    return false;
}

bool String::operator>(String str1)
{
    for (int i = 0, j = 0; i < this->length && j < str1.length; i++, j++)
    {
        if (this->char_arr[i] > str1.char_arr[i])
        {
            return true;
        }
    }
    return false;
}

bool String::operator<=(String str1)
{
    for (int i = 0, j = 0; i < this->length && j < str1.length; i++, j++)
    {
        if (this->char_arr[i] <= str1.char_arr[i])
        {
            return true;
        }
    }
    return false;
}

bool String::operator>=(String str1)
{
    for (int i = 0, j = 0; i < this->length && j < str1.length; i++, j++)
    {
        if (this->char_arr[i] >= str1.char_arr[i])
        {
            return true;
        }
    }
    return false;
}

int String::find(char ch)
{
    for (int i = 0; i < length; i++)
    {
        if (char_arr[i] != ch)
        {
            return i;
        }
    }
    return -1;
}

#endif string
