#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <vector>

using namespace std;

struct Note {
private:
	string date; // Дата записи
	string patientName; // Фамилия и инициалы
	string bookNumber; // номер книжки пациента
	string doctorName; // Фамилия и инициалы
public:
	void setDate(string date) {
		this->date = date;
	}
	void setPatientName(string patientName) {
		this->patientName = patientName;
	}
	void setBookNumber(string bookNumber) {
		this->bookNumber = bookNumber;
	}
	void setDoctorName(string doctorName) {
		this->doctorName = doctorName;
	}
	string getDate() {
		return date;
	}
	string getPatientName() {
		return patientName;
	}
	string getBookNumber() {
		return bookNumber;
	}
	string getDoctorName() {
		return doctorName;
	}
};

class Registry {
private:
	list <Note> notes;
	string fileName = "registry.txt";
	list <Note> doctorNotesList; // список искомых записей определённого доктора

	Registry() = default;
	~Registry() = default;

	Registry(const Registry&) = delete;
	Registry& operator=(const Registry&) = delete;

	void* operator new(std::size_t) = delete;
	void* operator new[](std::size_t) = delete;

	void operator delete(void*) = delete;
	void operator delete[](void*) = delete;
public:
	static Registry& initialize() {
		static Registry obj;
		return obj;
	}

	void addNote() {
		Note tmp;
		string tmpS;
		
		cout << "Input date: ";
		getline(cin, tmpS);
		tmp.setDate(tmpS);
		cout << "Input patient name: ";
		getline(cin, tmpS);
		tmp.setPatientName(tmpS);
		cout << "Input book number: ";
		getline(cin, tmpS);
		tmp.setBookNumber(tmpS);
		cout << "Input doctor name: ";
		getline(cin, tmpS);
		tmp.setDoctorName(tmpS);
		
		ofstream file;
		file.open(fileName, ofstream::app);
		if (!file.is_open()) {
			cout << "Error opening file! (Registry::addNote)\n";
		}
		else {
			file << tmp.getDate() + "|" + tmp.getPatientName() + "|" +
				tmp.getBookNumber() + "|" + tmp.getDoctorName() + "\n";
		}
	}

	void readNoteList() {
		ifstream file;
		file.open(fileName);
		if (!file.is_open()) {
			cout << "Error opening file! (Registry::printNoteList)\n";
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

			for (int i = 0; i < tmp.size()-1; i++) { // -1 пото му что в файле последння строка пустая
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
				
				Note tmpNote;
				auto iter = tmpVec.begin();
				tmpNote.setDate(*iter);
				iter++;
				tmpNote.setPatientName(*iter);
				iter++;
				tmpNote.setBookNumber(*iter);
				iter++;
				tmpNote.setDoctorName(*iter);

				notes.push_back(tmpNote);
			}
		}
	}

	void printNoteList() {
		auto it = notes.begin();
		Note tmp;
		for (int i = 0; i < notes.size(); i++) {
			tmp = *it;
			cout << tmp.getDate() << " | " << tmp.getPatientName() << " | " <<
				tmp.getBookNumber() << " | " << tmp.getDoctorName() << endl;
			it++;
		}
	}

	void search(string doctorName) {
		auto it = notes.begin();
		Note tmp;
		for (int i = 0; i < notes.size(); i++) {
			tmp = *it;
			if (tmp.getDoctorName() == doctorName) {
				doctorNotesList.push_back(tmp);
			}
			it++;
		}
	}

	void printDoctorNotesList() {
		auto it = doctorNotesList.begin();
		Note tmp;
		for (int i = 0; i < doctorNotesList.size(); i++) {
			tmp = *it;
			cout << tmp.getDate() << " | " << tmp.getPatientName() << " | " <<
				tmp.getBookNumber() << " | " << tmp.getDoctorName() << endl;
			it++;
		}
	}
};