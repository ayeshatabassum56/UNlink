#include "Post.h"
Post::Post()
{
	this->Title = {};
	this->replies = nullptr;
	this->Des = {};
	this->Cid = {};
	this->Status = {};
	this->size_reply = 0;
}
Post::Post(const string& T, const string&  D, const string& C, bool S)
{
	this->Title = T;
	this->replies = nullptr;
	this->Des = D;
	this->Cid = C;
	this->Status = S;
	this->size_reply = 0;
}
Reply** Post::regrow(Reply** ptr, int size, int new_size, Reply copy)
{
	Reply** temp = new Reply * [new_size];
	for (int i = 0; i < new_size; i++)
	{
		if (i < size)
		{
			temp[i] = new Reply(ptr[i]->getId(), ptr[i]->getValue(), ptr[i]->getResponderId());
		}
		else
		{
			temp[i] = new Reply(copy.getId(), copy.getValue(), copy.getResponderId());
		}
	}
	for (int i = 0; i < size; i++)
	{
		delete ptr[i];
	}
	delete[]ptr;
	ptr = nullptr;
	return temp;
}
Post::~Post(void)
{
	if (this->replies != nullptr)
			{
				delete[] replies;
			}
}
string Post::getPostDetails()
{
	
	string concatination{}, temp = {};
		if (this->Status)
		{
			temp = "ONN";
		}
		else
		{
			temp = "OFF";
		}
		concatination = "ID: " + this->ID + "\nTitle: " + this->Title + "\nDescription: " + this->Des + "\nStatus: " + temp;
		return concatination;
}
string Post::getID() const
{ 
	return ID; 
}
void Post::setID(string iD) 
{ 
	ID = iD; 
}
string Post::getTitle() const 
{ 
	return Title; 
}
void Post::setTitle(string title) 
{ 
	Title = title; 
}
string Post::getDes() const 
{ 
	return Des;
}
void Post::setDes(string des) 
{
	Des = des; 
}
string Post::getCid() const 
{ 
	return Cid; 
}
void Post::setCid(string cid) 
{ 
	Cid = cid; 
}
bool Post::getStatus() const
{ 
	return Status;
}
void Post::setStatus(bool status) 
{
	Status = status;
}

bool Post::check(Reply& obj)
{
	for (int i = 0; i < size_reply; i++)
	{
		if (replies[i]->getResponderId() == obj.getResponderId())
		{
			return false;
		}
	}
	return true;
}
