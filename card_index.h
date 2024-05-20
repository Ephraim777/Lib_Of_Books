

#ifndef UNTITLED10_CARD_INDEX_H
#define UNTITLED10_CARD_INDEX_H

#include <cstdlib>
#include "book.h"
#include <unistd.h>
struct CARD_INDEX{
    size_t count = 0;
    size_t capacity= 1;
    BOOK *pB=nullptr;
};

CARD_INDEX* LibraryOFBooks();
void menu(CARD_INDEX*ptr);
void PrintBook(BOOK*);
void PrintLibrary(CARD_INDEX *);
void ReadFromFile(CARD_INDEX*ptr);
void WriteToFile(CARD_INDEX*ptr);
void resize(CARD_INDEX *pCard);
void addBook(CARD_INDEX *&pCard);
void deleteBook(CARD_INDEX *pCard);
void DeleteLibrary(CARD_INDEX *ptr);

#endif 