
#pragma once
#include "post.h"
#include<string>
class job :public Post
{
	double Proposed_price;
	double Lowest_offer;
	static int job_id;
public:
	job(const string&, const string&, const string&, bool, double);
     string getPostDetails();
	 bool handleReply(Reply replies);
	 string getReplyDetails();
	void setProposed_price(double);
	void setLowest_offer(double);
	double getProposed_price();
	double getLowest_offer();

};

