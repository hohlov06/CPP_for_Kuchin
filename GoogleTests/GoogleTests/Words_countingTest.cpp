#include "pch.h"

// ��� ������� ����� ����� ����������������� , ���� ����������������
// ���������������� �� ���� ��������� cpp ��, ��� ���� #include "pch.h"
// ���� ��������� �� ������� ��� ��������� cpp
//
//#define GOOGLE_TEST_DEBUG
//#include "../../Words_counting/Words_counting/engcount.h"
//
//using namespace std;
//using namespace WordCount;
//
//
//const char* text_path_en = R"foo(../../Words_counting/Words_counting/texts/en_text.txt)foo";
//const char* stop_path_en = R"foo(../../Words_counting/Words_counting/texts/en_stop.txt)foo";
//const char* output_path_en = R"foo(../../Words_counting/Words_counting/texts/en_output.txt)foo";
//const char* text_path_ru = R"foo(../../Words_counting/Words_counting/texts/ru_text.txt)foo";
//const char* stop_path_ru = R"foo(../../Words_counting/Words_counting/texts/ru_stop.txt)foo";
//const char* output_path_ru = R"foo(../../Words_counting/Words_counting/texts/ru_output.txt)foo";
//
//
//class TestCase
//{
//public:
//    std::unordered_map<std::string, int>& counter;
//    std::unordered_set<std::string>& stops;
//    //std::unordered_map<std::string, int>&  base;
//    TestCase(WordCounter& count_) : counter(count_.m_counter), stops(count_.m_stops) {}
//};
//
//TEST(English, Words)
//{
//    WordCounter count(text_path_en, stop_path_en, output_path_en, std::locale("English"));
//    TestCase qwe(count);
//    EXPECT_EQ(qwe.counter.at("amy"), 24);
//    EXPECT_EQ(qwe.counter.at("tara"), 21);
//    EXPECT_EQ(qwe.counter.at("and"), 17);
//    EXPECT_EQ(qwe.counter.at("looked"), 6);
//    EXPECT_EQ(qwe.counter.at("kamal"), 19);
//    EXPECT_EQ(qwe.counter.at("school"), 4);
//    EXPECT_EQ(qwe.counter.at("zombies"), 3);
//    EXPECT_EQ(qwe.counter.at("now"), 4);
//    EXPECT_EQ(qwe.counter.at("dad"), 4);
//    EXPECT_EQ(qwe.counter.at("arrived"), 3);
//    EXPECT_EQ(qwe.counter.at("art"), 3);
//    EXPECT_EQ(qwe.counter.at("dancing"),3 );
//}
//
////TEST(English, Base)
////{
////    WordCounter count(text_path_en, stop_path_en, output_path_en, std::locale("English"));
////    EXPECT_EQ(1, 1);
////    EXPECT_EQ(1, 1);
////    EXPECT_EQ(1, 1);
////}
//
//TEST(Russian, Words)
//{
//    WordCounter count(text_path_ru, stop_path_ru, output_path_ru, std::locale("Russian"));
//    TestCase qwe(count);
//    EXPECT_EQ(qwe.counter.at("��"), 5);
//    EXPECT_EQ(qwe.counter.at("�����"), 2);
//    EXPECT_EQ(qwe.counter.at("�����"), 2);
//    EXPECT_EQ(qwe.counter.at("���"), 2);
//    EXPECT_EQ(qwe.counter.at("���"), 2);
//    EXPECT_EQ(qwe.counter.at("�����������"), 2);
//    EXPECT_EQ(qwe.counter.at("���"), 2);
//    EXPECT_EQ(qwe.counter.at("����"), 2);
//    EXPECT_EQ(qwe.counter.at("��������"), 1);
//    EXPECT_EQ(qwe.counter.at("���������"), 1);
//
//}
//
////TEST(Russian, Base)
////{
////    WordCounter count(text_path_ru, stop_path_ru, output_path_ru, std::locale("Russian"));
////    EXPECT_EQ(1, 1);
////    EXPECT_EQ(1, 1);
////    EXPECT_EQ(1, 1);
////}
//
//
//
//int main(int argc, char** argv)
//{
//    try
//    {
//        //===============================================================================================================
//        // ��������� � ������� ��� "Words_counting.exe input.txt result.txt stop_list.txt English"
//        // ����������������� ���� ����, ���������������� ���������
//        //if (argc != 5)
//        //    throw std::invalid_argument
//        //    ("wrong number of parameters of command line, correct format: *exe input.txt result.txt stop_list.txt language(Russian/English)");
//        //
//        //const char* input = argv[1];
//        //const char* result = argv[2];
//        //const char* stop_list = argv[3];
//        //const char* locale_str = argv[4];
//        //
//        ////const char* input = R"foo(input.txt)foo";
//        ////const char* result = R"foo(result.txt)foo";
//        ////const char* stop_list = R"foo(stop_list.txt)foo";
//        //
//        //WordCounter count(input, stop_list, result, std::locale(locale_str));
//        //===============================================================================================================
//
//
//
//
//
//
//         //===============================================================================================================
//        // ��� ������� � visual studio ��� ���������� ��� ��������� ������
//
//
//        WordCounter count(text_path_en, stop_path_en, output_path_en, std::locale("English"));
//        //WordCounter count(text_path_ru, stop_path_ru, output_path_ru, std::locale("Russian"));
//
//         //===============================================================================================================
//    }
//    catch (std::exception& e)
//    {
//        std::fstream text_str;
//        if (!text_str.is_open())
//        {
//            text_str.clear();
//            text_str.open("log.txt", std::ios::out);
//            text_str << e.what() << '\n';
//            text_str.close();
//        }
//        std::abort();
//    }
//
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}