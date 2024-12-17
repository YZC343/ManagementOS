#include<iostream>
#include<string>
#include"List.hpp"
#include"Classes/Employee.hpp"
#include"Classes/Manager.hpp"
#include"Classes/Engineer.hpp"
#include"Classes/Salesman.hpp"
#include"Classes/SaleManager.hpp"
using namespace std;
#define Manager_Salary 10000
#define Engineer_Salary_Gain 30
#define Salesman_Salary_Gain 50
#pragma once
void AddEmployee(List &list){
	int level;
	string name;
	int position;
	cout<<"����Ա��������ְλ������ "<<endl;
	cin>>name;
	cin>>position;
	cin>>level;
	Employee* p;
	float sales;
	list.setMaxnumber(list.getMaxnumber()+1);
	switch(position){
		case 1:
			p=new Manager(name,list.getMaxnumber(),level);
			list.Add(p);
			break;
		case 2:
			cout<<"���빤��Сʱ����"<<endl;
			int hours;
			cin>>hours;
			p=new Engineer(name,list.getMaxnumber(),level,hours);
			list.Add(p);
			break;
		case 3:
			cout<<"�������۶"<<endl;
			cin>>sales;
			p=new SaleManager(name,list.getMaxnumber(),level,sales);
			list.Add(p);
			break;
		case 4:
			cout<<"�������۶"<<endl;
			cin>>sales;
			p=new Salesman(name,list.getMaxnumber(),level,sales);
			list.Add(p);
			break;
		default:
			cout<<"�������"<<endl;
			break;
	}
}
