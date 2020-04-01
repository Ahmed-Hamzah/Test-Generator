#include "../headerFiles/headers.hpp"

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); 
    
std::minstd_rand0 generator (seed);  

class Generator
{
private:
    std::vector<std::string>chapters;
    int NUMBER_OF_CHAPTERS_ALL = 15;
    int NUMBER_OF_CHAPTERS_ONE_CHAP = 10;

public:
    Generator(std::vector<std::string>chapters);
    void generateAll(std::vector<int>&questions);
    void generateSubject(int a,std::vector<int>&questions);
    
    void generateQuestion(bool boo, std::string chap, std::string str, int r, int k);
};


//Constructor to initialise chapters with the parameter ch.
Generator::Generator(std::vector<std::string>ch)
{
    chapters = ch;
}


//generates a question
void Generator::generateQuestion(bool boo, std::string chap, std::string str, int r, int k)
{
    std::ifstream fin;
    fin.open("files/" + chap+".txt");
    
    while(!fin.eof())
    {
        getline(fin, str);
            
        if(str.empty())
        {
            ++r;
            if(r==k)
                boo = true;
            else if(r>k)
                break;
        }
        if(boo && !str.empty())
            std::cout << str << std::endl; 
    }
    
    fin.close();
}


//Function to generate a test of all chapters.
void Generator::generateAll(std::vector<int>&questions)
{
    std::vector<int>used, alsoused;
    //std::ifstream fin;
    std::vector<int>appeared(chapters.size(), 0);
    
    for(int i=0; i<NUMBER_OF_CHAPTERS_ALL; ++i)
    {
        //Select a question that has not yet appeared
        over:
        
        //'a' gets a random number between 0 and the number of chapters
        int a = generator()%chapters.size();

        //'chap' is  chapter name chosen on random
        std::string chap = chapters[a];
        
        //If a question from this chapter has already appeared, go back and get another random question
        //(Since there are only 15 questions, we are outputting one question from each chapter)
        if(appeared[a]==1)
            goto over;
        
        //If not, increment appeared[a] to indicate that is has already been chosen.
        ++appeared[a];

        //Open the file of the chapter 
        //fin.open("files/" + chap+".txt");
        std::cout << i+1 << ". ";
        int k;

        //Check if our random question has already appreared
        here:

        //'k' is a random question number between 0 and the total number of questions in the chapter.
        k = generator() % questions[a];
        for(int j=0 ; j<used.size(); ++j)
            if(used[j]==k && alsoused[k]==i)
                goto here;
        
        used.push_back(k);
        alsoused.push_back(a);
        int r = -1;
        bool boo = false;
        std::string str;

        generateQuestion(boo, chap, str, r, k);

        std::cout << std::endl;
    }
}


//Works same as above, only that there will be 10 questions and all from the same chapter
void Generator::generateSubject(int a,std::vector<int>&questions)
{
    std::vector<int>used;
    std::string chap = chapters[a-1];
    
    for(int i=0; i<NUMBER_OF_CHAPTERS_ONE_CHAP; ++i)
    {
        std::cout << i+1 << ". ";
        int k;
        here:
        k = generator() % questions[a-1];
        for(int j=0 ; j<used.size(); ++j)
            if(used[j]==k)
                goto here;
        
        used.push_back(k);
        
        int r = -1;
        bool boo = false;
        std::string str;

        generateQuestion(boo, chap, str, r, k);
        
        std::cout << std::endl;
    }
}
