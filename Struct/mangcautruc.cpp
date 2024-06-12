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

void Display(Employee myEmployee, int length); // function prototype phải được đặt ngay trước định hàm, nếu có struct, typedef xen vào giữa sẽ bị lỗi
void initStruct(Employee myEmployee[], int length);  // không được đặt phía trên typedef sẽ gây lỗi biên dịch
Employee searchSalaryMax(Employee *myEmployee, int length);
Employee searchSalaryMin(Employee myEmployee[], int length);

int main(){
    int length;
    cout<<"Nhập số lượng nhân viên: "; cin>>length;
    Employee *myEmployee = new Employee[length];
    initStruct(myEmployee, length);
    
    //Nhân viên có lương cao nhất
    cout<<"Nhân viên có lương cao nhất"<<endl;
    Employee tempEmployee = searchSalaryMax(myEmployee, length);
    Display(tempEmployee, length);

    //Nhân viên có lương thấp nhất
    cout<<"Nhân viên có lương thấp nhất"<<endl;
    tempEmployee = searchSalaryMin(myEmployee, length);
    Display(tempEmployee, length);
    
    delete []myEmployee;
    return 0;
}

void Display(Employee myEmployee, int length){
    cout<<"Name: "<<myEmployee.name<<endl;
    cout<<"Birth Day: "<<myEmployee.birthDay.day<<"/"<<myEmployee.birthDay.month<<"/"<<myEmployee.birthDay.year<<endl;
    cout<<"Role: "<<myEmployee.role<<endl;
    cout<<"Salary: "<<myEmployee.salary<<endl; 
    
}

void initStruct(Employee myEmployee[], int length){
    cout<<"Nhập thông tin nhân viên"<<endl;
    for(int i=0; i<length; i++){
        cout<<"Nhân viên "<<i+1<<endl;
        cout<<"Name: ";
        cin.ignore();
        cin.getline(myEmployee[i].name,20);

        cout<<"Birth day: "; cin>>myEmployee[i].birthDay.day;
        cout << "Birth month: "; cin >> myEmployee[i].birthDay.month;
        cout << "Birth year: "; cin >> myEmployee[i].birthDay.year;
    
        cout<<"Role: ";
        cin.ignore();
        cin.getline(myEmployee[i].role,20);

        cout<<"Salary: "; cin>>myEmployee[i].salary;
    }
}

Employee searchSalaryMax(Employee *myEmployee, int length){
    Employee maxSalary = myEmployee[0];
    for(int i=0; i<length; i++){
        if(myEmployee[i].salary > maxSalary.salary){
            maxSalary = myEmployee[i];
        }
    }
    return maxSalary;
}

Employee searchSalaryMin(Employee myEmployee[], int length){
    Employee minSalary = myEmployee[0];
    for(int i=0; i<length; i++){
        if(myEmployee[i].salary < minSalary.salary){
            minSalary = myEmployee[i];
        }
    }
    return minSalary;
}