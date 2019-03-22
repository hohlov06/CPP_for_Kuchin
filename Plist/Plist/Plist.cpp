#include "Plist.h"

void Plist::push_back(S_ptr value_)
{
    if (mBegin == nullptr)
    {
        mBegin = value_;
        mEnd = mBegin;
    }
    else
    {
        mEnd->next_ptr = value_;
        S_ptr newEnd(value_);
        newEnd->prev_ptr = mEnd;
        mEnd = newEnd;
    }
}

void Plist::push_front(S_ptr value_)
{
    if (mBegin == nullptr)
    {
        push_back(value_);
    }
    else
    {
        mBegin->prev_ptr = value_;
        S_ptr newBegin(value_);
        newBegin->next_ptr = mBegin;
        mBegin = newBegin;
    }
}
void Plist::pop_front()
{
    if (mBegin != nullptr)
    {
        S_ptr newBegin(mBegin->next_ptr);
        mBegin->next_ptr = nullptr; 
        mBegin = newBegin;
    }
}
void Plist::pop_back()
{
    if (mEnd != nullptr)
    {
        S_ptr newEnd(mEnd->prev_ptr);
        mEnd->prev_ptr = nullptr; 
        mEnd = newEnd;
    }
}



void Plist::add(S_ptr value_, S_ptr place_)
{
    S_ptr it = mBegin;
    while ((it != nullptr) && (it != place_))
        it = it->next_ptr;
    if (it == nullptr)
        std::cout << "No such place/n";
    else if (it->next_ptr == nullptr)
        push_back(value_);
    else
    {
        S_ptr newNext(value_);
        newNext->prev_ptr = it;
        newNext->next_ptr = it->next_ptr;
        it->next_ptr = newNext;
        newNext->next_ptr->prev_ptr = newNext;
    }
}


bool Plist::has(S_ptr value_)
{
    S_ptr it = mBegin;
    while ((it != nullptr) && (it != value_))
        it = it->next_ptr;
    if (it != nullptr)
        return true;
    else return false;
}

void Plist::drop(S_ptr value_)
{
    S_ptr it = mBegin;
    while ((it != nullptr) && (it != value_))
        it = it->next_ptr;
    if (it == nullptr)
        std::cout << "No such place\n";
    else if (it->next_ptr == nullptr)
        pop_back();
    else if (it->prev_ptr == nullptr)
        pop_front();
    else
    {
        it->prev_ptr->next_ptr = it->next_ptr;
        it->next_ptr->prev_ptr = it->prev_ptr;
        it->next_ptr = nullptr;
        it->prev_ptr = nullptr;
        it = nullptr;
    }
}
void Plist::print()
{
    S_ptr it = mBegin;
    while (it != nullptr)
    {
        std::cout << (*it) << " ";
        it = it->next_ptr;
    }
    std::cout << std::endl;
}

void Plist::clean()
{
    S_ptr it = mBegin;
    while (it != nullptr)
    {
        S_ptr newNext = it->next_ptr;
        it->prev_ptr = nullptr;
        it->next_ptr = nullptr;
        it = newNext;
    }
}