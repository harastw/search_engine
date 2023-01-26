#include "ConvertJSON.cpp"

int main()
{
  ConvertJSON search_engine;
  search_engine.GetTextDocuments();
  search_engine.GetResponsesLimit();
  search_engine.GetRequests();
  search_engine.LoadUnique();
  search_engine.PutAnswers(); 
  return 0;
}
