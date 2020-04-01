#include "../headerFiles/headers.hpp"

class Start
{
private:
    std::vector<std::string>chapters;
public:
    Start(std::vector<std::string>ch);
    void setThingsUp(std::vector<int>&questions);
    int mainMenu();
};


//Constructor to initialise chapters with the parameter ch.
Start::Start(std::vector<std::string>ch)
{
    chapters = ch;
}


//goes over all the text files and stores the number of questions in each text file in str, and the final number of questions is stored in questions
void Start::setThingsUp(std::vector<int>&questions)
{
     for(int i=0; i<chapters.size(); ++i)
    {
        //Open all the text files in the folder files
        std::ifstream fin;
        fin.open("files/"+chapters[i]+".txt");
        std::string str;
        int numberOfQuestions=-1;

        //Go over the text file and every time there's a space, we can say that a question has ended. Thus increment numberOfQuestions
        while (!fin.eof())
        {
            getline(fin, str);
            if(str.empty())
                ++numberOfQuestions;
        }
        
        //Store the number of questions in questions
        questions.push_back(numberOfQuestions);
        fin.close();
    }
}


//Takes in the choice from the user to determine the chapter of which the test has to be generated. 
int Start::mainMenu()
{
    int choice;
    std::cin >> choice;
    return choice;
}