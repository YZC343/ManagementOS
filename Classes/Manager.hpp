#include<iostream>
#include<string>
#include"Employee.hpp"
using namespace std;
#define Manager_Salary 10000
#define Engineer_Salary_Gain 30
#define Salesman_Salary_Gain 50
#pragma once
class Manager:public Employee{
	public:
		Manager(string n1,int n2,int l):Employee(n1,n2,l){
			setSalary(Manager_Salary);
			setPosition("Manager");
		}
		
};
