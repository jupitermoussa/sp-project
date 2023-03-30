#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
struct User {
    string name;
    int id;
}user,users[100];   // struct to get data for one user at a time and.. another one to save data for 100 users
 
User add_new_user() {  //add one user at a time function
 
    cout << "Enter user name: "<<endl;
    getline(cin, user.name);
 
    cout << "Enter user id: "<<endl;
    cin.ignore();
    cin >> user.id;
 
 
 
    return user;         //to transfer one user data to another big structure
}
void display_all(int n) {      //to display all users data
    for (int i = 0; i < n; i++) {
        cout <<"Name : " << users[i].name << endl;
        cout << "ID : " <<users[i].id << endl;
        cout << "__________________________________"<<endl;
    }
}
 
int main(){
 
    int n_of_users = 0; // to be used as a number of display
    char ch;         //to continue or stop
    int i = 0; //counter for copying one user data to a bigger struct
 
    do {
 
        users[i]= add_new_user();  // to transfer one user data into bigger structure
        i++;              // to continue transferring 
        n_of_users++;       // that's one user in
 
            cout << "Do you wish to add more user? (Y/N)"<<endl;
            cin >> ch;
            cin.ignore();
 
    } while (ch=='y' || ch == 'Y');
 
    display_all(n_of_users);
 
}