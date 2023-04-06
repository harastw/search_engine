#include "ConvertJSON.cpp"

int main() {
  ConvertJSON search_engine;
  search_engine.GetTextDocuments();
  search_engine.GetResponsesLimit();
  search_engine.ToUnique();

  std::string choise;
  while (true) {
    search_engine.GetRequests();
    search_engine.PutAnswers();
    std::cout << "read requests again? y-yes/enything-no: ";
    std::cin >> choise;
    if (choise != "y" and choise != "yes")
      break;
  }
  return 0;
}
