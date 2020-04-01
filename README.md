# Test-Generator
Takes in random questions from prewritten text files and generates tests.

'files' contains 15 text files each corresponding to a chapter. In each of these text files are the corresponding questions. If you'd like to add more questions, leave a line between each question and at the end as well.

'classes' contains the classes Generator, Print and Start.
- Generator generates the questions, either of a single chapter or of all chapters (depending on the value passed in by the user, 1-15 corresponding to each of the 15 chapters and 16 corresponding to all chapters)
- Print has a few functions of which the contents are printed on the screen.
- Start has a function 'setThingsUp' that stores the number of questions in each the files in a vector 'questions'. Member funtion 'mainMenu' takes in the chapter number which is passed into Generator.

'headerFiles' contains 'header.hpp' and 'classes.hpp" which contain all the necessary libraries and header files.

Contact me at ahmedhamzah2002@gmail.com if you'd like to share your thoughts.
