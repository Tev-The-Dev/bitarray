//   bitarray.cpp
//Tevyn Payne
//Object Oriented 3330 secton 7
//   BitArray class definition

//private:
//unsigned char* barray;		   // pointer to the bit array
//int arraySize;


#include <cstring>
#include <iostream>
#include "bitarray.h"

using namespace std;



ostream& operator<< (ostream& os, const BitArray& a)
{
	os << "(";
	for(int i = 0; i < a.arraySize; i++)
	{
		if (a.barray[i] & 0b10000000) 
			os << '1' ;
		else
			os << '0' ;

		if (a.barray[i] & 0b01000000) 
			os << '1' ;
		else
			os << '0' ;

		if (a.barray[i] & 0b00100000) 
			os << '1' ;
		else
			os << '0' ;

		if (a.barray[i] & 0b00010000) 
			os << '1' ;
		else
			os << '0' ;

		if (a.barray[i] & 0b00001000) 
			os << '1' ;
		else
			os << '0' ;

		if (a.barray[i] & 0b00000100) 
			os << '1' ;
		else
			os << '0' ;

		if (a.barray[i] & 0b00000010) 
			os << '1' ;
		else
			os << '0' ;

		if (a.barray[i] & 0b00000001) 
			os << '1' ;
		else
			os << '0' ;
	}
	os << ")" << endl;
}

bool operator== (const BitArray& str1, const BitArray& str2)
{

	if(str1.arraySize == str2.arraySize) 
	{
		for(int i = 0; i < str1.arraySize; i++)
		{
			if(str1.barray[i] != str2.barray[i])
				return false;
		}

		return true;
	}
	else 
		return false;
}

bool operator!= (const BitArray& str1, const BitArray& str2)
{
	if(str1 == str2)
		return false;
	else
		return true;

}

BitArray::BitArray(unsigned int n)    // Construct an array that can handle n bits
{

								
	int multiplier = n / size_in_bits;

	if(n % size_in_bits > 0)
	{
		multiplier += 1;
	}

	arraySize = multiplier * size;   

	// cout << "Create BitArray of size: " << n << endl;
	// cout << "  multiplier: " << multiplier << endl;
	// cout << "  unsigned char size:: " << size << endl;
	// cout << "  BitArray length:: " << arraySize << endl;


	barray  = new unsigned char[arraySize];	
	for(int i = 0; i < arraySize; i++)
		barray[i] = 0;

}

BitArray::BitArray(const BitArray& incoming)   // copy constructor
{
	arraySize = incoming.arraySize;
	
	barray  = new unsigned char[arraySize];	

	for(int i = 0; i < arraySize; i++)
		barray[i] = incoming.barray[i];
}

BitArray::~BitArray()                 // destructor
{
	delete [] barray;
}

BitArray& BitArray::operator= (const BitArray& a)  // assignment operator
{
	
   if (this != &a)		// only make the copy if the original is
   {				//  not this same object

		// first, delete the existing array
		delete [] barray;

		// now do the copy.  Same way we did copy constructor
		arraySize = a.arraySize;
		barray = new unsigned char[arraySize];
		for (int i = 0; i < arraySize; i++)
			barray[i] = a.barray[i];
	}

	return *this;		// return this object
}

unsigned int BitArray::Length() const            // return number of bits in bitarray
{
	return arraySize * size_in_bits;
}

void BitArray::Set   (unsigned int index)        // set bit with given index to 1
{
	if(index > size_in_bits * arraySize)
		return;					//cant flip a bit out of array bounds
	int byte = index / size_in_bits;
	int bit = index % size_in_bits;
//	barray[byte] = barray[byte] | (0x80 >> bit); 
	barray[byte] = barray[byte] | (1 <<( size_in_bits - bit -1)); 
}

void BitArray::Unset (unsigned int index)        // set bit with given index to 0
{
	if(index > size_in_bits * arraySize)
		return;					//cant flip a bit out of array bounds
	int byte = index / size_in_bits;
	int bit = index % size_in_bits;
//	barray[byte] = barray[byte] | (0x80 >> bit); 
	barray[byte] = barray[byte] & ~(1 <<( size_in_bits - bit -1)); 



}

void BitArray::Flip  (unsigned int index)        // change bit (with given index)
{
	if(index > size_in_bits * arraySize)
		return;					//cant flip a bit out of array bounds
	int byte = index / size_in_bits;
	int bit = index % size_in_bits;
//	barray[byte] = barray[byte] | (0x80 >> bit); 
	barray[byte] = barray[byte] ^ (1 <<( size_in_bits - bit -1)); 

}

bool BitArray::Query (unsigned int index) const  // return true if the given bit is set to 1, false otherwise
{
	//cant flip a bit out of array bounds
	if(index > size_in_bits * arraySize)
		return false;					

	int byte = index / size_in_bits;
	int bit = index % size_in_bits;
	if(barray[byte] & (1 <<( size_in_bits - bit -1)))
		return true;
	else
		return false;

}

