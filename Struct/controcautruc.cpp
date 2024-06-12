#include<iostream>
using namespace std;

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char name[20];
    Date birthDay;
    char role[20];
    float salary;
} Employee;

void Display(Employee *myEmployee); // function prototype phải được đặt ngay trước định hàm, nếu có struct, typedef xen vào giữa sẽ bị lỗi
void initStruct(Employee *myEmployee);  // không được đặt phía trên typedef sẽ gây lỗi biên dịch

int main(){
    Employee *myEmployee = new Employee;
    initStruct(myEmployee);
    Display(myEmployee);
    delete myEmployee;
    return 0;
}

void Display(Employee *myEmployee){
    cout<<"Name: "<<myEmployee->name<<endl;
    cout<<"Birth Day: "<<myEmployee->birthDay.day<<"/"<<myEmployee->birthDay.month<<"/"<<myEmployee->birthDay.year<<endl;
    cout<<"Role: "<<myEmployee->role<<endl;
    cout<<"Salary: "<<myEmployee->salary<<endl; 
}

void initStruct(Employee *myEmployee){
    
    cout<<"Nhập thông tin nhân viên"<<endl;
    cout<<"Name: ";
    cin.getline(myEmployee->name,20);

    cout<<"Birth day: "; cin>>myEmployee->birthDay.day;
    cout << "Birth month: "; cin >> myEmployee->birthDay.month;
    cout << "Birth year: "; cin >> myEmployee->birthDay.year;
    
    cout<<"Role: ";
    cin.ignore();
    cin.getline(myEmployee->role,20);

    cout<<"Salary: "; cin>>myEmployee->salary;
}