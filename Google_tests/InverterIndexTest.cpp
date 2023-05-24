#include "gtest/gtest.h"
#include "InvertedIndex.hpp"
using namespace std;

void TestInvertedIndexFunctionality(
        std::vector<std::string>& docs,
        std::vector<std::string>& requests,
        std::vector<std::vector<Entry>>& expected
) {
    std::vector<std::vector<Entry>> result;
    auto* idx = new InvertedIndex();

    idx->update_document_base(docs);
    ASSERT_EQ(result, expected);
}
TEST(TestCaseInvertedIndex, TestBasic) {
    std::vector<std::string> docs = {
            "london is the capital of great britain",
            "big ben is the nickname for the Great bell of the striking clock"
    };
    std::vector<std::string> requests = {"london", "the"};
    std::vector<std::vector<Entry>> expected = {
            {
                    {0, 1}
            }, {
                    {0, 1}, {1, 3}
            }
    };
    TestInvertedIndexFunctionality(docs, requests, expected);
}
TEST(TestCaseInvertedIndex, TestBasic2) {
    std::vector<std::string> docs = {
            "milk milk milk milk water water water",
            "milk water water",
            "milk milk milk milk milk water water water water water",
            "Americano Cappuccino"
    };
    std::vector<std::string> requests = {"milk", "water", "cappuccino"};
    std::vector<std::vector<Entry>> expected = {
            {
	      
                    {0, 4}, {1, 1}, {2, 5}
            }, {
                    {0, 3}, {1, 2}, {2, 5}
            }, {
                    {3, 1}
            }
    };
    TestInvertedIndexFunctionality(docs, requests, expected);
}
TEST(TestCaseInvertedIndex, TestInvertedIndexMissingWord) {
    std::vector<std::string> docs = {
            "a b c d e f g h i j k l",
            "statement"
    };
    std::vector<std::string> requests = {"m", "statement"};
    std::vector<std::vector<Entry>> expected = {
            {
            }, {
                    {1, 1}
            }
    };
    TestInvertedIndexFunctionality(docs, requests, expected);
}
