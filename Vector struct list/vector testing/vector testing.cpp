#include <iostream>
#include <Windows.h>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

struct Student {
	string name;
	string lastname;
	string album_id;

	Student() {
		name = "NULL";
		lastname = "NULL";
		album_id = "0";
	}
};

void addStudent(vector<Student>& vec);
void removeStudent(vector<Student>& vec);
void addData(vector<Student>& vec, int& i);
void showList(vector<Student>& vec);
void fileManipulation(vector<Student>& vec);
int menu();


int main()
{
	vector<Student> v;
	int i = 0;

	while (1) {
		int choice=menu();
		switch (choice) {
		case 1: addStudent(v); addData(v, i); break;
		case 2: removeStudent(v); break;
		case 3: fileManipulation(v); break;
		case 4: exit(0); break;

		}
		showList(v);
	}
}

void addStudent(vector<Student>& vec) {
	vec.push_back(Student());
}

void removeStudent(vector<Student>& vec) {
	if (vec.size() == 0) return;
	vec.pop_back();
}


void addData(vector<Student>& vec ,int& i) {
	string name;
	string last;
	string id;

	cout << "type in name : ";
	cin >> name;
	system("cls");
	cout << "type in last name : ";
	cin >> last;
	system("cls");
	cout << "type in album id : ";
	cin >> id;
	
	vec[i].name = name;
	vec[i].lastname = last;
	vec[i].album_id = id;

	i++;
}

void showList(vector<Student>& vec) {
	system("cls");
	cout << "student list : "<<endl;
	for (auto& a : vec) {
		cout << a.name << " "<<a.lastname<<" "<< a.album_id << endl;
	}
}

int menu() {
	int c = NULL;
	cout << "-----------------" << endl;
	cout << "1. add student" << endl;
	cout << "2. remove student" << endl;
	cout << "3. fileManipulation" << endl;
	cout << "4. exit" << endl;
	cout << "-----------------" << endl;
	cout << "choose action : " << endl;
	cin >> c;
	system("cls");
	if(c ==1 || c==2 || c==3 || c==4)
	return c;
}

void fileManipulation(vector<Student>& vec) {
	int choice = 0;
	int line_id = 0;
	string line = "";

	string name="####";
	string lastname="####";
	string album_id="0";

	fstream file;

	cout << "1. load from file" << endl;
	cout << "2. save to file" << endl;
	cout << "3. cancel" << endl;
	cout << "choose option : ";
	cin >> choice;

	switch (choice) {
	case 1: 
		file.open("load.txt",ios::in);
		while (getline(file, line)) {
			switch (line_id%3){
				case 0: addStudent(vec);
						name = line; break;
				case 1: lastname = line; break;
				case 2: album_id = line; break;
			}
			if (line_id % 3 == 0) vec[vec.size() - 1].name = name;
			if (line_id % 3 == 1) vec[vec.size() - 1].lastname = lastname;
			if (line_id % 3 == 2) vec[vec.size() - 1].album_id = album_id;
			line_id++;
		}
		file.close();
		break;
	case 2:
		file.open("save.txt",ios::out);
		for (auto& a : vec) {
			file << a.name << " " << a.lastname << " " << a.album_id << endl;
		}
		file.close();
		break;
	case 3: break;
	}
}