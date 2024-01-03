#include<set>

#include<vector>

using namespace std;

const int maxNumberOfLevel = 20;

class Node {
    public:

        int data;
    vector < Node * > next;
    Node(int data, int Level): data(data),
    next(Level + 1, nullptr) {}
};

class skipList {
    private: 
		Node * head;
		int Level;

	public: 
		skipList();
		skipList(vector<int> data);
		void insert(int data);
		multiset <int> range_query(int data, int end);

};

skipList::skipList() {
    head = new Node(0, maxNumberOfLevel);

    Level = 0;

}

skipList::skipList(vector<int> data) {
    head = new Node(0, maxNumberOfLevel);
    Level = 0;
	for(int i : data){
		this->insert(i);
	}
}
void skipList::insert(int data) {
    int newLevel = 0;

    while (newLevel < maxNumberOfLevel and(rand() % 2) == 1) {
        newLevel++;
    }

    if (Level < newLevel) {
        head -> next.resize(newLevel + 1, nullptr);
        Level = newLevel;
    }

    Node * current = head;
    vector < Node * > Update(Level + 1, nullptr);

    for (int i = Level; i >= 0; i--) {

        while (current -> next[i] and current -> next[i] -> data < data) {
            current = current -> next[i];
        }

        Update[i] = current;
    }

    current = current -> next[0];

    Node * newNode = new Node(data, Level);

    for (int i = 0; i <= newLevel; i++) {
        newNode -> next[i] = Update[i] -> next[i];
        Update[i] -> next[i] = newNode;
    }

}

multiset < int > skipList::range_query(int data, int end) {
    Node * current = head;
	vector<int> arr;
    multiset < int > ret;

    for (int i = Level; i >= 0; i--) {
        while (current -> next[i] and current -> next[i] -> data < data) {
            current = current -> next[i];

        }
    }

    current = current -> next[0];
    for (; current != nullptr and current -> data <=end; current = current -> next[0]) {
        arr.push_back(current -> data);
    }
    return multiset<int>(arr.begin(),arr.end());
}
