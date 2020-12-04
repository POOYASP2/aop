#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
/*
class Manager
{
	string name;
	Manager(string username)
	{
		name = username;
	}
	bool create_staff(string code, string name, int age, int price, string password)
	{
		Staff x = Staff();
	}
};
class Staff
{
	string code, name, password;
	int age, price;
	Staff(string codeinp, string nameinp, int ageinp, int priceinp, string passwordinp) {
		code = codeinp;
		name = nameinp;
		age = ageinp;
		price = priceinp;
		password = passwordinp;
	}
};

*/
bool login()
{
	int type;
	string name, password;
	cout << "Please Enter your type:" << endl << "for manager type 1" << endl << "for storeman type 2" << endl;
	cin >> type;
	system("cls");
	cout << "enter your usrname:";
	cin.ignore();
	getline(cin, name);
	cout << endl << "enter your password:";
	getline(cin, password);
	if (type == 1) {
		fstream file;
		file.open("manager.txt",  ios::in);
		string userfile, passfile;
		while (file >> userfile >> passfile)
		{
			if (userfile == name && passfile == password) {
				return true;
			}

		}

		file.close();
		return false;
	}
}


int main() {
	int breackcon = 1;
	while (breackcon) {
		if (login()) {
			cout << endl << "True";
			breackcon = 0;
		}
		else {
			cout <<endl<< "this the false mother fucker if u want exit type 0 but if u wa 1";
			cin >> breackcon;
		}

	}
	int a;
	cin >> a;


}



