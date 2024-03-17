#include "TimeC.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int TimeC::Triad::counter = 0;

int TimeC::counter = 0;

int TimeC::getCounter() {
	return TimeC::counter;
}

int TimeC::Triad::getCounter() {
	return TimeC::Triad::counter;
}


TimeC::Triad::Triad() {
	hour = 0;
	min = 0;
	sec = 0;
	counter++;
}

TimeC::Triad::Triad(int h, int m, int s) {
	hour = h;
	min = m;
	sec = s;
	counter++;
}

TimeC::Triad::Triad(const Triad& t) {
	this->hour = t.hour;
	this->min = t.min;
	this->sec = t.sec;
	counter++;
}

void TimeC::Triad::incremSec() {
	int tmp = getSec();
	setSec(++tmp);
}

istream& operator >> (istream& in, TimeC::Triad& r) {
	int h, m, s;
	do {
		cout << "Enter hour: ";
		in >> h;
		cout << "Enter minute: ";
		in >> m;
		cout << "Enter second: ";
		in >> s;
	} while (!(h < 24 && h >= 0 && m < 60 && m >= 0 && s < 60 && s >= 0));
	r.setHour(h);
	r.setMin(m);
	r.setSec(s);
	return in;
}

ostream& operator << (ostream& out, const TimeC::Triad& r) {
	out << string(r);
	return out;
}

TimeC::Triad::operator string () const {
	stringstream ss;
	ss << "Hour: " << getHour() << endl;
	ss << "Minute: " << getMin() << endl;
	ss << "Second: " << getSec() << endl;
	return ss.str();
}

TimeC::Triad& TimeC::Triad::operator ++() {
	hour++;
	return *this;
}

TimeC::Triad& TimeC::Triad::operator --() {
	hour--;
	return *this;
}

TimeC::Triad TimeC::Triad::operator ++(int) {
	Triad n(*this);
	min++;
	return n;
}

TimeC::Triad TimeC::Triad::operator --(int) {
	Triad n(*this);
	min--;
	return n;
}

TimeC::TimeC() {
	triad.setHour(0);
	triad.setMin(0);
	triad.setSec(0);
	counter++;
}

TimeC::TimeC(Triad t) {
	triad = t;
	counter++;
}

TimeC::TimeC(const TimeC& t) {
	this->triad = t.triad;
	counter++;
}

istream& operator >> (istream& in, TimeC& r) {
	in >> r.triad;
	return in;
}

TimeC::operator string () const {
	stringstream ss;
	ss << "h: " << triad.getHour() << "\nm: " << triad.getMin() << "\ns: " << triad.getSec() << endl;
	return ss.str();
}


ostream& operator << (ostream& out, const TimeC& r) {
	out << string(r);
	return out;
}

void TimeC::incremSec() {
	triad.incremSec();
}

void TimeC::operator+(int n) {
	triad.setMin(triad.getMin() + n);
}

void TimeC::operator*(int n) {
	triad.setSec(triad.getSec() + n);
}

TimeC& TimeC::operator ++() {
	++triad;
	return *this;
}

TimeC& TimeC::operator --() {
	--triad;
	return *this;
}

TimeC TimeC::operator ++(int) {
	TimeC n(*this);
	triad++;
	return n;
}

TimeC TimeC::operator --(int) {
	TimeC n(*this);
	triad--;
	return n;
}