#include "SortedSetIterator.h"
#include <exception>

using namespace std;

SortedSetIterator::SortedSetIterator(const SortedSet& m) : multime(m)
{
	//TODO - Implementation
	//Complexity BC,WC,AC is Theta(1) => Total Complexity Theta(1)
	current =0;
}


void SortedSetIterator::first() {
	//TODO - Implementation
	//Complexity BC,WC,AC is Theta(1) => Total Complexity Theta(1)
	current = 0;
}


void SortedSetIterator::next() {
	//TODO - Implementation
	//Complexity BC,WC,AC is Theta(1) => Total Complexity Theta(1)
	if (current >= multime.length)
		throw std::exception();
	current++;
}


TElem SortedSetIterator::getCurrent()
{
	//TODO - Implementation
	//Complexity BC,WC,AC is Theta(1) => Total Complexity Theta(1)
	if (current >= multime.length)
		throw std::exception();
	return multime.elem_dy[current];
}

bool SortedSetIterator::valid() const {
	//TODO - Implementation
	//Complexity BC,WC,AC is Theta(1) => Total Complexity Theta(1)
	return current < multime.length;
}