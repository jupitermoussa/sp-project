#include <iostream>
#include <string>
#include<string.h>
#include <vector>
#include <cctype>
using namespace std;
int numMoviesRented = 0;
const int MAX_MOVIES = 100;
int returnDate(int rentalPeriod);
struct Time {
    int hours;
    int minutes;
};
struct movie {
    string name;
    Time duration;
    float price;
    int year;
    string language;
}m[100];
void inputmovie(int n);
struct User {
    string name;
    int id;
}user, users[100];
void rent_movie(int n) {
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the movie title you want to rent: ";
        cin >> rentedMovies[i].title;

        cout << "Enter the customer name: ";
        cin >> rentedMovies[i].customer;

        cout << "Enter the rental period (in days): ";
        do
        {
            cin >> rentedMovies[i].rentalPeriod;
            if (cin.fail())
            {
                cout << "invalid input" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }
            else
            {
                break;
            }
        } while (true);
        cout << "Enter the rental fee:";
        cin >> rentedMovies[i].rentalFee;
        numMoviesRented++;
    }
}
void add_new_user(int n);
void display_all(int n) {      //to display all users data
    for (int i = 0; i < n; i++) {
        cout << "Name : " << users[i].name << endl;
        cout << "ID : " << users[i].id << endl;
        cout << "____________" << endl;
    }
}
struct MovieRental {
    string title;
    string customer;
    int rentalPeriod;
    float rentalFee;
} rentedMovies[MAX_MOVIES];
void movie_rented() {
    for (int i = 0; i < numMoviesRented; i++) {
        cout << "Movie #" << i + 1 << endl;
        cout << "Title: " << rentedMovies[i].title << endl;
        cout << "Customer: " << rentedMovies[i].customer << endl;
        cout << "Rental period: " << rentedMovies[i].rentalPeriod << " days" << endl;
        cout << "Rental fee: $" << rentedMovies[i].rentalFee << endl;
        cout << endl;
    }
};
int main() {
    int n_of_users = 0; // to be used as a number of display
    char ch;         //to continue or stop
    int i = 0; //counter for copying one user data to a bigger struct
    do {
        users[i] = add_new_user();  // to transfer one user data into bigger structure
        i++;              // to continue transferring 
        n_of_users++;       // that's one user in
        std::cout << "Do you wish to add more user? (Y/N)" << endl;
        cin >> ch;
        cin.ignore();

    } while (ch == 'y' || ch == 'Y');
    display_all(n_of_users);
}
User add_new_user() {  //add one user at a time function
    cout << "Enter user name: " << endl;
    cin.ignore();
    cin >> user.name;
    cout << "Enter user id: " << endl;
    cin.ignore();
    cin >> user.id;
    return user;         //to transfer one user data to another big structure
}
void inputmovie(int n)
{
    for (int i = 0; i < n; i++)
    {
        {
            int i = 0;
            cout << "Enter movie name : ";
            cin.ignore();
            cin >> m[i].name;
            cout << "Enter movie in hours : ";
            do {
                cin >> m[i].duration.hours;
                if (cin.fail())
                {
                    cout << "invaild input" << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    continue;
                }
                else
                {
                    break;
                }
            } while (true);
            cout << "Enter movie in minutes :";
            do {
                cin >> m[i].duration.minutes;
                if (cin.fail())
                {
                    cout << "invalid input" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }
                else
                {
                    break;
                }
            } while (1);
            cout << "Enter movie price : ";
            do
            {
                cin >> m[i].price;
                if (cin.fail())
                {
                    cout << "invalid input" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }
                else
                {
                    break;
                }
            } while (true);
            cout << "Enter movie year : ";
            do
            {
                cin >> m[i].year;
                if (cin.fail())
                {
                    cout << "invalid input" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }
                else
                {
                    break;
                }
            } while (true);
            cout << "Enter movie language : ";
            cin >> m[i].language;
            cout << "added" << endl;
        }
    }
}
int returnDate(int rentalPeriod)
{
    int day, month, year;
    cout << "enter todays date" << endl << "date, month then year:\n";
    do {
        cin >> day;
        if (cin.fail())
        {
            cout << "invalid input" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        else
        {
            break;
        }
    } while (1);
    do
    {
        cin >> month;
        if (cin.fail())
        {

            cout << "invalid input" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        else
        {
            break;
        }
    } while (1);
    do
    {
        cin >> year;
        if (cin.fail())
        {

            cout << "invalid input" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        else
        {
            break;
        }
    } while (true);
    if (rentalPeriod == 30)
        month++;
    if (rentalPeriod == 365)
        year++;
    if (rentalPeriod < 30)
    {
        if ((day + rentalPeriod) > 30)
        {
            day = (day + rentalPeriod) - 30;
            month++;
        }
        else if ((day + rentalPeriod) < 30)
            day += rentalPeriod;
        if (month > 12)
        {
            year++;
            month = month - 12;
        }
    }
    if ((rentalPeriod > 30) && (rentalPeriod < 365))
    {
        while (rentalPeriod > 30)
        {
            rentalPeriod -= 30;
            month++;
        }

        if ((day + rentalPeriod) > 30)
        {
            day = ((day + rentalPeriod) - 30);
            month++;
        }
        if ((day + rentalPeriod) < 30)
            day += rentalPeriod;
        if (month > 12)
        {
            year++;
            month = month - 12;
        }
    }
    if (rentalPeriod > 365)
    {
        int remaining = (rentalPeriod - 365);
        year++;
        if (remaining < 30)
        {
            if ((day + remaining) > 30)
            {
                day = ((day + rentalPeriod) - 30);
                month++;
            }
            if ((day + remaining) < 30)
                day += remaining;
        }
        else if (remaining == 30)
            month++;
        else if (remaining > 30)
        {
            while (remaining > 30)
            {
                month++;
                remaining -= 30;
            }
            if ((day + remaining) > 30)
            {
                day = ((day + rentalPeriod) - 30);
                month++;
            }
            if ((day + remaining) < 30)
                day += remaining;
        }
        if (month > 12)
        {
            year++;
            month = month - 12;
        }
    }
    cout << day << "/" << month << "/" << year;
}