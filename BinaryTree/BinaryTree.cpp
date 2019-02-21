//#include "pch.h"
#include <iostream>
#include <algorithm>

#define private public

using namespace std;

template <typename K, typename D>
class Tree;

//template <typename K, typename D>
//class Node_ptr;


template <typename K, typename D>
class Node 
{
    friend class Tree<K, D>;
//    friend class Node_ptr<K, D>;
public:
    Node()
    {
        data = new D;
    }

    Node(const K key_, const D& data_) : key(key_), up(nullptr), left(nullptr), right(nullptr)
    {
        data = new D;
        *data = data_;
    }

    ~Node()
    {
        delete data;
    }

    K GetKey() { return key; }

    D* GetData() {return data;}
private:
    K key;
    D* data;
    Node* up;
    Node* left;
    Node* right;
};


//хотел обернуть в RAII, но запутался в конструкторах

//template <typename K, typename D>
//class Node_ptr {
//    friend class Tree<K, D>;
//public:
//    Node_ptr()
//    {
//        node_ptr = new Node<K, D>;
//        *node_ptr = Node<K, D>{};
//    }
//
//    //Node_ptr(const Node<K, D>& node)
//    //{
//    //    node_ptr = new Node<K, D>;
//    //    (*node_ptr) = node;
//    //}
//    //
//    //Node_ptr(const K key_, const D& data_)
//    //{
//    //    node_ptr = new Node<K, D>;
//    //    node_ptr->key = key_;
//    //    *(node_ptr->data) = data_;
//    //}
//
//    //void operator=(const Node<typename K, typename D>& node_)
//    //{
//    //    *node_ptr = node_;
//    //}
//
//    ~Node_ptr()
//    {
//        delete node_ptr;
//    }
//private:
//    Node<K, D>* node_ptr;
//};



template <typename K, typename D>
class Tree 
{
public:

    Tree(): root(nullptr){}

    ~Tree()
    {
        destruct(this->root);
    }

    void destruct(Node<K, D>* node_)
    {
        if (node_->left != nullptr)
            destruct(node_->left);
        if (node_->right != nullptr)
            destruct(node_->right);
        if ((node_->left == nullptr) && (node_->right == nullptr)){
            if (node_->up->left == node_)
                node_->up->left == nullptr;
            if (node_->up->right == node_)
                node_->up->right == nullptr;
        }
        delete node_;
    }

    void add(K key_, const D& data_)
    {
        if (root == nullptr){
            root = new Node<K, D>;
            root->key = key_;
            *(root->data) = data_;
        }
        else //(root != nullptr)
        {
            add_recursive(root, key_, data_);
        }
    }

    void add_recursive(Node<K, D>* node,K key_, const D& data_)
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

    void print_recursive(Node<K,D>* node)
    {
        if (node != nullptr)
        {
            print_recursive(node->left);
            cout << node->key << " ";
            print_recursive(node->right);
        }
    }

    void pretty_print()
    {
        int i = 0;
        while (i <= MaxLayerNumber(root))
        {
            print_layer(root,i);
            cout << endl;
            i++;
        }
    }

    void print_layer(Node<K,D>* node, int n)
    {
        if (node == nullptr) {
            // Если дерево пустое, то отображать нечего, выходим
            return;
        }
        else {
            print_layer(node->left, n-1);  // С помощью рекурсии посещаем левое поддерево
            if (n== 0) {
                // level будет равен нулю на нужной глубине, так как при каждом рекурсивном вызове значение level уменьшается на один
                cout << node->key << " " ;  // Показываем элемент, если он на нужном нам уровне
            }
            print_layer(node->right, n-1);  // С помощью рекурсии посещаем правое поддерево
        }
    }

    
    int MaxLayerNumber (Node<K,D>* node)
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
        return max(lhs, rhs)+1;
    }

    Node<K, D>* GetRoot()
    {
        return root;
    }
private:
    Node<K, D>* root;
};

int main()
{
    Tree<int, double> tree;
    
    //data = key + 0.5;
    tree.add(10, 10.5);
    tree.add(5, 5.5);
    tree.add(4, 4.5);
    tree.add(12, 12.5);
    tree.add(8, 8.5);
    tree.add(7, 7.5);
    tree.add(9, 9.5);
    tree.add(15, 15.5);

    cout << "tree.print()" << endl;
    tree.print();
    cout << endl << endl;

    cout << "tree.pretty_print()" << endl;
    tree.pretty_print();
    cout << endl;

    cout << "tree.GetRoot()->GetKey()" << endl;
    cout << tree.GetRoot()->GetKey() << endl << endl;

    cout << "*tree.find(7)" << endl;
    cout << *tree.find(7) << endl << endl;
    
    cout << "tree.MaxLayerNumber(tree.GetRoot())" << endl;
    cout << tree.MaxLayerNumber(tree.GetRoot()) << endl << endl;

    //программа обрушивается, т.к. разименование nullptr
    //cout << *tree.find(6) << endl;
}
