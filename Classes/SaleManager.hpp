#include<iostream>
#include<string>
#include"Employee.hpp"
using namespace std;
#define Manager_Salary 10000
#define Engineer_Salary_Gain 30
#define Salesman_Salary_Gain 50
#pragma once 
class SaleManager:public Employee{
	public:
		SaleManager(string n1,int n2,int l,int sale):Employee(n1,n2,l){
			setSalary(Salesman_Salary_Gain*sale+Manager_Salary);
			setPosition("SaleManager");
		}
};
