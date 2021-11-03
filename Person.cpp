#include "Person.h"
#pragma warning(disable  : 4996)//VS counts strcpy for unsafe function and thus we ignore the warning

Person::Person() :name(0), egn{0},adress(0)
{}
Person::Person(const Person& other)
{
	delete []this->name;
	this->name = new char[strlen(other.name)+1];
	strcpy(this->name, other.name);
	this->name[strlen(other.name)] = '\0';

	for (size_t i = 0; i < 10; i++)
	{
		this->egn[i] = other.egn[i];
	}

	delete []this->adress;
	this->adress = new char[strlen(other.adress) + 1];
	strcpy(this->adress, other.adress);
	this->adress[strlen(other.adress)] = '\0';
}
Person::~Person()
{//egn is int array with built-in deconstructor, so no need to delete it here
	delete []this->name;
	delete []this->adress;
}

char* Person::getName()
{
	return this->name;
}
int* Person::getEGN()
{
	return this->egn;
}
char* Person::getAdress()
{
	return this->adress;
}

//SETters
void Person::setName(const char* new_name)
{
	delete this->name; 
	this->name = new char[strlen(new_name) + 1];
	strcpy(this->name, new_name);
	this->name[strlen(new_name)] = '\0';
}
void Person::setEGN(int* new_egn)
{
	for (size_t i = 0; i < 10; i++)
	{
		this->egn[i] = new_egn[i];
	}
}
void Person::setAdress(const char* new_adress)
{
	delete this->adress;
	this->adress = new char[strlen(new_adress) + 1];
	strcpy(this->adress, new_adress);
	this->adress[strlen(new_adress)] = '\0';
}

Person& Person::operator= (const Person& other)
{//calling the copy constructor
	this->Person::Person(other);
	return *this;
}
std::ostream& operator <<(std::ostream& out, const Person& person)
{
	out << "\nName: " << person.name;
	out << "\nEGN: ";
	for (size_t i = 0; i < 10; i++)
	{
		out << person.egn[i];
	}
	out<<"\nAdress: " << person.adress << '\n';
	return out;
}
