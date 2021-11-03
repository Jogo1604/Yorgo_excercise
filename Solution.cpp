#include "Solution.h"

Solution::Solution(int n = 0):people(nullptr),numberPeople(n)
{
	delete []this->people;
	this->people = new Person[n];
}
Solution::Solution(const Solution& other)
{
	this->people = other.people;
	this->numberPeople = other.numberPeople;
}
Solution::~Solution()
{
	delete []this->people;
}

void Solution::insertElement(const Person& person)
{
	Person* people_buffer = new Person[numberPeople];	
	for (size_t i = 0; i < numberPeople; i++)
	{
		people_buffer[i] = this->people[i];
	}

	delete []this->people;
	this->people = new Person[numberPeople + 1];

	for (size_t i = 0; i < numberPeople; i++)
	{
		this->people[i] = people_buffer[i];
	}
	this->people[numberPeople] = person;
	delete []people_buffer;
	this->numberPeople++;
}
void Solution::deleteElement( Person& person)
{
	Person* people_buffer = new Person[this->numberPeople];
	for (size_t i = 0; i < this->numberPeople; i++)
	{	//getters return pointers, so we get their values
		//with this if, predefining operator == for Person becomes no-need
		if (*(this->people[i].getAdress()) == *(person.getAdress()) &&
			*(this->people[i].getEGN())    == *(person.getEGN()) &&
			*(this->people[i].getName())   == *(person.getName())	)
		{
			this->numberPeople--;
		}
		else
		{
			people_buffer[i] = this->people[i];
		}
	}

	delete []this->people;
	this->people = new Person[this->numberPeople];

	for (size_t i = 0; i < this->numberPeople; i++)
	{
		this->people[i]=people_buffer[i];
	}

	delete[] people_buffer;
}
void Solution::outputElements()//podredeni po azbu4en red
{
}
void Solution::writeInBinaryFile()
{

}
int Solution::countedByAdress(const char* adress)
{
	int number = 0;
	for (size_t i = 0; i < this->numberPeople; i++)
	{
		if (this->people[i].getAdress() == adress)
		{
			number++;
		}
	}
	return number;
}

std::ostream& operator<<(std::ostream& out, const Solution& soluiton)
{
	for (size_t i = 0; i < soluiton.numberPeople; i++)
	{
		out << "\nName[" << i << "]: " << soluiton.people[i].getName();
		out << "\nEGN[" << i << "]: ";

		int* p = soluiton.people[i].getEGN();
		for (size_t i = 0; i < 10; i++)
		{
			out<< *(p+i);
		}
		out << "\nAdress[" << i << "]: " << soluiton.people[i].getAdress();
	}
	return out;
}
