#include <iostream>
#include <string>
#include<string.h>
#include <vector>
#include <cctype>
#include<stdio.h>
#include<time.h>
using namespace std;
int numMoviesRented;
const int MAX_MOVIES = 100;
struct DATE {
    int day;
    int month;
    int year;
};
struct Time 
{
    int minutes;
    int hours;


};
struct movie {
    string name;
    Time duration;
    double price;
    int year;
    string language;
}m[100];
struct MovieRental {
    string title;
    string customer;
    int rentalPeriod;
    int rentalFee;
    DATE  rent_date;
} rentedMovies[MAX_MOVIES];
struct User {
    string name;
    int id;
} users[100];
//void returnDate(int rentalPeriod);
int dayenter();
int monthenter();
int yearenter();
int over_due_fn(int a,int b,int c, int price);
void rent_movie(int n);
int addid();
string addname();
void add_new_user(int n);
void inputmovie(int n);
void movie_rented();
void display_all(int n);
int main() {
    int overdue ;
    rent_movie(1);
    overdue = over_due_fn(rentedMovies[0].rent_date.day, rentedMovies[0].rent_date.month, rentedMovies[0].rent_date.year, rentedMovies[0].rentalFee);
    cout << overdue;
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
        cout << "Enter Today's Date" << endl << "(Date, Month then Year):\n";
        rentedMovies[i].rent_date.day = dayenter();
        rentedMovies[i].rent_date.month = monthenter();
        rentedMovies[i].rent_date.year = yearenter();
        if (((rentedMovies[i].rent_date.month == 4 || rentedMovies[i].rent_date.month == 6 || rentedMovies[i].rent_date.month == 9 || rentedMovies[i].rent_date.month == 11) && rentedMovies[i].rent_date.day > 30))
        {
            cout << "invalid day input" << endl;
            rentedMovies[i].rent_date.day = dayenter();
        }
        else if (((rentedMovies[i].rent_date.year % 4 == 0) && ((rentedMovies[i].rent_date.year % 400 == 0) || (rentedMovies[i].rent_date.year % 100 != 0))) && rentedMovies[i].rent_date.month == 2 && rentedMovies[i].rent_date.day > 29)
        {
            cout << "invalid day input" << endl;
            rentedMovies[i].rent_date.day = dayenter();
        }
        else if (rentedMovies[i].rent_date.month == 2 && rentedMovies[i].rent_date.day > 28)
        {
            cout << "invalid day input" << endl;
            rentedMovies[i].rent_date.day = dayenter();
        }
        if (rentedMovies[i].rentalPeriod == 30)
            rentedMovies[i].rent_date.month++;
        if (rentedMovies[i].rentalPeriod == 365)
            rentedMovies[i].rent_date.year++;
        if (rentedMovies[i].rentalPeriod < 30)
        {
            if ((rentedMovies[i].rent_date.day + rentedMovies[i].rentalPeriod) > 30)
            {
                rentedMovies[i].rent_date.day = (rentedMovies[i].rent_date.day + rentedMovies[i].rentalPeriod) - 30;
                rentedMovies[i].rent_date.month++;
            }
            else if ((rentedMovies[i].rent_date.day + rentedMovies[i].rentalPeriod) < 30)
                rentedMovies[i].rent_date.day += rentedMovies[i].rentalPeriod;
            if (rentedMovies[i].rent_date.month > 12)
            {
                rentedMovies[i].rent_date.year++;
                rentedMovies[i].rent_date.month = rentedMovies[i].rent_date.month - 12;
            }
        }
        if ((rentedMovies[i].rentalPeriod > 30) && (rentedMovies[i].rentalPeriod < 365))
        {
            while (rentedMovies[i].rentalPeriod > 30)
            {
                rentedMovies[i].rentalPeriod -= 30;
                rentedMovies[i].rent_date.month++;
            }
            if ((rentedMovies[i].rent_date.day + rentedMovies[i].rentalPeriod) > 30)
            {
                rentedMovies[i].rent_date.day = ((rentedMovies[i].rent_date.day + rentedMovies[i].rentalPeriod) - 30);
                rentedMovies[i].rent_date.month++;
            }
            if ((rentedMovies[i].rent_date.day + rentedMovies[i].rentalPeriod) < 30)
                rentedMovies[i].rent_date.day += rentedMovies[i].rentalPeriod;
            if (rentedMovies[i].rent_date.month > 12)
            {
                rentedMovies[i].rent_date.year++;
                rentedMovies[i].rent_date.month = rentedMovies[i].rent_date.month - 12;
            }
        }
        if (rentedMovies[i].rentalPeriod > 365)
        {
            int remaining = (rentedMovies[i].rentalPeriod - 365);
            rentedMovies[i].rent_date.year++;
            if (remaining < 30)
            {
                if ((rentedMovies[i].rent_date.day + remaining) > 30)
                {
                    rentedMovies[i].rent_date.day = ((rentedMovies[i].rent_date.day + rentedMovies[i].rentalPeriod) - 30);
                    rentedMovies[i].rent_date.month++;
                }
                if ((rentedMovies[i].rent_date.day + remaining) < 30)
                    rentedMovies[i].rent_date.day += remaining;
            }
            else if (remaining == 30)
                rentedMovies[i].rent_date.month++;
            else if (remaining > 30)
            {
                while (remaining > 30)
                {
                    rentedMovies[i].rent_date.month++;
                    remaining -= 30;
                }
                if ((rentedMovies[i].rent_date.day + remaining) > 30)
                {
                    rentedMovies[i].rent_date.day = ((rentedMovies[i].rent_date.day + rentedMovies[i].rentalPeriod) - 30);
                    rentedMovies[i].rent_date.month++;
                }
                if ((rentedMovies[i].rent_date.day + remaining) < 30)
                    rentedMovies[i].rent_date.day += remaining;
            }
            if (rentedMovies[i].rent_date.month > 12)
            {
                rentedMovies[i].rent_date.year++;
                rentedMovies[i].rent_date.month = rentedMovies[i].rent_date.month - 12;
            }
        }
        //cout << "The Return Date is:\n" << rentedMovies[i].rent_date.day << "/" << rentedMovies[i].rent_date.month << "/" << rentedMovies[i].rent_date.year;
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
int over_due_fn(int rent_day, int rent_month,  int rent_year, int price) //  index[0] is the day and index[1]is the month  and index [2] is the  yerar
{
    int dof2[3] = {}, day, month, year;
    cout << "Enter Today's Date" << endl << "(Date, Month then Year):\n";
    day = dayenter();
    month = monthenter();
    year = yearenter();
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

    dof2[0] = day;
    dof2[1] = month;
    dof2[2] = year;
    double period;// period is the period that the user had the film with him
    double  overdue;

    if (rent_month == dof2[1] && abs(dof2[0] -rent_day) <= 7 && rent_year == dof2[2])
    {
        cout << "there is no overdue fee, thanks for chosing our movie store";
    }
    else
    {
        if (rent_year == dof2[2] && rent_month == dof2[1]) //check if the user returned the film in the same month and same year
        {
            period = (dof2[0] - rent_day) - 7;
            overdue = .1 * price * period;
            cout << "you should have returned the film scince " << period << " dayes ago, so your fee is " << overdue;
            return overdue;
        }
        else if (rent_year == dof2[2] && (dof2[1] - rent_month) == 1)//check if the user returned the film in diffrent month and same year
            //all  monthes casee is under this line
        {
            switch (rent_month)
            {
            case(1):
            case(3):
            case(5):
            case(7):
            case(8):
            case(10):
                period = abs(((31 - rent_day) + dof2[0])) - 7;
                overdue = .1 * price * period;
                cout << "you should have returned the film scince " << period << " days ago, so your fee is " << overdue;
                break;
            case(2):
                period = abs(((28 - rent_day) + dof2[0])) - 7;
                overdue = .1 * price * period;
                cout << "you should have returned the film scince " << period << " days ago, so your fee is " << overdue;
                break;
            case(4):
            case(6):
            case(9):
            case(11):
                period = abs(((30 - rent_day) + dof2[0])) - 7;
                overdue = .1 * price * period;
                cout << "you should have returned the film scince " << period << " days ago, so your fee is " << overdue;
                break;
                return overdue;
            }
        }
        else if (rent_year != dof2[2] && rent_month == 12 && dof2[1] == 1)
        {
            period = abs(((31 - rent_day) + dof2[0])) - 7;
            overdue = .1 * price * period;
            cout << "you should have returned the film scince " << period << " days ago, so your fee is " << overdue;
            return overdue;
        }
        else
        {
            cout << "you have been so much late so You will pay 10 times the original price ";
            overdue = 10 * price;
           // cout << overdue;
            return overdue;
        }
    }
}
int monthenter()
{
    int month;
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
    int day;
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
    int year;

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
void display_all(int n) {      //to display all users data
    for (int i = 0; i < n; i++) {
        cout << "Name : " << users[i].name << endl;
        cout << "ID : " << users[i].id << endl;
        cout << "____________" << endl;
    }
}
