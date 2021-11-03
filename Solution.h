#include"Person.h"
#include<vector>
class Solution
{
private:
	Person* people;
	int numberPeople;
public:
	Solution(int n);
	Solution(const Solution&);
	~Solution();

	void insertElement(const Person&);
	void deleteElement( Person&);
	void outputElements();//podredeni po azbu4en red
	void writeInBinaryFile();//not done yet
	int countedByAdress(const char*);

	friend std::ostream& operator<<(std::ostream&, const Solution&);
};

