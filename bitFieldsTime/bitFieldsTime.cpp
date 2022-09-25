#include <iostream>
using namespace std;

class Time {
	unsigned hours : 5, minutes : 6, seconds : 6, milliseconds : 10;
public:
	Time(unsigned h = 0, unsigned m = 0, unsigned s = 0, unsigned ms = 0) :hours(h), minutes(m), seconds(s), milliseconds(ms) {
		if (h > 23) hours = 23;
		if (m > 59) minutes = 59;
		if (s > 59) seconds = 59;
		if (ms > 999) milliseconds = 999;
	}
	void output() {
		cout << hours << ":" << minutes << ":" << seconds << ":" << milliseconds << endl;
	}
	void setTime(unsigned h, unsigned m, unsigned s, unsigned ms) {
		if (h > 23) hours = 23;
		else hours = h;
		if (m > 59) minutes = 59;
		else minutes = m;
		if (s > 59) seconds = 59;
		else seconds = s;
		if (ms > 999) milliseconds = 999;
		else milliseconds = ms;
	}
	void setH(unsigned h) {
		if (h > 23) hours = 23;
		else hours = h;
	}
	void setM(unsigned m) {
		if (m > 59) minutes = 59;
		else minutes = m;
	}
	void setS(unsigned s) {
		if (s > 59) seconds = 59;
		else seconds = s;
	}
	void setMS(unsigned ms) {
		if (ms > 999) milliseconds = 999;
		else milliseconds = ms;
	}
	void getTime(short& h_variable, short& m_variable, short& s_variable, short& ms_variable) {
		h_variable = hours;
		m_variable = minutes;
		s_variable = seconds;
		ms_variable = milliseconds;
	}
	inline short getH() { return hours; }
	inline short getM() { return minutes; }
	inline short getS() { return seconds; }
	inline short getMS() { return milliseconds; }
	void outputDifference(Time& T) {
		cout << (hours > T.getH() ? hours - T.getH() : T.getH() - hours) << ":" << (minutes > T.getM() ? minutes - T.getM() : T.getM() - minutes) << ":" <<
			(seconds > T.getS() ? seconds - T.getS() : T.getS() - seconds) << ":" << (milliseconds > T.getMS() ? milliseconds - T.getMS() : T.getMS() - milliseconds) << endl;
	}
	Time getDifference(Time& T) {
		return Time((hours > T.getH() ? hours - T.getH() : T.getH() - hours), (minutes > T.getM() ? minutes - T.getM() : T.getM() - minutes),
			(seconds > T.getS() ? seconds - T.getS() : T.getS() - seconds), (milliseconds > T.getMS() ? milliseconds - T.getMS() : T.getMS() - milliseconds));
	}
};

int main() {
	Time T;
	T.setTime(-4, 60, -60, 1000);
	Time T2 = T;
	cout << "time before:\n";
	T.output();

	T.setMS(111);
	T.setM(33);
	T.setH(3);
	T.setS(33);

	short h, m, s, ms;
	T.getTime(h, m, s, ms);
	cout << "\ntime after:\n" << h << ":" << m << ":" << s << ":" << ms << endl;

	cout << "\ndifference:\n";
	T.outputDifference(T2);

	cout << "\nhour difference:\n";
	cout << T.getDifference(T2).getH();
}