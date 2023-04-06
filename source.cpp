#include <iostream>
#include <string>
#include<string.h>
#include <vector>
#include <cctype>
#include<stdio.h>
using namespace std;
using std::cin, std::cout, std::string, std::endl;
int numMoviesRented = 0;
const int MAX_MOVIES = 100;
int day, month, year, day_return, month_return, year_return;
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
struct MovieRental {
    string title;
    string customer;
    int rentalPeriod;
    float rentalFee;
} rentedMovies[MAX_MOVIES];
struct User {
    string name;
    int id;
}user, users[100];
int returnDate(int rentalPeriod);
int dayenter();
int monthenter();
int yearenter();
int over_due_fn(int dof[3], int dof2[3], double price);
void rent_movie(int n);
int addid();
string addname();
void add_new_user(int n);
void inputmovie(int n);
void movie_rented();
void display_all(int n);
int main() {
}
void display_all(int n) {      //to display all users data
    for (int i = 0; i < n; i++) {
        cout << "Name : " << users[i].name << endl;
        cout << "ID : " << users[i].id << endl;
        cout << "____________" << endl;
    }
}
void rent_movie(int n) {
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the movie title you want to rent: ";
        getline(cin, rentedMovies[i].title);
        cout << "Enter the customer name: ";
        getline(cin, rentedMovies[i].customer);
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
        do
        {
            cin >> rentedMovies[i].rentalFee;
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
        numMoviesRented++;
    }
}
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
void inputmovie(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter movie name : ";
        getline(cin, m[i].name);
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
        getline(cin, m[i].language);
        cout << "added" << endl;
    }
}
int returnDate(int rentalPeriod)
{
    cout << "Enter Today's Date" << endl << "(Date, Month then Year):\n";
    day = dayenter();
    month = monthenter();
    year = yearenter();
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
    cout << "The Return Date is:\n" << day << "/" << month << "/" << year;
}
int monthenter()
{
    do {
        cin >> month;
        if (cin.fail() || month > 12)
        {

            cout << "invalid input" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        else
        {
            return month;
            break;
        }
    } while (true);
}
int dayenter()
{
    do {
        cin >> day;
        if (cin.fail() || day > 31)
        {
            cout << "invalid input" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        else
        {
            return day;
            break;
        }
    } while (1);
}
int yearenter()
{

    if (((month == 4 || month == 6 || month == 9 || month == 11) && day > 30))
    {
        cout << "invalid day input" << endl;
        day = dayenter();
    }
    else if (((year % 4 == 0) && ((year % 400 == 0) || (year % 100 != 0))) && month == 2 && day > 29)
    {

        cout << "invalid day input" << endl;
        day = dayenter();

    }
    else if (month == 2 && day > 28)
    {

        cout << "invalid day input" << endl;
        day = dayenter();

    }
    cin >> year;
    do {

        if (cin.fail())
        {
            cout << "invalid input" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        else
        {
            return year;
            break;
        }
    } while (1);
}
void add_new_user(int n)
{
    for (int i = 0; i < n; i++)
    {
        users[i].name = addname();
        users[i].id = addid();
    }
}
int addid()
{
    int x;
    cout << "Enter user id: " << endl;
    do {
        cin >> x;
        if (cin.fail())
        {
            cout << "invalid input" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        else
        {
            break;
        }
    } while (1);
    return x;
}
string addname()
{
    string s;
    cout << "Enter user name: " << endl;
    getline(cin, s);
    return s;
}
int over_due_fn(int dof[3], int dof2[3], double price) //  index[0] is the day and index[1]is the month  and index [2] is the  yerar
{
    double period;// period is the period that the user had the film with him
    double  overdue;
    if (dof[1] == dof2[1] && abs(dof2[0] - dof[0]) <= 7 && dof[2] == dof2[2])
    {
        cout << "there is no overdue fee, thanks for chosing our movie store";
    }
    else
    {
        if (dof[2] == dof2[2] && dof[1] == dof2[1]) //check if the user returned the film in the same month and same year
        {
            period = (dof2[0] - dof[0]) - 7;
            overdue = .1 * price * period;
            cout << "you should have returned the film scince " << period << " dayes ago, so your fee is " << overdue;
            return overdue;
        }
        else if (dof[2] == dof2[2] && (dof2[1] - dof[1]) == 1)//check if the user returned the film in diffrent month and same year
            //all  monthes casee is under this line
        {
            switch (dof[1])
            {
            case(1):
            case(3):
            case(5):
            case(7):
            case(8):
            case(10):
                period = abs(((31 - dof[0]) + dof2[0])) - 7;
                overdue = .1 * price * period;
                cout << "you should have returned the film scince " << period << " dayes ago, so your fee is " << overdue;
                break;
            case(2):
                period = abs(((28 - dof[0]) + dof2[0])) - 7;
                overdue = .1 * price * period;
                cout << "you should have returned the film scince " << period << " dayes ago, so your fee is " << overdue;
                break;
            case(4):
            case(6):
            case(9):
            case(11):
                period = abs(((30 - dof[0]) + dof2[0])) - 7;
                overdue = .1 * price * period;
                cout << "you should have returned the film scince " << period << " dayes ago, so your fee is " << overdue;
                break;
                return overdue;
            }
        }
        else if (dof[2] != dof2[2] && dof[1] == 12 && dof2[1] == 1)
        {
            period = abs(((31 - dof[0]) + dof2[0])) - 7;
            overdue = .1 * price * period;
            cout << "you should have returned the film scince " << period << " dayes ago, so your fee is " << overdue;
            return overdue;
        }
        else
        {
            cout << "you have been so much late so You will pay 10 times the original price ";
            overdue = 10 * price;
            cout << overdue;
            return overdue;
        }
    }
}