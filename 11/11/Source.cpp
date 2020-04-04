#include <wchar.h>
#include <string>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <map>

#ifdef _MSC_VER

#define _CRT_SECURE_NO_WARNINGS

#endif

using namespace std;

class Locality{

public:

	string Name;

	string Region;

	Locality() :
		Population(0), Budget(0), Code(0) {
	};

	Locality(int Population, string Region) :
		Population(Population), Budget(0), Code(0) {
		this->Region = Region;
	};

	Locality(Locality& Local) :
		Population(Local.Population), Budget(Local.Budget), Code(Local.Code) {
	};

	Locality(string Name, string Region, int Code = 43, int Population = 100000, int Budget = 50000) :
		Population(Population), Budget(Budget), Code(Code) {
		this->Region = Region;
		this->Name = Name;
	};

	Locality(string Region, int Code) :
		Population(0), Budget(0), Code(Code) {
		this->Region = Region;
	};

	Locality(int Population, int Budget) :
		Population(Population), Budget(Budget), Code(0) {
	};


	void Input(void) {
		cout << "Enter name of locality: "; cin >> Name;
		cout << "Enter region of locality: "; cin >> Region;
		cout << "Enter code of locality: "; cin >> Code;
		cout << "Enter population of locality: "; cin >> Population;
		cout << "Enter budget of locality: "; cin >> Budget;
	}

	void Output(void) {
		cout << ("Name: " + Name) << endl;
		cout << ("Region: " + Region) << endl;
		cout << "Code: " << Code << endl;
		cout << "Population: " << Population << endl;
		cout << "Budget: " << Budget << endl;
	}

	void ClassInfo() {
		cout << "Class size: " << sizeof(Locality) << endl;
		cout << "Length of char's arrays: " << sizeof(Name) << endl;
		this->AbleBodied();
		this->BudgetToUSD();
		cout << endl;
	}

	~Locality() {
		Population = NULL;
		Code = NULL;
		Budget = NULL;
	};

	void Clear() {
		this->Locality::~Locality();
	}


protected:
	int Population;
	int Code;
	int Budget;
	void AbleBodied() {
		cout << "Able-bodied population: " << (this->Population / 2) << endl;
	}

private:

	void BudgetToUSD() {
		cout << "Budget of locality: " << (this->Budget / 65) << " USD" << endl;
	}

};

class City : public Locality {

public: int isRegionCenter;

	  void Output() {
		  Locality::Output();
		  cout << "Count of district: " << isRegionCenter << endl;
	  }

	  void Input() {
		  Locality::Input();
		  cout << "Enter a count of district: "; cin >> isRegionCenter;
	  }
};

class Township : public Locality {

public: 
	  int SchoolCount;
	  void Output() {
		  Locality::Output();
		  cout << "Schools: " << SchoolCount << endl;
	  }

	  void Input() {
		  Locality::Input();
		  cout << "Enter a count of schools: "; cin >> SchoolCount;
	  }
};

class Village : public Township {

public: int ShopCount;
	  void Output() {

		  Township::Output();

		  cout << "Shops: " << ShopCount << endl;

	  }

	  void Input() {

		  Township::Input();

		  cout << "Enter a count of shops: "; cin >> ShopCount;

	  }
};

int main() {

	std::multimap<string, Locality*> mLocalityMultimap;
	std::multimap<string, Locality*>::iterator mLocalityMultimapIterator;

	Locality* SampleLocality;
	for (int i = 0; i < 2; i++) {
		SampleLocality = new Locality();
		SampleLocality->Input();
		mLocalityMultimap.insert(std::pair<string, Locality*>(SampleLocality->Name, SampleLocality));
	}

	string tDeleteCondidate;

	do {
		for (mLocalityMultimapIterator = mLocalityMultimap.begin(); mLocalityMultimapIterator != mLocalityMultimap.end(); mLocalityMultimapIterator++)
			mLocalityMultimapIterator->second->Output();
		cout << "Input a name of region which could be deleted: ";
		cin >> tDeleteCondidate;
		mLocalityMultimapIterator = mLocalityMultimap.find(tDeleteCondidate);
		if (mLocalityMultimapIterator != mLocalityMultimap.end()) {
			mLocalityMultimap.erase(mLocalityMultimapIterator);
		}
		else {
			cout << "The container does not contains inputed name" << endl;
		}
	} while (!(tDeleteCondidate.empty()));
	cout << endl;

	_getch();
	return 1;
}