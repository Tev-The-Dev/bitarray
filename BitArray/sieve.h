//Tevyn Payne
//COP 3330 section 7
//declaration and definitions of the sieve funtion
#include <cmath>
#include "bitarray.h"


using namespace std;

void Sieve(BitArray&);
int find_next_uncleared_bit(BitArray&, int);
void clear_multiples(BitArray&, int);
void Sieve(BitArray& ba)
{
	for(int i = 0; i < ba.Length(); i++)
		ba.Set(i);

//	cout << "Original BitArray:" << endl;
//	cout << ba << endl;

	ba.Unset(0);
	ba.Unset(1);

//	cout << "Unset(0), Unset(1)"<< endl;
//	cout << ba << endl;

	int next = find_next_uncleared_bit(ba, 1);
//	cout << "Next uncleared bit is " << next << endl;

	clear_multiples(ba, next);
//	cout << "Clear multiples of " << next << endl;

	int stop = ceil( sqrt(ba.Length()));

	while( next < stop)
	{
//		cout << "LOOP Clear multiples of " << next << endl;
		clear_multiples(ba, next);
//		cout << ba << endl << endl;

		next = find_next_uncleared_bit(ba, next);
//		cout << "LOOP Next uncleared bit is " << next << endl;

	}
}

int find_next_uncleared_bit(BitArray & ba,int x)
{
	for(int i = x+1; i < ba.Length(); i++)
	{
		if(ba.Query(i))
		return i;

	}

}

void clear_multiples(BitArray& ba, int x)
{

	int multiple = x;
	for(int i = 2; multiple * i  < ba.Length(); i++)
	{
		ba.Unset(x * i);

	}

}
