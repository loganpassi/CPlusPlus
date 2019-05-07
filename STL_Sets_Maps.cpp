/*
FILE:	 STL_Sets_Maps.cpp
AUTHOR: <Your Name Here>
DATE:   MM/DD/YYYY
DESCR:
This program practices the use of STL set and map containers.
*/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
using namespace std;

int main() {

	// vectors to hold months and days per month 
	vector<string> months = { "January", "February", "March", "April", "May", "June", "July", "August",
	"September", "October", "November", "Decemter" };
	vector<int> daysPerMonth = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	// create ordered/unordered set of month names
	// initialize with vector values
	set<string> setMonths(months.begin(), months.end());
	unordered_set<string> unsetMonths(months.begin(), months.end());
	// display all ordered keys and values using range based for loop
	cout << "Ordered set of months..." << endl;
	for (auto entry : setMonths)
		cout << entry << endl;
	cout << "Unordered set of months..." << endl;
	for (auto entry : unsetMonths)
		cout << entry << endl;

	// create ordered/unordered map of months as key and number of days as value
	map<string, int> mapMonths;
	unordered_map<string, int> unmapMonths;
	// store map key-values
	for (size_t i = 0; i < months.size(); i++) {
		mapMonths[months[i]] = daysPerMonth[i];
		unmapMonths.emplace(months[i], daysPerMonth[i]);
	}
	// display all ordered keys and values using range based for loop
	cout << "Ordered map of months..." << endl;
	for (auto entry : mapMonths)
		cout << entry.first << ' ' << entry.second << endl;
	cout << "Unordered map of months..." << endl;
	// display all unordered keys and values
	for (auto entry : unmapMonths)
		cout << entry.first << ' ' << entry.second << endl;

	return EXIT_SUCCESS;
}

/* another way to initialize map
map<string, int> mapMonths = {
{"January", 31}, {"February", 28}, {"March", 31}, {"April", 30},
{"May", 31}, { "June", 30 }, { "July", 31 }, { "August", 31 },
{"September", 30 }, {"October", 31}, {"November", 30}, {"December", 31 }};
*/
