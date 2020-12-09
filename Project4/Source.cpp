#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
//GLOBAL VECTOR
fstream file;
vector<Staff> list_of_staffs;

class Manager
{
	string name;
	Manager(string username)
	{
		name = username;
	}
	void create_staff(string code, string name, int age, int price, string password)
	{
		Staff name(code, name, age, price, password);
	}
};
class Staff
{
public:
	string code, name, password;
	int age, price;
	Staff(string codeinp, string nameinp, int ageinp, int priceinp, string passwordinp) {
		code = codeinp;
		name = nameinp;
		age = ageinp;
		price = priceinp;
		password = passwordinp;
		file.open("Warehousemans.txt", ios::out);
		if (file){
			file << code << name << age << price << password;
		}
	}
};
class Item
{
public:
	//Date 
	string code, name, codeInputer;
	int price, store;
	// Methods
	Item(
		string nameI, string codeI, string codeInputerI, int priceI, int storeI
		){
		code = codeI;
		name = nameI;
		codeInputer = codeInputerI;
		price = priceI;
		store = storeI;
	};
};
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
		file.open("manager.txt", ios::in);
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
			cout << endl << "this the false mother fucker if u want exit type 0 but if u wa 1";
			cin >> breackcon;
		}

	}
	int a;
	cin >> a;


}



