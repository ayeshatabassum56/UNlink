#pragma once
#include<string>
#include"Reply.h"
#include "Post.h"
class Event :public Post
{
private:

	string Venue;
	string Date;
	int Capacity;
	int Attendee;
	static int eve_id;
	//int hold = 000;
public:
	Event(const string&, const string&, const string&, bool, string, string, int);
	string getPostDetails();
	 bool  handleReply(Reply replies);
	 string getReplyDetails();
	string getvenue();
		string getdate();
		int getcapacity();
		int getattendee();
		void setvenue(string);
		void setdate(string);
		void setcapacity(int);
		void setattendee(int);
};