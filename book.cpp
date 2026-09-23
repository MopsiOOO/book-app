#include "book.h"

#include <stdexcept>
namespace {
constexpr int kMinYear = 1450;
constexpr int kMaxYear = 2025;
constexpr int kClassicCutoffYear = 1975;
}

Book::Book(std::string title, std::string author, int year, int pages)
    : title_(std::move(title))
    , author_(std::move(author))
    , year_(year)
    , pages_(pages)
    , is_available_(true)
{
    if (!isValidData(title_, author_, year_, pages_)) {
        throw std::invalid_argument("Invalid book data: title and author must be non-empty, "
                                    "year must be between 1450 and 2025, pages must be > 0.");
    }
}

std::string Book::title() const {
    return title_;
}
std::string Book::author() const {
    return author_;
}
int Book::year() const {
    return year_;
}
int Book::pages() const {
    return pages_;
}
bool Book::isAvailable() const {
    return is_available_;
}
void Book::checkout() {
    is_available_ = false;
}
void Book::returnBook() {
    is_available_ = true;
}
void Book::updateTitle(std::string new_title) {
    if (!isValidData(new_title, author_, year_, pages_)) {
        throw std::invalid_argument("Invalid title: must be non-empty.");
    }
    title_ = std::move(new_title);
}
void Book::updateAuthor(std::string new_author) {
    if (!isValidData(title_, new_author, year_, pages_)) {
        throw std::invalid_argument("Invalid author: must be non-empty.");
    }
    author_ = std::move(new_author);
}
void Book::updateYear(int new_year) {
    if (!isValidData(title_, author_, new_year, pages_)) {
        throw std::invalid_argument("Invalid year: must be between 1450 and 2025.");
    }
    year_ = new_year;
}
void Book::updatePages(int new_pages) {
    if (!isValidData(title_, author_, year_, new_pages)) {
        throw std::invalid_argument("Invalid pages: must be greater than 0.");
    }
    pages_ = new_pages;
}
bool Book::isValidData(const std::string& title, const std::string& author,
                       int year, int pages) const {
    if (title.empty() || author.empty()) {
        return false;
    }
    if (year < kMinYear || year > kMaxYear) {
        return false;
    }
    return pages > 0;
}
std::string formatBookInfo(const Book& book) {
    return "Title: " + book.title()
        + ", Author: " + book.author()
        + ", Year: " + std::to_string(book.year())
        + ", Pages: " + std::to_string(book.pages())
        + ", Status: " + (book.isAvailable() ? "Available" : "Checked Out");
}
bool isClassic(const Book& book) {
    return book.year() < kClassicCutoffYear;
}
double readingTime(int pages, int pages_per_day) {
    if (pages_per_day <= 0) {
        throw std::invalid_argument("pages_per_day must be greater than 0.");
    }
    return static_cast<double>(pages) / pages_per_day;
}
bool isOlder(const Book& first, const Book& second) {
    return first.year() < second.year();
}