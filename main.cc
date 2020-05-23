#include <iostream>
#include <string>
#include <bitset>
#include "ArrayInt.h"
#include "LinkedList.h"

void test(){
    std::string input;
    std::cout << "Geef file name" << std::endl;
    std::cin >> input;
    ArrayInt<uint8_t> test(input);

    std::cout << std::endl << "length is: " << test.length() << std::endl;

    for(int i = 0; i < test.length(); ++i){
        std::cout << test.at(i);
    }
    std::cout << std::endl << std::endl << std::endl;

    test.slice(1, 4);

    
    
    std::cout << std::endl;

    std::cout << "Geef file name" << std::endl;
    std::cin >> input;

    ArrayInt<uint8_t> test2(input);

    std::cout << test.equal(test2);

    std::cout << std::endl;

    test.concat(test2);

    
}

void test2(){
    std::string input;
    std::cout << "Geef file name" << std::endl;
    std::cin >> input;

    LinkedList<uint8_t> test1(input);
    //auto a = test1.front;
    for(int i = 0; i < test1.length(); ++i){
        std::cout << test1.at(i);
    }
    //while(a->next != nullptr){
    //    std::bitset<8> x(a->number);
    //    std::cout << x << '|';
    //    a = a->next;
   // }

    std::cout << std::endl << "Geef file name" << std::endl;

    std::cin >> input;

    LinkedList<uint8_t> test2(input);
    test1.concat(test2);
    



 
    //std::cout << test1.listSize;
}

int main(){
    test();


    return 0;

}   