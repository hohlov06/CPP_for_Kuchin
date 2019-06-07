#include <iostream>
#include <utility>
#include <vector>

#include "SectorContainer.h"
#include "SimpleVector.h"

using namespace std;

int main()
{
    //по умолчанию считаем пару уже упорядоченной, т.е. first <= second
    try
    {
    //SimpleVector vec;

    //vec.add({ 1,2 });
    //vec.add({ 0,2 });
    //vec.add({ 6,7 });
    //auto val = vec.find(3);

    SectorContainer<true> sect; // шаблонный параметр true - кидаются исключения при пересечении отрезков,
                                //                    false(по умолчанию) - слияние пересекающихся в один
    sector a(1, 4);
    sector b(3, 7);
    sect.add(a);
    sect.add(b);
    sect.add(sector(8, 9));
    sect.add({ 13,15 });
    sect.add({{ 0,1 }, { 9,13 }, {16,19}});
    std::vector<sector> vecsec({ {-9,-8}, {-6,1} });
    sect.add(vecsec);

    auto it = sect.find(16);

    sect.print();
    }
    catch (std::exception& e)
    {
        cout << e.what() << endl;
        //std::abort();
    }

    system("pause");

}