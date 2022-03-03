#include "Event.h"

Event::Event(const string& tit, const string& des, const string& c_i, bool st, string v, string d, int c) :Post(tit, des, c_i, st)
{
	this->Attendee = 0;
	this->Date = d;
	this->Capacity = c;
	this->Venue = v;
	this->ID = "EVE";
	eve_id++;
	if (eve_id >= 0 && eve_id <= 9)
	{
		this->ID += "00" + to_string(eve_id);
	}
	else if (eve_id >= 10 && eve_id <= 99)
	{
		this->ID += "0" + to_string(eve_id);
	}
	else
	{
		this->ID += to_string(eve_id);
	}
}
string Event::getPostDetails()
{
	string eve = Post::getPostDetails()+ "\nVenue: " + this->Venue + "\n"+"Date: " + 
		this->Date + "\n"+ "Capacity: " + to_string(this->Capacity) +
		"\n"+eve +"Attendees: " + to_string(this->Attendee) + "\n";
	return eve;
}
bool  Event::handleReply(Reply replies)
{
	if (replies.getValue() == 1 && this->Attendee < this->Capacity && !(this->check(replies)) && this->Status == true)
	{
		this->replies = regrow(this->replies, this->size_reply, this->size_reply + 1, replies);
		this->Attendee += 1;
		return true;
		if (this->Attendee == this->Capacity)
		{
			this->Status = false;
		}
	}

	return false;
}
string Event::getReplyDetails()
{
	string temp = {};
	for (int i = 0; i < size_reply; i++)
	{
		temp += this->replies[i]->getResponderId() + ",";
	}
	return temp;
}
string Event::getvenue()
{
	return Venue;
}
string Event::getdate()
{
	return Date;
}
int Event::getcapacity()
{
	return Capacity;
}
int Event::getattendee()
{
	return Attendee;
}

void Event::setvenue(string v)
{
	this->Venue = v;
}
void Event::setdate(string d)
{
	this->Date = d;
}
void Event::setcapacity(int c)
{
	this->Capacity = c;
}
void Event::setattendee(int a)
{
	this->Attendee = a;
}
int Event::eve_id = 0;


