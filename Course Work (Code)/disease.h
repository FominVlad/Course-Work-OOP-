#include <iostream>
#include <string>

using namespace std;

class Disease {
private:
	string date;
	string doctorName;
	string diseaseName;
	string comment;
public:
	void addNewObject() {
		cout << "\nInput date: ";
		getline(cin, date);
		cout << "Input doctorName: ";
		getline(cin, doctorName);
		cout << "Input diseaseName: ";
		getline(cin, diseaseName);
		cout << "Input comment: ";
		getline(cin, comment);
	}

	void setDate(string date) {
		this->date = date;
	}
	void setDoctorName(string doctorName) {
		this->doctorName = doctorName;
	}
	void setDiseaseName(string diseaseName) {
		this->diseaseName = diseaseName;
	}
	void setComment(string comment) {
		this->comment = comment;
	}

	string getDate() {
		return date;
	}
	string getDoctorName() {
		return doctorName;
	}
	string getDiseaseName() {
		return diseaseName;
	}
	string getComment() {
		return comment;
	}
};