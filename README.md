# ProgrammingAssignment10

## Project Goals
The goal of this project is to:
1. Be the culmination of concepts learned throughout the entire semester
2. Allow students to develop teamwork skills
### Important Notes:
1.	**Comments**: Header comments are required on all files and should include the names of all group members. Points will be deducted if no header comments are included.
3.	**Filename**: Save your program as ```minesweeper.c```
## Program  
Bombs away! We'll be building a minesweeper game for our final project. 

#### First Checkpoint
The first checkpoint only requires basic game play functionality. Correct implementation of these features will earn a project grade of B. The design document for the example executable at this checkpoint is provided. These features will be demonstrated to staff (and other students) during lab on 12/12.

#### Second Checkpoint
The second checkpoint includes basic game play functionality and the ability to save player scores. Correct implementation of these features will earn a project grade of A.   

### Required Functionality
A file stores player scores. These scores are displayed when the program starts and ends. A player gets a point for every game they win, they are added to the file after they decide not to play any more. 

Your minesweeper game is required to allow the user to choose different cells to interact with. Users can mark that cell with a flag, if they think a bomb is in that cell. They can uncover that single cell to see what is there, or they can check all the cells surrounding their chosen cell. If the user uncovers a bomb, they lose. If one of the cells uncovered when they check surrounding cells is either an unmarked bomb or incorrectly marked as a bomb, they lose.

When a user uncovers a cell, it either has a bomb in it, is blank, or has a number in it. Numbers tell the users how many bombs are in the surrounding cells. For example, if the number is ```2```, there are only two bombs in the surrounding cells. If the cell is blank, there are no bombs touching that cell. 

Your minesweeper game will get the field layout from a file (an example file is included in this repository).

#### Extra Credit
These features will not be considered for extra credit unless the required functionality is completely implemented:  
1. Player scores are sorted from highest to lowest  
2. If the player uncovers a blank cell when checking, a chain reaction will occur to uncover any touching blank cells  
3. Random fields are generated within the game (not loaded from a file)  


### The example executable:
An example executable is provided in this repository. You should be able to run it from your project folder.
If you encounter a "permission denied" error when attempting to run the executable, type ```chmod u+x minesweeperAExecutable``` into the terminal and try running the executable again.

## Submission details
### It will be easier for one student to manage the repository. 
To submit your project, you will have to use git on your VirtualBox installation:
1.	After accepting the assignment invitation, copy the clone URL
2.	Type 
```git clone clone_URL```
3.	cd into your new assignment directory
4.	After working on your files
5.	When you’re ready, type the following commands: 
```
git add .
git commit -m “a descriptive message!”
git push
```

## Academic Honesty
Academic dishonesty is against university as well as the system community standards. Academic dishonesty includes, but is not limited to, the following:
Plagiarism: defined as submitting the language, ideas, thoughts or work of another as one's own; or assisting in the act of plagiarism by allowing one's work to be used in this fashion.
Cheating: defined as (1) obtaining or providing unauthorized information during an examination through verbal, visual or unauthorized use of books, notes, text and other materials; (2) obtaining or providing information concerning all or part of an examination prior to that examination; (3) taking an examination for another student, or arranging for another person to take an exam in one's place; (4) altering or changing test answers after submittal for grading, grades after grades have been awarded, or other academic records once these are official.
Cheating, plagiarism or otherwise obtaining grades under false pretenses constitute academic
dishonesty according to the code of this university. Academic dishonesty will not be tolerated and
penalties can include cancelling a student’s enrolment without a grade, giving an F for the course, or for the assignment. For more details, see the University of Nevada, Reno General Catalog.
