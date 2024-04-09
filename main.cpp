#include <iostream>
#include "card_index.h"
#include <fstream>

using namespace std;

int main() {

    CARD_INDEX *ptr =LibraryOFBooks();
  menu(ptr);
  DeleteLibrary(ptr);


    return 0;
}