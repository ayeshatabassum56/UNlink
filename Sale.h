
#pragma once
#include "Post.h"
#include<string>
using namespace std;
class Sale :public Post
{
	double Asking_price;
	double Highest_price;
	double Minimum_raise;
	static int sale_id;
public:
	Sale(const string&, const string&, const string&, bool, double, double);
	 string getPostDetails();
	 bool handleReply(Reply replies);
	 string getReplyDetails();
	void setAsking_price(double);
	void setHighest_price(double);
	void setMinimum_raise(double);
	double getAsking_price();
	double getHighest_price();
	double getMinimum_raise();

};

