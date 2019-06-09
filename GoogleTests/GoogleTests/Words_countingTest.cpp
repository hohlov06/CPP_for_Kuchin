#include "pch.h"

// Для запуска этого файла раскомментировать , если закомментировано
// Закомментировать во всех остальных cpp всё, что ниже #include "pch.h"
// либо исключить из проекта все остальные cpp

#define GOOGLE_TEST_DEBUG
#include "../../Words_counting/Words_counting/engcount.h"

using namespace std;
using namespace WordCount;


const char* text_path_en = "..\\..\\Words_counting\\Words_counting\\texts\\en_text.txt";
const char* stop_path_en = "..\\..\\Words_counting\\Words_counting\\texts\\en_stop.txt";
const char* output_path_en = "..\\..\\Words_counting\\Words_counting\\texts\\en_output.txt";
const char* text_path_ru = "..\\..\\Words_counting\\Words_counting\\texts\\ru_text.txt";
const char* stop_path_ru = "..\\..\\Words_counting\\Words_counting\\texts\\ru_stop.txt";
const char* output_path_ru = "..\\..\\Words_counting\\Words_counting\\texts\\ru_output.txt";


class TestCase
{
public:
    std::unordered_map<std::string, int>& counter;
    std::unordered_set<std::string>& stops;
    std::unordered_map<std::string, int>&  stemmed;
    TestCase(WordCounter& count_) : counter(count_.m_counter), stops(count_.m_stops), stemmed(count_.m_stemmed) {}
};

TEST(English, Words)
{
    WordCounter count(text_path_en, stop_path_en, output_path_en, "english");
    TestCase qwe(count);
    EXPECT_EQ(qwe.counter.at("amy"), 24);
    EXPECT_EQ(qwe.counter.at("tara"), 21);
    EXPECT_EQ(qwe.counter.at("and"), 17);
    EXPECT_EQ(qwe.counter.at("looked"), 6);
    EXPECT_EQ(qwe.counter.at("kamal"), 19);
    EXPECT_EQ(qwe.counter.at("school"), 4);
    EXPECT_EQ(qwe.counter.at("zombies"), 3);
    EXPECT_EQ(qwe.counter.at("now"), 4);
    EXPECT_EQ(qwe.counter.at("dad"), 4);
    EXPECT_EQ(qwe.counter.at("arrived"), 3);
    EXPECT_EQ(qwe.counter.at("art"), 3);
    EXPECT_EQ(qwe.counter.at("dancing"),3 );
}

TEST(English, Base)
{
    WordCounter count(text_path_en, stop_path_en, output_path_en, "english");
    //count.write("..\\..\\Words_counting\\Words_counting\\texts\\stem_test.txt", "-s-f");
    TestCase qwe(count);
    EXPECT_EQ(qwe.stemmed.at("ami"), 24);
    EXPECT_EQ(qwe.stemmed.at("tara"), 21);
    EXPECT_EQ(qwe.stemmed.at("and"), 17);
    EXPECT_EQ(qwe.stemmed.at("look"), 10);
    EXPECT_EQ(qwe.stemmed.at("kamal"), 19);
    EXPECT_EQ(qwe.stemmed.at("school"), 4);
    EXPECT_EQ(qwe.stemmed.at("zombi"), 5);
    EXPECT_EQ(qwe.stemmed.at("now"), 4);
    EXPECT_EQ(qwe.stemmed.at("dad"), 4);
    EXPECT_EQ(qwe.stemmed.at("messag"), 3);
    EXPECT_EQ(qwe.stemmed.at("worri"), 3);
    EXPECT_EQ(qwe.stemmed.at("danc"), 4);
}

TEST(Russian, Words)
{
    WordCounter count(text_path_ru, stop_path_ru, output_path_ru, "russian");
    TestCase qwe(count);
    EXPECT_EQ(qwe.counter.at("вы"), 5);
    EXPECT_EQ(qwe.counter.at("книга"), 2);
    EXPECT_EQ(qwe.counter.at("мысли"), 2);
    EXPECT_EQ(qwe.counter.at("вам"), 2);
    EXPECT_EQ(qwe.counter.at("она"), 2);
    EXPECT_EQ(qwe.counter.at("соглашаться"), 2);
    EXPECT_EQ(qwe.counter.at("что"), 2);
    EXPECT_EQ(qwe.counter.at("этой"), 2);
    EXPECT_EQ(qwe.counter.at("возможно"), 1);
    EXPECT_EQ(qwe.counter.at("волновать"), 1);

}

TEST(Russian, Base)
{
    WordCounter count(text_path_ru, stop_path_ru, output_path_ru, "russian");
    //count.write("..\\..\\Words_counting\\Words_counting\\texts\\stem_test_ru.txt", "-s-f");
    TestCase qwe(count);
    EXPECT_EQ(qwe.stemmed.at("вы"), 5);
    EXPECT_EQ(qwe.stemmed.at("книга"), 2);
    EXPECT_EQ(qwe.stemmed.at("мысли"), 2);
    EXPECT_EQ(qwe.stemmed.at("вам"), 2);
    EXPECT_EQ(qwe.stemmed.at("она"), 2);
    EXPECT_EQ(qwe.stemmed.at("соглашаться"), 2);
    EXPECT_EQ(qwe.stemmed.at("что"), 2);
    EXPECT_EQ(qwe.stemmed.at("этой"), 2);
    EXPECT_EQ(qwe.stemmed.at("возможно"), 1);
    EXPECT_EQ(qwe.stemmed.at("волновать"), 1);
}



int main(int argc, char** argv)
{
    try
    {
        //===============================================================================================================
        // Запускать к консоли как "Words_counting.exe input.txt result.txt stop_list.txt English"
        // Раскомментировать этот блок, закомментировать следующий
        //if (argc != 5)
        //    throw std::invalid_argument
        //    ("wrong number of parameters of command line, correct format: *exe input.txt result.txt stop_list.txt language(Russian/English)");
        //
        //const char* input = argv[1];
        //const char* result = argv[2];
        //const char* stop_list = argv[3];
        //const char* locale_str = argv[4];
        //
        ////const char* input = R"foo(input.txt)foo";
        ////const char* result = R"foo(result.txt)foo";
        ////const char* stop_list = R"foo(stop_list.txt)foo";
        //
        //WordCounter count(input, stop_list, result, locale_str);
        //===============================================================================================================






         //===============================================================================================================
        // Для запуска в visual studio без параметров для командной строки


        WordCounter count(text_path_en, stop_path_en, output_path_en, "english");
        //WordCounter count(text_path_ru, stop_path_ru, output_path_ru, "russian");
        count.write("..\\..\\Words_counting\\Words_counting\\texts\\stem_test.txt", "-s-f");
         //===============================================================================================================
    }
    catch (std::exception& e)
    {
        std::fstream text_str;
        if (!text_str.is_open())
        {
            text_str.clear();
            text_str.open("log.txt", std::ios::out);
            text_str << e.what() << '\n';
            text_str.close();
        }
        std::abort();
    }

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}