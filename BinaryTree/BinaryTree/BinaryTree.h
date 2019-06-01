#pragma once

#include <iostream>
#include <algorithm>


template <typename K, typename D>
class Tree;

template <typename K, typename D>
class Node
{
    friend class Tree<K, D>;
public:
    Node(): data(new D) {}

    Node(const K key_, const D& data_) : key(key_),
                                         up(nullptr),
                                         left(nullptr),
                                         right(nullptr),
                                         data(new D(data_)) {}

    ~Node() { delete data;}

    inline K GetKey() { return key; }

    inline D* GetData() { return data; }
private:
    K key;
    D* data;
    Node* up;
    Node* left;
    Node* right;
};





template <typename K, typename D>
class Tree
{
public:

    Tree() : root(nullptr) {}

    ~Tree()
    {
        try 		{ destruct(this->root); }
        catch (...) { std::abort(); 		} 
    }

    void destruct(Node<K, D>* node_)
    {
        if (node_->left != nullptr)
            destruct(node_->left);
        if (node_->right != nullptr)
            destruct(node_->right);
        if ((node_->left == nullptr) && (node_->right == nullptr)) 
        {
            if (node_->up->left == node_)
                node_->up->left == nullptr;
            if (node_->up->right == node_)
                node_->up->right == nullptr;
        }
        delete node_;
    }

    void add(K key_, const D& data_)
    {
        if (root == nullptr)
        {
            root = new Node<K, D>;
            root->key = key_;
            *(root->data) = data_;
        }
        else //(root != nullptr)
        {
            add_recursive(root, key_, data_);
        }
    }

    void add_recursive(Node<K, D>* node, K key_, const D& data_)
    {
        if (node->key > key_)
        {
            if (node->left == nullptr)
            {
                node->left = new Node<K, D>(key_, data_);
                node->left->up = node;
            }
            else //(node->left != nullptr)
            {
                add_recursive(node->left, key_, data_);
            }
        }
        else //(node->key <= key_)
        {
            if (node->right == nullptr)
            {
                node->right = new Node<K, D>(key_, data_);
                node->right->up = node;
            }
            else //(node->left != nullptr)
            {
                add_recursive(node->right, key_, data_);
            }
        }
    }

    D* find(K key_)
    {
        return find_recursive(root, key_);
    }

    D* find_recursive(Node<K, D>* node, K key_)
    {
        if (node->key == key_)
            return node->data;
        else if (node->key > key_)
        {
            if (node->left == nullptr)
                return nullptr;
            else
                return find_recursive(node->left, key_);
        }
        else // if (node->key < key_)
        {
            if (node->right == nullptr)
                return nullptr;
            else
                return find_recursive(node->right, key_);
        }
    }

    void print()
    {
        print_recursive(root);
    }

    void print_recursive(Node<K, D>* node)
    {
        if (node != nullptr)
        {
            print_recursive(node->left);
            std::cout << node->key << " ";
            print_recursive(node->right);
        }
    }

    void pretty_print()
    {
        int i = 0;
        while (i <= MaxLayerNumber(root))
        {
            print_layer(root, i);
            std::cout << std::endl;
            i++;
        }
    }

    void print_layer(Node<K, D>* node, int n)
    {
        if (node == nullptr)
        {
            return;
        }
        else
        {
            print_layer(node->left, n - 1); 
            if (n == 0) 
            {
                std::cout << node->key << " "; 
            }
            print_layer(node->right, n - 1);  
        }
    }


    int MaxLayerNumber(Node<K, D>* node)
    {
        int lhs, rhs;
        if (node == nullptr)
            return 0;
        if (node->left == nullptr)
            lhs = -1;
        else
            lhs = MaxLayerNumber(node->left);
        if (node->right == nullptr)
            rhs = -1;
        else
            rhs = MaxLayerNumber(node->right);
        return std::max(lhs, rhs) + 1;
    }

    Node<K, D>* GetRoot()
    {
        return root;
    }
private:
    Node<K, D>* root;
};
