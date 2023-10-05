#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

struct hashTable
{ 
  string username, password;
} dataAkun[26];

int hashFunction(string password, int tableSize) //menggunakan modulo hashing
{
	int asciiValue = tolower(password[0])-'a'; //mengambil nilai ASCII pada karakter pertama password
	return asciiValue % tableSize; //mengambil nilai modulo sebagai hasil dari hash table
}

void printAll()
{
    for (int i = 0; i < 26; i++) {
        cout << i << "[ " << dataAkun[i].username << "-" << dataAkun[i].password << " ]" << endl;
    }
}


bool login(string username, string password){
	int index = hashFunction(password, 26);
	if (dataAkun[index].username == username && dataAkun[index].password == password){
		cout << "Login berhasil." << endl;
		return true;
	}
	else{
		cout << "Login gagal." << endl;
		return false;
	}
}

void menu (){
	const int tableSize = 26;
	string username, password;
	
	while (true){
		int input_user;
		cout << "MENU" << endl;
		cout << "1. Register" << endl;
		cout << "2. Login" << endl;
		cout << "3. Exit" << endl;
		cout << endl;
		
		cin >> input_user;
		cout << endl;
		
		if (input_user == 1)
		{
			string username, password;
			
			cout << "Masukkan Username :" << endl;
			cin  >> username;
			cout << "Masukkan Password :" << endl;
			cin  >> password;
			
			int index = hashFunction(password, tableSize);
			dataAkun[index].username = username;
			dataAkun[index].password = password;
		}
		else if (input_user == 2){
			cout << "Masukkan Username :" << endl;
			cin >> username;
			cout << "Masukkan Password :" << endl;
			cin >> password;
			
		  login(username, password);		
		}
		else if (input_user == 3)
		{
			printAll();
			
			break;
		}
	}
}

int main()
{
	menu();
	return 0;
	
}
