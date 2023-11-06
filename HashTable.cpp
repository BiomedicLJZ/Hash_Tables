#include "HashTable.h"
#include <stdexcept>

template<typename KeyType, typename ValueType>
HashTable<KeyType, ValueType>::HashTable(size_t size) : table(size) {}

template<typename KeyType, typename ValueType>
void HashTable<KeyType, ValueType>::insert(const KeyType& key, const ValueType& value) {
    size_t idx = this->hashFunc(key);
    table[idx].push_back(std::make_pair(key, value));
}

template<typename KeyType, typename ValueType>
ValueType HashTable<KeyType, ValueType>::getValueByKey(const KeyType& key) {
    size_t idx = this->hashFunc(key);
    for(auto& pair : table[idx]) {
        if(pair.first == key) {
            return pair.second;
        }
    }
    throw std::runtime_error("Key not found");
}

template<typename KeyType, typename ValueType>
void HashTable<KeyType, ValueType>::remove(const KeyType& key) {
    size_t idx = this->hashFunc(key);
    table[idx].remove_if([&](const std::pair<KeyType, ValueType>& pair) {
        return pair.first == key;
    });
}

template<typename KeyType, typename ValueType>
void HashTable<KeyType, ValueType>::clear() {
    for(auto& bucket : table) {
        bucket.clear();
    }
}

template<typename KeyType, typename ValueType>
size_t HashTable<KeyType, ValueType>::hashFunc(const KeyType& key) {
    unsigned long hash = 5381;
    int length = key.length();
    int c;

    for (int i = 0; i < length; ++i) {
        c = (int)key[i];
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return hash % table.size();
}
