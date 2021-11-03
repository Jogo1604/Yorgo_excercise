#ifndef PERSON_H
#define PERSON_H

#include<iostream>
#include<fstream>

class Person
{
private:
	char* name;
	int egn[10];
	char* adress;
public:
	Person();
	Person(const Person&);
	~Person();

	//GETters
	char* getName();
	int* getEGN();
	char* getAdress();

	//SETters
	void setName(const char*);
	void setEGN(int*);
	void setAdress(const char*);
	
	//operators
	Person& operator= (const Person&);
	friend std::ostream& operator <<(std::ostream&,const Person&);
};


#endif // !PERSON_H