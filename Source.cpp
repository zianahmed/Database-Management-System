#include <iostream>
#include "Header.h"
#include <string>
using namespace std;

/*

Hassan i210507
Zian   i210503
Humaiyon i210662

*/


Queue<Data>* Choose(Queue<Data>* temp, Data d) {
	Queue<Data>* tData = new Queue<Data>;
	while (!temp->isempty()) {
		Data t = temp->dequeue();
		int old = t.flag;
		t.flag = d.flag;
		if (t == d) {
			t.flag = old;
			tData->enqueue(t);
		}
	}

	return tData;
}


Queue<Data>* searchhelper(int x, string inputstr, int flag = -1, string str = "") {
	Queue<Data>* tempqueue = new Queue<Data>;

	if (x == 1) {
		Data d(stoi(inputstr), 0, 0, 0, "s", "s", "s", "s", 1, 1);
		tempqueue = search(d, 1);
	}

	if (x == 2) {
		Data d(0, stod(inputstr), 0, 0, "s", "s", "s", "s", 1, 2);
		tempqueue = search(d, 1);
	}

	if (x == 3) {
		Data d(0, 0, stoi(inputstr), 0, "s", "s", "s", "s", 1, 3);
		tempqueue = search(d, 1);

	}


	if (x == 4) {
		Data d(0, 0, 0, stoi(inputstr), "s", "s", "s", "s", 1, 4);
		tempqueue = search(d, 1);
	}

	if (x == 5) {
		Data d(0, 0, 0, 0, inputstr, "s", "s", "s", 1, 5);
		tempqueue = search(d, 1);
	}

	if (x == 6) {
		Data d(0, 0, 0, 0, "s", inputstr, "s", "s", 1, 6);
		tempqueue = search(d, 1);
	}

	if (x == 7) {
		Data d(0, 0, 0, 0, "s", "s", inputstr, "s", 1, 7);
		tempqueue = search(d, 1);
	}

	if (flag == -1)
		return tempqueue;

	x = flag;
	if (x == 1) {
		Data d(stoi(str), 0, 0, 0, "s", "s", "s", "s", 1, 1);
		tempqueue = Choose(tempqueue, d);
	}

	if (x == 2) {
		Data d(0, stod(str), 0, 0, "s", "s", "s", "s", 1, 2);
		tempqueue = Choose(tempqueue, d);
	}

	if (x == 3) {
		Data d(0, 0, stoi(str), 0, "s", "s", "s", "s", 1, 3);
		tempqueue = Choose(tempqueue, d);
	}


	if (x == 4) {
		Data d(0, 0, 0, stoi(str), "s", "s", "s", "s", 1, 4);
		tempqueue = Choose(tempqueue, d);
	}

	if (x == 5) {
		Data d(0, 0, 0, 0, str, "s", "s", "s", 1, 5);
		tempqueue = Choose(tempqueue, d);
	}

	if (x == 6) {
		Data d(0, 0, 0, 0, "s", str, "s", "s", 1, 6);
		tempqueue = Choose(tempqueue, d);
	}

	if (x == 7) {
		Data d(0, 0, 0, 0, "s", "s", str, "s", 1, 7);
		tempqueue = Choose(tempqueue, d);
	}

	return tempqueue;

}

void BSTree() {
	int x;
	do {
		system("CLS");
		cout << endl;
		cout << "*****************************************************" << endl;
		cout << "*****************************************************" << endl;
		cout << "*****************************************************" << endl;
		cout << "*****************************************************" << endl;
		cout << "******************UNDER CONSTRUCTION*****************" << endl;
		cout << "*****************************************************" << endl;
		cout << "*****************************************************" << endl;
		cout << "*****************************************************" << endl;
		cout << "*****************************************************" << endl;
		cout << "*************** < COMING TO YOU SOON > **************\n0. Back\n";
		cin >> x;
	} while (x != 0);

}
void AVL() {
	int x, y, dz = 0;

	while (dz == 0)
	{
	lab2:
		do {
			system("CLS");
			cout << endl;
			cout << "*****************************************************" << endl;
			cout << "Please select the field with which you want to index?\n";
			cout << "1. ID\n2. AGE-adjusted DEATH RATE\n3. DEATHS\n4. YEAR\n5. STATE \n6. CAUSE \n7. CAUSE NAME\n0. Exit\n";
			cout << "*****************************************************" << endl;
			cin >> x;
		} while (x > 7 || x < 0);

		if (x == 0)
		{
			break;
		}

		system("CLS");
		cout << "*****************************************************" << endl;
		cout << "INDEXING...\n";
		indexing(x, 1);

	labs:
		do {
			system("CLS");
			cout << endl;
			cout << "*****************************************************" << endl;
			cout << "Please select the field with which you want to Choose?\n";
			cout << "1. Point Search\n2. Range Search\n3. Where Clause(BONUS)\n0. Exit\n";
			cout << "*****************************************************" << endl;
			cin >> y;
		} while (y > 4 || y < 0);
		Queue<Data>* tempqueue = new Queue<Data>;
		Queue<Data>* tempqueue2 = new Queue<Data>;

		string inputstr;
		if (y == 1)
		{
			cout << "\nEnter String: ";
			getline(cin, inputstr);
			getline(cin, inputstr);
			tempqueue = searchhelper(x, inputstr);

		}

		if (y == 2)
		{
			int start = 0, eend = 0;

			if (x >= 1 && x <= 4)
			{

				cout << "\nEnter Starting Range: ";
				cin >> start;
				cout << "\nEnter Ending Range: ";
				cin >> eend;

				for (int i = start; i <= eend; i++) {

					tempqueue2 = searchhelper(x, to_string(i));

					while (tempqueue2 != NULL && !tempqueue2->isempty()) {
						tempqueue->enqueue(tempqueue2->dequeue());
					}

				}
			}

		}
		if (y == 3) {
			cout << "\nEnter String: ";
			getline(cin, inputstr);
			getline(cin, inputstr);
			system("cls");
			int k2;
			string strk2;
			cout << "*****************************************************" << endl;
			cout << "Please select the field with which you want to Choose?\n";
			cout << "1. ID\n2. AGE-adjusted DEATH RATE\n3. DEATHS\n4. YEAR\n5. STATE \n6. CAUSE \n7. CAUSE NAME\n0. Exit\n";
			cout << "*****************************************************" << endl;
			cin >> k2;
			cout << "Enter String: ";
			cin >> strk2;
			tempqueue = searchhelper(x, inputstr, k2, strk2);
		}
		if (y == 0)
		{
			goto lab2;
		}

		if (tempqueue != NULL)
		{
			tempqueue->disp();
			cout << "*****************************************************" << endl;
			cout << "Please select the field with which you want to Choose?\n";
			cout << "1. Delete\n2. Update\n0. Exit\n";
			cout << "*****************************************************" << endl;
			cin >> dz;

			if (dz == 1)
			{
				DeleteKey(tempqueue);
				cout << "\Done.\n0. Exit\n-> ";
				cin >> y;
				goto labs;

			}
			if (dz == 2)
			{
				string l1;
				cout << "Enter new string: ";
				cin >> l1;
				UpdateKey(tempqueue, l1);
				cout << "\Done.\n0. Exit\n-> ";
				cin >> y;
				goto labs;

			}

			if (dz == 0)
			{
				goto labs;
			}


			dz = 0;

		}
		else
		{
			cout << "\nRecord Not Found.\n0. Exit\n-> ";
			cin >> y;
			goto labs;
		}


	}

	removeFiles();

}
void redblack() {
	int x, y, dz = 0;

	while (dz == 0)
	{
	lab2:
		do {
			system("CLS");
			cout << endl;
			cout << "*****************************************************" << endl;
			cout << "Please select the field with which you want to index?\n";
			cout << "1. ID\n2. AGE-adjusted DEATH RATE\n3. DEATHS\n4. YEAR\n5. STATE \n6. CAUSE \n7. CAUSE NAME\n0. Exit\n";
			cout << "*****************************************************" << endl;
			cin >> x;
		} while (x > 7 || x < 0);

		if (x == 0)
		{
			break;
		}

		system("CLS");
		cout << "*****************************************************" << endl;
		cout << "INDEXING...\n";
		indexing(x, 2);

	labs:
		do {
			system("CLS");
			cout << endl;
			cout << "*****************************************************" << endl;
			cout << "Please select the field with which you want to Choose?\n";
			cout << "1. Point Search\n2. Range Search\n3. Where Clause(BONUS)\n0. Exit\n";
			cout << "*****************************************************" << endl;
			cin >> y;
		} while (y > 4 || y < 0);
		Queue<Data>* tempqueue = new Queue<Data>;
		Queue<Data>* tempqueue2 = new Queue<Data>;

		string inputstr;
		if (y == 1)
		{
			cout << "\nEnter String: ";
			getline(cin, inputstr);
			getline(cin, inputstr);
			tempqueue = searchhelper(x, inputstr);

		}

		if (y == 2)
		{
			int start = 0, eend = 0;

			if (x >= 1 && x <= 4)
			{

				cout << "\nEnter Starting Range: ";
				cin >> start;
				cout << "\nEnter Ending Range: ";
				cin >> eend;

				for (int i = start; i <= eend; i++) {

					tempqueue2 = searchhelper(x, to_string(i));

					while (tempqueue2 != NULL && !tempqueue2->isempty()) {
						tempqueue->enqueue(tempqueue2->dequeue());
					}

				}
			}

		}
		if (y == 3) {
			cout << "\nEnter String: ";
			getline(cin, inputstr);
			getline(cin, inputstr);
			system("cls");
			int k2;
			string strk2;
			cout << "*****************************************************" << endl;
			cout << "Please select the field with which you want to Choose?\n";
			cout << "1. ID\n2. AGE-adjusted DEATH RATE\n3. DEATHS\n4. YEAR\n5. STATE \n6. CAUSE \n7. CAUSE NAME\n0. Exit\n";
			cout << "*****************************************************" << endl;
			cin >> k2;
			cout << "Enter String: ";
			cin >> strk2;
			tempqueue = searchhelper(x, inputstr, k2, strk2);
		}
		if (y == 0)
		{
			goto lab2;
		}

		if (tempqueue != NULL)
		{
			tempqueue->disp();
			cout << "*****************************************************" << endl;
			cout << "Please select the field with which you want to Choose?\n";
			cout << "1. Delete\n2. Update\n0. Exit\n";
			cout << "*****************************************************" << endl;
			cin >> dz;

			if (dz == 1)
			{
				DeleteKey(tempqueue);

				cout << "\Done.\n0. Exit\n-> ";
				cin >> y;
				goto labs;

			}
			if (dz == 2)
			{
				string l1;
				cout << "Enter new string: ";
				cin >> l1;
				UpdateKey(tempqueue, l1);


				cout << "\Done.\n0. Exit\n-> ";
				cin >> y;
				goto labs;

			}

			if (dz == 0)
			{
				goto labs;
			}


			dz = 0;

		}
		else
		{
			cout << "\nRecord Not Found.\n0. Exit\n-> ";
			cin >> y;
			goto labs;
		}


	}

	removeFiles();
}


void print() {
	int x = -1;
	while (x != 0) {
		system("CLS");
		cout << endl;
		cout << "*************************************" << endl;
		cout << "What KIND of TREE do you want to use?\n";
		cout << "1. BST\n2. AVL\n3. Red-Black\n0. Exit\n";
		cout << "*************************************" << endl;
		cin >> x;
		if (x == 1) {
			BSTree();
		}
		else if (x == 2) {
			AVL();
		}
		else if (x == 3) {
			redblack();
		}
	}
}



int main() {
	print();
}