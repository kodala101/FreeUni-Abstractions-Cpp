#include <iostream>
#include <string>
#include "set.h"
#include "vector.h"
#include "console.h"

using namespace std;

bool coversAllCities(Set<string>& cities, Vector< Set<string> >& subVector) {
    for (string s : cities) {
        bool b = false;
        for (int i = 0; i < subVector.size(); i++) {
            if (subVector[i].contains(s)) b = true;
        }
        if (!b) return false;
    }
    return true;
}

Vector<  Vector< Set<string> >  > allSubVectors(Vector< Set<string> > locations) {
    Vector<  Vector< Set<string> >  > s;
    if (locations.size() == 0) {
        Vector< Set<string> > empty;
        s.add(empty);
        return s;
    }
    Set<string> first = locations[0];
    locations.remove(0);
    Vector<  Vector< Set<string> >  > withoutFirst = allSubVectors(locations);
    for (Vector< Set<string> > v : withoutFirst) {
        Vector< Set<string> > copy = v;
        copy.add(first);
        s.add(v);
        s.add(copy);
    }
    return s;
}

bool canOfferUniversalCoverage(Set<string>& cities, Vector< Set<string> >& locations, int numHospitals, Vector< Set<string> >& result) {
    if (locations.size() <= numHospitals) {
        if (coversAllCities(cities, locations)) {
            result = locations;
            return true;
        }
        return false;
    }
    bool b = false;
    for (Vector< Set<string> > v : allSubVectors(locations)) {
        if( v.size() == numHospitals && canOfferUniversalCoverage(cities, v, numHospitals, result)) b = true;
    }
    return b;
}

int main() {
    Vector< Set<string> > result;

    Set<string> cities;
    cities.add("A");
    cities.add("B");
    cities.add("C");
    cities.add("D");
    cities.add("E");
    cities.add("F");

    Vector< Set<string> > locations;
    Set<string> f;
    f.add("A");
    f.add("B");
    f.add("C");
    locations.add(f);

    Set<string> s;
    s.add("A");
    s.add("C");
    s.add("D");
    locations.add(s);

    Set<string> t;
    t.add("B");
    t.add("F");
    locations.add(t);

    Set<string> fo;
    fo.add("E");
    fo.add("C");
    fo.add("F");
    locations.add(fo);

    cout << canOfferUniversalCoverage(cities, locations, 3, result) << endl;

    return 0;
}
