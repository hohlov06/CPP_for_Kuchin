#include "Plist.h"
#include <memory>

void Plist::push_back(S_ptr value_)
{
    auto new_ptr = std::make_shared<Node>(Node(value_));
    if (mBegin == nullptr)
    {
        mBegin = new_ptr;
        mEnd = mBegin;
    }
    else
    {
        mEnd->next_ptr = new_ptr;
        new_ptr->prev_ptr = mEnd;
        mEnd = new_ptr;
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
        auto new_ptr = std::make_shared<Node>(Node(value_));
        mBegin->prev_ptr = new_ptr;
        new_ptr->next_ptr = mBegin;
        mBegin = new_ptr;
    }
}
void Plist::pop_front()
{
    if (mBegin != nullptr)
    {
        auto newBegin = mBegin->next_ptr;
        mBegin->next_ptr = nullptr;
        mBegin->current_ptr = nullptr;
        mBegin = newBegin;
        if (newBegin != nullptr)
            mBegin->prev_ptr = nullptr;
        else
            mEnd = nullptr;
    }
}
void Plist::pop_back()
{
    if (mEnd != nullptr)
    {
        auto newEnd = mEnd->prev_ptr;
        mEnd->current_ptr = nullptr;
        mEnd->prev_ptr = nullptr;
        mEnd = newEnd;
        if (newEnd != nullptr)
            mEnd->next_ptr = nullptr;
        else
            mBegin = nullptr;
    }
}



void Plist::add(S_ptr value_, Node_ptr place_)
{
    auto it = mBegin;
    while ((it != nullptr) && (it != place_))
        it = it->next_ptr;
    if (it == nullptr)
        std::cout << "No such place\n";
    else if (it->next_ptr == nullptr)
        push_back(value_);
    else
    {
        auto new_ptr = std::make_shared<Node>(Node(value_));
        new_ptr->prev_ptr = it;
        new_ptr->next_ptr = it->next_ptr;
        it->next_ptr = new_ptr;
        new_ptr->next_ptr->prev_ptr = new_ptr;
    }
}


bool Plist::has(S_ptr value_)
{
    auto it = mBegin;
    while ((it != nullptr) && (it->current_ptr != value_))
        it = it->next_ptr;
    if (it != nullptr)
        return true;
    else 
        return false;
}

void Plist::drop(S_ptr value_)
{
    auto it = mBegin;
    while ((it != nullptr) && (it->current_ptr != value_))
        it = it->next_ptr;
    if (it == nullptr)
        std::cout << "No such value\n";
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
        it->current_ptr = nullptr;
        it = nullptr;
    }
}

void Plist::drop(Node_ptr place_)
{
    auto it = mBegin;
    while ((it != nullptr) && (it != place_))
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
        it->current_ptr = nullptr;
        it = nullptr;
    }

}


void Plist::print()
{
    auto it = mBegin;
    while (it != nullptr)
    {
        it->current_ptr->print();
        std::cout << " ";
        it = it->next_ptr;
    }
    std::cout << std::endl;
}

void Plist::clean()
{
    while (mBegin != nullptr)
    {
        pop_back();
    }
    //mBegin = nullptr;
    //mEnd = nullptr;
}