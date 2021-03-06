#include "Coordinates.h"


Coordinates::Coordinates(double longitude, double latitude):
	longitude(longitude), latitude(latitude){}

double Coordinates::getLongitude() const {
	return longitude;
}

double Coordinates::getLatitude() const {
	return latitude;
}

double Coordinates::distanceTo(Coordinates coords) {
	double x = coords.getLongitude() - longitude;
	double y = coords.getLatitude() - latitude;
	return sqrt(x*x + y*y);
}

ostream &operator<<(ostream &os, const Coordinates &c) {
	os << "(" << c.longitude << " , " << c.latitude << ")";
	return os;

}

string Coordinates::toString() const {
	return to_string(longitude) + ", " + to_string(latitude);
}

void Coordinates::setLatitude(double lat){
	this->latitude = lat;
}

void Coordinates::setLongitude(double longit){
	this->longitude = longit;
}
