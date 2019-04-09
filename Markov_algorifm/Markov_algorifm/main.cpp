/*
    набросок кода без заключительных правил, 
    без учета символов вида \n,
    без шаблонов
    без проверок на бесконечные замены(ограничения по времени)
*/

#include "Markov.h"
#include <iostream>

using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");

    Markov mark;

    mark.setData("Я купил кг Аов в Т М");

    mark.addRule("А","апельсин");
    mark.addRule("кг", "килограмм");
    mark.addRule("М", "магазинчике");
    mark.addRule("Т", "том");
    mark.addRule("магазинчике", "ларьке");
    mark.addRule("в том ларьке", "на том рынке");

    

    while (mark.isTerminated() != true)
    {
        mark.step();
        cout << mark.getData() << endl;
    }

    //mark.run();

    
    /*
    Markov mark;

    mark.setData("101");
    mark.addRule("1","0|");
    mark.addRule("|0", "0||");
    mark.addRule("0", "");

    while (mark.isTerminated() != true)
    {
        mark.step();
        cout << mark.getData() << endl;
    }

    //mark.run();

    */

    cout << "ok" << endl;
    system("Pause");
}