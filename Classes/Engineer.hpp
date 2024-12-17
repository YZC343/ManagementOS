#include<iostream>
#include<string>
#include"Employee.hpp"
using namespace std;
#define Manager_Salary 10000
#define Engineer_Salary_Gain 30
#define Salesman_Salary_Gain 50
#pragma once
class Engineer:public Employee{
	public:
		Engineer(string n1,int n2,int l,int hour):Employee(n1,n2,l){
			setSalary(Engineer_Salary_Gain*hour);
			setPosition("Engineer");
		}
};

