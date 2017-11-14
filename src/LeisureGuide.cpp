#include "LeisureGuide.h"

LeisureGuide::LeisureGuide() {
}

LeisureGuide::LeisureGuide(multimap<string, Beach *> beaches):
	beaches(beaches) {
}

LeisureGuide::LeisureGuide(multimap<string, Beach *> beaches, vector<Restaurant> restaurants, vector<POI> POIs, vector<Lodging> lodging):
	beaches(beaches), restaurants(restaurants), POIs(POIs), lodging(lodging) {
}

void LeisureGuide::displayAllBeaches() const{

	// Iterate through multimap's elements (by key)
	// Inside we iterate through the range generated by equal_range (all elements for that key)
	// No need to alter it outside of the inside for, since we are going through all the elements and it is being incremented
	for(auto it = beaches.cbegin(); it != beaches.cend(); ) {

		//Gets the range of elements for this key
		auto elem_range = beaches.equal_range(it->first);

		//Prints each key before printing the element range
		cout << it->first << ":\n";

		//Iterates through the elements for this key
		for(auto elem_it = elem_range.first; elem_it != elem_range.second; ++it, ++elem_it){
			//Prints each element for this key
			cout << elem_it->second << endl;
		}

	}

	// An alternative would be to use upper_bound to get the next key based on the passed key (it->first, aka current key)
	// it = beaches.upper_bound(it->first); //This would cycle it to the next key
}

void LeisureGuide::displayAllPOIs() const{
	for(auto const &poi : POIs)	{
		cout << poi << endl;
	}
}

void LeisureGuide::displayAllRestaurants() const{
	for(auto const &restaurant : restaurants){
		cout << restaurant << endl;
	}
}

void LeisureGuide::displayAllLodging() const{
	for(auto const &l : lodging){
		cout << l << endl;
	}
}
