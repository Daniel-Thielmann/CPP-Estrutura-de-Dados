#ifndef MENU_H
#define MENU_H

#include <fstream>

class Menu {
public:
    Menu();
    ~Menu() = default;

private:
    void UI();
    void sortMenu();
    void treeMenu();
    void compressionsMenu();
    std::ofstream outputFile;
};

#endif //MENU_H
