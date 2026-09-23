#ifndef BOOK_H
#define BOOK_H

#include <string>
class Book {
public:
    Book(std::string title, std::string author, int year, int pages = 100);

    std::string title() const;
    std::string author() const;
    int year() const;
    int pages() const;
    bool isAvailable() const;

    void checkout();
    void returnBook();

    void updateTitle(std::string new_title);
    void updateAuthor(std::string new_author);
    void updateYear(int new_year);
    void updatePages(int new_pages);

private:
    bool isValidData(const std::string& title, const std::string& author,
                     int year, int pages) const;

    std::string title_;
    std::string author_;
    int year_;
    int pages_;
    bool is_available_;
};

std::string formatBookInfo(const Book& book);
bool isClassic(const Book& book);
double readingTime(int pages, int pages_per_day);
bool isOlder(const Book& first, const Book& second);
#endif
