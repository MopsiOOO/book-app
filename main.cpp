#include <iostream>
#include <stdexcept>

#include "book.h"
int main() {
    try {
        Book warAndPeace("Война и мир", "Л. Толстой", 1869, 1225);
        Book nineteenEightyFour("1984", "Д. Оруэлл", 1949, 328);
        try {
            warAndPeace.updateYear(3000);
            std::cout << "Ошибка: исключение не выброшено!" << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cerr << "Не удалось обновить год: " << e.what() << std::endl;
        }
        try {
            nineteenEightyFour.updatePages(-50);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Не удалось обновить страницы: " << e.what() << std::endl;
        }
        warAndPeace.updateTitle("Война и мир (полное издание)");
        nineteenEightyFour.updateYear(1948);
        nineteenEightyFour.updatePages(320);
        nineteenEightyFour.updateAuthor("Джордж Оруэлл");

        std::cout << formatBookInfo(warAndPeace) << std::endl;
        std::cout << formatBookInfo(nineteenEightyFour) << std::endl;

        std::cout << "\"" << warAndPeace.title() << "\" - классика: "
                  << (isClassic(warAndPeace) ? "да" : "нет") << std::endl;
        std::cout << "\"" << nineteenEightyFour.title() << "\" - классика: "
                  << (isClassic(nineteenEightyFour) ? "да" : "нет") << std::endl;
        std::cout << "Чтение \"Войны и мира\" (50 стр./день): "
                  << readingTime(warAndPeace.pages(), 50) << " дней" << std::endl;

        std::cout << "\"" << warAndPeace.title() << "\" старше \""
                  << nineteenEightyFour.title() << "\": "
                  << (isOlder(warAndPeace, nineteenEightyFour) ? "да" : "нет") << std::endl;

        warAndPeace.checkout();
        std::cout << formatBookInfo(warAndPeace) << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Ошибка создания книги: " << e.what() << std::endl;
    }
    return 0;
}
