#include <iostream>
using namespace std;
int main()
{
	int choice;
	bool gameOn = true;
	while (gameOn != false) {
		cout << "*******************************" << endl;
		cout << " 1 - Start the game." << endl;
		cout << " 2 - Story." << endl;
		cout << " 3 - Help." << endl;
		cout << " 4 - Exit." << endl;
		cout << " Enter your choice and press return: ";
		cin >> choice;
		//Add Menu
		switch (choice)
		{
		case 1:
			cout << "game start!" << endl;

			break;
		case 2:
			cout << "Story:" << endl;

			break;
		case 3:
			cout << "Help" << endl;

			break;
		case 4:
			cout << "End  Program." << endl;


			gameOn = false;
			break;
		default:
			cout << "Not a Valid Choice." << endl;
			cout << "Choose again." << endl;
			cin >> choice;
			break;
		}

	}
	return 0;
}