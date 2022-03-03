#include "Reply.h"
Reply::Reply()
{
	this->Id = {};
   this->Value = 0;
   this->ResponderId = {};
}
Reply::~Reply(void)
{

}
Reply::Reply(const string& id, double v, const string& R_d)	
{
	this->Id = id;
	this->Value = v;
	this->ResponderId = R_d;
}
string Reply::getId() const 
{
	return Id; 
}
void Reply::setId(string id) 
{
	Id = id; 
}
double Reply::getValue() const 
{
	return Value; 
}
void Reply::setValue(double value) 
{
	this->Value = value; 
}
string Reply::getResponderId() const 
{
	return ResponderId;
}
void Reply::setResponderId(string responderId) 
{
	ResponderId = responderId; 
}
