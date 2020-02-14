#include "queue.h"

template <class Arr> class queue  {
    private:
        vector<vector<string> > names {10};
        vector<vector<string> > phones {10};
        // init vector<vector<int>> vec(10, vector<int> (10, 0)) not work!
        // https://stackoverflow.com/questions/11490988/c-compile-time-error-expected-identifier-before-numeric-constant
    	vector<string> events;

    public:
        // constructor
    	queue(int size = SIZE);

        void demo();

        void shift(int);
    	void add(int, Arr, Arr);
        void findByName(int, Arr);
        void findByPhone(int, Arr);
        void showDashboard();
        void renameEvent(int, string);
        void clear(int);
    	int size(int);
    	bool isEmpty(int);
    	bool isFull(int);
};

// init queue constructor
template <class Arr> queue<Arr>::queue(int size) {
    for (int i = 0; i < 10; i++) {
        events.push_back("Event_" + to_string(i));
    }
}

/// queue::shift() is queue member function
/// function to remove first element from the queue
///
/// \param queueNum is number of column in the matrix
template <class Arr> void queue<Arr>::shift(int queueNum) {
	// check for queue underflow
	if (isEmpty(queueNum)) {
		printf("\n\n\t\033[1;31mNo one in this queue\033[0m");

		// exit(EXIT_FAILURE); // force exit program
	}
    else {
        printf("Removing first person");

        // remove the first value in queue
        names[queueNum].erase(names[queueNum].begin());
        phones[queueNum].erase(phones[queueNum].begin());
    }
}

/// queue::add() is queue member function
/// function to add an item to the queue
///
/// \param queueNum is number of column in the matrix
/// \param namesVal is the value be stored  in user names list
/// \param phonesVal is the value be stored  in phones list
template <class Arr> void queue<Arr>::add(int queueNum, Arr namesVal, Arr phonesVal) {
	// check for queue overflow
    if (isFull(queueNum)) {
        printf("Overflow !!!");
    }
    else {
        printf("Add one person \n");

    	names[queueNum].push_back(namesVal.c_str());
        phones[queueNum].push_back(phonesVal.c_str());
    }
}

/// queue::findByName() is queue member function
/// for search name's position in queue
///
/// \param queueNum is number of column in the matrix
/// \param item is a query for search
template <class Arr> void queue<Arr>::findByName(int queueNum, Arr item) {
    int index = -1;

	if (isEmpty(queueNum)) {
        printf("\n\n\t\033[1;31mNo one in this queue\033[0m");
	}
    else {
        for (int i = 0; i < names.size(); i++) {
            if (names[queueNum][i] == item) {
                index = i;
            }
        }

        if (index >= 0) {
            // print color text trick
            // https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
            printf("\n\n\tThere are %d people in the queue and you are in \033[1;32m %d \033[0m position \n", names[queueNum].size(), index +1);
        }
        else {
            printf("\n\n\033[1;31mbold Not found\033[0m");
        }
    }
}

/// queue::findByPhone() is queue member function
/// for search phone's position in queue
///
/// \param queueNum is number of column in the matrix
/// \param item is a query for search
template <class Arr> void queue<Arr>::findByPhone(int queueNum, Arr item) {
    int index = -1;

	if (isEmpty(queueNum)) {
        printf("\n\n\t\033[1;31mNo one in this queue\033[0m");
	}
    else {
        for (int i = 0; i < names.size(); i++) {
            if (phones[queueNum][i] == item) {
                index = i;
            }
        }

        if (index >= 0) {
            // print color text trick
            // https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
            printf("\n\n\tThere are %d people in the queue and you are in \033[1;32m %d \033[0m position \n", names[queueNum].size(), index +1);
        }
        else {
            printf("\n\n\033[1;31mbold Not found\033[0m");
        }
    }
}

/// queue::size() is queue member function
/// for checking queue usage
///
/// \param queueNum is number of column in the matrix
template <class Arr> int queue<Arr>::size(int queueNum) {
	return names[queueNum].size();
}

/// queue::isEmpty() is queue member function
/// for checking whether queue (one-dimensional array) in the matrix is empty
///
/// \param queueNum is number of column in the matrix
template <class Arr> bool queue<Arr>::isEmpty(int queueNum) {
	return (size(queueNum) == 0);
}

/// queue::isFull() is queue member function
/// for checking whether queue (one-dimensional array) in the matrix is full
///
/// \param queueNum is number of column in the matrix
template <class Arr> bool queue<Arr>::isFull(int queueNum) {
    return (size(queueNum) >= SIZE);
}

/// queue::showDashboard() is queue member function
/// displays current matrix status
template <class Arr> void queue<Arr>::showDashboard() {
    printf("\n\n");
    // header
    printf("%-3s%-30s\t%-3s\t", "Id", "Event", "Count");
    for (int i = 0; i < SIZE; i++) {
        printf("%-3s\t", "Name");
    }
    printf("\n");

    // body
    for (int i = 0; i < SIZE; i++) {
        printf("%-3d", i);
        printf("%-30s\t", events[i].c_str());
        printf("%-3d\t", names[i].size());

        for (int j = 0; j < names[i].size(); j++) {
            printf("%-3s\t", names[i][j].c_str());
        }

        printf("\n");
    }

    printf("\n\n");
}

/// queue::renameEvent() is queue member function
/// rename the one event name
///
/// \param queueNum is number of column in the matrix
/// \param newEvent is new event name
template <class Arr> void queue<Arr>::renameEvent(int queueNum, string newEvent) {
    events[queueNum] = newEvent;
}

/// queue::clear() is queue member function
/// clear one queue in user name list and phone list
///
/// \param queueNum is number of column in the matrix
template <class Arr> void queue<Arr>::clear(int queueNum) {
    names[queueNum].clear();
    phones[queueNum].clear();
}

/// queue::demo() is queue member function
/// generate fake data and insert into matrix
template <class Arr> void queue<Arr>::demo() {
    // set fake data for demo
    events = {"FIFA World Cup ", "Mardi Gras Festival", "Leeds & Reading Music Festivals", "Albuquerque International Balloon", "Coachella Music Festival", "Sasquatch Music Festival", "Taiwan National Day", "Royal Ascot Races", "Italian Grand Prix", "Rugby World Cup"};
}
