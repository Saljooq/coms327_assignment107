#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Person{
	public:
		string fname;
 	 	string lname;
};

class Student{
public:
	Person* p;
	string status;
};

int main(int argc, char* argv[])
{
	cout <<"Hello World!\n\n";

	int *i = (int*) malloc(sizeof(int));

	*i = 1234567;

	cout <<"Number entered:  "<<*i << "\n\n";

	free(i);

	Person *p = (Person*) malloc(sizeof(Person));
	p->fname = "Saljooq";
	p->lname = "Altaf";
	cout <<"fName entered:  "<< p->fname << "\n\n";
	cout <<"lName entered:  "<< p->lname << "\n\n";

	cout<<"Making a student\n\n";
	Student *s = (Student*) malloc(sizeof(Student));

	s->p = p;
	s->status = "Senior";

	cout <<"Entering student details....\n";
	cout <<"Student status:  "<< s->status << "\n";
	cout <<"fName entered:  "<< s->p->fname << "\n";
	cout <<"lName entered:  "<< s->p->lname << "\n";

	//string name = "Saljooq";
	//cout <<"Name entered:  "<< name << "\n\n";
	free(s);
	free(p);


	ifstream f("monster_desc.txt");
	int j;
	string t;

	j = f.get();
	cout<<(char)j<<endl;




	return 0;

}
