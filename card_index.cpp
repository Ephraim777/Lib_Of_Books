
#include <string.h>
#include "card_index.h"
#include <fstream>

using namespace  std;
const char* strCategory[] = { "PROSE", "POESY" , "SCIENCE" ,
                              "UNDEF" };


CARD_INDEX* LibraryOFBooks() {
    CARD_INDEX* card = new CARD_INDEX;
    card->pB = new BOOK*[card->capacity];
    for ( int i =0; i < card->capacity; i++){
        card->pB[i] = new BOOK[card->capacity];
    }
    card->count = 0;
    return card;
}
void addBook(CARD_INDEX*& pCard) {
    if (pCard->count == pCard->capacity) {
        pCard->capacity += 5;
        BOOK** newarr = new BOOK*[pCard->capacity];
        for (int i =0; i< pCard->capacity; i++){
            newarr[i] = new BOOK[pCard->capacity];
        }

        for (int i = 0; i < pCard->count; i++) {
            for ( int j =0; j < pCard->count; j++){
            newarr[i][j] = pCard->pB[i][j]; }
        }

        for ( int i =0; i < pCard->count; i++){
            delete [] pCard->pB[i];

        }
        delete[] pCard->pB;


        pCard->pB = newarr;
    }


    FillBook(&pCard->pB[pCard->count]);


    pCard->count++;
    std::cout << "Добавить ещё книгу? Да или Нет?\n";
    std::cout << std::endl;
    string answer;
    cin >> answer;
    if (answer == "Да" || answer == "ДА" || answer == "да" || answer == "дА") {
        sleep(1);
        cout << "\033[2J\033[1;1H";
        addBook(pCard);


    }
    else {
    std::cout << "Возвращаемся в меню....\n";
        sleep(1);
        cout << "\033[2J\033[1;1H";
        menu(pCard);
    }
}
void deleteBook(CARD_INDEX* pCard) {
    if (pCard->count == 0) {
        std::cout << "Ваша картотека пуста,нечего удалять\n";
        std::cout << "Возвращаемся в меню....\n";
        sleep(1);
        cout << "\033[2J\033[1;1H";
        menu(pCard);
    }
    string allbooks;
    std::cout << "Вы хотите удалить все книги? Да или Нет?\n";
    std::cin >> allbooks;
    if (allbooks == "да" ||  allbooks == "Да" || allbooks == "ДА" || allbooks == "дА" ){
      pCard->count =0;
        std::cout  << "Вы удалили все книги\n";
        std::cout << "Возвращаемся в меню....\n";
        sleep(1);
        cout << "\033[2J\033[1;1H";
        menu(pCard);
    } else {
    std::cout << "Введите номер книги,которую хотите удалить\n";
    int numberbook;
    std::cin >> numberbook;
    bool answer = false;
    while(answer == false){
    if ( numberbook < 1 || numberbook > pCard->count){
        std::cout << "Ошибка такой книги по счёту у вас нет\n";
        std::cout << "Введите номер книги,которую хотите удалить\n";
        std::cin >> numberbook;
    }
    else {
        answer = true;

    }
    }
    if (numberbook > 0) {
        numberbook -= 1;
    }
    if (pCard->count != 1){
    for (int i = numberbook; i < pCard->count -1; ++i) {
        pCard->pB[i] = pCard->pB[i+1];
    }}
    pCard->count--;

     std::cout << "Вы удалили книгу номер: \n" << numberbook+1  << std::endl;
     if (pCard->count != 0){
    std::cout << "Удалить еще книгу? Да или Нет?\n";
    std::cout << std::endl;
    string answer1;
    cin >> answer1;
    if (answer1 == "Да" || answer1 == "ДА" || answer1 == "да" || answer1 == "дА") {
        deleteBook(pCard);
    }
    else {
        std::cout << "Возвращаемся в меню....\n";
        sleep(1);
        cout << "\033[2J\033[1;1H";
        menu(pCard);
    }} else {
         std::cout << "Возвращаемся в меню....\n";
         sleep(1);
         cout << "\033[2J\033[1;1H";
         menu(pCard);
     }}

}
void PrintBook(BOOK** ptr) {
    BOOK *ptr1 = *ptr;
    std::cout << "Автор книги: \n";
    std::cout << ptr1->author;
    std::cout << std::endl;
    std::cout << "Название книги: \n";
    std::cout << ptr1->name;
    std::cout << std::endl;
    std::cout << "Год издания книги: \n";
    std::cout << ptr1->year;
    std::cout << std::endl;
    std::cout << "Стоимость книги в рублях: \n";
    std::cout << ptr1->price;
    std::cout << std::endl;
    std::cout << "Тип книги: \n";
    if (ptr1->category == PROSE) {
        std::cout << strCategory[0];
    }
    else if (ptr1->category == POETRY) {
        std::cout << strCategory[1];
    }
    else if (ptr1->category == SCIENCE) {
        std::cout << strCategory[2];
    }
    else if (ptr1->category == UNDEF) {
        std::cout << strCategory[3];
    }

}
void PrintLibrary(CARD_INDEX* ptr) {
    if (ptr->count == 0) {
        std::cout << "У вас пустая картотека книг\n";
        std::cout << "Возвращаемся в меню....\n";
        sleep(1);
        cout << "\033[2J\033[1;1H";
        menu(ptr);
    } else {
    for (int i = 0; i < ptr->count; i++) {
        std::cout << "Книга № " << i + 1 << "\n";
        PrintBook(&ptr->pB[i]);
        std::cout << std::endl << std::endl;

    }
    std::cout << "Вернуться в меню? Да или Нет?\n";
    std::cout << std::endl;
    string answer;
    cin >> answer;
    if (answer == "Да" || answer == "ДА" || answer == "да" || answer == "дА") {
        std::cout << "Возвращаемся в меню....\n";
        sleep(1);
        cout << "\033[2J\033[1;1H";
        menu(ptr);
    }
    else {

        return;
    }}

}
void ReadFromFile(CARD_INDEX* ptr) {
    std::cout << "Укажите путь по которому находится файл\n";
    string WayOfFile;
    std::cin >> WayOfFile;
    std::ifstream file(WayOfFile);
    if (WayOfFile.ends_with(".txt") || WayOfFile.ends_with(".md")) {
        std::cout << "Расширение файла подходит для чтения)\n";
    }
    else {
        std::cout << "Ваше расширение для файла должно быть .txt или .md\n";
        std::cout << "Возвращаемся в меню....\n";
        sleep(1);
        cout << "\033[2J\033[1;1H";
        menu(ptr);
    }

    if (file.is_open()) {
        std::cout << "Файл успешно открыт,считываем информацию с файла.... \n";
        int count;
        file >> count;

        while (count) {
            BOOK * newbook = new BOOK;
            file.ignore(1);
            file.getline( newbook->author, 40);
            file.getline( newbook->name,80);
            file >> newbook->year;
            file >> newbook->price;
            string categoryStr;
            file >> categoryStr;
            if (categoryStr == strCategory[0]) {
                newbook->category = PROSE;
            }
            else if (categoryStr == strCategory[1]) {
                newbook->category = POETRY;
            }
            else if (categoryStr == strCategory[2]) {
                newbook->category = SCIENCE;
            }
            else {
                newbook->category = UNDEF;
            }


            if(ptr->count == ptr->capacity)
            {
                resize(ptr);
            }

            ptr->pB[ptr->count++] =  newbook;
            count--;
        }



        file.close();
    }
    else {
        std::cout << "Ошибка,файл не открылся ,проверьте данные\n";
        std::cout << "Возвращаемся в меню....\n";
        sleep(3);
        cout << "\033[2J\033[1;1H";
        menu(ptr);

    }
    std::cout << "Возвращаемся в меню....\n";
    sleep(3);
    cout << "\033[2J\033[1;1H";
    menu(ptr);

}
void WriteToFile(CARD_INDEX* ptr) {
    if (ptr->count == 0) {
        std::cout << "Упс, ваша картотека пуста, нечего записать в файл\n";
        std::cout << "Возвращаемся в меню....\n";
        sleep(3);
        cout << "\033[2J\033[1;1H";
        menu(ptr);

    }
    std::cout << "Укажите путь по которому находится файл\n";
    string WayOfFile;
    std::cin >> WayOfFile;
    std::ofstream file(WayOfFile, std::ofstream::binary);


    if (WayOfFile.ends_with(".txt") || WayOfFile.ends_with(".md")) {
        std::cout << "Расширение файла подходит для записи)\n";
    } else {
        std::cout << "Ваше расширение  для файла должно быть .txt или .md\n";

        std::cout << "Возвращаемся в меню....\n";
        sleep(3);
        cout << "\033[2J\033[1;1H";
        menu(ptr);
    }

    if (file.is_open()) {
            std::cout << "Файл успешно открыт, проверьте его\n";
            file << ptr->count << "\n";
            for (int i = 0; i < ptr->count; i++) {
               BOOK **ptr1 = &(ptr->pB[i]);
               BOOK * current = *ptr1;
               file << current->author << "\n";
               file << current->name << "\n";
               file << current->year << "\n";

                file << current->price << "\n";
                if (current->category == PROSE) {
                    file << strCategory[0];
                } else if (current->category == POETRY) {
                   file << strCategory[1];
               } else if (current->category == SCIENCE) {
                   file << strCategory[2];
                    } else if (current->category == UNDEF) {
                    file << strCategory[3];
                }
                file << '\n';

            }



        file.close();
        std::cout << "Возвращаемся в меню....\n";
        sleep(3);
        cout << "\033[2J\033[1;1H";
        menu(ptr);
    } else {
        std::cout << "Что-то пошло не так, файл не открылся...\n";
        std::cout << "Возвращаемся в меню....\n";
        sleep(3);
        cout << "\033[2J\033[1;1H";
        menu(ptr);
    }

}








void menu(CARD_INDEX* ptr) {
    std::cout << "Привет,перед тобой меню, выбери что хочешь сделать :)\n";
    std::cout << "Распечатать содержимое картотеки (1)\n";
    std::cout << "Ввести новую книгу (2) \n";
    std::cout << "Удалить существующую(ие) (3)\n";
    std::cout << "Записать текущее содержимое картотеки в файл (4)\n";
    std::cout << "Считать из файла содержимое в картотеку (5)\n";
    std::cout << "Выйти из программы (6)\n";
    std::cout << "В вашей картотеке вот такое количество книг: " << ptr->count << std::endl;
    size_t number = ptr->capacity - ptr->count;
    std::cout << "Резервных мест: " << number << std::endl;
    int num;
    bool inputnum = false;
    std::cin >> num;
    while (inputnum != true) {

        if (std::cin.fail() || num <= 0 || num > 6) {
            inputnum = false;
            std::cout << "Упс, похоже вы ввели не цыфру или такой цыфры нет, попробуем еще раз!!\n";
            std::cin.clear();
            cin.ignore(999999999999, '\n');
            std::cin >> num;
        }
        else {


            inputnum = true;


        }



    }
    switch (num) {
        case 1: PrintLibrary(ptr); break;
        case 2: addBook(ptr);  break;
        case 3: deleteBook(ptr); break;
        case 4: WriteToFile(ptr); break;
        case 5: ReadFromFile(ptr); break;
        case 6: std::cout << "Вы вышли из программы\n"; return;
        default: std::cout << "Неизвестная  ошибка, попробуйте еще раз)\n";
    }





}
void DeleteLibrary(CARD_INDEX* ptr) {
for ( int i = 0; i <ptr->count; i++){
    delete [] ptr->pB[i];
    ptr->pB[i] = nullptr;
}
    delete[] ptr->pB;
    ptr = nullptr;
}

void resize(CARD_INDEX * pCard)
{
    pCard->capacity += 5;
    BOOK** newarr = new BOOK*[pCard->capacity];
    for (int i =0; i< pCard->capacity; i++){
        newarr[i] = new BOOK[pCard->capacity];
    }

    for (int i = 0; i < pCard->count; i++) {
        for ( int j =0; j < pCard->count; j++){
            newarr[i][j] = pCard->pB[i][j]; }
    }

    for ( int i =0; i < pCard->count; i++){
        delete [] pCard->pB[i];

    }
    delete[] pCard->pB;
    pCard->pB = newarr;

}