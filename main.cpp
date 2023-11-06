#include "HashTable.h"
#include <iostream>
#include <string>

int main(){
    HashTable<int, std::string> hashTable(10);
    hashTable.insert(1, "Hello World");
    hashTable.insert(2, "Hello World 2");
    hashTable.insert(3, "Hello World 3");
}
