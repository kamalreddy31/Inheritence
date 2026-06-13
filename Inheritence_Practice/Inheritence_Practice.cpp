
#include <iostream>

using namespace std;


class Employee
{
	int m_Eid;
	char* m_Ename;

public:

	Employee()
	{
		m_Eid = 0;
		m_Ename = new char;
		m_Ename[0] = '\0';
	}

	Employee(int id, const char* name)
	{
		m_Eid = id;
		m_Ename = new char[strlen(name) + 1];
		strcpy_s(m_Ename, -1, name);
	}

	void Display()
	{

		cout << "EMP ID : " << m_Eid << "\n" << "EMP NAME : " << m_Ename << "\n";
	}

	~Employee()
	{
		delete[] m_Ename;
	}
};

class Company : virtual public Employee
{
	char* m_Cname;

public:

	Company()
	{
		m_Cname = new char;
		m_Cname[0] = '\0';
	}

	Company(const char* Cname) 
	{
		m_Cname = new char[strlen(Cname) + 1];
		strcpy_s(m_Cname, -1, Cname);
	}
	void Display()
	{

		
		cout << "The Company name is : " << m_Cname << "\n";
	}

	~Company()
	{
		delete[] m_Cname;
	}

};

class Client : virtual public Employee, public Company
{
	char* m_Clname;

public:

	Client()
	{
		m_Clname = new char;
		m_Clname[0] = '\0';
	}

	Client(int id, const char* name, const char* Cname, const char* Clname) : Employee(id, name), Company(Cname)
	{
		m_Clname = new char[strlen(Clname) + 1];
		strcpy_s(m_Clname, -1, Clname);
	}
	void Display()
	{

		Employee::Display();
		Company::Display();
		cout << "The Client name is : " << m_Clname << "\n" << endl;
	}

	~Client()
	{
		delete[] m_Clname;
	}
};
int main()
{
	Client obj;

	Client obj1(1, "kamal", "Cadmaxx", "SDI Airforce");

	obj.Display();
	obj1.Display();

	return 0;
}