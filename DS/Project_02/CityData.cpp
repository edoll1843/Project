#include "CityData.h"
#include <cstring>
#pragma warning(disable:4996)
CityData::CityData()
{
	LocationId = 0;//value declare
	name = new char[50]; //value declare
	country = new char[50]; //value declare
}

CityData::~CityData()
{
}

int CityData::GetLocationId()
{
	return LocationId; //return location
}

char * CityData::Getname()
{
	return name; // return name
}

char * CityData::Getcountry()
{
	return country; //return contry
}

void CityData::SetLocationId(int LocationId)
{
	this ->LocationId = LocationId;
}

void CityData::Setname(char * name)
{
	strncpy(this->name,name,sizeof(name)-1);
}

void CityData::Setcountry(char * country)
{
	strncpy(this->country,country,sizeof(country)-1);
}
