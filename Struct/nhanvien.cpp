#include<iostream>
using namespace std;

void Display(struct Employee myEmployee);

struct Date{
    int day;
    int month;
    int year;
};

struct Employee{
    char name[20];
    struct Date birthDay;
    char role[20];
    float salary;
};

int main(){
    struct Employee myEmployee={"Nguyen Van A", {13,1,2002}, "Nhan vien", 300};
    cout<<"Thông tin nhân viên mặc định:"<<endl;
    Display(myEmployee);

    cout<<"Nhập thông tin nhân viên"<<endl;
    cout<<"Name: ";
    cin.getline(myEmployee.name,20);

    cout<<"Birth day: "; cin>>myEmployee.birthDay.day;

    cout<<"Role: ";
    cin.ignore();
    cin.getline(myEmployee.role,20);

    cout<<"Salary: "; cin>>myEmployee.salary;
    cout<<"Thông tin nhân viên sau khi chỉnh sửa"<<endl;
    Display(myEmployee);
    return 0;
}

void Display(struct Employee myEmployee){
    cout<<"Name: "<<myEmployee.name<<endl;
    cout<<"Birth Day: "<<myEmployee.birthDay.day<<"/"<<myEmployee.birthDay.month<<"/"<<myEmployee.birthDay.year<<endl;
    cout<<"Role: "<<myEmployee.role<<endl;
    cout<<"Salary: "<<myEmployee.salary<<endl; 
}