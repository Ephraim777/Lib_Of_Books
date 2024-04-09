
// Created by nikita on 02.04.24.
//

#ifndef UNTITLED10_BOOK_H
#define UNTITLED10_BOOK_H

#include <iostream>

enum eCategory{ PROSE, POETRY , SCIENCE , UNDEF };

struct BOOK
{
    char author[40];
//автор
    char name[80];
//название
    unsigned short year;
//год издания
    float price;
//цена
    eCategory category;
//категория


};
void FillBook(BOOK *book);

#endif //UNTITLED10_BOOK_H
