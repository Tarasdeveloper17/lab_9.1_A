#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
using namespace std;

enum Specialnist { KN, IT, KIBERBEZPEKA, CA, RI};
string specialnistStr[] = {"KN", "IT", "KIBERBEZPEKA", "CA", "RI"};

struct Student
{
    string surname;
    unsigned course;
    Specialnist specialnist;
    union
    {
        unsigned physics;
        unsigned math;
        unsigned informatics;
    };
};

void Create(Student* p, const int N);
void Print(Student* p, const int N);
void Excellent(Student* p, const int N);
double AverangeScore(Student* p, const int  N);
    
int main()
{
    cout << "Enter N: ";
    int N;
    cin>>N;
    Student *p = new Student[N];
    
    Create(p, N);
    Print(p, N);
    Excellent(p, N);
    cout<<"Процент студентів, у яких середній бал більший за 4,5: ";
    cout<<AverangeScore(p,  N)<< "%"<< endl;
    return 0;
}

void Create(Student* p, const int N)
{
    int specialnist;

    for (int i = 0; i < N; i++)
    {
        cout << "Student № " << i + 1 << ":" << endl;
        cin.get();
        cin.sync();
        cout << " Surname : "; getline(cin, p[i].surname);
        cout << " Course: "; cin >> p[i].course;
        cout << " Specialnist (0 - KN, 1 - IT, 2 - KIBERBEZPEKA, 3 - CA, 4 - RI):";
        cin >> specialnist;
        cout << " Assessment in physics : "; cin >> p[i].physics;
        cout << "Assessment in math    : "; cin >> p[i].math;
        cout << "Assessment in informatics : "; cin >> p[i].informatics;
        p[i].specialnist = Specialnist(specialnist);
    }
}

void Print(Student* p, const int N)
{
    cout << "=========================================================================="
        << endl;
    cout << "| № | Surname | Course | Spec | Score in PH | Score in Math | Score in iT |"
        << endl;
    cout << "--------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(1) << right << i + 1 << " ";
        cout << "| " << setw(10) << left << p[i].surname
            << "| " << setw(2) << right << p[i].course << " "
            << "| " << setw(15) << left << specialnistStr[p[i].specialnist]
            << "| " << setw(6) << right << p[i].physics << " "
            << "| " << setw(10) << left << p[i].math << " "
            << "| " << setw(11) << right << p[i].informatics << " " << "|";
        cout << endl;
    }
    cout << "=========================================================================="
        << endl;
    cout << endl;
}

    
void Excellent(Student* p, const int N)
{
    for(int i = 0; i < N; i++)
    {
        if(p[i].math == 5  && p[i].physics == 5 && p[i].informatics ==5)
        {
            cout<<" Excellent student among students is : "<<p[i].surname<<endl;
        }
    }
}



double AverangeScore(Student* p, const int  N)
{
    double AverangeScore = 0.0;
    int res = 0.0;
    
    for(int i = 0 ; i < N; i++)
    {
        AverangeScore = (p[i].physics + p[i].informatics + p[i].math) / 3;
        
        if(AverangeScore > 4.5)
        {
            res++;
        }
    }
    
    return 100.0 * res / N;
}

