#include<iostream>
#include<string>
using namespace std;
#define Manager_Salary 10000
#define Engineer_Salary_Gain 30
#define Salesman_Salary_Gain 50
#pragma once
class Employee{
	private:
		string name;
		int number;
		int level;
		float salary;
		string position;
	public:
		Employee(string n1,int n2,int l){
			name=n1;
			number=n2;
			level=l;
		}
		virtual ~Employee(){}
		
		void setSalary(float s){
			salary=s;
		}
		float getSalary(){
			return salary;
		}
		void setPosition(string a){
			position=a;		
		}
		int getLevel(){
			return level;
		}
		void setLevel(int l){
			level=l;
		}
		int getNumber(){
			return number;
		}
		string GetName(){
			return name;
		}
		string getPosition(){
			return position;
		}
/*		void outPut(){
			cout<<"����: "<<name<<" ���: "<<number<<" ְλ: "<<position<<" ����: "<<level<<" ����нˮ: "<<salary<<endl;
		}
		void Promote(int x=1){
			level+=x;
			cout<<name<<"����"<<level<<"��"<<endl; 
		}
*/
};
