#pragma once
#include <iostream>
#include <string>

using namespace std;

class People { // Каким образом People связан с классом Client??????
public:
	People() {}
	virtual void addInfoKeyboard() = 0;
	virtual void addInfoFile(string filename) = 0;
	virtual void addNewObject() = 0;
	virtual void redactObject(int num) = 0;
	virtual void printObject() = 0;
	virtual void addDisease() = 0;
};