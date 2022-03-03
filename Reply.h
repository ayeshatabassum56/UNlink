#pragma once
#include<iostream>
using namespace std;
class Reply {
private:
	string Id;
	double Value;
	string ResponderId;
public:
	Reply();
	~Reply();
	Reply(const string&, double, const string&);
	string getId() const;
	void setId(string id);
	double getValue() const;
	void setValue(double value);
	string getResponderId() const;
	void setResponderId(string responderId);
};
