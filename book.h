



#ifndef UNTITLED10_BOOK_H
#define UNTITLED10_BOOK_H

#include <iostream>

enum eCategory{ PROSE, POETRY , SCIENCE , UNDEF };

struct BOOK
{
    char author[40];

    char name[80];

    unsigned short year;

    float price;

    eCategory category;



};
void FillBook(BOOK **book);

#endif 
