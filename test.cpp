#include <catch2/catch_test_macros.hpp>
#include "ConvertJSON.cxx"

TEST_CASE("Factorials are computed", "[factorial]") {
  ConvertJSON testObject;
  REQUIRE(testObject.GetTextDocuments() == 1);
  REQUIRE(testObject.GetResponsesLimit() == 1);
  REQUIRE(testObject.GetRequests() == 1);
  REQUIRE(testObject.PutAnswers() == 1);
}
