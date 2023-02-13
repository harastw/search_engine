#include "ConvertJSON.cxx"

int main()
{
  ConvertJSON search_engine;
  search_engine.GetTextDocuments();
  search_engine.printAllWords()
  search_engine.GetResponsesLimit();
  search_engine.GetRequests();
  search_engine.InvertedIndex();
  search_engine.PutAnswers(); 
  return 0;
}
