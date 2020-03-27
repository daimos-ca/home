#include<iostream>
#include<ctime>
#include <string>
#include "qi.h"
using namespace std;
int main() {
	init();
	int act = 0;
	do
	{
		cout << "1.Add new quiz" << endl;
		cout << "2.Show and pass quizes" << endl;
		cout << "3.Exit" << endl;
		cout << endl;
		cout << "Select action->_" << endl;
		cin >> act;
		switch (act)
		{
		case 1:
			addQuiz();
			break;
		case 2:
			ShowAllQuizes();
			passQuiz();
			break;
		case 3:
			cout << "Goodbye" << endl;
			break;
		default:
			cout << "Error: please select act from list" << endl;
			break;
		}
	} while (act!=3);
	system("pause");
	return 0;
}