#include "qi.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

Quiz*quizes;
int countQuiz = 0;
const int countQuestQi = 5;
const string fileName = "quiz.txt";
void insertQuiz(Quiz getQuiz)
{
	Quiz*temp = new Quiz[countQuiz+1];
	for (int i = 0; i < countQuiz; i++)
	{
		temp[i] = quizes[i];

	}
	temp[countQuiz] = getQuiz;
	countQuiz++;
	quizes = new Quiz[countQuiz];
	for (int i = 0; i < countQuiz; i++)
	{
		quizes[i] = temp[i];
	}
	delete[]temp;
}
void init()
{
	ifstream fin;
	fin.open(fileName);
	bool isOpen = fin.is_open();
	if (isOpen == true) {
		while (!fin.eof())
		{
			Quiz getQuiz;
			fin >> getQuiz.Title;
			for (int i = 0; i < countQuestQi; i++)
			{
				fin >> getQuiz.quest[i].questText;
				fin >> getQuiz.quest[i].trAnswer;
			}
			insertQuiz(getQuiz);
		}
	}
	else {
		cout << "error" << endl;
	}
}
void addQuiz()
{
	ofstream fout;
	fout.open(fileName, fstream::app);
	bool isOpen = fout.is_open();
	if (isOpen==true) {
		Quiz*temp = new Quiz[countQuiz + 1];
		for (int i = 0; i < countQuiz; i++)
		{
			temp[i] = quizes[i];

		}
		cout << "Enter title for quiz->_";
		cin >> temp[countQuiz].Title;
		for (int i = 0; i < countQuestQi; i++)
		{
			cout << "Enter" << i + 1 << "/" << countQuestQi << "quest for quiz->_";
			cin >> temp[countQuiz].quest[i].questText;
			cout << "Enter correct answer for quiz->_";
			cin >> temp[countQuiz].quest[i].trAnswer;
		}
		fout << temp[countQuiz].Title << endl;;
		for (int i = 0; i < countQuestQi; i++)
		{
			fout << temp[countQuiz].quest[i].questText << endl;
			fout << temp[countQuiz].quest[i].trAnswer << endl;
		}
			countQuiz++;
		quizes = new Quiz[countQuiz];
		for (int i = 0; i < countQuiz; i++)
		{
			quizes[i] = temp[i];
		}
		delete[]temp;
	}
	else {
		cout << "error" << endl;
	}
}

void ShowAllQuizes()
{
	if (countQuiz!=0) {
		for (int i = 0; i < countQuiz; i++)
		{
			cout << i + 1 << ". " << quizes[i].Title << endl;

		}
	}
	else {

	}
}

void passQuiz()
{
	int selectQuiz = 0;
	int score = 0;
	cout << "Enter number quiz for passing->_ ";
	cin >> selectQuiz;
	selectQuiz--;
	cout << endl;
	cout << "You started passing-" << quizes[selectQuiz].Title << endl;
	for (int i = 0; i < countQuestQi; i++)
	{
		string tempAns = "";
		cout << i + 1 << ". " << quizes[selectQuiz].quest[i].questText << endl;
		cout << "Your answer->_ ";
		cin >> tempAns;
		if (tempAns == quizes[selectQuiz].quest[i].trAnswer) {
			score += 20;
			cout << "It's true" << endl;
		}
		else {
			cout << "It's false" << endl;
		}
	}
	cout << "Your result: " << score << "/100" << endl;
}
