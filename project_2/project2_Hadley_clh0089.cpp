/*
*   Caelan Hadley (clh0089)   
*   project2_Hadley_clh0089.cpp
*
*   Reference(s):
*   (1) Stack Overflow - How to format decimal output.
*   https://stackoverflow.com/questions/16280069/show-two-digits-after-decimal-point-in-c
*   (2) Project2_hints.pdf
*   
*   Compilation/Execution Instrctiions (Run in command line):
*   # g++ -o a project2_Hadley_clh0089.cpp
*   # ./a
*/

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>
#include <iomanip>

using namespace std;

int a_win = 0;
int b_win = 0;
int c_win = 0;

const int AARON_SHOOT_CHANCE = 33;
const int BOB_SHOOT_CHANCE = 50;

// My Functions

// Returns true 1/3 of the time the function is called.
bool aaron_fire()
{
    if (rand() % 100 <= AARON_SHOOT_CHANCE)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Returns true 1/2 of the time the function is called.
bool bob_fire()
{
    if (rand() % 100 <= BOB_SHOOT_CHANCE)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Sets the number of wins for each competitor to 0.
void reset_wins()
{
    a_win = b_win = c_win = 0;
}

// Required Functions

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive)
{
    if (A_alive)
    {
        if (B_alive || C_alive)
        {
            return true;
        }
    }
    else if (B_alive && C_alive)
    {
        return true;
    }

    return false;
}

void Aaron_shoots1(bool &B_alive, bool &C_alive)
{
    if (aaron_fire())
    {
        if (C_alive)
        {
            C_alive = false;
        }
        else
        {
            B_alive = false;
        }
    }
}

void Bob_shoots(bool &A_alive, bool &C_alive)
{
    if (bob_fire())
    {
        if (C_alive)
        {
            C_alive = false;
        }
        else
        {
            A_alive = false;
        }
    }
}

void Charlie_shoots(bool &A_alive, bool &B_alive)
{
    if (A_alive || B_alive)
    {
        if (B_alive)
        {
            B_alive = false;
        }
        else
        {
            A_alive = false;
        }
    }
}

void Aaron_shoots2(bool &B_alive, bool &C_alive)
{
    if (!B_alive || !C_alive)
    {
        if (aaron_fire())
        {
            if (C_alive)
            {
                C_alive = false;
            }
            else
            {
                B_alive = false;
            }
        }
    }
}

//Simple method to implement pause function in linux
void Press_any_key(void)
{
    cout << "Press Enter to continue...";
    cin.ignore().get(); //Pause Command for Linux Terminal
};

//TEST PROTOTYPES
void test_at_least_two_alive(void)
{
    cout << "Unit Testing 1: Function –at_least_two_alive()\n";
    cout << "Case 1: Aaron alive, Bob alive, Charlie alive\n";
    assert(true == at_least_two_alive(true, true, true));
    cout << "Case passed ...\n";

    cout << "Case 2: Aaron dead, Bob alive, Charlie alive\n";
    assert(true == at_least_two_alive(false, true, true));
    cout << "Case passed ...\n";

    cout << "Case 3: Aaron alive, Bob dead, Charlie alive\n";
    assert(true == at_least_two_alive(true, false, true));
    cout << "Case passed ...\n";

    cout << "Case 4: Aaron alive, Bob alive, Charlie dead\n";
    assert(true == at_least_two_alive(true, true, false));
    cout << "Case passed ...\n";

    cout << "Case 5: Aaron dead, Bob dead, Charlie alive\n";
    assert(false == at_least_two_alive(false, false, true));
    cout << "Case passed ...\n";

    cout << "Case 6: Aaron dead, Bob alive, Charlie dead\n";
    assert(false == at_least_two_alive(false, true, false));
    cout << "Case passed ...\n";

    cout << "Case 7: Aaron alive, Bob dead, Charlie dead\n";
    assert(false == at_least_two_alive(true, false, false));
    cout << "Case passed ...\n";

    cout << "Case 8: Aaron dead, Bob dead, Charlie dead\n";
    assert(false == at_least_two_alive(false, false, false));
    cout << "Case passed ...\n";
}

void test_Aaron_shoots1(void)
{
    bool b_alive;
    bool c_alive;

    cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";

    // Test Case 1
    cout << "\tCase 1: Bob alive, Charlie alive\n";
    cout << "\t\tAaron is shooting at Charlie\n";
    b_alive = c_alive = true;
    Aaron_shoots1(b_alive, c_alive);
    assert(true == b_alive);

    // Test Case 2
    cout << "\tCase 2: Bob dead, Charlie alive\n";
    cout << "\t\tAaron is shooting at Charlie\n";
    b_alive = false;
    c_alive = true;
    Aaron_shoots1(b_alive, c_alive);
    assert(false == b_alive);

    // Test Case 3
    cout << "\tCase 3: Bob alive, Charlie dead\n";
    cout << "\t\tAaron is shooting at Bob\n";
    b_alive = true;
    c_alive = false;
    Aaron_shoots1(b_alive, c_alive);
    assert(false == c_alive);
}

void test_Bob_shoots(void)
{
    bool a_alive;
    bool c_alive;
    cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";

    cout << "\tCase 1: Aaron alive, Charlie alive\n";
    cout << "\t\tBob is shooting at Charlie\n";
    a_alive = c_alive = true;
    Bob_shoots(a_alive, c_alive);
    assert(true == a_alive);

    cout << "\tCase 2: Aaron dead, Charlie alive\n";
    cout << "\t\tBob is shooting at Charlie\n";
    a_alive = false;
    c_alive = true;
    Bob_shoots(a_alive, c_alive);

    cout << "\tCase 3: Bob alive, Charlie dead\n";
    cout << "\t\tBob is shooting at Aaron\n";
    a_alive = true;
    c_alive = false;
    Bob_shoots(a_alive, c_alive);
    assert(c_alive == false);
}
void test_Charlie_shoots(void)
{
    bool a_alive, b_alive;

    cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";

    cout << "\tCase 1: Aaron alive, Bob alive\n";
    cout << "\t\tCharlie is shooting at Bob\n";
    a_alive = b_alive = true;
    Charlie_shoots(a_alive, b_alive);
    assert(true == a_alive);
    assert(false == b_alive);

    cout << "\tCase 2: Aaron dead, Bob alive\n";
    cout << "\t\tCharlie is shooting at Bob\n";
    a_alive = false;
    b_alive = true;
    Charlie_shoots(a_alive, b_alive);
    assert(false == a_alive);
    assert(false == b_alive);

    cout << "\tCase 3: Aaron alive, Bob dead\n";
    cout << "\t\tCharlie is shooting at Aaron\n";
    a_alive = true;
    b_alive = false;
    Charlie_shoots(a_alive, b_alive);
    assert(false == a_alive);
    assert(false == b_alive);
}

void test_Aaron_shoots2(void)
{
    bool b_alive, c_alive;

    cout << "Unit Testing 5: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";

    cout << "\tCase 1: Bob alive, Charlie alive\n";
    cout << "\t\tAaron intentionally Missed his first shot\n";
    b_alive = c_alive = true;
    Aaron_shoots2(b_alive, c_alive);
    assert(true == b_alive && true == c_alive);
    cout << "\t\tBoth Bob and Charlie are alive\n";

    cout << "\tCase 2: Bob dead, Charlie alive\n";
    cout << "\t\tAaron is shooting at Charlie\n";
    b_alive = false;
    c_alive = true;
    Aaron_shoots1(b_alive, c_alive);
    assert(false == b_alive);

    cout << "\tCase 3: Bob alive, Charlie dead\n";
    cout << "\t\tAaron is shooting at Bob\n";
    b_alive = true;
    c_alive = false;
    Aaron_shoots1(b_alive, c_alive);
    assert(false == c_alive);
}

void strat1()
{
    bool a_alive = true;
    bool b_alive = true;
    bool c_alive = true;

    do
    {
        if (a_alive)
        {
            Aaron_shoots1(b_alive, c_alive);
        }
        if (b_alive)
        {
            Bob_shoots(a_alive, c_alive);
        }
        if (c_alive)
        {
            Charlie_shoots(a_alive, b_alive);
        }
    } while (at_least_two_alive(a_alive, b_alive, c_alive));

    if (a_alive)
    {
        a_win++;
    }
    if (b_alive)
    {
        b_win++;
    }
    if (c_alive)
    {
        c_win++;
    }
}
void strat2()
{
    bool a_alive = true;
    bool b_alive = true;
    bool c_alive = true;
    //cout << a_alive << b_alive << c_alive << "\n";
    do
    {
        if (a_alive)
        {
            Aaron_shoots2(b_alive, c_alive);
        }
        if (b_alive)
        {
            Bob_shoots(a_alive, c_alive);
        }
        if (c_alive)
        {
            Charlie_shoots(a_alive, b_alive);
        }
    } while (at_least_two_alive(a_alive, b_alive, c_alive));

    if (a_alive)
    {
        a_win++;
    }
    if (b_alive)
    {
        b_win++;
    }
    if (c_alive)
    {
        c_win++;
    }
}

int main()
{
    cout << "***Welcome to Caelan's Duel Simulator***\n";
    srand(time(0));
    const int NUM_RUNS = 10000;

    test_at_least_two_alive();

    Press_any_key();
    test_Aaron_shoots1();

    Press_any_key();
    test_Bob_shoots();

    Press_any_key();
    test_Charlie_shoots();

    Press_any_key();
    test_Aaron_shoots2();

    Press_any_key();

    cout << "Ready to test strategy 1 (run 10000 times):\n";
    Press_any_key();

    strat1();
    int duels = 0;

    do
    {
        strat1();
        duels++;
    } while (duels < NUM_RUNS);

    double a_per = ((double)a_win / (double)duels) * 100;
    double b_per = ((double)b_win / (double)duels) * 100;
    double c_per = ((double)c_win / (double)duels) * 100;

    cout << "Aaron won " << a_win << "/" << duels << " duels or " << fixed << setprecision(2) << a_per << "%\n";
    cout << "Bob won " << b_win << "/" << duels << " duels or " << fixed << setprecision(2) << b_per << "%\n";
    cout << "Charlie won " << c_win << "/" << duels << " duels or " << fixed << setprecision(2) << c_per << "%\n\n";
    int a_wins_run1 = a_win;

    duels = 0;
    reset_wins();
    cout << "Ready to test strategy 2 (run 10000 times):\n";
    Press_any_key();

    do
    {
        strat2();
        duels++;
    } while (duels < NUM_RUNS);

    a_per = ((double)a_win / (double)duels) * 100;
    b_per = ((double)b_win / (double)duels) * 100;
    c_per = ((double)c_win / (double)duels) * 100;

    cout << "Aaron won " << a_win << "/" << duels << " duels or " << fixed << setprecision(2) << a_per << "%\n";
    cout << "Bob won " << b_win << "/" << duels << " duels or " << fixed << setprecision(2) << b_per << "%\n";
    cout << "Charlie won " << c_win << "/" << duels << " duels or " << fixed << setprecision(2) << c_per << "%\n\n";

    if (a_wins_run1 < a_win)
    {
        cout << "Strategy 2 is better than strategy 1.\n";
    }
    else
    {
        cout << "Strategy 1 is better than strategy 2.\n";
    }

    return 0;
}
