#include <iostream>
#include <string>
#include <vector>
#include <fstream>


using namespace std;
//GLOBAL VECTOR
fstream file;
vector<Staff> list_of_staffs;
int reverse(int str)
{
	return str;
}
class Manager
{
	public:
		string name;
		Manager(string username)
		{
			name = username;
		}
		void create_staff(int code, string name, int age, int price, int password)
		{
			Staff name(code, name, age, price, password);
		}
};
class Staff
{
public:
	string  name, password;
	int code, age, price;
	Staff(int codeinp, string nameinp, int ageinp, int priceinp, string passwordinp) {
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
int login()
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
				return type;
			}

		}

		file.close();
		return false;
	}
}
void addStaff(){
	int forbreak = 1;
	system("cls");
	while (forbreak)
	{
		string  name, password;
		int code, age, price;
		try{
			cout << "Please enter code:";
			cin >> code;
			if (code<10 && code>99){
				throw string("your code is must corrcet!");
			}
			cin >> name;
			cin >> age;
			if (age > 50 && age < 25){
				throw string("your age is must corrcet!");
			}
			cin >> price;
			if (price <= 0){
				throw string("your price is must corrcet!");
			}
			cin >> password;
			if (password == reverse(password) && password.length())

		}
		catch (string msg){
			cout << msg;
		}
	}
}
void mangerMunue(Manager persona){
	while (true)
	{
		cout << "Wellcome back" << persona.name<<endl;
		cout << "Please for:" << endl << "Add Staff enter 1" << endl << "Show Items enter 2" << endl << "show items less 5 count enter 3" << endl << "show must staff enter 4"<<endl;
		int choice;
		cin >> choice;
		switch (choice) {
		case 1:
			addStaff();
			break;
		}
	}
}
int main() {
	int breackcon = 1;
	while (breackcon) {
		if (login() == 1) {
			mangerMunue();
			breackcon = 0;
		}
		else if (login() == 2){
			cout << endl << "True";
			breackcon = 0;
		}
		else {
			cout << endl << "this the false  if u want exit type 0 but if u wa 1";
			cin >> breackcon;
		}

	}
	int a;
	cin >> a;


}



