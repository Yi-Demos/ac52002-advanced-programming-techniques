///////////////////////////////////////////////////////////////////////
/// Copyright (C), 2020, Tranquility Tech. All rights reserved.
/// AC52002 Advanced Programming Techniques - Assignment 1
/// \author Ta-Yi Cheng
/// \version 1.0.0
/// \date 10 Feb 2020
/// \brief the programme is the simple the selling ticket system including storage user name and phone in the waiting list and queue searches.
///
/// Description:
///     The program generates two 10*10 matrix for storing user name and phone
///     and one 1*10 array for event names.
///     Then the user able to choose the event and select one edit option such as inserting one person,
///     remove the first people in the queue, search users by name or phone, edit event name.
///     Moreover, in this script, there is queue.demo() generate fake data function to a quick insert data.
///
///////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>  // std::setw
#include "queue.cpp"

using namespace std;

void clearConsole(void);
void mainMenu(void);
bool isValidNumber(int, int, int);

int main(int argc, char const *argv[]) {
    int queueNum = -1, serviceCode = -1;
    char shutdown = 'Y';
    string queueVal, nameVal, phoneVal, input;
    queue<string> queue(SIZE);

    clearConsole();

    do {
        while (!isValidNumber(0, SIZE -1, queueNum)) {
            // display the current queues status
            queue.showDashboard();

            printf("Please select one event (input Id nuber which is 0 ~ 9) \n");
            std::cin >> queueNum;
        }

        printf("\n\nYou are editing Id: \033[1;32m%d\033[0m \n", queueNum);
        // display the menu option
        mainMenu();

        while (!isValidNumber(0, 10, serviceCode)) {
            printf("Select one option \n");
            std::cin >> serviceCode;
        }

        switch (serviceCode) {
            case 1: // add person
                if (queue.isFull(queueNum)) {
                    printf("This queue is full \n");
                }
                else {
                    // insert queue
                    printf("Name ? \n");
                    std::cin >> nameVal;
                    // insert phone
                    printf("Phone ? \n");
                    std::cin >> phoneVal;
                    queue.add(queueNum, nameVal, phoneVal);
                }

                clearConsole();
                // display the current queues status
                queue.showDashboard();
                break;

            case 2: // remove first person
                queue.shift(queueNum);

                clearConsole();
                // display the current queues status
                queue.showDashboard();
                break;

            case 3:
                printf("Whats you name ? \n");
                std::cin >> input;
                queue.findByName(queueNum, input);
                break;

            case 4:
                printf("Whats you phone ? \n");
                std::cin >> input;
                queue.findByPhone(queueNum, input);
                break;

            case 5:
                printf("What's new event name ? \n");
                std::cin >> input;
                queue.renameEvent(queueNum, input);

                clearConsole();
                // display the current queues status
                queue.showDashboard();
                break;

            case 6:
                printf("What's new event name ? \n");
                std::cin >> input;
                queue.renameEvent(queueNum, input);
                queue.clear(queueNum);

                clearConsole();
                // display the current queues status
                queue.showDashboard();
                break;

            case 8:
                queue.demo();

                clearConsole();
                // display the current queues status
                queue.showDashboard();
                break;

            case 9:
                queueNum = -1;
                while (!isValidNumber(0, SIZE -1, queueNum)) {
                    printf("Please select one event (input Id nuber which is 0 ~ 9) \n");
                    std::cin >> queueNum;
                }

                clearConsole();
                // display the current queues status
                queue.showDashboard();
                break;

            case 0:
                printf("\n\n");
                printf("Countinu? (y/n) \n");
                cin.clear(); // fix cin not works in while loop bug
                cin >> shutdown;
                break;
        }

        // clear service
        serviceCode = -1;
        input = "";

    } while(shutdown == 'Y' || shutdown == 'y');

	return 0;
}

/// clearConsole() is the function to clear console log
/// the code works on Linux and Windows
void clearConsole() {
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    // https://stackoverflow.com/questions/6486289/how-can-i-clear-console
    printf("\x1B[2J\x1B[H");
}

void mainMenu() {
    printf("\n\n");
    printf( "%-3s %-10s \n" , "1)" , "Add one person");
    printf( "%-3s %-10s \n" , "2)" , "Delete first person");
    printf( "%-3s %-10s \n" , "3)" , "Search person status by name");
    printf( "%-3s %-10s \n" , "4)" , "Search person status by phone");
    printf( "%-3s %-10s \n" , "5)" , "Rename event");
    printf( "%-3s %-10s \n" , "6)" , "Reset & Rename event");
    printf("\n");
    printf( "%-3s %-10s \n" , "8)" , "Fake data generator (Demo)");
    printf( "%-3s %-10s \n" , "9)" , "Edit another queue");
    printf( "%-3s %-10s \n" , "0)" , "Shutdown");
    printf("\n");
}

bool isValidNumber (int low, int high, int input) {
    return (low <= input && input <= high);
}
