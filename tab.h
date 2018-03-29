#ifndef TAB_H_INCLUDED
#define TAB_H_INCLUDED

#include <iostream>
using namespace std;
class table
{
	int size;
	int capacity;
	int* numbers;
	public:
	table();
	table(int);
	table(table&);
	~table();
	void addFront(int);
	void addEl(int indeks,int number);
	void addElNextTo(int value,int number);
	void fill();
	void del(int);
	void delValue(int);
	void delValue(int,int);
	int& operator[](int);
	int index(int value);


	int tabSize();
	int tabCapacity();

	table operator+(const table& b);
	table operator-(const table& b);

	table& operator+=(const table& b );
	table& operator-=(const table& b );

	bool operator==(const table& b );
	bool operator!=(const table& b );

	bool operator<(const table& b );
	bool operator>(const table& b );

	bool operator<=(const table& b );
	bool operator>=(const table& b );

	table& operator=(const table & v);
	

	void deleteDuplicates();

	friend ostream& operator<<(ostream& out, const table& z);

};
#endif
