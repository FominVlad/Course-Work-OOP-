#include <iostream>
#include "registry.h"

#include "patient.h"
#include "doctor.h"
#include "people.h"

using namespace std;

int main() {
	/*Registry& test1 = Registry::initialize();

	test1.readNoteList();
	test1.search("Donka P.A.");
	test1.printDoctorNotesList();*/
	
	/*People *test = new Patient();
	test->addInfoFile("8");
	test->printObject();
	cout << "================\n";
	test->redactObject(1);
	test->printObject();*/

	People *test = new Doctor();
	test->addInfoFile("McCalisterSurgeon");
	test->printObject();
	test->redactObject(1);
	test->printObject();
	

	return 0;
}