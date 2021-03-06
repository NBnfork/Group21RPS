/*********************************************************************
 * Author: Noah Buchen, Alexandra Henley, Elliott Lapinel, Patrick
 * Rice, and Samantha Tone
 * Date: 10/25/2017
 * Description:
*********************************************************************/

#include "RPSGame.hpp"
#include "validChar.hpp"
#include "utilities.hpp"

using std::string;
using std::vector;
using std::rand;
using std::to_string;

/*********************************************************************
 * Constructor for game class.
*********************************************************************/
RPSGame::RPSGame() {
    this->width = 72;
    rounds = 1;
    hWins = 0;
    cWins = 0;
    ties = 0;
    this->rock = 'r';
    this->paper = 'p';
    this->scissor = 's';
}

/*********************************************************************
 * Assigns the tool based on the users selection.
*********************************************************************/
string RPSGame::assignToolUser() {
    if (rpseInput == 'r') {
        userTool = new Rock();
        userTool->setStrength(userStrength);
        return "Rock";

    } else if (rpseInput == 'p') {
        userTool = new Paper();
        userTool->setStrength(userStrength);
        return "Paper";

    } else {
        userTool = new Scissors();
        userTool->setStrength(userStrength);
        return "Scissors";
    }
}

/*********************************************************************
 * Contains logic for game play. Prompts user if they want to set
 * strength. Asks user what tool they would like to user for the round
 * calls print function for round totals
*********************************************************************/
void RPSGame::playGame() {
    // print title and menu
    printBoldCenterTitle("Welcome to the rock, paper, scissors game!", width);
    cout << "Would you like to set different strengths for the tools? (y - yes, n - no)" << endl;

    // get user input
    getline(cin, inputStr);
    ynInput = validChar(inputStr, yn, 2);

    if (ynInput == 'y') {
        // user strength
        cout << "Please enter strength for user, 1 to 100" << endl;
        getline(cin, userStrengthString);
        userStrength = validInt(userStrengthString, 1, 100);

        // computer strength
        cout << "Please enter strength for computer, 1 to 100" << endl;
        getline(cin, compStrengthString);
        compStrength = validInt(compStrengthString, 1, 100);

    } else if (ynInput == 'n') {

        // default values
        cout << "You have chose to use default strength values" << endl;
        userStrength = 1; //otherwise they are being set to zero in the assign tool function
        compStrength = 1;
    }

    // do while loop for the game to play as long as the user has not input 'e'
    do {
        // prints a notice with a box around it
        cout << endl;
        printBorder(width);
        printCenterTitle("Round " + to_string(rounds), width);
        printBorder(width);

        // print menu
        cout << "Choose your tool (r - rock, p - paper, s - scissor, e - exit)" << endl;
        getline(cin, inputStr);
        rpseInput = validChar(inputStr, rpse, 4);

        if (rpseInput != 'e') {
            string round = "";

            printBorder(width);
            // assign computer tool and construct string
            round += "Computer: " + assignToolComp() + " vs. Human: ";

            userHistory.push_back(rpseInput); // must assign after comp AI done to avoid cheating
            round += assignToolUser();
            printCenterTitle(round, width);

            //fight will always be userTool vs. compTool
            gameWinner = userTool->fight(compTool);

            // print results
            printResults();

            // no memory leaks here
            delete userTool;
            delete compTool;
        }

        this->rounds++;
    } while (rpseInput != 'e');

    // print final totals
    printCenterTitle("Final game totals", width);
    printLeftAndRightAlignedStrings("Human", to_string(hWins), width);
    printLeftAndRightAlignedStrings("Computer", to_string(cWins), width);
    printLeftAndRightAlignedStrings("Ties", to_string(ties), width);
    printBorder(width);

}

/*********************************************************************
 * Assigns the computers tool based on user choice history.
*********************************************************************/
string RPSGame::assignToolComp() // making this void as the Tools are available throughout class
{
    rCount = pCount = sCount = 0;

    if (rounds > 3) // must have 3 saved rounds in order to have enough input
    {
        last = userHistory[rounds - 3]; // this is -3 because starts at zero & we look at 2 rounds back
        current = userHistory[rounds - 2]; // this is -2 because starts at zero & we look at prev round
        for (int i = 1; i < rounds - 1; i++) {
            if (userHistory[i] == current && userHistory[i - 1] == last) {
                if (userHistory[i + 1] == rock) { rCount++; }
                else if (userHistory[i + 1] == paper) { pCount++; }
                else if (userHistory[i + 1] == scissor) { sCount++; }
            }
        }

        // 7 possible outcomes below:
        if (rCount == pCount && rCount == sCount) // all equally likely
        {
            randVal = rand() % 3;
            if (randVal == 0) { compChoice = 'r'; }
            else if (randVal == 1) { compChoice = 'p'; }
            else if (randVal == 2) { compChoice = 's'; }
        } else if (rCount > pCount && rCount > sCount) // rock most likely
        { compChoice = 'p'; } // choose paper to beat their rock
        else if (pCount > rCount && pCount > sCount) // paper most likely
        { compChoice = 's'; } // choose scissors to beat their paper
        else if (sCount > pCount && sCount > rCount) // scissors most likely
        { compChoice = 'r'; } // choose rock to beat their scissors
        else if (rCount == pCount && rCount > sCount) // rock & paper most likely
        { compChoice = 'p'; } // p beats r & ties p but s loses to r & beats p
        else if (rCount == sCount && rCount > pCount) // rock & scissors most likely
        { compChoice = 'r'; } // r beats s & ties r but p loses to s & beats r
        else if (sCount == pCount && sCount > rCount) // scissors & paper most likely
        { compChoice = 's'; } // s beats p & ties s but r loses to p & beats s
    } else // randomly select if not enough data for AI
    {
        randVal = rand() % 3;
        if (randVal == 0) { compChoice = 'r'; }
        else if (randVal == 1) { compChoice = 'p'; }
        else if (randVal == 2) { compChoice = 's'; }
    }

    rCount = pCount = sCount = 0;

    // assign the computers tool
    if (compChoice == 'r') {
        compTool = new Rock();
        compTool->setStrength(compStrength);
        return "Rock";
    } else if (compChoice == 'p') {
        compTool = new Paper();
        compTool->setStrength(compStrength);
        return "Paper";
    } else {
        compTool = new Scissors();
        compTool->setStrength(compStrength);
        return "Scissors";
    }
}

/*********************************************************************
 * Prints the results of the round.
*********************************************************************/
void RPSGame::printResults() {

    // print the winner
    if (gameWinner == 't') {
        printCenterTitle("It's a tie!", width);
        ties = ties + 1;
    } else if (gameWinner == 'h') {
        printCenterTitle("Human wins!", width);
        hWins = hWins + 1;
    } else if (gameWinner == 'c') {
        printCenterTitle("Computer wins!", width);
        cWins = cWins + 1;
    }

    // print the totals
    printCenterTitle("Running game totals", width);
    printLeftAndRightAlignedStrings("Human", to_string(hWins), width);
    printLeftAndRightAlignedStrings("Computer", to_string(cWins), width);
    printLeftAndRightAlignedStrings("Ties", to_string(ties), width);
    printBorder(width);
}
