#include <iostream>
#include <istream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int menu(int &selection);
void newTask(ofstream &fout);
void deleteTask(ifstream &fin, ofstream &fout);

int main()
{
	ifstream fin;
	ofstream fout;

	int selection;
	selection = menu(selection);

	if (selection == 1)
	{
		cin.ignore();
		newTask(fout);
	}
	else if (selection == 3)
	{
		deleteTask(fin, fout);
	}

	return 0;
}

int menu(int &selection)
{
	cout << "Press 1 to create a task" << endl;
	cout << "Press 2 to view current tasks" << endl;
	cout << "Press 3 to delete a task" << endl;
	cout << "Enter your selection: ";
	cin >> selection;

	return selection;
}

void newTask(ofstream &fout)
{
	string taskName;
	string taskDesc;

	cout << "Enter the name of your new task: ";
	getline(cin, taskName);
	cout << "Enter the description for " << taskName << ": ";
	cin.clear();
	getline(cin, taskDesc);

	fout.open("tasks.dat", fstream::app);

	fout << taskName << endl;
	fout << taskDesc << endl;

	fout.close();
}

void deleteTask(ifstream &fin, ofstream &fout)
{
	string file;
	string temp;
	int delLine;
	int i = 1;

	fin.open("tasks.dat");

	while (fin)
	{
		getline(fin, file);
		cout << i << "    " << file << endl;
		getline(fin, file);
		i++;
	}
	fin.close();

	cout << "Which task would you like to delete? ";
	cin >> delLine;

	fin.open("tasks.dat");
	fout.open("temp.dat");

	i = 1;

	while (fin)
	{
		if (i == delLine + delLine - 1 || i == delLine*2)
		{
			getline(fin, temp);
			i++;
		}
		else
		{
			getline(fin, file);
			fout << file << endl;
			cout << i << endl;
			i++;
		}
	}

	fin.close();
	fout.close();

	remove("tasks.dat");
	rename("temp.dat", "tasks.dat");
}