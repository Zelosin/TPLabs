#include <iostream>
#include <windows.h>
#include <locale>
#include <codecvt>
#include <string>

#pragma warning(disable, 4996)

typedef struct _struct1 {
public:
	int Population;
	int Code;
	int Budget;
	int isRegionCenter;
	wchar_t Name[10];
	wchar_t Region[10];
}CityStruct;

int main() {
}

extern "C" int __declspec(dllexport)_cdecl InputInt() {
	int buf;
	std::cin >> buf;
	return buf;
}

extern "C" void __declspec(dllexport)_cdecl OutputInt(int Param) {
	std::cout << Param << std::endl;
}


extern "C" void __declspec(dllexport)_cdecl InputStr(wchar_t* dst) {
	wchar_t* src = new wchar_t[10];
	std::wcin >> src;
	wcscpy(dst, src);
}

extern "C" void __declspec(dllexport)_cdecl OutputStr(wchar_t* src) {
	std::wcout << src << std::endl;
}


extern "C" void __declspec(dllexport)_cdecl InputCity(CityStruct * pSampleStruct) {
	std::cout << "Input a name of the region: ";
	std::wcin >> pSampleStruct->Name;
	std::cout << "Input a population of the region: ";
	std::wcin >> pSampleStruct->Region;
	std::cout << "Input a budget of the region: ";
	std::cin >> pSampleStruct->Population;
	std::cout << "Input a regional center of the region: ";
	std::cin >> pSampleStruct->Budget;
	std::cout << "Input a code of the region: ";
	std::cin >> pSampleStruct->Code;
	std::cout << "This is a region center: ";
	std::cin >> pSampleStruct->isRegionCenter;
}

extern "C" void __declspec(dllexport)_cdecl OutputCity(CityStruct * pSampleStruct) {
	std::wcout << "A name of the region: " << pSampleStruct->Name << std::endl;
	std::wcout << "A regional center of the region: " << pSampleStruct->Region << std::endl;
	std::cout << "A population of the region: " << pSampleStruct->Population << std::endl;
	std::cout << "A budget of the region: " << pSampleStruct->Budget << std::endl;
	std::cout << "A code of the region: " << pSampleStruct->Code << std::endl;
	std::cout << "This is a region center:" << pSampleStruct->isRegionCenter << std::endl;
}

typedef struct _struct2 {
public:

	int Population;
	int Code;
	int Budget;
	int SchoolCount;
	wchar_t Name[10];
	wchar_t Region[10];

}TownshipStruct;


extern "C" void __declspec(dllexport)_cdecl InputTownship(TownshipStruct * TownshipStructSample) {
	std::cout << "Input a name of the region: ";
	std::wcin >> TownshipStructSample->Name;
	std::cout << "Input a regional center of the region: ";
	std::wcin >> TownshipStructSample->Region;
	std::cout << "Input a population of the region: ";
	std::cin >> TownshipStructSample->Population;
	std::cout << "Input a budget of the region: ";
	std::cin >> TownshipStructSample->Budget;
	std::cout << "Input a code of the region: ";
	std::cin >> TownshipStructSample->Code;
	std::cout << "Input a count of schools: ";
	std::cin >> TownshipStructSample->SchoolCount;
}

extern "C" void __declspec(dllexport)_cdecl OutputTownship(TownshipStruct * TownshipStructSample) {
	std::wcout << "A name of the region: " << TownshipStructSample->Name << std::endl;
	std::wcout << "A regional center of the region: " << TownshipStructSample->Region << std::endl;
	std::cout << "A population of the region: " << TownshipStructSample->Population << std::endl;
	std::cout << "A budget of the region: " << TownshipStructSample->Budget << std::endl;
	std::cout << "A code of the region: " << TownshipStructSample->Code << std::endl;
	std::cout << "A count of schools: " << TownshipStructSample->SchoolCount << std::endl;
}

typedef struct _struct3 {
public:
	int Population;
	int Code;
	int Budget;
	int SchoolCount;
	int ShopCount;
	wchar_t Name[10];
	wchar_t Region[10];

}VillageStruct;

extern "C" void __declspec(dllexport)_cdecl InputVillage(VillageStruct * VillageStructSample) {
	std::cout << "Input a name of the region: ";
	std::wcin >> VillageStructSample->Name;
	std::cout << "Input a regional center of the region: ";
	std::wcin >> VillageStructSample->Region;
	std::cout << "Input a population of the region: ";
	std::cin >> VillageStructSample->Population;
	std::cout << "Input a budget of the region: ";
	std::cin >> VillageStructSample->Budget;
	std::cout << "Input a code of the region: ";
	std::cin >> VillageStructSample->Code;
	std::cout << "Input a count of schools: ";
	std::cin >> VillageStructSample->SchoolCount;
	std::cout << "Input a count of shops:  ";
	std::cin >> VillageStructSample->ShopCount;
}

extern "C" void __declspec(dllexport)_cdecl OutputVillage(VillageStruct * VillageStructSample) {
	std::wcout << "A name of the region: " << VillageStructSample->Name << std::endl;
	std::wcout << "A regional center of the region: " << VillageStructSample->Region << std::endl;
	std::cout << "A population of the region: " << VillageStructSample->Population << std::endl;
	std::cout << "A budget of the region: " << VillageStructSample->Budget << std::endl;
	std::cout << "A code of the region: " << VillageStructSample->Code << std::endl;
	std::cout << "A count of schools: " << VillageStructSample->SchoolCount << std::endl;
	std::cout << "A count of shops: " << VillageStructSample->ShopCount << std::endl;
}
