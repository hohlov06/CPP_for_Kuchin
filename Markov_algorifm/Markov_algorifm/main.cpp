/*
    �������� ���� ��� �������������� ������, 
    ��� ����� �������� ���� \n,
    ��� ��������
    ��� �������� �� ����������� ������(����������� �� �������)
*/

#include "Markov.h"
#include <iostream>

using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");

    Markov mark;

    mark.setData("� ����� �� ��� � � �");

    mark.addRule("�","��������");
    mark.addRule("��", "���������");
    mark.addRule("�", "�����������");
    mark.addRule("�", "���");
    mark.addRule("�����������", "������");
    mark.addRule("� ��� ������", "�� ��� �����");

    

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