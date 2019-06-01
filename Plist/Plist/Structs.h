#pragma once

#include <memory>

class WrappedType;
class WrappedDouble;
class WrappedInt;
class WrappedComplex;
struct Node;

using Complex = std::complex<double>;
using S_ptr = std::shared_ptr<WrappedType>;
using Node_ptr = std::shared_ptr<Node>;

enum class E_typeOfValue
{
    ABSTRACT,
    DOUBLE,
    INT,
    COMPLEX //,
    //STRING,
    //...
};






