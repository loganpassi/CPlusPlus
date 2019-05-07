/*
Logan Passi
10/25/2017
CIS2541
testQueue.cpp*/

#include <iostream>
#include <queue> //for queue and prority_queue

using namespace std;

int main() {
	//create simple integer queue
	priority_queue<int> iQueue;
	cout << "adding some items to the queue..." << endl;
	for (int count = 2; count < 10; count += 2) {
		cout << "\tpushing " << count << " onto queue..." << endl;
		iQueue.push(count);
	}

	//examine items on the queue
	cout << "The size of the queue is " << iQueue.size() << endl;
	cout << "Item at front of queue is " << iQueue.top() << endl;
	//cout << "Item at back of queue is " << iQueue.back() << endl;

	//removing items from queue
	for (int count = 2; count < 10; count += 2) {
		cout << "\tpopping " << iQueue.top() << " from queue..." << endl;
		iQueue.pop();
	}

	//examine items on the queue
	cout << "The size of the queue is " << iQueue.size() << endl;
	return EXIT_SUCCESS;
}