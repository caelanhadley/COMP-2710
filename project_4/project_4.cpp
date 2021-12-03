#include <iostream>

using namespace std;

struct trivia_node
{
    string question;
    string answer;
    int point;
    trivia_node *next;
};

typedef trivia_node *ptr_node;

void Unit_test();

#define trivia_quiz

int main()
{
    Unit_test();
    ptr_node node_list = new trivia_node;

#ifdef trivia_quiz
}
