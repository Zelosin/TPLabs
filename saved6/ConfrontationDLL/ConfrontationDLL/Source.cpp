#include <iostream>

#include<windows.h>

#include <locale>

#include <codecvt>

typedef struct _struct1{
public:
	wchar_t Name[100];
	wchar_t Region[100];
	int Population;
	int Code;
	int Budget;
	int isRegionCenter;

}CityStruct;

int main() {
}

extern "C" void __declspec(dllexport)_cdecl ReadClass2(CityStruct * pSampleStruct){
	printf("Input a name of the region: ");
	wscanf_s(L"%s", pSampleStruct->Name);
	printf("Input a regional center of the region: ");
	wscanf_s(L"%s", (pSampleStruct->Region));
	printf("Input a population of the region: ");
	scanf_s("%d", &(pSampleStruct->Population));
	printf("Input a budget of the region: ");
	scanf_s("%d", &(pSampleStruct->Budget));
	printf("Input a code of the region: ");
	scanf_s("%d", &(pSampleStruct->Code));
	printf("This is a region center: ");
	scanf_s("%d", &(pSampleStruct->isRegionCenter));
}

extern "C" void __declspec(dllexport)_cdecl WriteClass2(CityStruct * pSampleStruct){
	printf("A name of the region: %S \n", pSampleStruct->Name);
	printf("A regional center of the region: %S\n", pSampleStruct->Region);
	printf("A population of the region: %d\n", pSampleStruct->Population);
	printf("A budget of the region: %d\n", pSampleStruct->Budget);
	printf("A code of the region: %d\n", pSampleStruct->Code);
	printf("This is a region center:%d\n", pSampleStruct->isRegionCenter);
}

typedef struct _struct2 {
public:
	wchar_t Name[100];
	wchar_t Region[100];
	int Population;
	int Code;
	int Budget;
	int SchoolCount;

}TownshipStruct;


extern "C" void __declspec(dllexport)_cdecl ReadClass3(TownshipStruct * TownshipStructSample){
	printf("Input a name of the region: ");
	wscanf_s(L"%s", TownshipStructSample->Name);
	printf("Input a regional center of the region: ");
	wscanf_s(L"%s", (TownshipStructSample->Region));
	printf("Input a population of the region: ");
	scanf_s("%d", &(TownshipStructSample->Population));
	printf("Input a budget of the region: ");
	scanf_s("%d", &(TownshipStructSample->Budget));
	printf("Input a code of the region: ");
	scanf_s("%d", &(TownshipStructSample->Code));
	printf("Input a count of schools: ");
	scanf_s("%d", &(TownshipStructSample->SchoolCount));
}

extern "C" void __declspec(dllexport)_cdecl WriteClass3(TownshipStruct * TownshipStructSample) {
	printf("A name of the region: %S \n", TownshipStructSample->Name);
	printf("A regional center of the region: %S\n", TownshipStructSample->Region);
	printf("A population of the region: %d\n", TownshipStructSample->Population);
	printf("A budget of the region: %d\n", TownshipStructSample->Budget);
	printf("A code of the region: %d\n", TownshipStructSample->Code);
	printf("A count of schools: %d\n", TownshipStructSample->SchoolCount);
}

typedef struct _struct3 {
public:
	wchar_t Name[100];
	wchar_t Region[100];
	int Population;
	int Code;
	int Budget;
	int SchoolCount;
	int ShopCount;

}VillageStruct;

extern "C" void __declspec(dllexport)_cdecl ReadClass4(VillageStruct * VillageStructSample){
	printf("Input a name of the region: ");
	wscanf_s(L"%s", VillageStructSample->Name);
	printf("Input a regional center of the region: ");
	wscanf_s(L"%s", (VillageStructSample->Region));
	printf("Input a population of the region: ");
	scanf_s("%d", &(VillageStructSample->Population));
	printf("Input a budget of the region: ");
	scanf_s("%d", &(VillageStructSample->Budget));
	printf("Input a code of the region: ");
	scanf_s("%d", &(VillageStructSample->Code));
	printf("Input a count of schools: ");
	scanf_s("%d", &(VillageStructSample->SchoolCount));
	printf("Input a count of shops:  ");
	scanf_s("%d", &(VillageStructSample->ShopCount));
}

extern "C" void __declspec(dllexport)_cdecl WriteClass4(VillageStruct * VillageStructSample) {
	printf("A name of the region: %S \n", VillageStructSample->Name);
	printf("A regional center of the region: %S\n", VillageStructSample->Region);
	printf("A population of the region: %d\n", VillageStructSample->Population);
	printf("A budget of the region: %d\n", VillageStructSample->Budget);
	printf("A code of the region: %d\n", VillageStructSample->Code);
	printf("A count of schools: %d\n", VillageStructSample->SchoolCount);
	printf("A count of shops: %d\n", VillageStructSample->ShopCount);
}