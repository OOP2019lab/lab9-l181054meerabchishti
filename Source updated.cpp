#include"Employee.h";

Address::Address(char* house_Number, char* Street_Name, char * City, char* County)
{
	this->house_Number = house_Number;
	this->street_Name = Street_Name;
	this->city = City;
	this->country = County;
}
ostream& operator<<(ostream& osObject, const Address&d)
{
	osObject << d.house_Number << "," << d.street_Name << "," << d.city << "," << d.country << endl;
	//osObject<<"House Number"<<" "<<d.house_Number<<","<<"Street "<<" "<<d.street_Name<<","<<"City"<<" "<<d.city<<" "<<"Country"<<" "<<d.country<<endl;
	return osObject;
}
Address::Address(const Address&d)
{
	this->house_Number = d.house_Number;
	this->street_Name = d.street_Name;
	this->city = d.city;
	this->country = d.country;
}
const Address & Address:: operator=(const Address& other)
{
	this->house_Number = other.house_Number;
	this->street_Name = other.street_Name;
	this->city = other.city;
	this->country = other.country;
	return *this;
}
Project::Project(char* name, int budget, int duration)
{
	this->name = name;
	this->budget = budget;
	this->duration = duration;


}
Project::Project(const Project&d)
{
	this->budget = d.budget;
	this->duration = d.duration;
	this->name = d.name;

}
const Project & Project::  operator=(const Project& other)
{
	this->name = other.name;
	this->budget = other.budget;
	this->duration = other.duration;

	return *this;
}
ostream& operator<<(ostream& osObject, const Project&d)
{
	osObject << d.name << "," << d.budget << "," << d.duration << endl;
	return osObject;
}
Employee::Employee(char* name, const Address& d) :emp_name(name), adrress(d)
{
	this->current = new Project*[3];
	this->noOfProjects = 0;
}
Employee::Employee(const Employee&d) : emp_name(d.emp_name), adrress(d.adrress)
{
	this->current = d.current;
	this->noOfProjects = d.noOfProjects;
	for (int i = 0; i<noOfProjects; i++)
	{
		this->current[i] = d.current[i];
	}

}
ostream& operator<<(ostream& osobject, const Employee&d)
{
	osobject << "employee name:" << d.emp_name << endl;
	osobject << "address :" << d.adrress;
	for (int i = 0; i<d.noOfProjects; i++)
	{
		cout << *d.current[i] << " ";

	}
	return osobject;
}
void Employee::addProject(Project const*s)
{
	if (noOfProjects>=2)
	{
		cout << "not possible" << endl;
	}
	else
	{
		current[noOfProjects] = new Project(*s);
		noOfProjects++;

	}
}
bool Project::exists(Project const *d)const
{
	if (strlen(name) == strlen(d->name))
	{
		for (int i = 0; i < strlen(name); i++)
		{
			if (name[i] != d->name[i])
			{
				return false;
			}
		}
		return true;
	}
	else
		return false;
}
void Employee::removeProject(Project const*s)
{
	for (int i = 0; i < 2; i++)
	{
		if (current[i]->exists(s))
		{
			for (int j = i; j < 2; j++)
			{
				this->current[j] = current[j + 1];
			}
		}
	}

	this->noOfProjects--;
}
Address::~Address()
{
	delete house_Number;
	delete street_Name;
	delete city;
	delete country;

}

Employee::~Employee()
{
	delete current[0], current[1];
	delete emp_name;
	delete current;

}

Project::~Project()
{
	delete name;
}

void Project::setBudget(int i)
{
	this->budget = i;
}

const Employee & Employee::  operator=(const Employee& other)
{
	this->emp_name = other.emp_name;
	this->adrress = other.adrress;
	this->current = new Project*[2];
	for (int i = 0; i < 2; i++)
	{
		this->current[i] = other.current[i];
	}
	this->noOfProjects = other.noOfProjects;

	return *this;
}