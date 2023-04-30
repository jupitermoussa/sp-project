#include <iostream>
#include <string>
#include<string.h>
#include <vector>
#include <cctype>
#include<stdio.h>
#include <fstream>
using namespace std;
//using std::cin, std::cout, std::endl, std::string;
namespace file {
    int x = 0;
    int j = 0;
}
bool x = true;
int n_movie = 0, n_customer = 0, dof2[3] = {};
struct DATE {
    int day, month, year;
};
struct Time
{
    int minutes, hours;
};
struct movie {
    string name, language;
    Time duration;
    double price;
    bool rented=0;
    int id, year, numberofmoviesexist ,rentalfee, languagesnumbers;
}m[1000];
struct Customer {
    string first_name, last_name;
    int id, rentalPeriod,rentalFee,rentmovieid;
    double overdueprice;
    bool renting = 0,overdue=0;
    DATE  rent_date;
} customers[1000];
int dayenter();
int monthenter();
int yearenter();
double over_due_fn(int a, int b, int c, int price);
void rent_movie();
string addname();
void today_date();
void add_new_customer();
void inputmovie();
void display_movie_rented();
void display_all_customers();
void display_all_movies();
void check_overdue();
void display_overdue();
int main() {
    string my;
    string him;
    int y = 4;
    ifstream customerlist2;
    customerlist2.open("customer.txt");
    for (int mor = 0; mor < 5; mor++) {
        customerlist2 >>customers[mor].first_name;
        customerlist2 >> customers[mor].last_name;
        customerlist2 >> customers[mor].id;
        customerlist2.ignore();
        mor++;
    }
    customerlist2.close();
    add_new_customer();
    ofstream customerlist;
    customerlist.open("customer.txt", ios::app);
    if (customerlist.is_open()) {
        for (int i = 0; i < file::j; i++) {
            customerlist << customers[i].first_name << " " << customers[i].last_name <<endl << customers[i].id << endl;
        }
    }
    else {
        cout << "failed to open";
        exit(0);
    }
    ifstream moviesfile2;
    moviesfile2.open("movieslist.txt");
    inputmovie();
    for (int ju = 0; ju < 2; ju++) {
        moviesfile2>>m[ju].name;
        moviesfile2.ignore();
        moviesfile2 >> m[ju].duration.hours;
        moviesfile2.ignore();
        moviesfile2 >> m[ju].duration.hours;
        moviesfile2.ignore();
        moviesfile2 >> m[ju].year;
        moviesfile2.ignore();
        moviesfile2 >> m[ju].year;
        moviesfile2>> m[ju].language;
        moviesfile2.ignore();
        moviesfile2 >> m[ju].numberofmoviesexist;
        moviesfile2.ignore();
    }
    moviesfile2.close();
    for (int yu = 0; yu < 2; yu++) {
        cout << m[yu].name << endl;
        cout << m[yu].duration.hours << endl;
        cout << m[yu].duration.minutes << endl;
        cout << m[yu].year << endl;
        cout << m[yu].language << endl;
        cout << m[yu].numberofmoviesexist << endl;
    }
    ofstream moviesfile;
    moviesfile.open("movieslist.txt", ios::app);
    if (moviesfile.is_open()) {
        for (int i = 0; i < file::x; i++) {
            moviesfile << m[i].name << endl << m[i].duration.hours << endl << m[i].duration.minutes << endl << m[i].price << endl << m[i].year << endl << m[i].language << endl << m[i].numberofmoviesexist;
        }
    }
    else {
        cout << "failed to open";
    }
    rent_movie();
    check_overdue();
}
void rent_movie() 
{
    int id_movie, id_customer;
    bool x = 0;
    cout << " enter the number of the movie you want to rent" << endl;
    display_all_movies();
    cin >> id_movie;
    cout << " enter the id of the user" << endl;
    cin >> id_customer;
        cout << "Enter the rental period (in days): ";
        do
        {
            cin >> customers[id_customer].rentalPeriod;
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
            cin >> customers[id_customer].rentalFee;
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
        cout << "Enter Today's Date" << endl << "(Date, Month then Year):";
        do
        {
        customers[id_customer].rent_date.day = dayenter();
        customers[id_customer].rent_date.month = monthenter();
        customers[id_customer].rent_date.year = yearenter();
        if (((customers[id_customer].rent_date.month == 4 || customers[id_customer].rent_date.month == 6 || customers[id_customer].rent_date.month == 9 || customers[id_customer].rent_date.month == 11) && customers[id_customer].rent_date.day > 30))
        {
            cout << "invalid day input" << endl;
            customers[id_customer].rent_date.day = dayenter();
        }
        else if (((customers[id_customer].rent_date.year % 4 == 0) && ((customers[id_customer].rent_date.year % 400 == 0) || (customers[id_customer].rent_date.year % 100 != 0))) && customers[id_customer].rent_date.month == 2 && customers[id_customer].rent_date.day > 29)
        {
            cout << "invalid day input" << endl;
            customers[id_customer].rent_date.day = dayenter();
        }
        else if (customers[id_customer].rent_date.month == 2 && customers[id_customer].rent_date.day > 28)
        {
            cout << "invalid day input" << endl;
            customers[id_customer].rent_date.day = dayenter();
        }
        if (customers[id_customer].rent_date.day - dof2[0] > 0 && customers[id_customer].rent_date.month - dof2[1] > 0 && customers[id_customer].rent_date.year - dof2[2] > 0)
        {
            x = 0;
        }
        else
        {
            x = 1;
        }
        } while (x=0);
        if (customers[id_customer].rentalPeriod == 30)
            customers[id_customer].rent_date.month++;
        if (customers[id_customer].rentalPeriod == 365)
            customers[id_customer].rent_date.year++;
        if (customers[id_customer].rentalPeriod < 30)
        {
            if ((customers[id_customer].rent_date.day + customers[id_customer].rentalPeriod) > 30)
            {
                customers[id_customer].rent_date.day = (customers[id_customer].rent_date.day + customers[id_customer].rentalPeriod) - 30;
                customers[id_customer].rent_date.month++;
            }
            else if ((customers[id_customer].rent_date.day + customers[id_customer].rentalPeriod) < 30)
                customers[id_customer].rent_date.day += customers[id_customer].rentalPeriod;
            if (customers[id_customer].rent_date.month > 12)
            {
                customers[id_customer].rent_date.year++;
                customers[id_customer].rent_date.month = customers[id_customer].rent_date.month - 12;
            }
        }
        if ((customers[id_customer].rentalPeriod > 30) && (customers[id_customer].rentalPeriod < 365))
        {
            while (customers[id_customer].rentalPeriod > 30)
            {
                customers[id_customer].rentalPeriod -= 30;
                customers[id_customer].rent_date.month++;
            }
            if ((customers[id_customer].rent_date.day + customers[id_customer].rentalPeriod) > 30)
            {
                customers[id_customer].rent_date.day = ((customers[id_customer].rent_date.day + customers[id_customer].rentalPeriod) - 30);
                customers[id_customer].rent_date.month++;
            }
            if ((customers[id_customer].rent_date.day + customers[id_customer].rentalPeriod) < 30)
                customers[id_customer].rent_date.day += customers[id_customer].rentalPeriod;
            if (customers[id_customer].rent_date.month > 12)
            {
                customers[id_customer].rent_date.year++;
                customers[id_customer].rent_date.month = customers[id_customer].rent_date.month - 12;
            }
        }
        if (customers[id_customer].rentalPeriod > 365)
        {
            int remaining = (customers[id_customer].rentalPeriod - 365);
            customers[id_customer].rent_date.year++;
            if (remaining < 30)
            {
                if ((customers[id_customer].rent_date.day + remaining) > 30)
                {
                    customers[id_customer].rent_date.day = ((customers[id_customer].rent_date.day + customers[id_customer].rentalPeriod) - 30);
                    customers[id_customer].rent_date.month++;
                }
                if ((customers[id_customer].rent_date.day + remaining) < 30)
                    customers[id_customer].rent_date.day += remaining;
            }
            else if (remaining == 30)
                customers[id_customer].rent_date.month++;
            else if (remaining > 30)
            {
                while (remaining > 30)
                {
                    customers[id_customer].rent_date.month++;
                    remaining -= 30;
                }
                if ((customers[id_customer].rent_date.day + remaining) > 30)
                {
                    customers[id_customer].rent_date.day = ((customers[id_customer].rent_date.day + customers[id_customer].rentalPeriod) - 30);
                    customers[id_customer].rent_date.month++;
                }
                if ((customers[id_customer].rent_date.day + remaining) < 30)
                    customers[id_customer].rent_date.day += remaining;
            }
            if (customers[id_customer].rent_date.month > 12)
            {
                customers[id_customer].rent_date.year++;
                customers[id_customer].rent_date.month = customers[id_customer].rent_date.month - 12;
            }
        }
        cout << "The Return Date is:\n" << customers[id_customer].rent_date.day << "/" << customers[id_customer].rent_date.month << "/" << customers[id_customer].rent_date.year;
        customers[id_customer].renting = 1;
        m[id_movie].numberofmoviesexist--;
        m[id_movie].rented = 1;
}
void display_movie_rented(){
    for (int i = 0; i < n_movie; i++) {
        if (m[i].rented == 1)
        {
            cout << "Movie #" << i + 1 << endl;
            cout << "Title: " << m[i].name << endl;
            cout << "Rental fee: $" << m[i].rentalfee << endl;
        }
        else 
        {
            continue;
        }
    }
};
void display_all_movies() 
{
    for (int  i = 0; i < n_movie; i++)
    {
        cout << m[i].id << " " << m[i].name << endl;
    }
}
void inputmovie()
{
    char ans;
    do {
        cout << "Enter movie name : ";
        cin >> m[n_movie].name;
        cout << "Enter movie in hours : ";
        do {
            cin >> m[n_movie].duration.hours;
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
        m[n_movie].id = n_movie+1;
        cout << "Enter movie in minutes :";
        do {
            cin >> m[n_movie].duration.minutes;
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
            cin >> m[n_movie].price;
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
            cin >> m[n_movie].year;
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
        cout << "Please select the subtitle language of the movie you want to rent :" << endl;
        cout << "1. English" << endl;
        cout << "2. French" << endl;
        cout << "3. German" << endl;
        cout << "4. Spanish" << endl;
        cout << "5. Italian" << endl;
        cout << "6. Arabic" << endl;
        do {
            cin >> m[n_movie].languagesnumbers;
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
        if (m[n_movie].languagesnumbers == 1)
            m[n_movie].language = "english";
        else if (m[n_movie].languagesnumbers == 2)
            m[n_movie].language = "french";
        else if (m[n_movie].languagesnumbers == 3)
            m[n_movie].language = "german";
        else if (m[n_movie].languagesnumbers == 4)
            m[n_movie].language = "spanish";
        else if (m[n_movie].languagesnumbers == 5)
            m[n_movie].language = "italian";
        else if (m[n_movie].languagesnumbers == 6)
            m[n_movie].language = "arabic";
        cout << "enter number of movies exist:";
        do
        {
            cin >> m[n_movie].numberofmoviesexist;
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
        cout << "addded" << endl;
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    file::x++;
}
void add_new_customer()
{
    do {
        char ans;
        cout << "enter cutomer first name" << endl;
        customers[n_customer].first_name = addname();
        cout << "enter customer last name" << endl;
        customers[n_customer].last_name = addname();
        customers[n_customer].id = n_customer;
        n_customer++;
        file::j++;
        cout << "  do you want to contnue" << endl;
        cin >> ans;
        if (ans == 'y' || ans == 'Y')
            continue;
        else
            break;
    } while ( 1);
}
string addname()
{
    string s;
    cin>> s;
    return s;
}
double over_due_fn(int rent_day, int rent_month, int rent_year, int price) //  index[0] is the day and index[1]is the month  and index [2] is the  yerar
{
    double period;// period is the period that the user had the film with him
    double  overdue;
    if (rent_month == dof2[1] && abs(dof2[0] - rent_day) <= 7 && rent_year == dof2[2])
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
                return overdue;
                break;
            case(2):
                period = abs(((28 - rent_day) + dof2[0])) - 7;
                overdue = .1 * price * period;
                cout << "you should have returned the film scince " << period << " days ago, so your fee is " << overdue;
                break;
                return overdue;
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
void display_all_customers() {
    for (int i = 0; i < n_customer; i++) {
        cout << "Name : " << customers[i].first_name <<" " << customers[i].last_name << endl;
        cout << "ID : " << customers[i].id << endl;
        cout << "____" << endl;
    }
}
void today_date()
{
    int day, month, year;
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
}
void check_overdue()
{
    for (int i = 0; i < n_customer; i++)
    {
        if (customers[i].renting)
        {
            customers[i].overdueprice = over_due_fn(customers[i].rent_date.day, customers[i].rent_date.month, customers[i].rent_date.year, customers[i].rentalFee);
        }
        else
        {
            continue;
        }
    }
}
void display_overdue() 
{
    for (int i =0;i<n_customer;i++)
    {
        if (customers[i].overdue)
        {
            cout << customers[i].first_name << " " << customers[i].last_name << " " << customers[i].id << customers[i].overdueprice << endl;
        }
        else
        {
            continue;
        }
    }

}