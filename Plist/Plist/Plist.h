#pragma once

#include "WrappedTypes.h"

struct Node;
using S_ptr = std::shared_ptr<WrappedType>;
using Node_ptr = std::shared_ptr<Node>;

struct Node
{
    Node() : current_ptr(nullptr), prev_ptr(nullptr), next_ptr(nullptr) {}
    Node(S_ptr current_) : current_ptr(current_), prev_ptr(nullptr), next_ptr(nullptr) {}
    Node(S_ptr current_,
         Node_ptr prev_,
         Node_ptr next_) : current_ptr(current_),
                           prev_ptr(prev_),
                           next_ptr(next_) {}

    S_ptr current_ptr;
    Node_ptr prev_ptr;
    Node_ptr next_ptr;
};

class Plist
{
public:

    Plist() {}
    ~Plist() { clean(); }

    Node_ptr begin() { return mBegin; }
    Node_ptr end() { return mEnd; }
    void push_back(S_ptr value_);
    void push_front(S_ptr value_);
    void pop_back();
    void pop_front();
    void clean();

    void add(S_ptr value_, Node_ptr place_);
    bool has(S_ptr value_);
    void drop(S_ptr value_);
    void drop(Node_ptr place_);
    void print();

private:
    Node_ptr mBegin;
    Node_ptr mEnd; //указатель на последний элемент, а не идущий за ним
};
