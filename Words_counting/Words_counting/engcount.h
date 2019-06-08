#pragma once
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <locale>

//#include <array>

#ifdef GOOGLE_TEST_DEBUG
class TestCase;
#endif // GOOGLE_TEST_DEBUG

namespace WordCount{


    namespace WordConstants{
        //constexpr std::array<const char*, 2> encoding_array = { "en_US.UTF8", "ru_RU.UTF8" };

        const std::locale loc_en = std::locale("English");
        const std::locale loc_ru = std::locale("Russian");
    };


class WordCounter 
{
public:

    #ifdef GOOGLE_TEST_DEBUG
    friend TestCase;
    #endif // GOOGLE_TEST_DEBUG

    //WordCounter() {}

    WordCounter(const char* text_path,
                const char* stop_path,
                const char* output_path /*= "output.txt"*/,
                std::locale locale /*= WordConstants::loc_en*/);

    void read_text(const char* text_path);

    void read_stop(const char* stop_path);

    void write_chronological(const char* output_path);

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
    //    return (m_locale_str == "en") ? isPunct_en(sym) :
    //           (m_locale_str == "ru") ? isPunct_ru(sym) : throw std::invalid_argument("locale" + m_locale_str + "isn't supported");
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
    std::unordered_map<std::string, int> m_counter;
    std::unordered_set<std::string> m_stops;
    std::unordered_set<std::string> m_apostrophe_words;
    std::locale m_locale;
    std::string m_locale_str;
    char m_apostrophe; //TODO зависит от кодировки
};

};