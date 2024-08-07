#pragma once

#include <stdint.h>

struct Data
{
    int first_value;
    int second_value;
};

class Serializer
{
    public:
        static uintptr_t serialize(Data* ptr); // convert ptr to uintptr_t
        static Data* deserialize(uintptr_t raw); // convert raw to a Data pointer
    private:
        Serializer();
        ~Serializer();
        Serializer(const Serializer &toCopy);
        Serializer &operator=(const Serializer &toCopy);
};