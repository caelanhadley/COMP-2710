/*
*   Caelan Hadley (clh0089)   
*   project4_Hadley_clh0089.cpp
*
*   Reference(s):
*   (1) http://www.cplusplus.com/forum/general/1477/ - Used to fix bug with getline() function by using cin.ignore() before user input.
*   
*   Compilation/Execution Instructions (Run in command line):
*   # g++ -o a project4_Hadley_clh0089.cpp
*   # ./a
*/
#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

/*
*   Trivia Node Data Structure.
*/
struct trivia_node {
    string question;
    string answer;
    int point;
    trivia_node* next = NULL;
};

typedef trivia_node* ptr_node;

/*
*   Function Protoypes
*   See function Definitions for Documentation.
*/

void Unit_test();

void init_question_list(ptr_node& node_in);

void add_question(ptr_node node_in);

void cap(ptr_node node_in);

void ask_for_questions(ptr_node node_in, int &num_of_questions);

int ask_question(ptr_node question_node);

int ask_question_amt(ptr_node head, int num_ask, int num_of_questions);

int possible_points(ptr_node head);

ptr_node find_question(ptr_node head, int position, int num_of_questions);


/* 
* Two versions, trivia_quiz and UNIT_TESTING
*/

#define trivia_quiz
// #define UNIT_TESTING

int main() {
    ptr_node question_node = new trivia_node;
    int num_of_questions = 0;
    int total_points = 0;

#ifdef trivia_quiz

    cout << "*** Welcome to Caelan's trivia quiz game ***" << endl;

    /*
    *   Initialize 3 questions that are hard coded into the quiz.
    */
    init_question_list(question_node);
    num_of_questions = 3;

    /* 
    *   Prompt the user for additional questions.
    */
    ask_for_questions(question_node, num_of_questions);

    /*
    *   The user is given questions and asked to respond with the correct answer.
    */
    total_points = ask_question_amt(question_node, num_of_questions, num_of_questions);

    /*
    *   Displays the user's score.
    */
    cout << "\nYour score is " << total_points << " out of " << possible_points(question_node) <<  " possible points.\n" << endl;
    cout << "*** Thank you for playing the trivia quiz game. Goodbye! ***" << endl;

    return 0;
}
#endif

#ifdef  UNIT_TESTING
    cout << "***This is a debugging version ***" << endl;
    /*
    *   Runs Unit Tests, see Unit_test() definition for further documentation.
    */
    Unit_test();
    return 0;
}
#endif
    

/*
*   Function Definitions.
*/

/*
*   Function: Unit_test
*   Use: This is for Unit Testing.
*
*   @return void
*/
void Unit_test () {
    ptr_node node = new trivia_node;
    init_question_list(node);
    int num_of_questions = 3;

    cout << "Unit Test Case 1: Ask no question the program should give a warning message." << endl;
    assert(-1 == ask_question_amt(node, 0, num_of_questions));
    cout << "\nCase 1 Passed\n\n"; 

    cout << "Unit Test Case 2.1: Ask 1 question in the linked list.  The tester enters an incorrect answer." << endl; 
    assert(0 == ask_question_amt(node, 1, num_of_questions));
    cout << "\nCase 2.1 Passed\n\n";

    cout << "Unit Test Case 2.2: Ask 1 question in the linked list.  The tester enters an correct answer." << endl; 
    assert(node->point == ask_question_amt(node, 1, num_of_questions));
    cout << "\nCase 2.2 Passed\n\n";

    int sum_of_points = node->point + node->next->point + node->next->next->point;

    cout << "Unit Test Case 3.1: Ask 3 questions in the linked list.  The tester enters incorrect answers." << endl; 
    assert(0 == ask_question_amt(node, 3, num_of_questions));
    cout << "\nCase 3.1 Passed\n\n";

    cout << "Unit Test Case 3.2: Ask 3 questions in the linked list.  The tester enters correct answers." << endl; 
    assert(sum_of_points == ask_question_amt(node, 3, num_of_questions));
    cout << "\nCase 3.2 Passed\n\n";

    cout << "Unit Test Case 4: Ask more questions than the list contains. A warning should be given." << endl; 
    assert(-1 == ask_question_amt(node, 5, num_of_questions));
    cout << "\nCase 4 Passed\n\n";

    cout << "\nUnit Testing Complete! All Tests Passed...";

}

/*
*   Function: init_question_list                            
*   Use: Creates the default question list.
*   @param node_in
*   @return void
*/
void init_question_list(ptr_node& node_in) {

    string bob;                                       
    ptr_node cur_ptr1 = new trivia_node;
    ptr_node cur_ptr2 = new trivia_node;
    ptr_node cur_ptr3 = new trivia_node;


    cur_ptr1 -> question = "How long was the shortest war on record?";
    cur_ptr1 -> answer = "38";
    cur_ptr1 -> point = 100;

    node_in = cur_ptr1;

    cur_ptr2->question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
    cur_ptr2->answer = "Bank of Italy";
    cur_ptr2->point = 50;

    node_in->next = cur_ptr2;

    cur_ptr3->question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)?";
    cur_ptr3->answer = "Wii Sports";
    cur_ptr3->point = 20;

    cap(cur_ptr3);

    node_in->next->next = cur_ptr3;
}

/*
*   Function: add_question
*   Use: Adds a triva node to the end of the provided headders list.
*
*   @param node_in <- headder for the singly-linked list.
*   @return void
*/
void add_question(ptr_node node_in) {
    
    ptr_node temp = new trivia_node;
    ptr_node sel_node = node_in;

    cout << "Question: ";
    // cin >> temp->question;
    getline(cin, temp->question);
    cout << "Answer: ";
    // cin >> temp->answer;
    getline(cin, temp->answer);
    cout << "Points: ";
    cin >> temp->point;

    if (cin.fail()){
        cin.clear();
        cout << "ERROR: Input was not numeric!";
    }

    cap(temp);

    while (sel_node->next != NULL) {
        sel_node = sel_node->next;
    }
    if (sel_node->next == NULL) {
        sel_node->next = temp;
    }
    else {
        cout << "ERROR: NODE LIST COULD NOT BE PARSED.";
    }
    
}

/*
*   Function: ask_question
*   Use: Given a ptr_node object this will display the 
*       question and ask for the answer. If the answer
*       is correct the points are returned. Otherwise,
*       the user is told the correct answer and no
*       points are awarded.
*
*   @param question_node
*   @return int
*/
int ask_question(ptr_node question_node) {
    string answer = "";

    cout << "Question: " << question_node->question << endl;
    cout << "Answer: ";
    //cin  >> answer;
    getline(cin, answer);

    if (answer.compare(question_node->answer) == 0) {
        cout << "Your answer is correct! You recive " << question_node->point << " points." << "\n" << endl;
        return question_node->point;
    }
    else {
        cout << "Your answer is wrong! The correct answer is: " << question_node->answer << "\n" << endl;
        return 0;
    }
}


/*
*   Function: find_question
*   Use: This function selects a trivia_node at a specific
*       index. 
*
*   @param head <- headder of the singly linked list.
*   @param position <- index of the desired ptr_node object.
*   @param num_of_questions <- total number of all questions for error checking.
*   @return ptr_node
*/
ptr_node find_question(ptr_node head, int position, int num_of_questions) {
    ptr_node cur_node = head;

    if (position > num_of_questions - 1) {
        cout << "Warning: There are only " << num_of_questions << " questions in this quiz." << endl;
        return NULL;
    }
    else if (position < 0) {
        cout << "Warning: Invalid input there is no question at index " << position << endl;
        return NULL;
    }
    else {
        for (int i = 0; i < position; i++) {
            cur_node = cur_node->next;
        }
        return cur_node;
    }
}

/*
*   Function: ask_question_amt
*   Use: This function is more in line with what this assignment
*       is asking to be implemented. I do not understand how to
*       pass through the total number of questions without making
*       it a parameter or a global varaible. In this implemenetation
*       I have made it a parameter.
*
*   @param head <- headder of the singly linked list.
*   @param num_ask <- How many questions to be asked.
*   @param num_of_questions <- total number of all questions for error checking.
*   @return int
*/
int ask_question_amt(ptr_node head, int num_ask, int num_of_questions) {
    int total_points = 0;

    if (num_ask <= 0) {
        cout << "Warning - the number of trivia to be asked must equal to or be larger than 1." << endl; 
        return -1;
    }
    else if (num_ask > num_of_questions) {
        cout << "Warning - There is only " << num_of_questions << " trivia in the list." << endl; 
        return -1;
    }
    else {
         for (int i = 0; i < num_ask; i++) {
            ptr_node cur_node = find_question(head, i, num_of_questions);
            total_points += ask_question(cur_node);
        }
    }
    return total_points;
}

/*
*   Function: possible_points
*   Use: Returns the sum of the points of all of the 
*       questions in a given list.
*
*   @param head <- headder of the singly linked list.
*   @return int
*/
int possible_points(ptr_node head) {
    int total_points = head->point;
    while (head->next != NULL) {
        head = head->next;
        total_points += head->point;
    } 
    
    
    return total_points;
}

/*
*   Function: cap
*   Use: Sets the next-> value for a given node to NULL
*       which solves the next-> field of the last node
*       being a random location in memory.
*
*   @param node_in
*   @return void
*/
void cap(ptr_node node_in) {
    node_in->next = NULL;
}

/*
*   Function: ask_for_questions
*   Use: Prompts the user to add questions to an existing
*       question set.
*
*   @param node_in
*   @param num_of_questions <- used for keeping the total number of questions
*   @return void
*/
void ask_for_questions(ptr_node node_in, int &num_of_questions) {
    string input = "";
    ptr_node sel_node = node_in;

    while (input != "No") {
        add_question(sel_node);
        num_of_questions++;
        cout << "Continue? (Yes/No): ";
        cin >> input;
        cin.ignore();
    }
    node_in = sel_node;
}
