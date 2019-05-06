#include <iostream>
#include "people.h"
#include <fstream>
#include <string>
#include <cstdlib>
#include <list>
#include <cstdio>

using namespace std;

class Doctor:public People {
private:
	//----Информация о докторе----
	string surname;
	string name;
	string patronymic;
	string speciality;
	string cabinet;
	string phoneNumber;
public:
	Doctor() {} // Конструктор для ввода информации с клавиатуры
	
	void addInfoKeyboard() {
		cout << "Input info:\n";
		cout << "Input surname: ";
		getline(cin, surname);
		cout << "Input name: ";
		getline(cin, name);
		cout << "Input patronymic: ";
		getline(cin, patronymic);
		cout << "Input speciality: ";
		getline(cin, speciality);
		cout << "Input cabinet: ";
		getline(cin, cabinet);
		cout << "Input phoneNumber: ";
		getline(cin, phoneNumber);
	};

	void addInfoFile(string filename) {
		filename = "doctors/" + filename + ".txt";
		ifstream file;
		file.open(filename);
		if (!file.is_open()) {
			cout << "Error opening file! (addInfoFile)\n";
		}
		else {
			list <string> tmp;
			string tmpStr;
			while (!file.eof()) {
				file >> tmpStr;
				tmp.push_back(tmpStr);
			}
			file.close();
			auto it = tmp.begin();
			surname = *it;
			it++;
			name = *it;
			it++;
			patronymic = *it;
			it++;
			speciality = *it;
			it++;
			cabinet = *it;
			it++;
			phoneNumber = *it;
		}
	};

	void addNewObject() {
		ifstream file;
		string idFile = "doctors/" + this->surname + this->speciality + ".txt";
		file.open(idFile);
		if (!file.is_open()) {
			ofstream file;
			file.open(idFile);

			if (!file.is_open()) {
				cout << "Error opening file! (addNewObject)\n";
			}
			else {
				file << this->surname + "\n";
				file << this->name + "\n";
				file << this->patronymic + "\n";
				file << this->speciality + "\n";
				file << this->cabinet + "\n";
				file << this->phoneNumber + "\n";
			}
		}
		else {
			cout << "Doctor is already registered.\n";
		}
	};

	void redactObject(int num) {
		string filename = "doctors/" + surname + speciality + ".txt";
		const char * cFilename = filename.c_str();

		switch (num) {
			case 1: {
				cout << "Input new surname: ";
				getline(cin, surname);
				break;
			}
			case 2: {
				cout << "Input new name: ";
				getline(cin, name);
				break;
			}
			case 3: {
				cout << "Input new patronymic: ";
				getline(cin, patronymic);
				break;
			}
			case 4: {
				cout << "Input new speciality: ";
				getline(cin, speciality);
				break;
			}
			case 5: {
				cout << "Input new cabinet: ";
				getline(cin, cabinet);
				break;
			}
			case 6: {
				cout << "Input new phoneNumber: ";
				getline(cin, phoneNumber);
				break;
			}
			default: {
				cout << "Error. Undefined key.\n";
				break;
			}
		}

		if (num == 1 || num == 4) {
			if (remove(cFilename) != 0) {
				perror("File deletion failed");
			}
			else {
				cout << "File deleted successfully";
			}
			addNewObject();
		}
		else {
			string idFile = "doctors/" + this->surname + this->speciality + ".txt";
			ofstream file;
			file.open(idFile);

			if (!file.is_open()) {
				cout << "Error opening file! (addNewObject)\n";
			}
			else {
				file << this->surname + "\n";
				file << this->name + "\n";
				file << this->patronymic + "\n";
				file << this->speciality + "\n";
				file << this->cabinet + "\n";
				file << this->phoneNumber + "\n";
			}
		}
	};
	
	void printObject() {
		cout << "Surname:" << this->surname << endl <<
			"Name: " << this->name << endl <<
			"Patronymic: " << this->patronymic << endl <<
			"Ident. number: " << this->speciality << endl <<
			"Date of birth: " << this->cabinet << endl <<
			"Phone number: " << this->phoneNumber << endl;
	};
	
	void addDisease() {};
};