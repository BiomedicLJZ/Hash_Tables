//
// Created by Lordleojz on 11/2/2023.
//

#ifndef HASH_TABLES_HASHTABLE_H
#define HASH_TABLES_HASHTABLE_H
#include <vector>
#include <list>
#include <utility>

template<typename KeyType, typename ValueType>
class HashTable {
public:
    explicit HashTable(size_t size);

    void insert(const KeyType& key, const ValueType& value);

    ValueType getValueByKey(const KeyType& key);

    void remove(const KeyType& key);

    void clear();


private:
    size_t hashFunc(const KeyType& key);

    std::vector<std::list<std::pair<KeyType, ValueType>>> table;
};

#endif//HASH_TABLES_HASHTABLE_H
