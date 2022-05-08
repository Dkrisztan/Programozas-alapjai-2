#include "pstring.h"

std::ostream& operator<<(std::ostream& os, const PString& s0) {
	os << s0.c_str();
	return os;
}

std::istream& operator>>(std::istream& is, PString& s0) {
	unsigned char ch;
	s0 = String("");
	std::ios_base::fmtflags fl = is.flags();
	is.setf(std::ios_base::skipws);
	while (is >> ch) {
		is.unsetf(std::ios_base::skipws);
		if (isspace(ch)) {
			is.putback(ch);
			break;
		}
		else {
			s0 = s0 + ch;
		}
	}
	is.setf(fl);
	return is;
}

void PString::write(std::ostream& os) {
	os << size() << " " << c_str();
}

void PString::read(std::istream& is) {
	size_t tempsize;
	PString tmp="";
	unsigned char ch;
	std::ios_base::fmtflags fl = is.flags();
	is >> tempsize;
	is.unsetf(std::ios_base::skipws);
	is >> ch;
	while (tempsize>0){
		is >> ch;
		tmp = tmp + ch;
		tempsize--;
	}
	PString temp(tmp);
	*this = temp;
	is.setf(fl);
}