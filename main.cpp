#include<iostream>
#include<windows.h>
#include<mmsystem.h>
#include<string>
#include<cmath>
#include <stdlib.h>
#include<fstream>
using namespace std;
SetColor(int value)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),value);
}
class Login
{
	private:
		
		string username = "officer007";
        string password = "crypto";
        bool accessGranted;
     public:
         string Var_user;
         string Var_password;

         Login()
		 {

            accessGranted = 0;
         }

         void loginFunction()
		 {
             SetColor(10);cout << "\nUsername: ";
             SetColor(12);cin >> Var_user;
             if(Var_user!=username)
			 {
			 	PlaySound(TEXT("alert.wav"),NULL,SND_SYNC);
			 	cout << "\nInvalid username!!!\nThe program is terminated!" << endl;
			 	exit(0);
			 }
                SetColor(10);cout << "Password: ";
                SetColor(12);cin >> Var_password;

                if(Var_password!=password)
				{
					PlaySound(TEXT("alert.wav"),NULL,SND_SYNC);
					cout << "\nInvalid password!!!\nThe program is terminated!" << endl;
                    exit(0);
                }
                cout << endl;
        }
};
class header
{
	public:
	header()
	{
		SetColor(10);cout << "\n\t\t\t                         ---------------------------------------" << endl;
    cout << "\t\t\t                         | PAKISTAN ARMY CRYPTOGRAPHY SOFTWARE |" << endl;
    cout << "\t\t\t                         ---------------------------------------" << endl;
    cout << endl;
    SetColor(12);cout << "\n\n                                \t\t\t>>>Important Note<<<" << endl;
    cout << "_____________________________________________________________________________________________________________________________________"<<endl<<endl;
    cout << "1) Due to security concerns you have only one attempt to enter a username and password." << endl;
    cout << "2) If username or password is wrong the software is terminated automatically." << endl << endl;
    cout << "_____________________________________________________________________________________________________________________________________"<<endl;
	cout << endl;
	}
};
class graphics
{
	private:
		char x = 220;
	public:
		graphics()
		{
		  for(int i=0; i<35; i++)
	      {
		    cout << x;
		    if(i<10)
		    Sleep(300);
		    if(i>=10 && i<20)
		    Sleep(150);
		    if(i>=10)
		    Sleep(25);
	    }
	        cout << " 100%";
		}
};

void reverse_cipher(string &str) 
{ 
    int n = str.length(); 
    for (int i = 0; i < n / 2; i++)
	{ 
        swap(str[i], str[n - i - 1]);
    }
} 

void S_cipher(string &str) 
{
   char cipher_key = 'S';
   int len = str.length();
   
   for (int i = 0; i < len; i++)
   {
      str[i] = str[i] ^ cipher_key;
   }
}

void XOR_cipher(string &str)
{
   char key[] = "ObjectOrientedProgramming";
   int len = str.length();
   int j = 0;
   for (int i = 0; i < len; i++)
   {
      	str[i] = str[i] ^ key[i];
   }
}
int main()
{
	header h1;
	Login obj1, obj2;
    obj1.loginFunction();
    char again ='Y';
while (again == 'y' || again == 'Y')
{
		int i=0;
	int x=0;
	string str;
	str.clear();
	
	SetColor(10);cout << "\nPlease choose following options: " << endl;
	cout << "1. Encrypting the file." << endl;
	cout << "2. Decrypting the file." << endl;
	cout << "\n\nEnter your choice: ";
	SetColor(12);cin >> x;
	cout << endl;
	switch(x)
	{
		case 1:
			{
			SetColor(10);string filename1;
			cout << "Enter the file name that you want to encrypt: ";
			SetColor(12);cin >> filename1;
			cout << endl;
			ifstream infile(filename1.c_str(), ios::binary);
	if(infile.is_open())
	{
		while(getline(infile,str))
		{
			reverse_cipher(str);
			for(i=0; i<str[i] ;i++)
			{
				str[i]=str[i]+3;
			}
			
			S_cipher(str);
			for(i=0; i<str[i] ;i++)
			{
				str[i]=str[i]+6;
			}
			
			XOR_cipher(str);
			for(i=0; i<str[i] ;i++)
			{
				str[i]=str[i]+7;
			}
			/*cout << "\nEncryped string: " << str << endl;*/
			ofstream outFile("encryptedfile.txt",ios::app | ios::binary);
			if(outFile.is_open())
			{
				outFile << str <<endl;
			}
			outFile.close();
		}
		infile.close();
		cout << "Encrypting File..." << endl;
		SetColor(10);graphics obj1;
		Sleep(800);
		SetColor(12);cout << "\n\nFile is encrypted successfully!!!" << endl;
		cout << "\n\nSaving encrypted data in file..." << endl;
		SetColor(10);graphics obj2;
		Sleep(800);
		SetColor(12);cout << "\n\nEncryptedfile.txt is created successfully!!!\n" << endl;
		PlaySound(TEXT("congo.wav"),NULL,SND_SYNC);
	}
	else
	{
		cout << "File is not found!!!" << endl;
	}
	break;
}
		case 2:
	    {
	    	system("cls");
	    	header h2;
	        cout << endl;
	    	cout << "\nNote: This feature is locked. Kindly enter username and password again."<<endl;
	    	obj2.loginFunction();
	    	SetColor(10);string filename2;
			cout << "Enter the file name that you want to decrypt: ";
			SetColor(12);cin >> filename2;
			cout << endl;
	    	ifstream decfile(filename2.c_str(), ios::binary);
	if(decfile.is_open())
	{
		while(getline(decfile,str))
		{
			for(i=0; i<str[i] ;i++)
			{
				str[i]=str[i]-7;
			}
			XOR_cipher(str);
			
			for(i=0; i<str[i] ;i++)
			{
				str[i]=str[i]-6;
			}
			S_cipher(str);
			
			for(i=0; i<str[i] ;i++)
			{
				str[i]=str[i]-3;
			}
			reverse_cipher(str);
			
			/*cout << "\nDecryped string: " << str << endl;*/
			ofstream endFile("decryptedfile.txt",ios::app | ios::binary);
			if(endFile.is_open())
			{
				endFile << str <<endl;
			}
			endFile.close();
		}
		decfile.close();
		cout << "Decrypting File..." << endl;
		SetColor(10);graphics obj3;
		Sleep(800);
		SetColor(12);cout << "\n\nFile is decrypted successfully!!!" << endl;
		cout << "\n\nSaving decrypted data in file..." << endl;
		SetColor(10);graphics obj4;
		Sleep(800);
		SetColor(12);cout << "\n\nDecryptedfile.txt is created successfully!!!\n" << endl;
		PlaySound(TEXT("congo.wav"),NULL,SND_SYNC);
    }
    else
	{
		cout << "File is not found!!!" << endl;
	}
			break;
        }
		default:
			{
				cout << "\n Invalid Input!!!" << endl;
			}
			
	}
	SetColor(10);cout << "\nRun Software again? (y/n): ";
	SetColor(12);cin >> again;
}

	system("pause");
	return 0;
}
