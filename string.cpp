#include <iostream>

class Str { 

    private:                    // Our private variables 
    char* char_Arr;
    int length = 0;
    
    
    public:
    Str(char* char_Arr){          //  Main constructor 
       this->char_Arr = char_Arr; 
       for ( int i = 0 ; true ; i++){
           if ( char_Arr[i] != '\0'){
               this->length++;
           }
           else {
               break;
           }
       }
    }
    

    void print (){                // print function
        std::cout << std::endl ;
        std::cout << "The string is: " << char_Arr ;
    }
  
  
    int Str_length (){            // function to return length of string
    return length ;
    }
    
    Str sub_string ( int pos , int n ) {       // function for substring 
        char* sub_String = new char[n];
        int helper = 0 ;
        for ( int i = pos ; i < pos + n ; i++ ){
            sub_String[helper] = this->char_Arr[i];
            helper++; 
        }
        Str newStr(sub_String);
        return newStr;
    }


    Str operator+( Str str1 ){     // Overloading the operator plus
        int helper = 0;
        char* plus = new char[this->Str_length() + str1.Str_length()];            
        for ( int i = 0 ; i < this->Str_length() ; i++ ){
            plus[i] = this->char_Arr[i];
        }
        for ( int i = this->Str_length() ; i < this->Str_length() + str1.Str_length() ; i++){
            plus[i] = str1.char_Arr[helper];
            helper++;    
        }
        Str newStr(plus);
        return newStr;
    } 

    // ~Str()                        // Destructor called                           
    // {
    //     std::cout << std::endl ;
    //     std::cout << "Destructor called" << std::endl;
    // }

};

int main(){

char* char_Arr = new char[5];
char* char_Arr1 = new char[5];
std::cout << "Input first string ";
std::cin >> char_Arr;
std::cout << "Input second string ";
std::cin >> char_Arr1;
Str mystr(char_Arr);
Str mystr1(char_Arr1);
mystr.print();
std::cout << std::endl ;
std::cout << "The length is: " << mystr.Str_length();
Str mystr2 = mystr+mystr1;
mystr2.print();
std::cout << std::endl ;
std::cout << "The length is: " << mystr2.Str_length();
mystr2 = mystr2.sub_string(1 , 3);
mystr2.print();
std::cout << std::endl ;
std::cout <<  "The length is: " << mystr2.Str_length();
}
