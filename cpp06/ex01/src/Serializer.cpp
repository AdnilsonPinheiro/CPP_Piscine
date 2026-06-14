#include "../inc/Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
    if (!ptr)
        return 0;
    uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
    return raw;
}
Data*   Serializer::deserialize(uintptr_t raw)
{
    Data *ptr = reinterpret_cast<Data*>(raw);
    return ptr;
}