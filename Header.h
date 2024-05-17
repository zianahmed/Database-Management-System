#pragma once
#include<iostream>
#include<conio.h>
#include <string>
#include <list>
#include <fstream>
using namespace std;

int kmax = -1;

class Data {
public:
	int id;
	double Age;
	int death;
	int year;
	char causename[70];
	char cause[30];
	char state[30];
	char filename[70];
	int line_num;
	int flag;

	Data(int i = 0, double a = 0, int d = 0, int y = 0, string strs = "", string strc = "", string strcn = "", string f = "", int l = 0, int fl = 0) {
		id = i;
		Age = a;
		death = d;
		year = y;
		flag = fl;
		line_num = l;
		Cause(strc);
		file(f);
		State(strs);
		Causename(strcn);
	}
	Data* operator=(Data a)
	{
		this->id = a.id;
		this->Age = a.Age;
		this->death = a.death;
		this->year = a.year;
		this->flag = a.flag;
		this->line_num = a.line_num;
		this->Cause(a.gCause());
		this->file(a.gfile());
		this->State(a.gState());
		this->Causename(a.gCausename());
		return this;
	}
	void file(string f) {
		strcpy_s(filename, f.length() + 1, f.c_str());
	}
	void Cause(string f) {
		strcpy_s(cause, f.length() + 1, f.c_str());
	}
	void State(string f) {
		strcpy_s(state, f.length() + 1, f.c_str());
	}
	void Causename(string f) {
		strcpy_s(causename, f.length() + 1, f.c_str());
	}

	string gfile() {
		string f(filename);
		return f;
	}
	string gCause() {
		string f(cause);
		return f;
	}
	string gState() {
		string f(state);
		return f;
	}
	string gCausename() {
		string f(causename);
		return f;
	}

	void change(string str, int flag) {

		switch (flag) {
		case 1:
			id = stoi(str);
			break;

		case 2:
			Age = stod(str);
			break;

		case 3:
			death = stoi(str);
			break;

		case 4:
			year = stoi(str);
			break;

		case 7:
			Cause(str);
			break;

		case 6:
			Causename(str);
			break;
		case 5:
			State(str);
			break;
		}
		return;
	}

	bool operator >(Data d) {

		switch (this->flag) {

		case 1:
			if (id > d.id)
				return true;
			else
				return false;
			break;

		case 2:
			if (Age > d.Age)
				return true;
			else
				return false;
			break;

		case 3:
			if (death > d.death)
				return true;
			else
				return false;
			break;

		case 4:
			if (year > d.year)
				return true;
			else
				return false;
			break;

		case 7:
			if (strcmp(this->cause, d.cause) > 0)
				return true;
			else
				return false;
			break;

		case 6:
			if (strcmp(this->causename, d.causename) > 0)
				return true;
			else
				return false;
			break;
		case 5:
			if (strcmp(this->state, d.state) > 0)
				return true;
			else
				return false;
			break;
		}
	}

	bool operator ==(Data d) {

		switch (this->flag) {

		case 1:
			if (id == d.id)
				return true;
			else
				return false;
			break;

		case 2:
			if (Age == d.Age)
				return true;
			else
				return false;
			break;

		case 3:
			if (death == d.death)
				return true;
			else
				return false;
			break;

		case 4:
			if (year == d.year)
				return true;
			else
				return false;
			break;

		case 7:
			if (strcmp(this->cause, d.cause) == 0)
				return true;
			else
				return false;
			break;

		case 6:
			if (strcmp(this->causename, d.causename) == 0)
				return true;
			else
				return false;
			break;
		case 5:
			if (strcmp(this->state, d.state) == 0)
				return true;
			else
				return false;
			break;
		}
	}

	bool operator <(Data d) {

		switch (this->flag) {

		case 1:
			if (id < d.id)
				return true;
			else
				return false;
			break;

		case 2:
			if (Age < d.Age)
				return true;
			else
				return false;
			break;

		case 3:
			if (death < d.death)
				return true;
			else
				return false;
			break;

		case 4:
			if (year < d.year)
				return true;
			else
				return false;
			break;

		case 7:
			if (strcmp(this->cause, d.cause) < 0)
				return true;
			else
				return false;
			break;

		case 6:
			if (strcmp(this->causename, d.causename) < 0)
				return true;
			else
				return false;
			break;
		case 5:
			if (strcmp(this->state, d.state) < 0)
				return true;
			else
				return false;
			break;
		}
	}
	friend ostream& operator<<(ostream& os, const Data& dt);

};
ostream& operator<<(ostream& os, const Data& dt) {
	os << dt.id << ',' << dt.year << ",\"" << dt.causename << "\"," << dt.cause << ',' << dt.state << ',' << dt.death << ',' << dt.Age << endl;
	return os;
}

template <class T>
class PNode {
public:
	T val;
	int line_num;
	PNode<T>* next;

};
template <class T>
class PQueue {

public:

	PNode<T>* front;
	int counter;

	PQueue() {
		front = NULL;
		counter = 0;
	}

	bool isEmpty() {
		return (front == NULL);
	}

	bool enqueue(T val, int line) {

		if (isEmpty()) {
			front = new PNode<T>;
			front->val = val;
			front->line_num = line;
			front->next = NULL;
			counter++;
			return 1;
		}

		PNode<T>* curr_nodee = front;
		PNode<T>* prev_nodee = NULL;

		while (curr_nodee != NULL && curr_nodee->line_num < line) {
			prev_nodee = curr_nodee;
			curr_nodee = curr_nodee->next;

		}


		PNode<T>* new_node = new PNode<T>;
		if (prev_nodee == NULL) {

			new_node->val = val;
			new_node->line_num = line;
			new_node->next = front;
			front = new_node;
		}

		else {
			new_node->val = val;
			new_node->line_num = line;
			new_node->next = curr_nodee;
			prev_nodee->next = new_node;
		}
		counter++;
		return 1;
	}

	T dequeue() {

		if (isEmpty())
			return NULL;

		PNode<T>* curr_node = front;
		front = front->next;
		counter--;
		return curr_node->val;

	}

};

template <class T>
class QueueNode
{
public:
	T data;
	QueueNode<T>* next;

};

template <class T>
class Queue {

public:

	QueueNode<T>* front;
	QueueNode<T>* rear;


	Queue() {
		front = NULL;
		rear = NULL;
	}




	bool isempty() {
		return front == NULL;
	}

	void enqueue(T d) {
		QueueNode<T>* n = new QueueNode<T>;
		n->data = d;
		n->next = NULL;
		if (isempty()) {
			front = n;
			rear = n;
		}

		else {
			rear->next = n;
			rear = n;
		}

	}




	T dequeue() {
		if (isempty())
		{
			return NULL;
		}
		T temp = front->data;

		if (front != NULL) {
			front = front->next;
		}
		return temp;
	}

	void disp()
	{
		QueueNode<T>* currnode = front;
		while (currnode)
		{
			cout << currnode->data;
			currnode = currnode->next;
		}

	}


};
Queue<string> tfiles;

template <class T>
class AVLNode {
public:
	T data;
	AVLNode<T>* left;
	AVLNode<T>* right;
	Queue<T> dup;
	int height;

	AVLNode()
	{
		left = NULL;
		right = NULL;
		height = 0;
	}

};

template <class T>
class AVLTree {

public:

	AVLNode<T>* root;
	AVLTree() {
		root = NULL;
	}

	int height(AVLNode<T>* curr) {
		if (curr == NULL)
			return -1;
		else
			return curr->height;
	}

	AVLNode<T>* RRRotation(AVLNode<T>*& old_root) {  //Left Rotation
		AVLNode<T>* new_root = old_root->left;
		old_root->left = new_root->right;
		new_root->right = old_root;
		old_root->height = max(height(old_root->left), height(old_root->right)) + 1;
		new_root->height = max(height(new_root->left), height(new_root->right)) + 1;
		return new_root;

	}

	AVLNode<T>* LLRotation(AVLNode<T>*& old_root) {  //Right Rotation
		AVLNode<T>* new_root = old_root->right;
		old_root->right = new_root->left;
		new_root->left = old_root;
		old_root->height = max(height(old_root->left), height(old_root->right)) + 1;
		new_root->height = max(height(new_root->left), height(new_root->right)) + 1;
		return new_root;
	}

	AVLNode<T>* RLRotation(AVLNode<T>*& curr) {
		if (curr->left != NULL)
			curr->left = LLRotation(curr->left);

		curr = RRRotation(curr);
		return curr;
	}

	AVLNode<T>* LRRotation(AVLNode<T>*& curr) {
		if (curr->right != NULL)
			curr->right = RRRotation(curr->right);
		curr = LLRotation(curr);
		return curr;
	}

	AVLNode<T>* insert(T val, AVLNode<T>*& curr) {
		if (curr == NULL) {
			curr = new AVLNode<T>;
			curr->data = val;
			curr->height = 0;
			return curr;
		}

		if (curr->data == val) {
			curr->dup.enqueue(val);
			return curr;
		}

		else if (val < curr->data) {
			insert(val, curr->left);
			if (height(curr->left) - height(curr->right) == 2) {
				if (val < curr->data)
					curr = RRRotation(curr);
				else
					curr = RLRotation(curr);
			}
		}

		else if (val > curr->data) {
			insert(val, curr->right);
			if (height(curr->right) - height(curr->left) == 2) {
				if (val > curr->data)
					curr = LLRotation(curr);
				else
					curr = LRRotation(curr);
			}
		}
		curr->height = max(height(curr->right), height(curr->left)) + 1;
		return curr;
	}

	AVLNode<T>* Delete(T val, AVLNode<T>*& curr) {
		if (curr == NULL) {
			return NULL;
		}

		else if (val < curr->data) {
			curr->left = Delete(val, curr->left);
			if (height(curr->left) - height(curr->right) == -2) {
				if (height(curr->left) - height(curr->right) <= 0)
					curr = LLRotation(curr);
				else
					curr = RLRotation(curr);
			}
		}

		else if (val > curr->data) {
			curr->right = Delete(val, curr->right);

			if (height(curr->right) - height(curr->left) == -2) {
				if (height(curr->left->left) - height(curr->left->right) >= 0)
					curr = RRRotation(curr);
				else
					curr = LRRotation(curr);
			}

		}

		else {
			AVLNode<T>* temp;
			temp = curr;
			T delVal = curr->data;
			if (curr->right != NULL) {
				temp = curr->right;
				while (temp->left != NULL)
					temp = temp->left;

				curr->data = temp->data;
				curr->right = Delete(temp->data, curr->right);

				if (height(curr->left) - height(curr->right) == -2)
					if (height(curr->left->left) - height(curr->left->right) >= 0)
						curr = LLRotation(curr);
					else
						curr = LRRotation(curr);
			}

			else {
				if (curr->left != NULL)
					curr->left->height = max(height(curr->left->right), height(curr->left->left)) + 1;
				return(curr->left);
			}
		}
		curr->height = max(height(curr->right), height(curr->left)) + 1;
		return curr;
	}


	bool isempty() {
		return root == NULL;
	}

	void LevelOrder(AVLNode<T>* n) {
		Queue<AVLNode<T>*> obj;
		obj.enqueue(n);

		while (!obj.isempty()) {
			AVLNode<T>* curr = obj.dequeue();
			if (curr->left != NULL) {
				obj.enqueue(curr->left);
			}

			if (curr->right != NULL) {
				obj.enqueue(curr->right);
			}

			cout << curr->data << endl;
		}

	}

	void InOrderTraversal(AVLNode<T>* n) {

		if (n == NULL)
			return;

		InOrderTraversal(n->left);
		cout << n->data << " ";
		InOrderTraversal(n->right);

		return;
	}

	void write(AVLNode<T>* curr, int k = 1) {

		if (curr == NULL)
			return;

		if (k > kmax)
			kmax = k;

		write(curr->left, 2 * k);
		write(curr->right, 2 * k + 1);
		string file_name = "E:/DS/Project/Project/AVLTree/AVLTree" + to_string(k) + ".dat";
		ofstream fout(file_name, ios::binary);
		fout.write((char*)&curr->data, sizeof(curr->data));

		while (!curr->dup.isempty()) {
			T d = curr->dup.dequeue();
			fout.write((char*)&d, sizeof(d));
		}

		fout.close();
		tfiles.enqueue(file_name);
	}

};

template <class T>
class RBNode {
public:
	T data;
	RBNode<T>* parent;
	RBNode<T>* left;
	RBNode<T>* right;
	Queue<T> dup;
	int colour;//-1=NULL 0=Red 1=Black
	RBNode() {
		parent = NULL;
		left = NULL;
		right = NULL;
		colour = 0;
	}


};

template <class T>
class RBTree {
public:

	int colour(RBNode<T>* curr) {
		if (curr == NULL)
			return -1;
		else
			return curr->colour;
	}

	RBNode<T>* root;
	RBTree() {
		root = NULL;
	}

	bool IsEmpty() {
		return root == NULL;
	}

	void insert(T Val) {
		RBNode<T>* ptr = new RBNode<T>;
		ptr->data = Val;
		root = InsertVal(ptr, root);
		root = FixViolation(this->root, ptr);
	}

	RBNode<T>* RRRotation(RBNode<T>*& root, RBNode<T>*& ptr) {  //Right Rotation
		RBNode<T>* new_ptr = ptr->left;
		ptr->left = new_ptr->right;
		new_ptr->right = ptr;

		if (ptr->left != NULL)
			ptr->left->parent = ptr;

		RBNode<T>* temp = ptr->parent;
		ptr->parent = new_ptr;
		new_ptr->parent = temp;

		if (new_ptr->parent == NULL)
			root = new_ptr;

		return new_ptr;
	}

	RBNode<T>* LLRotation(RBNode<T>*& root, RBNode<T>*& ptr) {  //Left Rotation
		RBNode<T>* new_ptr = ptr->right;
		ptr->right = new_ptr->left;
		new_ptr->left = ptr;

		if (ptr->right != NULL)
			ptr->right->parent = ptr;

		RBNode<T>* temp = ptr->parent;
		ptr->parent = new_ptr;
		new_ptr->parent = temp;


		if (new_ptr->parent == NULL)
			root = new_ptr;


		return new_ptr;
	}

	RBNode<T>* FixViolation(RBNode<T>*& root, RBNode<T>*& ptr) {
		RBNode<T>* uncle;
		RBNode<T>* gpar;
		gpar = NULL;
		RBNode<T>* par;
		par = NULL;
		uncle = NULL;

		while (ptr != root && colour(ptr) != 1 && colour(ptr->parent) == 0) {
			gpar = ptr->parent->parent;
			par = ptr->parent;

			if (par == gpar->left) {
				uncle = gpar->right;
				if (colour(uncle) == 0 && colour(ptr) == 0) {
					ptr->parent->colour = 1;
					ptr->parent->parent->right->colour = 1;
					ptr->parent->parent->colour = 0;
					ptr = ptr->parent->parent;
				}

				else {

					if (ptr == ptr->parent->right) {
						ptr = ptr->parent;
						ptr = LLRotation(root, ptr);
						ptr->parent->left = ptr;
						ptr = ptr->left;
					}

					ptr = ptr->parent;
					RBNode<T>* temp = RRRotation(root, ptr->parent);
					if (temp->parent == NULL)
						ptr = temp;
					else
						ptr->parent->left = temp;
					swap(ptr->right->colour, ptr->colour);

				}
			}

			else {
				uncle = gpar->left;
				if (colour(uncle) == 0 && colour(ptr) == 0) {
					ptr->parent->colour = 1;
					ptr->parent->parent->left->colour = 1;
					ptr->parent->parent->colour = 0;
					ptr = ptr->parent->parent;
				}

				else {
					if (ptr == ptr->parent->left) {
						ptr = ptr->parent;
						ptr = RRRotation(root, ptr);
						ptr->parent->right = ptr;
						ptr = ptr->right;
					}
					ptr = ptr->parent;
					RBNode<T>* temp = LLRotation(root, ptr->parent);
					if (temp->parent == NULL)
						ptr = temp;
					else
						ptr->parent->right = temp;
					swap(ptr->left->colour, ptr->colour);
				}
			}

		}
		root->colour = 1;
		return root;
	}

	RBNode<T>* InsertVal(RBNode<T>*& ptr, RBNode<T>*& curr) {

		if (curr == NULL) {
			curr = ptr;
			return ptr;
		}

		if (curr->data == ptr->data) {
			curr->dup.enqueue(ptr->data);
			return curr;
		}

		else if (ptr->data < curr->data) {
			curr->left = InsertVal(ptr, curr->left);
			curr->left->parent = curr;
			return curr;
		}
		else if (ptr->data > curr->data) {
			curr->right = InsertVal(ptr, curr->right);
			curr->right->parent = curr;
			return curr;
		}

	}


	void LevelOrder(RBNode<T>* n) {
		Queue<RBNode<T>*> obj;
		obj.enqueue(n);

		while (!obj.isempty()) {
			RBNode<T>* curr = obj.dequeue();
			if (curr->left != NULL) {
				obj.enqueue(curr->left);
			}

			if (curr->right != NULL) {
				obj.enqueue(curr->right);
			}

			cout << curr->data << endl;
		}

	}

	void InOrderTraversal(RBNode<T>* n) {

		if (n == NULL)
			return;

		InOrderTraversal(n->left);
		cout << n->data << " ";
		InOrderTraversal(n->right);

		return;
	}

	void write(RBNode<T>* curr, int k = 1) {

		if (curr == NULL)
			return;

		if (k > kmax)
			kmax = k;

		write(curr->left, 2 * k);
		write(curr->right, 2 * k + 1);
		string file_name = "E:/DS/Project/Project/AVLTree/AVLTree" + to_string(k) + ".dat";
		ofstream fout(file_name, ios::binary);
		fout.write((char*)&curr->data, sizeof(curr->data));


		while (!curr->dup.isempty()) {
			T d = curr->dup.dequeue();
			fout.write((char*)&d, sizeof(d));
		}

		fout.close();
		tfiles.enqueue(file_name);
	}

};





Queue<Data>* search(Data val, int k = 1) {
	if (k > kmax)
		return NULL;

	Queue<Data>* tempqueue = new Queue<Data>;
	Data obj;
	string file_name = "E:/DS/Project/Project/AVLTree/AVLTree" + to_string(k) + ".dat";
	ifstream in(file_name, ios::binary);
	bool found = false;


	while (in.read((char*)&obj, sizeof(obj))) {
		if (val == obj) {
			found = true;
			tempqueue->enqueue(obj);
		}
		else
			break;
	}in.close();

	if (found)
		return tempqueue;
	else if (val < obj)
		return search(val, 2 * k);
	else if (val > obj)
		return search(val, 2 * k + 1);
	return tempqueue;
}

void removeFiles() {
	while (!tfiles.isempty()) {
		string file = tfiles.dequeue();
		int i = remove(file.c_str());
	}
	kmax = -1;
}
void indexing(int flag, int t) {
	removeFiles();
	string path[10];
	path[0] = "NCHS_-_Leading_Causes_of_Death__United_States_1.csv";
	path[1] = "NCHS_-_Leading_Causes_of_Death__United_States_2.csv";
	path[2] = "NCHS_-_Leading_Causes_of_Death__United_States_3.csv";
	path[3] = "NCHS_-_Leading_Causes_of_Death__United_States_4.csv";
	path[4] = "NCHS_-_Leading_Causes_of_Death__United_States_5.csv";
	path[5] = "NCHS_-_Leading_Causes_of_Death__United_States_6.csv";
	path[6] = "NCHS_-_Leading_Causes_of_Death__United_States_7.csv";
	path[7] = "NCHS_-_Leading_Causes_of_Death__United_States_8.csv";
	path[8] = "NCHS_-_Leading_Causes_of_Death__United_States_9.csv";
	path[9] = "NCHS_-_Leading_Causes_of_Death__United_States_10.csv";

	if (t == 1) {
		AVLTree<Data> tree;
		for (int i = 0; i < 10; i++) {
			int linenum = 2;

			ifstream myfile;
			myfile.open(path[i]);
			string str;

			getline(myfile, str);
			while (!myfile.eof()) {
				getline(myfile, str);
				char array[10][60]{ '\0' };
				bool comma = true;
				int cc = 0;
				int cc2 = 0;
				for (int z = 0; str[z] != '\0'; z++) {
					if (str[z] == '\"') {
						comma = !comma;
					}
					else if (str[z] == ',' && comma) {
						cc++;
						cc2 = 0;
					}
					else {
						array[cc][cc2] = str[z];
						cc2++;
					}
				}

				string ar[7]{ "" };
				int indc = 0;

				for (int k = 0; k <= cc; k++) {
					int help = 0;
					while (array[k][help] != '\0') {
						ar[indc] += array[k][help];
						help++;
					}
					indc++;
				}
				int ag = 0;
				int bg = 0;
				int cg = 0;
				int dg = 0;
				if (ar[0] != "")
				{
					ag = stoi(ar[0]);
				}


				if (ar[6] != "")
				{
					bg = stod(ar[6]);
				}


				if (ar[5] != "")
				{
					cg = stoi(ar[5]);
				}


				if (ar[1] != "")
				{
					dg = stoi(ar[1]);
				}



				Data d(ag, bg, cg, dg, ar[4], ar[3], ar[2], path[i], linenum, flag);
				tree.root = tree.insert(d, tree.root);
				linenum++;
			}

		}
		tree.write(tree.root);
	}


	if (t == 2) {
		RBTree<Data> tree;
		for (int i = 0; i < 10; i++) {
			int linenum = 2;

			ifstream myfile;
			myfile.open(path[i]);
			string str;

			getline(myfile, str);
			while (!myfile.eof()) {
				getline(myfile, str);
				char array[10][60]{ '\0' };
				bool comma = true;
				int cc = 0;
				int cc2 = 0;
				for (int z = 0; str[z] != '\0'; z++) {
					if (str[z] == '\"') {
						comma = !comma;
					}
					else if (str[z] == ',' && comma) {
						cc++;
						cc2 = 0;
					}
					else {
						array[cc][cc2] = str[z];
						cc2++;
					}
				}

				string ar[7]{ "" };
				int indc = 0;

				for (int k = 0; k <= cc; k++) {
					int help = 0;
					while (array[k][help] != '\0') {
						ar[indc] += array[k][help];
						help++;
					}
					indc++;
				}
				int ag = 0;
				int bg = 0;
				int cg = 0;
				int dg = 0;
				if (ar[0] != "")
				{
					ag = stoi(ar[0]);
				}


				if (ar[6] != "")
				{
					bg = stod(ar[6]);
				}


				if (ar[5] != "")
				{
					cg = stoi(ar[5]);
				}


				if (ar[1] != "")
				{
					dg = stoi(ar[1]);
				}



				Data d(ag, bg, cg, dg, ar[4], ar[3], ar[2], path[i], linenum, flag);
				tree.insert(d);
				linenum++;
			}

		}
		tree.write(tree.root);
	}
}
void DeleteKey(Queue<Data>* obj, int tree = 1) {

	int type;
	PQueue<Data> file[10];
	string path[10];

	path[0] = "NCHS_-_Leading_Causes_of_Death__United_States_1.csv";
	path[1] = "NCHS_-_Leading_Causes_of_Death__United_States_2.csv";
	path[2] = "NCHS_-_Leading_Causes_of_Death__United_States_3.csv";
	path[3] = "NCHS_-_Leading_Causes_of_Death__United_States_4.csv";
	path[4] = "NCHS_-_Leading_Causes_of_Death__United_States_5.csv";
	path[5] = "NCHS_-_Leading_Causes_of_Death__United_States_6.csv";
	path[6] = "NCHS_-_Leading_Causes_of_Death__United_States_7.csv";
	path[7] = "NCHS_-_Leading_Causes_of_Death__United_States_8.csv";
	path[8] = "NCHS_-_Leading_Causes_of_Death__United_States_9.csv";
	path[9] = "NCHS_-_Leading_Causes_of_Death__United_States_10.csv";


	for (int i = 0; i < 10; i++) {
		Queue<Data>temp;
		while (!obj->isempty())
		{
			Data d = obj->dequeue();
			type = d.flag;
			if (strcmp(path[i].c_str(), d.gfile().c_str()) == 0) {
				file[i].enqueue(d, d.line_num);
			}
			else {
				temp.enqueue(d);
			}
		}
		while (!temp.isempty())
		{
			obj->enqueue(temp.dequeue());
		}
	}

	for (int i = 0; i < 10; i++) {

		if (file[i].isEmpty())
		{
			continue;
		}

		ifstream myfile;
		myfile.open(path[i]);
		ofstream newfile;
		string tt = "";
		tt += "temp.csv";
		newfile.open(tt);
		string str;
		int k = 0;
		Data d = file[i].dequeue();
		bool flag = false;
		while (!myfile.eof()) {

			if (flag) {
				getline(myfile, str);
				newfile << str << endl;
			}

			else if (d.line_num != k + 1) {
				getline(myfile, str);
				newfile << str << endl;
			}

			else {
				getline(myfile, str);
				d = file[i].dequeue();
				if (d == NULL) {
					flag = true;
				}
			}
			k++;
		}
		myfile.close();
		newfile.close();
		remove(path[i].c_str());
		rename(tt.c_str(), path[i].c_str());
	}

	int i = 0;
	return;
}
void UpdateKey(Queue<Data>* obj, string strchange, int tree = 1, int ch = -1) {
	int type;
	PQueue<Data> file[10];
	string path[10];
	path[0] = "NCHS_-_Leading_Causes_of_Death__United_States_1.csv";
	path[1] = "NCHS_-_Leading_Causes_of_Death__United_States_2.csv";
	path[2] = "NCHS_-_Leading_Causes_of_Death__United_States_3.csv";
	path[3] = "NCHS_-_Leading_Causes_of_Death__United_States_4.csv";
	path[4] = "NCHS_-_Leading_Causes_of_Death__United_States_5.csv";
	path[5] = "NCHS_-_Leading_Causes_of_Death__United_States_6.csv";
	path[6] = "NCHS_-_Leading_Causes_of_Death__United_States_7.csv";
	path[7] = "NCHS_-_Leading_Causes_of_Death__United_States_8.csv";
	path[8] = "NCHS_-_Leading_Causes_of_Death__United_States_9.csv";
	path[9] = "NCHS_-_Leading_Causes_of_Death__United_States_10.csv";


	for (int i = 0; i < 10; i++) {
		Queue<Data>temp;
		while (!obj->isempty())
		{
			Data d = obj->dequeue();
			type = d.flag;
			if (strcmp(path[i].c_str(), d.gfile().c_str()) == 0) {
				file[i].enqueue(d, d.line_num);
			}
			else {
				temp.enqueue(d);
			}
		}
		while (!temp.isempty())
		{
			obj->enqueue(temp.dequeue());
		}
	}

	for (int i = 0; i < 10; i++) {

		if (file[i].isEmpty())
		{
			continue;
		}

		ifstream myfile;
		myfile.open(path[i]);
		ofstream newfile;
		string tt = "";
		tt += "temp.csv";
		newfile.open(tt);
		string str;
		int k = 0;
		Data d = file[i].dequeue();
		bool flag = false;
		while (!myfile.eof()) {

			if (flag) {
				getline(myfile, str);
				newfile << str << endl;
			}

			else if (d.line_num != k + 1) {
				getline(myfile, str);
				newfile << str << endl;
			}

			else {

				getline(myfile, str);

				if (ch == -1)
					d.change(strchange, d.flag);
				else
					d.change(strchange, ch);

				newfile << d;
				d = file[i].dequeue();
				if (d == NULL) {
					flag = true;
				}
			}
			k++;
		}

		myfile.close();
		newfile.close();
		remove(path[i].c_str());
		rename(tt.c_str(), path[i].c_str());
	}
	indexing(type, tree);
	return;
}
