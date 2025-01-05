#include <iostream>
using namespace std;

class Course;

class Student{
    int id;
    string name;
    Course* c[20];  //max 20 course each student; array c, of pointers to objects, of type Course
    float grade[20];//grade for each course
    int count;      //course count per student

public:
    Student(int x,string n) : id(x),name(n),count(0){}

    string getname(){
        return name;
    }
    int getid(){
        return id;
    }
    void enroll(Course* course, float g){
        if(count < 20){
            c[count]=course;
            grade[count]=g;
            count++;
        }
    }
    void remove(Course* course){
        for(int i=0;i<count;++i){
            if(c[i]==course){
                for(int j=i;j<count-1;++j){
                    c[j]=c[j+1];
                    grade[j]=grade[j+1];
                }
                count--;
                return;
            }
        }
    }
    float sgpa(){
        if(count==0){
            return 0;
        }
        float sum;
        for (int i=0;i<count;i++){
            sum+=grade[i];
        }
        return sum/count;
    }
    void displaycourse();
};


class Course{
    int cid;
    string cname;
    Student* stu[60]; // each course can have at most 60 students
    int stcount;

public:
    Course(int x, string n) : cid(x),cname(n),stcount(0){}

    void addstu(Student* st){
        if(stcount<60){
            stu[stcount++]=st;
        }
    }
    void removestu(Student* st){
        for (int i=0;i<stcount;++i){
            if(stu[i]==st){
                for(int j=i;j<stcount-1;j++){
                    stu[j]=stu[j+1];
                }
                stcount--;
                return;
            }
        }
    }
    void  displayst(){
        cout<<"Students in "<<cname<<" :"<<endl;
        for(int i=0; i<stcount; ++i){
            cout<<stu[i]->getid()<<" : "<<stu[i]->getname()<<endl;
        }
    }
    string getcname(){
        return cname;
    }
    int getcid(){
        return cid;
    }
};

void Student::displaycourse(){
    cout<<"Courses of "<<name<<" :"<<endl;

    for (int i=0;i<count;i++){
        cout<<c[i]->getcid()<<": "<<c[i]->getcname()<<endl;//getcname is defined in Course class so it is needed to be defined after that class
    }
}

int searchstu(Student* arr[], int num, string& name) {
    for (int i = 0; i < num; ++i) {
        if (arr[i]->getname() == name) {
            return i;
        }
    }
    return -1;
}

int searchcourse(Course* arr[], int num, string& name) {
    for (int i = 0; i < num; ++i) {
        if (arr[i]->getcname() == name) {
            return i;
        }
    }
    return -1;
}

int main(){
    Student* arrstu[500];
    Course* arrcourse[100];
    int numst=0;
    int numcourse=0;
    int ch;

    int id,index,cindex;
    string n;

    cout << "1. Add Student\n";
    cout << "2. Add Course\n";
    cout << "3. Enroll Student in Course\n";
    cout << "4. Remove Student from Course\n";
    cout << "5. Display Students in Course\n";
    cout << "6. Display Courses of Student\n";
    cout << "7. Cgpa calculation\n"; 
    cout << "8. Exit\n";

    do {
        cout << "\nEnter Choice: ";
        cin >> ch;
        cin.ignore();
        switch (ch) {
        case 1:
            cout << "Enter student ID: ";
            cin >> id;cin.ignore();
            cout << "Enter student name: ";
            getline(cin,n);
            arrstu[numst] = new Student(id, n);
            numst++;
            break;
        case 2:
            cout << "Enter course ID: ";
            cin >> id;cin.ignore();
            cout << "Enter course name: ";
            getline(cin,n);
            arrcourse[numcourse] = new Course(id, n);
            numcourse++;
            break;
        case 3: 
            float grade;
            cout << "Enter student name: ";
            getline(cin,n);
            index = searchstu(arrstu, numst, n);
            if (index == -1) {
                cout << "No student found" << endl;
                break;
            }
            cout << "Enter course name: ";
            getline(cin,n);
            cindex = searchcourse(arrcourse, numcourse, n);
            if (cindex == -1) {
                cout << "No course found" << endl;
                break;
            }
            cout << "Enter grade: ";
            cin >> grade;
            arrstu[index]->enroll(arrcourse[cindex], grade);
            arrcourse[cindex]->addstu(arrstu[index]);
            break;
        case 4:
            cout<< "Enter student name: ";
            getline(cin,n);
            index = searchstu(arrstu, numst, n);
            if (index == -1) {
                cout<< "No student found" << endl;
                break;
            }
            cout<< "Enter course name: ";
            getline(cin,n);
            cindex = searchcourse(arrcourse, numcourse, n);
            if (cindex == -1) {
                cout << "No course found" << endl;
                break;
            }
            arrstu[index]->remove(arrcourse[cindex]);
            arrcourse[cindex]->removestu(arrstu[index]);
            break;
        case 5: 
            cout << "Enter course name: ";
            getline(cin,n);
            cindex = searchcourse(arrcourse, numcourse, n);
            if (cindex == -1) {
                cout << "No course found" << endl;
                break;
            }
            arrcourse[cindex]->displayst();
            break;
        case 6: 
            cout << "Enter student name: ";
            getline(cin,n);
            index = searchstu(arrstu, numst, n);
            if (index == -1) {
                cout << "No student found" << endl;
                break;
            }
            arrstu[index]->displaycourse();
            break;
        case 7:
            cout << "Enter student name: ";
            getline(cin,n);
            index = searchstu(arrstu, numst, n);
            if (index == -1) {
                cout << "No student found" << endl;
                break;
            }
            cout<<arrstu[index]->sgpa();
            break;
        case 8:
            break;
        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    } while (ch != 8);
}