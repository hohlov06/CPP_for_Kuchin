#pragma once

#include "WrappedTypes.h"

using S_ptr = std::shared_ptr<WrappedType>;

class Plist
{
public:

    Plist() {}
    ~Plist(){ clean();}

    S_ptr begin() { return mBegin; }
    S_ptr end() { return mEnd; }
    void push_back(S_ptr value_);
    void push_front(S_ptr value_);
    void pop_back();
    void pop_front();
    void clean();

    void add(S_ptr value_, S_ptr place_);
    bool has(S_ptr value_);
    void drop(S_ptr place_);
    void print();

private:
    S_ptr mBegin = nullptr;
    S_ptr mEnd = nullptr; //указатель на последний элемент, а не идущий за ним
};
