//#pragma once
//#include <utility>
//#include <vector>
//
//#include "SectorContainer.h"
//
//class SimpleVector : public std::vector<sector>
//{
//public:
//
//    SimpleVector() {}
//    //~SimpleVector() {}
//
//    void add(std::initializer_list<LLint> sec)
//    {
//        emplace_back(sector(*sec.begin(), *(std::next(sec.begin()))));
//    }
//
//    auto find(LLint value)
//    {
//        for (auto it = begin(); it != end(); it++)
//        {
//            if ((value >= it->first) && (value <= it->second))
//                return it;
//        }
//        return end();
//    }
//};