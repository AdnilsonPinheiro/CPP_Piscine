#include "inc/Data.hpp"
#include "inc/Serializer.hpp"
#include <iostream>
#include <exception>

int main()
{
    Data data = {42, "lets go, babe"};
    std::cout << "data addr: \t\t" << &data << std::endl;
    uintptr_t serializedPtr = Serializer::serialize(&data);
    std::cout << "serializedPtr: \t\t" << serializedPtr << std::endl;
    Data* deserializedPtr = Serializer::deserialize(serializedPtr);
    std::cout << "deserializedPtr: \t" << deserializedPtr << std::endl;

    if (&data == deserializedPtr)
        std::cout << "\nSUCCESS =)" << std::endl;
    else
        std::cout << "\nFAILURE =,(\nGet good" << std::endl;
    return 0;
}