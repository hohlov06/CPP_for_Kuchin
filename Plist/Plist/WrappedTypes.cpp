#include "WrappedTypes.h"

bool operator==(const WrappedType& lhs, const WrappedType& rhs)
{
    bool ret;
    switch (rhs.typeOfValue())
    {
    case E_typeOfValue::DOUBLE:
        ret = compareWithCast(const_cast<WrappedType*>(&lhs),
            dynamic_cast<WrappedDouble*>(const_cast<WrappedType*>(&rhs))->value());
        break;
    case E_typeOfValue::INT:
        ret = compareWithCast(const_cast<WrappedType*>(&lhs),
            static_cast<double>(dynamic_cast<WrappedInt*>(const_cast<WrappedType*>(&rhs))->value()));
        break;
    case E_typeOfValue::COMPLEX:
        ret = compareWithCast(const_cast<WrappedType*>(&lhs),
            dynamic_cast<WrappedComplex*>(const_cast<WrappedType*>(&rhs))->value());
        break;
    default:
        ret = false;
        break;
    }
    return ret;
}


bool operator!=(const WrappedType& lhs, const WrappedType& rhs)
{
    return (!(lhs == rhs));
}