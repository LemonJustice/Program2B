#include "LinkedList.h"
#include "Node.h"

Node::Node() {

}

Node::Node(LKString str) {
	data = str;
}



LinkedList::LinkedList() {

}

LinkedList::LinkedList(const LinkedList& dll) {
	//reset count
	count = 0;
	dll.resetIteration(); //reassurance for now
	while (dll.hasMore()) {
		//handles case of head
		if (count == 0) {
			head = new Node(dll.next());
			it = head;
		}
		else {
			//literally every other case
			it->next = new Node(dll.next());
			it = it->next;
		}
		count++;
	}
	tail = it;
}

LinkedList& LinkedList::operator =(const LinkedList& dll) {
	count = 0;
	dll.resetIteration(); //reassurance for now
	while (dll.hasMore()) {
		if (count == 0) {
			head = new Node(dll.next());
			it = head;
		}
		else {
			it->next = new Node(dll.next());
			it = it->next;
		}
		count++;
	}
	tail = it;
	return *this;
}

ostream& operator <<(ostream& ostrm, LinkedList& dll) {
	dll.resetIteration();
	if (ostrm.fail()) {
		ostrm << "The output seems to be corrupted!" << endl;
		return ostrm;
	}

	while (dll.hasMore()) {
		ostrm << dll.next() << " ";
	}
	ostrm << dll.next() << " ";
	ostrm << endl;
	return ostrm;
}

bool LinkedList::insert(const LKString& str) {
	Node* insertNode = new Node(str);

	//Check to make sure it isn't empty
	if (head == nullptr) {
		head = insertNode;
		it = head;
		tail = head;

		count++;
		return true;
	}

	//Loop until the data in the next node is greater than the new data
	while(hasMore()) {
		
		if (str == next()) {
			//Already has value, so exit
			resetIteration();
			return false;
		}
		else if (str < head->data) {
			
			//Placing at front of the list
			head->prev = insertNode;
			insertNode->next = head;
			head = insertNode;

			count++;
			resetIteration();
			return true;
		}
		else if (str < next()) {
			
			//Perhaps my next function hinders me
				//It iterates the it pointer, but comparison is done with previous string
				//Therefore, step back twice for real previous value?
			Node* prevNode = it->prev->prev;

			//Stepping back prev for better comprehension
			it = it->prev;

			//Linked insertNode with prevNode
			prevNode->next = insertNode;
			insertNode->prev = prevNode;

			//Finishing the other side of the insert
			insertNode->next = it;
			it->prev = insertNode;

			count++;
			resetIteration();
			return true;
		}
	}
	
	//Has to be at the end of list
	tail->next = insertNode;
	insertNode->prev = tail;
	tail = insertNode;

	count++;
	resetIteration();
	return true;
}

bool LinkedList::remove(const LKString& str) {
	//Check to make sure it isn't empty
	if (head == nullptr) {
		return false;
	}
	while (hasMore()) {
		if (str == head->data) {
			head->next->prev = head;
			head = head->next;
			delete head->prev;

			count--;
			resetIteration();
			return true;
		}
		else if (str == next()) {
			//Step back twice for real previous value?
			Node* prevNode = it->prev->prev;
			//Keep "it" at the incremented value

			//removing selected string
			delete it->prev;

			//Linking the remaining nodes
			prevNode->next = it;
			it->prev = prevNode;

			count--;
			resetIteration();
			return true;
		}
	}
	
	//Maybe the tail holds the search string
	if (str == tail->data) {
		tail->prev->next = tail;
		tail = tail->prev;
		delete tail->next;

		count--;
		resetIteration();
		return true;
	}
	return false;
}

//ITERATION HELPERS


void LinkedList::resetIteration() const {
	if (head != nullptr)
		it = head;
}

LKString& LinkedList::next() const {
	if (it != nullptr) {
		if (!hasMore())
			return it->data;
		it = it->next;
		return it->prev->data;
	}
}

bool LinkedList::hasMore() const {
	//Ensures that list isn't empty before checking for more values
	if (head != nullptr && it != nullptr) //JUST CHANGED THIS
		return true;
	return false;
}

//PUBLIC ACCESSORS 

int LinkedList::getCount() const {
	return count;
}

LinkedList::~LinkedList() {

}
