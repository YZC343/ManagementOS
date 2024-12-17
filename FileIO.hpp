#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include <stdlib.h>
#include"List.hpp"
using namespace std;
#define Manager_Salary 10000
#define Engineer_Salary_Gain 30
#define Salesman_Salary_Gain 50
#define Initial_Number 2024
#pragma once
void fileout(List& list){
	fstream file;
	file.open("data.txt",ios::out);
	if (!file) {
        cerr << "Unable to open file!" << std::endl;
         // 文件打开失败
    }
    int size= list.GetSize();
    for(int i=0;i<size;i++){
    	if(list.GetEmployee(i)!=NULL){
    		file<<" "<<list.GetEmployee(i)->GetName()<<" ";
    		file<<list.GetEmployee(i)->getNumber()<<" ";
    		if(list.GetEmployee(i)->getPosition().compare("Manager")==0){
    			file<<"1 ";
    			file<<list.GetEmployee(i)->getLevel()<<endl;
    		}
    		else if(list.GetEmployee(i)->getPosition().compare("Engineer")==0){
    			file<<"2 ";
    			file<<list.GetEmployee(i)->getLevel()<<" ";
    			file<<list.GetEmployee(i)->getSalary()/Engineer_Salary_Gain<<endl;
    		}
    		else if(list.GetEmployee(i)->getPosition().compare("Salesman")==0){
    			file<<"4 ";
    			file<<list.GetEmployee(i)->getLevel()<<" ";
    			file<<list.GetEmployee(i)->getSalary()/Salesman_Salary_Gain<<endl;
    		}
    		else if(list.GetEmployee(i)->getPosition().compare("SaleManager")==0){
    			file<<"3 ";
    			file<<list.GetEmployee(i)->getLevel()<<" ";
    			file<<(list.GetEmployee(i)->getSalary()-Manager_Salary)/Salesman_Salary_Gain<<endl;
    		}
    		else{
    			cout<<"错误输出数据"<<endl;
    		}
    		
    	}
    }
    file.close(); // 关闭文件
}

void filein(List& list){
	fstream file;
	file.open("data.txt",ios::in);
	 if (!file) {
        cerr << "Unable to open file!" <<endl;
        // 文件打开失败
    }
    char buf[1021]={0};
    string name;
    int number;
    int level;
    int count;
    int position;
    Employee* p;
    file.getline(buf,sizeof(buf),' ');
    while(file.getline(buf,sizeof(buf),' ')){
	     name=buf;
	     file.getline(buf,sizeof(buf),' ');
	     number=atoi(buf);
	     file.getline(buf,sizeof(buf),' ');
	     position=atoi(buf);
	     if(position==1){
	     	file.getline(buf,sizeof(buf),' ');
	     	level=atoi(buf);
	     	p=new Manager(name,number,level);
	     	list.Add(p);
	     }
	     else if(position==2){
	     	file.getline(buf,sizeof(buf),' ');
	     	level=atoi(buf);
	     	file.getline(buf,sizeof(buf),' ');
	     	count=atoi(buf);
	     	p=new Engineer(name,number,level,count);
	     	list.Add(p);
	     }
	     else if(position==3){
	     	file.getline(buf,sizeof(buf),' ');
	     	level=atoi(buf);
	     	file.getline(buf,sizeof(buf),' ');
	     	count=atoi(buf);
	     	p=new SaleManager(name,number,level,count);
	     	list.Add(p);
	     }
	     else if(position==4){
	     	file.getline(buf,sizeof(buf),' ');
	     	level=atoi(buf);
	     	file.getline(buf,sizeof(buf),' ');
	     	count=atoi(buf);
	     	p=new Salesman(name,number,level,count);
	     	list.Add(p);
	     }
	     else{
	     	cout<<"数据输入错误"<<endl;
	     }	
	     if(number>list.getMaxnumber()){
	     	list.setMaxnumber(number);
	     }
	} 
}
