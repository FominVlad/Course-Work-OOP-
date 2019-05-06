#include <iostream>
#include "people.h"
#include "disease.h"
#include <fstream>
#include <string>
#include <list>
#include <cstdlib>
#include <vector>

using namespace std;

class Patient:public People {
private:
	//----Информация о пациенте-----

	string surname;
	string name;
	string patronymic;
	string identNum;
	string dateOfBirth;
	string registration; // Прописка
	string id; // Номер медицинской книги
	string phoneNumber;

	//----Хранение болезней---
	list <Disease> disease;

public:
	void addInfoKeyboard() {
		cout << "Input info:\n";
		cout << "Input surname: ";
		getline(cin, surname);
		cout << "Input name: ";
		getline(cin, name);
		cout << "Input patronymic: ";
		getline(cin, patronymic);
		cout << "Input identNum: ";
		getline(cin, identNum);
		cout << "Input dateOfBirth: ";
		getline(cin, dateOfBirth);
		cout << "Input registration: \n";
		getline(cin, registration);
		cout << "Input phoneNumber: ";
		getline(cin, phoneNumber);
		cout << "Input id: ";
		getline(cin, id);
	}

	void addInfoFile(string filename) {
		filename = "patients/" + filename + ".txt";
		ifstream file;
		file.open(filename);
		if (!file.is_open()) {
			cout << "Error opening file!\n";
		}
		else {
			list <string> tmp;
			string tmpStr;
			while (!file.eof()) {
				getline(file, tmpStr, '\n');
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
			identNum = *it;
			it++;
			dateOfBirth = *it;
			it++;
			registration = *it;
			it++;
			phoneNumber = *it;
			it++;
			id = *it;
			it++;


			int tmpLen = tmp.size() - 8;
			for (int i = 0; i < tmpLen; i++) {
				vector <string> tmpVec;

				string s = *it;
				it++;
				
				string delimiter = "|";

				size_t pos = 0;
				string token;
				while ((pos = s.find(delimiter)) != string::npos) {
					token = s.substr(0, pos);
					tmpVec.push_back(token);
					s.erase(0, pos + delimiter.length());
				}
				tmpVec.push_back(s);
				
				Disease tmpDis;
				auto iter = tmpVec.begin();
				tmpDis.setDate(*iter);
				iter++;
				tmpDis.setDoctorName(*iter);
				iter++;
				tmpDis.setDiseaseName(*iter);
				iter++;
				tmpDis.setComment(*iter);

				disease.push_back(tmpDis);
			}
		}
	}
	
	void addNewObject() {
		ifstream file;
		id = this->id;
		string idFile = "patients/" + id + ".txt";
		file.open(idFile);
		if (!file.is_open()) {
			ofstream file;
			file.open(idFile);

			if (!file.is_open()) {
				cout << "Error opening file!!!!\n";
			}
			else {
				file << this->surname + "\n";
				file << this->name + "\n";
				file << this->patronymic + "\n";
				file << this->identNum + "\n";
				file << this->dateOfBirth + "\n";
				file << this->registration + "\n";
				file << this->phoneNumber + "\n";
				file << this->id + "\n";
			}
		}
		else {
			cout << "The patient is already registered.\n";
		}
	}

	void addDisease() {
		ofstream file;
		id = "patients/" + id + ".txt";
		file.open(id, ofstream::app);

		if (!file.is_open()) {
			cout << "Error opening file!!!!\n";
		}
		else {
			Disease newDisease;
			file << newDisease.getDate() + "|" + newDisease.getDoctorName() +
				"|" + newDisease.getDiseaseName() + "|" + newDisease.getComment();
		}
	}

	void printObject() {
		cout << "Surname:" << this->surname << endl <<
			"Name: " << this->name << endl <<
			"Patronymic: " << this->patronymic << endl <<
			"Ident. number: " << this->identNum << endl <<
			"Date of birth: " << this->dateOfBirth << endl <<
			"Registration: " << this->registration << endl <<
			"Phone number: " << this->phoneNumber << endl <<
			"ID: " << this->id << endl;

		auto it = disease.begin();
		Disease tmp;
		for (int i = 0; i < disease.size(); i++) {
			tmp = *it;
			cout << tmp.getDate() << " | " << tmp.getDoctorName() << " | " << tmp.getDiseaseName()
				<< " | " << tmp.getComment() << endl;
			it++;
		}
	}

	void redactObject(int num) {
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
				cout << "Input new identNum: ";
				getline(cin, identNum);
				break;
			}
			case 5: {
				cout << "Input new dateOfBirth: ";
				getline(cin, dateOfBirth);
				break;
			}
			case 6: {
				cout << "Input new registration: \n";
				getline(cin, registration);
				break;
			}
			case 7: {
				cout << "Input new phoneNumber: ";
				getline(cin, phoneNumber);
				break;
			}
			default: {
				cout << "Error. Undefined key.\n";
				break;
			}
		}
		
		string idFile = "patients/" + id + ".txt";
		ofstream file;
		file.open(idFile);

		if (!file.is_open()) {
			cout << "Error opening file!!!!\n";
		}
		else {
			file << this->surname + "\n";
			file << this->name + "\n";
			file << this->patronymic + "\n";
			file << this->identNum + "\n";
			file << this->dateOfBirth + "\n";
			file << this->registration + "\n";
			file << this->phoneNumber + "\n";
			file << this->id + "\n";
		}

		auto it = disease.begin();
		for (int i = 0; i < disease.size(); i++) {
			Disease tmp = *it;
			file << tmp.getDate() << "|" << tmp.getDoctorName() << "|" << tmp.getDiseaseName()
				<< "|" << tmp.getComment() << endl;
			it++;
		}
	}
};