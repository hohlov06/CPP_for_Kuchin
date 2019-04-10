#include "MarkovString.h"



void Markov<char>::addRule(const std::string& lhs, const std::string& rhs, bool isEnd_)
{
    rules.push_back(Rule<char>{lhs, rhs, isEnd_});
}

void Markov<char>::setData(const std::string& word_)
{
    init = result = word_;
    iteration = 0;
}


void Markov<char>::step()
{
    if (isEnd != true)
    {
        isEndCalc();
        for (const auto& item : rules)
        {
            pos = result.find(item.first);
            if (pos >= 0)
            {
                result.replace(pos, item.first.size(), item.second);
                break;
            }
        }
    }
}

void Markov<char>::run()
{
    while ((isEnd == false) && (iteration < iteration_limit))
    {
        step();
        iteration++;
    }
}



void Markov<char>::isEndCalc()
{
    for (const auto& item : rules)
    {
        pos = result.find(item.first);
        if (pos >= 0)
        {
            if (item.isEnd == true)
                isEnd = true;
            break;
        }
    }
    if (pos < 0)
        isEnd = true;
    if (rules.empty())
        isEnd = true;
}


bool Markov<char>::isTerminated() const
{
    if ((rules.empty()) || (result.empty()))
        return true;
    else
        return isEnd;
}