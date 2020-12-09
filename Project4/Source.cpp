#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
//GLOBAL VECTOR
fstream file;
//vector<Staff> list_of_staffs;
int reverse(int num)
{
	int rem, reverse = 0;
	while (num != 0)
	{
		rem = num % 10;
		reverse = reverse * 10 + rem;
		num /= 10;
	}
	return reverse;
}
class Manager
{
public:
	string name;
	Manager(string username)
	{
		name = username;
	}
	void addStaff()
	{
		int forbreak = 1;
		string name;
		int code, age, price, password;
		system("cls");
		while (forbreak)
		{
			try
			{
				cout << "Please enter code:" << endl;
				cin >> code;
				if (code < 10 || code > 99)
				{
					throw string("your code is must corrcet!");
				}
				cout << "please enter the name" << endl;
				cin >> name;
				cout << "please enter the age " << endl;
				cin >> age;
				if (age > 50 || age < 25)
				{
					throw string("your age is must corrcet!");
				}
				cout << "please enter the price" << endl;
				cin >> price;
				if (price <= 0)
				{
					throw string("your price is must corrcet!");
				}
				cout << "please enter the pass" << endl;
				cin >> password;
				if (password == reverse(password) || password < 1000)
				{
					throw string("your password is must corrcet!");
				}
				else
				{
					forbreak = 0;
				}
			}
			catch (string msg)
			{
				cout << msg;
			}
		}
		fstream file("Warehousemans.txt", ios::app);
		file << code << ' ' << name << ' ' << age << ' ' << price << ' ' << password << endl;
		file.close();

	}
	void mangerMunue()
	{
		while (true)
		{
			cout << "Wellcome back" << name << endl;
			cout << "Please for:" << endl
				<< "Add Staff enter 1" << endl
				<< "Show Items enter 2" << endl
				<< "show items less 5 count enter 3" << endl
				<< "show must staff enter 4" << endl;
			int choice;
			cin >> choice;
			switch (choice)
			{
			case 1:
				addStaff();
				break;
			}
		}
	}
};
class Staff
{
public:
	string name;
	int code, age, price, password;
	Staff(int codeinp, string nameinp, int ageinp, int priceinp, int passwordinp)
	{
		code = codeinp;
		name = nameinp;
		age = ageinp;
		price = priceinp;
		password = passwordinp;
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
		string nameI, string codeI, string codeInputerI, int priceI, int storeI)
	{
		code = codeI;
		name = nameI;
		codeInputer = codeInputerI;
		price = priceI;
		store = storeI;
	};
};
bool login(string name, int type)
{
	int password;
	cout << endl
		<< "enter your password:";
	cin >> password;
	if (type == 1)
	{
		file.open("manager.txt", ios::in);
		string userfile;
		int passfile;
		while (file >> userfile >> passfile)
		{
			if (userfile == name && passfile == password)
			{
				return true;
			}
		}

		file.close();
		return false;
	}
}

int main()
{
	int breackcon = 1;
	int type;
	string USERNAME;
	while (breackcon)
	{
		cout << "Please Enter your type:" << endl
			<< "for manager type 1" << endl
			<< "for storeman type 2" << endl;
		cin >> type;
		system("cls");
		cout << "enter your usrname:";
		cin>> USERNAME;
		if (login(USERNAME, type) && type == 1)
		{
			Manager persona(USERNAME);
			persona.mangerMunue();
			breackcon = 0;
		}
		else if (login(USERNAME, type))
		{
			cout << endl
				<< "True";
			breackcon = 0;
		}
		else
		{
			cout << endl
				<< "this the false  if u want exit type 0 but if u wa 1";
			cin >> breackcon;
		}
	}
	int a;
	cin >> a;
}
