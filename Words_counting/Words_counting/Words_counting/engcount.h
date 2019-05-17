#pragma once
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <locale>

//#include <array>
//constexpr std::array<const char*, 2> encoding_array = { "en_US.UTF8", "ru_RU.UTF8" };


class WordCounter 
{
public:

    //WordCounter() {}

    WordCounter(const char* text_path,
                const char* stop_path,
                const char* output_path /*= "output.txt"*/,
                std::locale locale /*= std::locale("English")*/);

    void read_text(const char* text_path);

    void read_stop(const char* stop_path);

    void write_alphabetical(const char* output_path);

    void write_sorted(const char* output_path);

    void set_locale(std::locale locale);

private:

    void insertion(std::string& word, bool apostrophe_flag);

    void remove_apostrophes();

    inline bool isValid(char sym);

    inline bool isValid_en(char sym);

    bool isValid_ru(char sym);


    //inline bool isPunct(char sym)
    //{
    //    return (m_locale == std::locale("English")) ? isPunct_en(sym) :
    //           (m_locale == std::locale("Russian")) ? isPunct_ru(sym) : throw("invalid_argument");
    //}

    //inline bool isPunct_en(char sym)
    //{
    //    return ((sym == '.') || (sym == ',') || (sym == '!')  || (sym == '?') ||
    //            (sym == 150) || (sym == 151) || (sym == '\"') || (sym == '(') || /*150,151 - тире*/
    //            (sym == ')') || (sym == ':') || (sym == ';')  || (sym == '[') || 
    //            (sym == ']') || (sym == '{') || (sym == '}')                    ); 
    //}

    //inline bool isPunct_ru(char sym)
    //{
    //    return (isPunct_en(sym) || (sym == '\'')); //TODO apostrphe
    //}

private:
    std::map<std::string, int> m_counter;
    std::set<std::string> m_stops;
    std::set<std::string> m_apostrophe_words; 
    std::locale m_locale;
    char m_apostrophe; //TODO зависит от кодировки
};