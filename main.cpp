#include "ConverterJSON.h"
#include "InvertedIndex.h"
#include "SearchServer.h"

int main() {
  ConverterJSON converter;
  InvertedIndex inverter;
  auto textDocuments = converter.GetTextDocuments();
  auto responsesLimit = converter.GetResponsesLimit();
  inverter.UpdateDocumentBase(textDocuments);
  auto requests = converter.GetRequests(); // принимаем запрос для поиска
  SearchServer searcher = SearchServer(inverter);
  searcher.Search(requests); // ищем ответ, присваиваем ему ранг
  return 0;
}
