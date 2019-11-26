#include "LinkedList.h"
#include "Node.h"

Node::Node() {

}

Node::Node(LKString str) {
	data = str;
}



LinkedList::LinkedList() {
	count = 0;
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
			it->next->prev = it;
			it = it->next;
		}
		count++;
	}
	tail = it;
	dll.resetIteration();
	return *this;
}

ostream& operator <<(ostream& ostrm, LinkedList& dll) {
	dll.resetIteration();
	dll.remove("");
	if (ostrm.fail()) {
		ostrm << "The output seems to be corrupted!" << endl;
		return ostrm;
	}

	while (dll.hasMore()) {
		LKString temp(dll.next());
		ostrm << temp << " ";
	}
	dll.resetIteration();
	return ostrm;
}

bool LinkedList::insert(const LKString& str) {
	Node* insertNode = new Node(str);

	//Check to make sure it isn't empty
	if (head == nullptr) {
		head = insertNode;
		head->prev = nullptr;
		it = head;
		tail = head;

		count++;
		return true;
	}
	LKString nextStr(next());
	while (hasMore()) {
		if (str == nextStr) {
			//Already has value, so exit
			resetIteration();
			return false;
		}
		else if (str < head->data) {

			//Placing at front of the list
			head->prev = insertNode;
			insertNode->next = head;
			head = insertNode;
			head->prev = nullptr;

			count++;
			resetIteration();
			return true;
		}
		else if (str < nextStr) {

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
		nextStr = next();
	}

	//Has to be at the end of list
	if (str != tail->data) {
		tail->next = insertNode;
		insertNode->prev = tail;
		tail = insertNode;
		tail->next = nullptr;

		count++;
		resetIteration();
		return true;
	}
	//Loop until the data in the next node is greater than the new data
	resetIteration();
	return false;
}

bool LinkedList::remove(const LKString& str) {
	//Check to make sure it isn't empty
	if (head == nullptr) {
		return false;
	}
	if (str == head->data) {
		head = head->next;
		delete head->prev;
		head->prev = nullptr;

		count--;
		resetIteration();
		return true;
	}
	else if (str == tail->data) {
		tail = tail->prev;
		delete tail->next;
		tail->next = nullptr;

		count--;
		resetIteration();
		return true;
	}
	while (hasMore()) {
		if (str == next()) {
			//Step back twice for real previous value?
			Node* prevNode = it->prev->prev;
			//Keep "it" at the incremented value

			//Linking the remaining nodes
			prevNode->next = it;
			it->prev = prevNode;

			count--;
			resetIteration();
			return true;
		}
	}
	resetIteration();
	return false;
}

//ITERATION HELPERS


void LinkedList::resetIteration() const {
	if (head != nullptr)
		it = head;
}

LKString& LinkedList::next() const {
	LKString* temp = new LKString(it->data);
	it = it->next;
	return *temp;
}

LKString& LinkedList::prev() const {
	LKString* temp = new LKString(it->data);
	it = it->prev;
	return *temp;
}

bool LinkedList::hasMore() const {
	//Ensures that list isn't empty before checking for more values
	if (it != nullptr) //JUST CHANGED THIS
		return true;
	return false;
}

//PUBLIC ACCESSORS 

int LinkedList::getCount() const {
	return count;
}

LinkedList::~LinkedList() {

}
