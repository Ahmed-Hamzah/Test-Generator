#include "headerFiles/headers.hpp"
#include "headerFiles/classes.hpp"

//vector that holds the names of each of the text files
std::vector<std::string>chapters = {"solutions", "electrochemistry", "chemicalkinetics", "surfacechemistry", "generalprinciplesandprocessesofisolationofelements", "pblock", "dandfblock", "coordinationcompounds" , "haloalkanesandhaloarenes", "alcoholsphenolsandethers", "aldehydesketonesandcarboxylicacids", "amines", "biomolecules","polymers", "chemistryineverydaylife"};

// vector that holds the number of questions in each chapter
std::vector<int>questions;//{40, 9, 31, 27, 27, 22, 29};


int main()
{   
    Start start(chapters);
    Print print;    
    Generator gen(chapters);
    
    //clear everything first.
    print.clearScreen();

    //'setThingsUp' will put the number of questions in each chapter in 'questions'
    start.setThingsUp(questions);
    
    //prints the list of options to choose the number of chapter
    print.menu();
    int ch = start.mainMenu();
    
    //clears the screen
    print.clearScreen();
   
   //16 corresponds to putting up question of all chapters...
    if(ch!=16)
    {
        print.genPrint();
        gen.generateSubject(ch, questions);
    }

    //...1-15 correspodns to putting up question of any one chapter (from chapters 1 to 15)
    else
    {
        print.genPrint();
        gen.generateAll(questions);
    }    
}