#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class TimeC
{
public:
	class Triad
	{
		int hour, min, sec;
		static int counter;
	public:
		Triad();
		Triad(int, int, int);
		Triad(const Triad&);
		~Triad() { counter--; };

		void setHour(int h) { hour = h; };
		void setMin(int m) { min = m; };
		void setSec(int s) { sec = s; };

		int getHour() const { return this->hour; };
		int getMin() const { return this->min; };
		int getSec() const { return this->sec; };

		Triad& operator ++();//hour
		Triad& operator --();//hour
		Triad operator ++(int);//min
		Triad operator --(int);//min

		void incremSec();

		friend istream& operator >> (istream& in, Triad& r);
		friend ostream& operator << (ostream& out, const Triad& r);

		operator string () const;

		static int getCounter();
	};
private:
	Triad triad;
	static int counter;

public:
	TimeC();
	TimeC(Triad);
	TimeC(const TimeC&);
	~TimeC() { counter--; };

	Triad getTriad() { return triad; };

	void setTriad(Triad t) { triad = t; };

	TimeC& operator ++();
	TimeC& operator --();
	TimeC operator ++(int);
	TimeC operator --(int);

	void operator+(int n);
	void operator*(int n);
	void incremSec();

	friend ostream& operator << (ostream& out, const TimeC& r);
	friend istream& operator >> (istream& in, TimeC& r);

	operator std::string() const;

	static int getCounter();
};

