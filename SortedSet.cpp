#include "SortedSet.h"
#include "SortedSetIterator.h"


SortedSet::SortedSet(Relation r) {
	//TODO - Implementation
	//creates a new empty set where the elements will be sorted based on the relation
	//Complexity Theta(1) in all cases AC,WC,BC 
	length = 0;
	elem_dy = new TComp[capacity]();
	capacity = 25;
	relation = r;
}

void SortedSet::resize()
{
	//total complexity Theta(n), Theta(n) stayes the same in AC,WC,BC
	TComp* newData = new TComp[capacity * 2]();

	for (unsigned int i = 0; i < length; i++)
		newData[i] = elem_dy[i];

	capacity = 2 * capacity;
	delete[] elem_dy;
	elem_dy = newData;
}


bool SortedSet::add(TComp elem) { 
	//the position where it should go based on the relation
	//TODO - Implementation
	//Complexity WC,AC Theta(n) & BC Theta(1) =>Total Complexity O(n)
	
	if (search(elem))
		return false; //if the element is already in the set

	if (length == capacity) {
		// double the capacity
		resize();
	}

	int poz = 0;
	for (int i = 0; i < length; i++)
	{
		if (relation(elem_dy[i], elem))
			poz = i + 1;
		else
			break;
	}
	for (int i = length; i > poz; i--)
		elem_dy[i] = elem_dy[i - 1];

	elem_dy[poz] = elem;
	length++;

	return true;
}


bool SortedSet::remove(TComp elem) {
	//TODO - Implementation
	//Complexity WC, AC (not sure for AC) Theta(log n) & BC Theta(1) =>Total Complexity O(log n)
	if(!search(elem)) //the elem to be deleted doesn't exist in the set
		return false;

	int assumption = 0;
	int l = 0;
	int r = length - 1;
	int m;

	while (l <= r)
	{
		m = (l + r) / 2;
		if (elem_dy[m] == elem)
		{
			assumption = 1;
			break;
		}
		else if (relation(elem_dy[m], elem))
			l = m + 1;
		else
			r = m - 1;
	}
	for (int i = m; i < length - 1; i++)
		elem_dy[i] = elem_dy[i + 1];

	length = length - 1;
	if(assumption==1)
		return true;
}


bool SortedSet::search(TElem elem) const 
{
	//TODO - Implementation
	//Complexity BC Theta(1) & WC Theta(log n) & AC Theta(log n) =>Total Complexity O(log n)
	int l = 0;
	int r = length - 1;
	int m;

	while (l <= r)
	{
		m = (l + r) / 2;
		if (elem_dy[m] == elem)
			return true;
		else if (relation(elem_dy[m], elem))
			l = m + 1;
		else 
			r= m - 1;
	}
	return false;
}


int SortedSet::size() const {
	//TODO - Implementation
	//Complexity BC,WC,AC is Theta(1) => Total Complexity Theta(1)
	return length;
}


bool SortedSet::isEmpty() const {
	//TODO - Implementation
	//Complexity BC,WC,AC is Theta(1)  => Total Complexity Theta(1)
	return length == 0;
}

SortedSetIterator SortedSet::iterator() const {
	return SortedSetIterator(*this);
}


SortedSet::~SortedSet() {
	//TODO - Implementation
	//Complexity BC,WC,AC is Theta(1)  => Total Complexity Theta(1)
	delete[] elem_dy;
}


