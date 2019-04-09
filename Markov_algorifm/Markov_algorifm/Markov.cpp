#include "Markov.h"


void Markov::addRule(const string& lhs, const string& rhs)
{
    rules.push_back(Rule(lhs,rhs));
}

void Markov::setData(const string& word_)
{
    init = result = word_;
}

bool Markov::isTerminated()
{
    isEndCalc();
    return isEnd; 
}


void Markov::step()
{
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

void Markov::run()
{
    while (isEnd == false)
    {
        step();
        isEndCalc();
    }
}



void Markov::isEndCalc()
{
    for (const auto& item : rules)
    {
        pos = result.find(item.first);
        if (pos >= 0)
            break;
    }
    if (pos < 0)
        isEnd = true;
}