#include<bits/stdc++.h>
using namespace std;


class AbstractEmployee {
	virtual void askForPromotion() = 0;
};


 
class employee : AbstractEmployee {

private:
	string company;
	int age;

protected:
	string name;

public:

	// setter
	void setName(string inputName) {
		name = inputName;
	}

	// getter
	string getName() {
		return name;
	}

	string getCompany() {
		return company;
	}

	// a function method
	void intro(){
		cout << "Name : " << name << "\n";
		cout << "Company : " << company << "\n";
		cout << "Age : " << age << "\n";

	}

	virtual void work() {
		cout << name << " is reviewing pull requests\n";
	}

	// constructor
	employee(string Name, string Company, int Age) {
		name = Name;
		company = company;
		age = Age;
	}

	// virtual contract signing function:
	void askForPromotion() {
		if(age >= 30) cout << "Promoted!\n";
		else cout << "We'll get em next time.\n";
	}
};


// derived/child  class of employee
class Developer : public employee{
public:
	string favLang;

	// constructor
	// here we pass the parent constructor name, company and age : as it knows how to handle it
	Developer(string name, string company, int age, string programmingLang) : employee(name, company, age) {
		favLang = programmingLang;
	}

	void fixBug() {
		cout << name << " Fixing bug using " << favLang << "\n";
	}

	void work() {
		cout << name << " is a software engineering intern\n";
	}
};


int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
		
	employee x = employee("Agnideep", "Pitney Bowes", 20);

	x.intro();

	x.setName("Mark");
	cout << "Using getter method: " << x.getName() << "\n";

	x.askForPromotion();


	Developer d = Developer("Tourist", "CodeForces", 25, "C++");
	d.fixBug();
	d.askForPromotion(); // as we have public inheritance


	d.work();


	//polymorphism:
	employee *e = &d;     // creating a pointer which holds reference to the derived class object d
	e->work();
}
