#include <iostream>
#include <vector>
#include <algorithm>
#include <clocale>


struct IndexedElement {
    double value;
    int index;
};

// Создание компаратора для сортировки в убывающем порядке
bool compare(const IndexedElement& a, const IndexedElement& b) {
    return a.value > b.value;
};

int main() {
    setlocale(LC_CTYPE, "rus");

    // Ввод размера массива
    int size;
    std::cin >> size;

    // Ввод массива и сохранение стартовых индексов
    std::vector<IndexedElement> array(size);
    for (int i = 0; i < size; ++i) {
        std::cin >> array[i].value;
        array[i].index = i;
    }

    // Предварительная сортировка массива по значениям в убывающем порядке
    sort(array.begin(), array.end(), compare);

    // Вывод двух наибольших элементов и их индексов
    std::cout << "Наибольшие элементы:\n";
    for (int i = 0; i < std::min(2, size); ++i) {
        std::cout << "Элемент: " << array[i].value << ", Индекс: " << array[i].index << "\n";
    }

    return 0;
}