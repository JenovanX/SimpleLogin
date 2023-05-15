#include <iostream>
#include <string>
#include <fstream>
using namespace std;
// have it read an input to set username
// have it read input to set password
// save these parameters in a file
// check if these parameters match when inputting username and password.
int createmethod();
int loginmethod();
string choicemethod(string x);

int main()
{
    string choice;
    printf("Welcome to the simple login page, would you like to create an account or login?\ntype 'create' to create an account, or 'login' for loging in: ");
    cin >> choice;
    choicemethod(choice);
}
string choicemethod(string x)
{

    if (x == "create")
    {
        createmethod();
        main();
    }
    else if (x == "login")
    {
        loginmethod();
    }
    else
    {
        printf("thats not an option, try again\n");
        cin >> x;
        choicemethod(x);
    }
    return x;
}
int createmethod()
{
    string user;
    string pass;
    string confirmpass;
    printf("You have chosen to create an account, to start, enter a username(this can be anything): ");
    cin >> user;
    printf("\nNow choose a password, this can be anything aswell: ");
    cin >> pass;
    printf("\nNow confirm your password: ");
    cin >> confirmpass;
    if (confirmpass == pass)
    {
        printf("\nyou have now created an account");
    }
    else
    {
        printf("\nthat was incorrect, please retry the whole thing again");
    }
    ofstream Makefile("usernamepassword.txt");
    Makefile << user << "\n"
             << pass << "\n";
    Makefile.close();
    printf("\nYou will now be sent back to the main menu:\n");
}
int loginmethod()
{
    ifstream Openfile("usernamepassword.txt");
    string username;
    string usercheck;
    string password;
    string checkpass;
    printf("please enter your username: \n");
    cin >> username;
    getline(Openfile, usercheck);
    printf("please enter your password: \n");
    cin >> password;
    getline(Openfile, checkpass);
    Openfile.close();
    if (usercheck == username && password == checkpass)
    {
        printf("you are now logged in\n");
    }
    else
    {
        string input;
        printf("incorrect username or password, please try again\n");
        printf("If you would like to create an account, please type 'create'\n");
        cin >> input;
        if(input == "create"){
            createmethod();
            main();
        }
        else{
            loginmethod();
        }
    }
}