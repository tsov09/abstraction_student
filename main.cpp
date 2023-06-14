#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;



class Person {

    char* firstname = new char[20];
    char* lastname = new char[20];
    char* profession = new char[20];
    char* faculty = new char[20];

    int b_year;
    int b_month;
    int b_day;
    int admission_year;
    double AQA;


    void set_b_year(int year) {
        if (this->admission_year != NULL && this->admission_year <= year) {
            cout << "Year of birth must be less than admission year." << endl;
        }
        else {
            if (year >= 1903 && year <= 2005) {
                this->b_year = year;
            }
            else {
                cout << "Invalid year." << endl;
            }
        }
    }
    void set_b_month(int month) {
        if (month > 0 && month < 13) {
            this->b_month = month;
        }
        else {
            cout << "Invalid month." << endl;
        }
    }
    void set_b_day(int day) {
        if (day > 0) {
            if (this->b_month == 2) {
                if (this->b_year % 4 == 0 && day <= 29) {
                    this->b_day = day;
                }
                else {
                    cout << "Invalid day." << endl;
                }
            }
            else if (this->b_month == 4 || this->b_month == 9 || this->b_month == 11) {
                if (day <= 30) {
                    this->b_day = day;
                }
                else {
                    cout << "Invalid day." << endl;
                }
            }
            else {
                if (day <= 31) {
                    this->b_day = day;
                }
                else {
                    cout << "Invalid day." << endl;
                }
            }
        }
        else {
            cout << "Invalid day." << endl;
        }
    }

    bool is_valid_string(char str[], int size = 20) {
        bool is_valid = true;
        for (int i = 0; i < size; i++) {
            if (str[i] < 65 || (str[i] > 90 && str[i] < 97) || str[i] > 122) {
                return is_valid;
            }
        }
        return is_valid;
    }

    void title_case(char str[], int size) {
        if (str[0] >= 97 && str[0] <= 122) {
            str[0] -= 32;
        }
        for (int i = 1; i < size; i++) {
            if (str[i] >= 65 && str[i] <= 90) {
                str[i] += 32;
            }
        }
    }

public:
    void set_firstname(char* f_name) {
        int size = sizeof(f_name);
        if (size > 20) {
            cout << "Firstname is too long." << endl;
        }
        else {
            if (is_valid_string(f_name, size)) {
                title_case(f_name, size);
                firstname = f_name;
            }
            else {
                cout << "Firstame is invalid." << endl;
            }
        }
    }
    void set_lastname(char* l_name) {
        int size = sizeof(l_name);
        if (size > 20) {
            cout << "Lastname is too long." << endl;
        }
        else {
            if (is_valid_string(l_name, size)) {
                title_case(l_name, size);
                lastname = l_name;
            }
            else {
                cout << "Lastame is invalid." << endl;
            }
        }
    }

    void set_faculty(char* fac) {
        int size = sizeof(fac);
        if (size > 20) {
            cout << "Faculty name is too long." << endl;
        }
        else {
            if (is_valid_string(fac, size)) {
                title_case(fac, size);
                this->faculty = fac;
            }
            else {
                cout << "Faculty name is invalid." << endl;
            }
        }
    }

    void set_profession(char* prof) {
        int size = sizeof(prof);
        if (size > 20) {
            cout << "Profession is too long." << endl;
        }
        else {
            if (is_valid_string(prof, size)) {
                title_case(prof, size);
                this->profession = prof;
            }
            else {
                cout << "Profession is invalid." << endl;
            }
        }
    }

    void set_birth_date(int day, int month, int year) {
        set_b_year(year);
        set_b_day(day);
        set_b_month(month);
    }

    void set_admission_year(int year) {
        if (this->b_year != NULL && this->b_year >= year) {
            cout << "Admission year must be greather than year of birth." << endl;
        }
        else {
            if (year >= 1920 && year < 2023) {
                this->admission_year = year;
            }
            else {
                cout << "Invalid admission year." << endl;
            }
        }
    }

    void set_AQA(double aqa) {
        if (aqa >= 8 && aqa <= 20) {
            this->AQA = aqa;
        }
        else {
            cout << "Invalid AQA value." << endl;
        }
    }

    void output_data() {
        cout << "Fullname: " << this->firstname << " " << this->lastname << ";" << endl
            << "Born on: " << this->b_day << "/" << this->b_month << "/" << this->b_year << ";" << endl
            << "Faculty: " << this->faculty << ";" << endl
            << "Profession: " << this->profession << ";" << endl
            << "Admission year: " << this->admission_year << ";" << endl
            << "AQA value: " << this->AQA << "." << endl << endl;

    }
    /*~Person() {
        delete [] this->firstname, this->lastname, this->faculty, this->profession;
    }*/

};


void fill_student_data() {
    Person person;

    /*char* firstname = new char[20];
    cout << "Enter firstname: ";
    cin >> firstname;*/
    
    char firstname[20] = "armen";
    person.set_firstname(firstname);


    /*char* lastname = new char[20];
    cout << "Enter lastname: ";
    cin >> lastname;*/

    char lastname[20] = "hakobyan";
    person.set_lastname(lastname);


    /*int day, month, year;
    cout << "Enter your birth" << endl;
    cout << "Day: ";
    cin >> day;

    cout << "Month: ";
    cin >> month;

    cout << "Year: ";
    cin >> year;*/

    int day = 5, month = 12, year = 2004;

    person.set_birth_date(day, month, year);

    /*int admiss;
    cout << "Enter admission year" << endl;
    cin >> admiss;*/

    int admiss = 2022;
    person.set_admission_year(admiss);

    /*char* fac = new char[20];
    cout << "Enter your faculty: " << endl;
    cin >> fac;*/

    char fac[20] = "managment";
    person.set_faculty(fac);

    /*char* prof = new char[20];
    cout << "Enter your profession: " << endl;
    cin >> prof;*/

    char prof[20] = "manager";
    person.set_profession(prof);

    /*double aqa;
    cout << "Enter AQA value: ";
    cin >> aqa;*/

    double aqa = 14.75;
    person.set_AQA(aqa);

    cout << endl;
    person.output_data();

}

int main() {
    srand(time(nullptr));
    fill_student_data();

    return 0;
}
