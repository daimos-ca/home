#pragma once
#include<iostream>
#include<string>
using namespace std;
struct Quest
{
	string questText;
	string trAnswer;
};
struct Quiz
{
	string Title;
	Quest quest[5];
};
void insertQuiz(Quiz getQuiz);
void init();
void addQuiz();
void ShowAllQuizes();
void passQuiz();