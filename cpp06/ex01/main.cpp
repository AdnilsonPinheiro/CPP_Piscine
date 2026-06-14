#include "inc/Data.hpp"
#include "inc/Serializer.hpp"
#include <iostream>

int main()
{
    Data data = {42, "lets go, babe"};
    std::cout << "data addr: " << &data << std::endl;
    uintptr_t serializedPtr = Serializer::serialize(&data);
    std::cout << "serializedPtr: " << serializedPtr << std::endl;
    Data* deserializedPtr = Serializer::deserialize(serializedPtr);
    std::cout << "deserializedPtr: " << deserializedPtr << std::endl;

    if (&data == deserializedPtr)
        std::cout << "\nSUCCESS" << std::endl;
    else
        std::cout << "\nFAILURE =,(\nGet good" << std::endl;
    return 0;
}