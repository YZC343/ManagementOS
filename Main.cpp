#include"Apply.hpp"
#include"List.hpp"
#include"FileIO.hpp"
int main(){
	List list;
	filein(list);
	Apply(list);
	list.Print();
	fileout(list);
	return 0;
}
