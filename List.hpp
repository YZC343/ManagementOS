#include<iostream>
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
class List{
	private:
		int size;
		Employee* employee[500];
		int maxnumber;
	public:
		List(){
			size=0;
		}
		void setMaxnumber(int n){
			maxnumber=n;
		}
		int getMaxnumber(){
			return maxnumber;
		}
		void Add(Employee* e){
			employee[size]=e;
			size++;
		}
		void DeleteByIndex(int i){
			if(employee[i]!=NULL){
				employee[i]->~Employee();
				employee[i]=NULL;
			}
			else{
				cout<<"��¼������"<<endl;
			}
		}
		
		void Calculate(){
			float sum=0;
			float Manager_sum=0,Engineer_sum=0,Salesman_sum=0,SaleManager_sum=0;
			for(int i=0;i<size;i++){
				if(employee[i]!=NULL){
					if(employee[i]->getPosition().compare("Manager")==0){
						Manager_sum+=employee[i]->getSalary();
					}
					else if(employee[i]->getPosition().compare("Engineer")==0){
						Engineer_sum+=employee[i]->getSalary();
					}
					else if(employee[i]->getPosition().compare("Salesman")==0){
						Salesman_sum+=employee[i]->getSalary();
					}
					else if(employee[i]->getPosition().compare("SaleManager")==0){
						SaleManager_sum+=employee[i]->getSalary();
					}
				}
			}
			sum=Manager_sum+Engineer_sum+Salesman_sum+SaleManager_sum;
			cout<<"�ܹ���: "<<sum<<" ,����Ա������ռ��:"<<endl;
			cout<<" ����:"<<Manager_sum/sum*100<<"% ,��ְ������Ա:"<<Engineer_sum/sum*100<<"% ,���۾���:"<<SaleManager_sum*100<<"% ,��ְ����Ա:"<<Salesman_sum/sum*100<<"%"<<endl;
		}
		void DeleteByNumber(int j){
				int i;
			for(i=0;i<size;i++){
				if(employee[i]!=NULL&&employee[i]->getNumber()==j){
					cout<<"ɾ�����ݣ�";
					employee[i]->outPut();
					DeleteByIndex(i);
					break;	
				}
			}
			if(i==size){
				cout<<"��¼������"<<endl;
			}
		}
		int GetSize(){
			return size;
		}
		Employee* GetEmployee(int n){
			return employee[n];
		}
		void Print(){
			for(int i=0;i<size;i++){
				if(employee[i]!=NULL){
					employee[i]->outPut();
				}
			}
		}
		Employee* SearchByIndex(int i){
			if(employee[i]!=NULL){
				cout<<"��ѯ�ɹ�: "; 
				employee[i]->outPut();
				return employee[i];
			}
			else{
				cout<<"��¼������"<<endl;
			}
			return NULL;
		}
		Employee* SearchByName(string name){
			int i;
			for(i=0;i<size;i++){
				if(employee[i]!=NULL&&employee[i]->GetName().compare(name)==0){
					cout<<"��ѯ�ɹ�: "; 
					employee[i]->outPut();
					return employee[i];
					break;
				}
			}
			if(size==i){
				cout<<"��¼������"<<endl;
			}
			return NULL;
		}
		
		Employee* SearchByNumber(int number){
			int i;
			for(i=0;i<size;i++){
				if(employee[i]!=NULL&&employee[i]->getNumber()==number){
					cout<<"��ѯ�ɹ�: "; 
					employee[i]->outPut();
					return employee[i];
					break;
				}
			}
			if(size==i){
				cout<<"��¼������"<<endl;
			}
			return NULL;
		}
		
};

