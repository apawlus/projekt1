#include <iostream>
#include "tab.cpp"

bool test1()
{
	//test operatorow
	
	bool test=true;
	table A(15);
	table B;
	A.fill();
	B=A;
	if((A<B)) test=false; 
	if((A>B)) test=false; 
	if(!(A<=B)) test=false; 
	if(!(A>=B)) test=false; 
	if(!(A==B)) test=false; 

	return test;
}

bool test2()
{
	table A(15);
	table B(7);
	A.fill();
	B.fill();
//Dodanie do A trzy razy elementu o indeksie 10 i wartosci 17
	A.addEl(10,17);
	A.addEl(10,17);
	A.addEl(10,17);

//Dodanie do A na poczatek elementu o wartosci 101
	A.addFront(101);
	
//Dodanie do A za element o wartosci 101 elementu o wartosci 77
	A.addElNextTo(101,77);

	if(A[12]==17 && A[13]==17 && A[14]==17 && A[0]==101 && A[1]==77) return true;
	return false;
}

bool test3()
{
	//test +  =
	table A(10);
	table B(3);
	table C;

	A.fill();
	B.addFront(10);
	B.addFront(11);
	B.addFront(12);
	
	C=(A+B);
	for(int i=0; i<A.tabSize(); i++)
		if(A[i]!=C[i]) return false;
		
	for(int i=0; i<B.tabSize(); i++)
	if(B[i] != C[i+A.tabSize()]) return false;
	
	return true;
}



bool test4()
{
	//test +=  deleteDuplicates
    table A(7);
    table B;
	A.addFront(1);
	A.addFront(2);
	A.addFront(99);
	A.addFront(188);
	A.addFront(55);
	B=A;
	A+=B;
	for(int i=0; i<B.tabSize(); i++)
	if(A[i]!=A[i+B.tabSize()]) return false;
	//Usuniecie wartosci powtarzajacych sie w tablicy A
	A.deleteDuplicates();
	if((A!=B)) return false;
	return true;
	
}

bool test5()
{
    table A(15);
    A.fill();
    table B(A);
    if(A==B) return 1;
    return 0;
}


bool test6()
{
	//test +=  -= !=
    table A(7);
    table B;
	A.fill();
	B=A;
	A+=B;
	A-=B;
	if((A!=B)) return false;
	return true;
	
}

bool test7()
{
	//test funkcji index
    table A(7);
	A.addFront(1);
	A.addFront(2);
	A.addFront(99);
	A.addFront(188);
	A.addFront(55);
	A.addEl(4,90);

	if(A.index(90)==4) return true;
	return false;
	
}

bool test8()
{
	//test funkcji del, delValue
    table A(7);
	A.fill();
	A.addEl(4,101);
	A.del(4);
	A.addFront(90);
	A.delValue(90);
	if(A[0]==90 || A[4]==101) return false;
	return true;
	
}


int main()
{
	cout<<"test"<<1<<": "<<test1()<<endl;
	cout<<"test"<<2<<": "<<test2()<<endl;
	cout<<"test"<<3<<": "<<test3()<<endl;
	cout<<"test"<<4<<": "<<test4()<<endl;
	cout<<"test"<<5<<": "<<test5()<<endl;
	cout<<"test"<<6<<": "<<test6()<<endl;
	cout<<"test"<<7<<": "<<test7()<<endl;
	cout<<"test"<<8<<": "<<test8()<<endl;
	
	return 0;
}
