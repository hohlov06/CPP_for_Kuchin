#pragma once

#include <vector>
#include <string>
#include <utility>

using Rule = std::pair<std::string, std::string>;
using std::vector;
using std::string;

class Markov
{
public:

    //Markov() {}

    void addRule(const string& lhs, const string& rhs);
    void setData(const string& word_);

    inline string getInit() const { return init; }
    inline string getData() const { return result; }
    bool isTerminated(); 

    void run();
    void step();

private:
    vector<Rule> rules;
    string init;
    string result;
    bool isEnd = false;

    //string::size_type pos = 0;
    long int pos = 0;

private:

    void isEndCalc();
};