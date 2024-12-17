#include<iostream>
#include<string>
#include"AddEmployee.hpp"
#include"List.hpp"
using namespace std;
#define Manager_Salary 10000
#define Engineer_Salary_Gain 30
#define Salesman_Salary_Gain 50
#pragma once
void Apply(List& list){
	string input;
	Employee* p;
	cin>>input;
	while(input.compare("exit")!=0){
		if(input.compare("add")==0){
			AddEmployee(list);
			cout<<"Ìí¼Ó³É¹¦"<<endl;
		}
		else if(input.compare("search")==0){
			input.clear();
			cout<<"Ñ¡Ôñ±àºÅ»òÐÕÃû: 1.±àºÅ 2.ÐÕÃû"<<endl;
			int sw;
			cin>>sw;
			if(sw==1){
				cout<<"ÊäÈë±àºÅ: "<<endl;
				cin>>sw;
				p=list.SearchByNumber(sw);
			}
			else if(sw==2){
				cout<<"ÊäÈëÐÕÃû: "<<endl;
				cin>>input;
				p=list.SearchByName(input);
			}
			else{
				cout<<"´íÎóÊäÈë"<<endl;
			}
		}
		else if(input.compare("promote")==0){
			if(p!=NULL){
				cout<<"ÊäÈë½úÉý¼¶Êý"<<endl;
				int in;
				cin>>in;
				p->Promote(in);
				}
			else{
				cout<<"´íÎóÊäÈë"<<endl;
			}
		}
		else if(input.compare("delete")==0){
			if(p!=NULL){
				list.DeleteByNumber(p->getNumber());
			}
			else{
				cout<<"´íÎóÊäÈë"<<endl;
			}
		}
		else if(input.compare("print")==0){
			list.Print();
		}
		else if(input.compare("calculate")==0){
			list.Calculate();
		}
		else{
			cout<<"´íÎóÊäÈë"<<endl;
		}
		input.clear();
		cin>>input;
	}
}
