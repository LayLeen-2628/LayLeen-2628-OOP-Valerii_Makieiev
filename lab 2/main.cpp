#include <iostream>
#include <vector>
#include <string>

class Inventory 
{ 
private:
    std::vector<std::string> items; // приватне поле

public:
    // Властивість: кількість товарів (тільки для читання)
    int getCount() const {
        return items.size();
    }

    // Властивість: додати товар (тільки для запису)
    void addItem(const std::string& item) {
        items.push_back(item);
    }

    // Індексатор
    std::string& operator[](int index) {
        return items.at(index);
    }

    int operator[](const std::string& name) const {
        for (size_t i = 0; i < items.size(); ++i) {
            if (items[i] == name)
                return static_cast<int>(i);
        }
        return -1;
    }

    // Оператор + для додавання товару
    Inventory operator+(const std::string& item) const {
        Inventory result = *this;
        result.items.push_back(item);
        return result;
    }

    // Вивід всіх товарів
    void print() const {
        std::cout << "Inventory: ";
        for (const auto& item : items)
            std::cout << item << " ";
        std::cout << std::endl;
    }
};

int main() {
    Inventory inv;
    inv.addItem("Sword");
    inv.addItem("Shield");
    inv.addItem("Potion");

    // Доступ через властивість
    std::cout << "Count: " << inv.getCount() << std::endl;

    // Доступ через індексатор [int]
    std::cout << "Item at index 1: " << inv[1] << std::endl;

    // Доступ через індексатор [string]
    std::cout << "Index of 'Potion': " << inv["Potion"] << std::endl;

    // Оператор +
    Inventory inv2 = inv + "Helmet";
    inv2.print();

    return 0;
}
