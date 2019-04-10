/*
    для специализации шаблона для char нет учета символов вида \n,
    но можно передавать сырые строки вида R"()"

    в случае, например, целых чисел предполагается, что элементы алфавита с общими
    цифрами никак не связаны(например, 1 и 12). 
    Т.е.пусть алфавит (1, 3, 12). (112) - слово-комбинация из 1 и 12. Правило (1 -> 3).
    Применение алгоритма даст конечное слово (312), а не (332).


*/

#include "Markov.h"
#include "MarkovString.h"
#include <iostream>
#include <list>

using namespace std;



template <typename T>
ostream& operator<<(ostream& stre, const std::list<T>& a) {
    for (auto item: a)
        stre << item << " ";
    stre << "\n";
    return stre;
}


int main()
{
    std::list<int> a;
    auto b = a.begin();
    setlocale(LC_ALL, "Russian");

    Markov<char> mark;


    mark.setData("Я купил кг Аов в Т М");

    mark.addRule("А","апельсин", false);
    mark.addRule("кг", "килограмм", false);
    mark.addRule("М", "магазинчике", false);
    mark.addRule("Т", "том", false);
    mark.addRule("магазинчике", "ларьке", true);
    mark.addRule("в том ларьке", "на том рынке", false);

    
    cout << mark.getData() << endl;
    
    while (mark.isTerminated() != true)
    {
        mark.step();
        cout << mark.getData() << endl;
    }

    //mark.run();
    //cout << mark.getData() << endl;
    
    cout << "===================================================" << endl;
    
    Markov<char> mark2;

    mark2.setData("101");
    mark2.addRule("1","0|", false);
    mark2.addRule("|0", "0||", false);
    mark2.addRule("0", "", false);

    cout << mark2.getData() << endl;
    while (mark2.isTerminated() != true)
    {
        mark2.step();
        cout << mark2.getData() << endl;
    }

    //mark2.run();
        //cout << mark2.getData() << endl;
    

    cout << "===================================================" << endl;

    Markov<int> mark3;
    mark3.setData({ 5 });
    mark3.addRule( {5}, {4, 4}, false );
    mark3.addRule( {4}, {3, 3}, false );
    mark3.addRule( {3}, {2, 2}, false );
    mark3.addRule( {2}, {1, 1}, false );

    cout << mark3.getData() << endl;
    while (mark3.isTerminated() != true)
    {
        mark3.step();
        cout << mark3.getData() << endl;
    }

    //mark3.run();
    //cout << mark3.getData() << endl;

    cout << "===================================================" << endl;
    cout << "ok" << endl;
    system("Pause");
}