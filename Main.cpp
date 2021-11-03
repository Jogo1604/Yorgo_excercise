#include "Person.h"
#include"Solution.h"

int main()
{
	//unit testing
	int egn[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 }, egn2[10] = { 0,9,8,7,6,5,4,3,2,1 };
	Person person;
	person.setName("Gosho");
	person.setEGN(egn);
	person.setAdress("ul. GEorgi Kirkov");

	Person person2(person);
	person2.setName("Ferit");
	person2.setEGN(egn2);
	person2.setAdress("ul. Atanas Ishirkov");

	Solution sol(2);
	Solution sol2(0);

	sol2.insertElement(person);
	sol2.insertElement(person2);

	std::cout << sol2;
		

}