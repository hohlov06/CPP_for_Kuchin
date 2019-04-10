#pragma once
/*
    Специализация шаблона для char (реализация через строки)
*/

#include <string>
#include <vector>
#include "Markov.h"


template <>
struct Rule<char>
{
    std::string first;
    std::string second;
    bool isEnd;
};



template <>
class Markov<char>
{
public:

    void addRule(const std::string& lhs, const std::string& rhs, bool isEnd_);
    void setData(const std::string& word_);

    void setIterationLimit(unsigned long int iteration_limit_) 
    {
        iteration_limit_ = iteration_limit;
    }

    inline std::string getInit() const { return init; }
    inline std::string getData() const { return result; }
    bool isTerminated() const;

    void run();
    void step();

private:
    std::vector<Rule<char>> rules;
    std::string init;
    std::string result;
    bool isEnd = false;

    long int pos = 0;
    unsigned long int iteration = 0;
    unsigned long int iteration_limit = 100000;

private:

    void isEndCalc();
};