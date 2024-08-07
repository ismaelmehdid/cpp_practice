#include "../include/Serializer.hpp"

#include <iostream>

int main(void)
{
    struct Data data;
    data.first_value = 42;
    data.second_value = 422;

    std::cout << "First Value Before: " << data.first_value << std::endl;
    std::cout << "Second Value Before: " << data.second_value << std::endl;

    uintptr_t serialized = Serializer::serialize(&data);

    std::cout << "data adress value: " << &data << std::endl;
    std::cout << "serialized value: " << serialized << std::endl;
    
    struct Data *deserialized = Serializer::deserialize(serialized);

    std::cout << "First Value After: " << deserialized->first_value << std::endl;
    std::cout << "Second Value After: " << deserialized->second_value << std::endl;

    //NULL Ptr test

    uintptr_t null_ptr_test = Serializer::serialize(0);
    std::cout << null_ptr_test << std::endl;
    struct Data *deserialized_null_ptr_test = Serializer::deserialize(null_ptr_test);
    (void)deserialized_null_ptr_test;
}