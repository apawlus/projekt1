#include <iostream>
#include <cstdlib>
#include "tab.h"
#include <time.h>

table::table() {
	capacity=0;
	size=0;
}

table::table(int b) {
	if(b<0) b=0;
	size=0;
	capacity=b;
	numbers = new int[b];   //utworzenie tablicy o pojemnosci b i liczbie elementow 0
}

table::table(table& tableCopy){
	
	size=tableCopy.size;
	capacity=tableCopy.capacity;
	numbers = new int[capacity];
    for (unsigned int i = 0; i < size; i++)
        numbers[i] = tableCopy.numbers[i];
}

int table::tabSize()
{
    return size;
}

int table::tabCapacity(){
    return capacity;
}

table::~table() {
	size=0;
	capacity=0;
    delete[] numbers;
}

table& table::operator=(const table & v)
{
    if(*this==v) return *this;
    if(size>0) delete[] numbers;
    size = v.size;
    capacity=v.capacity;
    numbers = new int [size];
    for (unsigned int i = 0; i < size; i++)
        numbers[i] = v.numbers[i];
    return *this;
}

void table::addEl(int indeks,int number){
	if(indeks>size){
		return;									//dodanie elementu w miejsce o danym indeksie
	}

    if(indeks<0){
		return;									//dodanie elementu w miejsce o danym indeksie
	}

	if( capacity == 0){
		numbers=new int[1];
		numbers[0]= number;
		capacity=1;
		size=1;
		return;
	}

    if (size == capacity) {			//kiedy brakuje miejsca w tablicy, zwiekszamy jej pojemnosc dwukrotnie

    int * newTable;
	capacity*=2;
	newTable = new int[capacity];
	size++;
	for (int i = 0; i < indeks; i++)
        newTable[i] = numbers[i];
    newTable[indeks] = number;

	for (int i = indeks; i < size; i++)
        newTable[i+1] = numbers[i];
    delete[] numbers;
    numbers = newTable;
    }
    else{
		for (int i = size; i >indeks; i--)
	        numbers[i] = numbers[i-1];
	    numbers[indeks] = number;
	    size++;
	}
}

void table::addElNextTo(int value,int number){
	int a;
	a=this->index(value);
	a++;
	this->addEl(a,number);
}

void table::del(int i){
	if(i<0) return;			//usuniecie elementu o danym indeksie, o ile taki istnieje
	if(i>=size) return;
	for(i; i < size ; i++)
	   	numbers[i] = numbers[i+1];
	size--;
}

void table::delValue(int v){
	int k=0;						//usuniecie elementu o elementow o danej wartosci
	for(int i=0; i < size ; i++){
		while(numbers[i+k]==v){
			k++;
			size--;
		}
	   	numbers[i] = numbers[i+k];
		}
}

void table::delValue(int a,int b){
	int k=0;							//usuniecie elementow o watosciach z przedzialu <a,b>
	if (a>b) return;
	for(int i=0; i < size ; i++){
		while(numbers[i+k]<=b && numbers[i+k]>=a){
			k++;
			size--;
		}
	   	numbers[i] = numbers[i+k];
		}
}

bool table::operator==(const table& b ){
	if(size != b.size) return 0;			//obiekty sa rowne, gdy kazde dwa elementy tablicy o tym samym indeksie sa rowne

	for(int i=0; i<size; i++)
	if(numbers[i] != b.numbers[i]) return 0;

	return 1;

}

bool table::operator!=(const table& b ){
	if(size == b.size)						//obiekty sa rozne, gdy nie sa rowne
	{
		for(int i=0; i<size; i++)
		if(numbers[i] != b.numbers[i]) return 1;
	}
	else return 1;
	return 0;

}

bool table::operator>(const table& b ){
	if(size>b.size) return 1;			//obiekty sa porownywane, jak liczby w systemie liczbowym o podstawie INT_MAX
	if(size<b.size) return 0;

	for(int i=0; i< size; i++)
	{
		if(numbers[i] > b.numbers[i]) return 1;
		if(numbers[i] < b.numbers[i]) return 0;
	}
	return 0;
}

bool table::operator<(const table& b ){
	if(size>b.size) return 0;
	if(size<b.size) return 1;

	for(int i=0; i< size; i++)
	{
		if(numbers[i] > b.numbers[i]) return 0;
		if(numbers[i] < b.numbers[i]) return 1;
	}
	return 0;
}

bool table::operator<=(const table& b ){
	if(size>b.size) return 0;
	if(size<b.size) return 1;

	for(int i=0; i< size; i++)
	{
		if(numbers[i] > b.numbers[i]) return 0;
		if(numbers[i] < b.numbers[i]) return 1;
	}
	return 1;
}


bool table::operator>=(const table& b ){
	if(size>b.size) return 1;
	if(size<b.size) return 0;

	for(int i=0; i< size; i++)
	{
		if(numbers[i] > b.numbers[i]) return 1;
		if(numbers[i] < b.numbers[i]) return 0;
	}
	return 1;
}

void table::fill(){
	srand(time(NULL));
	for(int i=0; i < capacity; i++)		//wypelnienie calej tablicy losowymi liczbami
	{
		numbers[i] = rand() % 100;
	}
	size=capacity;
}

void table::addFront(int a){
	addEl(0,a);
}


table table::operator+(const table& b ){
	table c;
	c=*this;
	for(int i=0; i<b.size; i++)
	{
		c.addEl(size+i,b.numbers[i]);
	}
	return c;
}


table table::operator-(const table& b ){
	table c(size);
	c=*this;
	for(int i=0; i<b.size; i++)
	{
		for(int j=0; j<c.size; j++)
		{
			if(c.numbers[j]== b.numbers[i])
			{
				c.del(j);
				break;
			}
		}
	}
	return c;
}



table& table::operator+=( const table& b ){
	for(int i=0; i<b.size; i++)
	{
		addEl(size,b.numbers[i]);
	}
	return *this;
}

table& table::operator-=( const table& b ){

	for(int i=0; i<b.size; i++)
	{
		for(int j=0; j<size; j++)
		{
			if(numbers[j]== b.numbers[i])
			{
				del(j);
				break;
			}
		}
	}
	return *this;
}

ostream& operator<<( ostream& out, const table& z ){
	for(int i=0; i<z.size; i++)
	out << z.numbers[i]<<" ";
	out<<endl;
	return out;
}

int& table::operator[](int i){
	if(i>=size || i<0) ;
	return numbers[i];
}

void table::deleteDuplicates(){
	int * newTable;					//usuniecie wartosci powtarzajacych sie w tablicy
	newTable = new int[capacity];
	int k=0;
	bool check;
	for (int i = 0; i < size; i++)
	{
		check=1;
		for(int j=0; j<k; j++)
		{
			if(newTable[j]==numbers[i])
			{
				check=0;
				break;
			}
		}
        if(check==1)
		{
			newTable[k] = numbers[i];
			k++;
		}
	}
    delete[] numbers;
    numbers = newTable;
    size=k;
}

int table::index(int value){
	int k=0;					//zwrocenie najmniejszego indeksu elementu o podanej wartosci
	for(int i=0; i < size ; i++){
		if(numbers[i]== value) return i;
	}
	return -2;
}


