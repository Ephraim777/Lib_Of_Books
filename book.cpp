
#include "book.h"

 void FillBook( BOOK **book) {
    BOOK * ptr = *book;
    std::cout << "Введите автора книги 30 символов\n";
    std::cin.ignore(1);
    std::cin.getline(ptr->author, 30);
    std::cout << "Введите название книги 80 символов\n";

    std::cin.getline(ptr->name, 80);
    std::cout << "Введите год издания книги\n";
    std::cin >> ptr->year;
    bool inputnum = false;
    while (inputnum != true) {

        if (std::cin.fail()) {
            inputnum = false;
            std::cout << "Упс, похоже вы ввели не цыфру, попробуем еще раз!!\n";
            std::cin.clear();
            std::cin.ignore(999999999999, '\n');
            std::cin >> ptr->year;
        } else {


            inputnum = true;


        }
    }
    std::cout << "Введите стоимость книги в рублях\n";
    std::cin >> ptr->price;
    bool inputnum1 = false;
    while (inputnum1 != true) {

        if (std::cin.fail()) {
            inputnum1 = false;
            std::cout << "Упс, похоже вы ввели не число, попробуем еще раз!!\n";
            std::cin.clear();
            std::cin.ignore(999999999999, '\n');
            std::cin >> ptr->price;
        } else {


            inputnum1 = true;


        }
    }
    std::cout << "Введите тип книги  PROSE(0), POETRY(1), SCIENCE(2), UNDEF(3) \n";
    int num;
    std::cin >> num;
    switch (num) {
        case 0:
            ptr->category = PROSE;
            break;
        case 1:
            ptr->category = POETRY;
            break;
        case 2:
            ptr->category = SCIENCE;
            break;
        case 3:
            ptr->category = UNDEF;
            break;
        default:
            bool number = false;
            while (!number){
                std::cout <<  "Похоже такой цыфры нет\n";
                std::cout << "Введите тип книги  PROSE(0), POETRY(1), SCIENCE(2), UNDEF(3) \n";
                std::cin >> num;
                if (num < 0 || num > 3){
                    number = false;
                } else {
                    number = true;
                }

            }

    }

};

