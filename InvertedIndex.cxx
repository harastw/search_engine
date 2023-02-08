#pragma once

struct Entry {
size_t doc_id, count;
// Данный оператор необходим для проведения тестовых сценариев
bool operator ==(const Entry& other) const {
return (doc_id == other.doc_id &&
count == other.count);
}
};
class InvertedIndex {
public:
InvertedIndex() = default;
/**
* Обновить или заполнить базу документов, по которой будем совершать
поиск
* @param texts_input содержимое документов
*/
void UpdateDocumentBase(std::vector<std::string> input_docs);
/**
