#pragma once

#include <vector>
#include <list>
#include <algorithm>

//#include "MarkovString.h"

template <typename T>
struct Rule
{
    std::list<T> first;
    std::list<T> second;
    bool isEnd;
};

template <typename T>
class Markov;


template <typename T>
class Markov
{
public:

    void addRule(const std::list<T> lhs, const std::list<T> rhs, bool isEnd_);
    void setData(const std::list<T> word_);

    void setIterationLimit(unsigned long int iteration_limit_)
    {
        iteration_limit_ = iteration_limit;
    }

    inline std::list<T> getInit() const & { return init; }
    inline std::list<T> getData() const & { return result; } 
    bool isTerminated() const;

    void run();
    void step();

private:
    std::vector<Rule<T>> rules;
    std::list<T> init;
    std::list<T> result;
    bool isEnd = false;

    //std::list<T>::iterator<T> pos = result.begin();
    //std::list<T>::iterator<T> pos_end = pos;
    unsigned long int iteration = 0;
    unsigned long int iteration_limit = 100000;

private:

    void isEndCalc();
};


template <typename T>
void Markov<T>::addRule(const std::list<T> lhs, const std::list<T> rhs, bool isEnd_)
{
    rules.push_back(Rule<T>{lhs, rhs, isEnd_});
}

template <typename T>
void Markov<T>::setData(const std::list<T> word_)
{
    init = result = word_;
    iteration = 0;
}

template <typename T>
bool Markov<T>::isTerminated() const
{
    if ((rules.empty()) || (result.empty()))
        return true;
    else
        return isEnd;
}

template <typename T>
void Markov<T>::run()
{
    while ((isEnd == false) && (iteration < iteration_limit))
    {
        step();
        iteration++;
    }
}

template <typename T>
void Markov<T>::step()
{
    if (isEnd != true)
    {
        isEndCalc();
        for (const auto& item : rules)
        {   
            if (!item.first.empty())
            {
                auto pos = search(result.begin(), result.end(),
                    item.first.begin(), item.first.end());
                if (pos != result.end())
                {
                    auto pos_end = pos;
                    for (int count = 0; count < item.first.size(); count++)
                        pos_end++;
                    pos = result.erase(pos, pos_end);
                    result.insert(pos, item.second.begin(), item.second.end());
                    break;
                }
            }
        }
    }
}

template <typename T>
void Markov<T>::isEndCalc()
{
    auto pos = result.begin();
    for (const auto& item : rules)
    {
        pos = search(result.begin(), result.end(),
            item.first.begin(), item.first.end());
        if (pos !=result.end())
        {
            if (item.isEnd == true)
                isEnd = true;
            break;
        }
    }
    if (pos == result.end())
        isEnd = true;
    if (rules.empty())
        isEnd = true;
}
