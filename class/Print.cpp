#include "../headerFiles/headers.hpp"

class Print
{
public:
    void genPrint();
    void gap();
    void clearScreen();
    void menu();
};

void Print::genPrint()
{
    std::cout << "=========================\tYour chapter test starts now\t=========================\n\n";
}

//prints a gap
void Print::gap()
{
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n";
}

void Print::clearScreen()
{
    system("cls");
}

//Prints the main menu.
void Print::menu()
{
    std::cout << "Choose a chapter:\n1.Solutions\n2.Electrochemistry\n3.Chemical kinetics\n4.Surface chemistry\n5.General principles and processes of isolation of elements\n6.p block\n7.d and f block\n8.Coordination compounds\n9.Haloalkanes and haloarenes\n10.Alcohols, phenols and ethers\n11.Aldehydes, ketones and carboxylic acids\n12.Amines\n13.Biomolecules\n14.Polymers\n15.Chemistry in everyday life\n16.all\n";
}