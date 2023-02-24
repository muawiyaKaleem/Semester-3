#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main()
{
	regex Number{ "[0-9]+" }; // Number validation
    regex Uppercase{ "[A-Z]+" }; // Alphabet validation
    regex Character{ "[@!?]+" }; // character validation
    
    // input from user for password
	string input;
    cout << "Enter password for validation => ";
    getline(cin,input);

    //check the length of the password
    if(input.length() > 5 && input.length() < 11)
    {
        bool x = regex_search(input,Number);
        bool y = regex_search(input,Uppercase);
        bool z = regex_search(input,Character);

        if( x && y && z)
        {
            cout << "Your password is valid" << endl;
        }
		else
        {
            cout << "Your password is invalid";
        }

    }

    else
    {
        cout << "Invalid password length" << endl;
    }

    return 0;
}