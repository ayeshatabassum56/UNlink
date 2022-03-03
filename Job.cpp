#include "Job.h"
job::job(const string& tit, const string& des, const string& c_i, bool st, double pp) :Post(tit, des, c_i, st)
{
	this->Proposed_price = pp;
	this->Lowest_offer = 0;
	this->ID = "JOB";
	job_id++;
	if (job_id >= 0 && job_id <= 9)
	{
		this->ID += "00" + to_string(job_id);
	}
	else if (job_id >= 10 && job_id <= 99)
	{
		this->ID += "0" + to_string(job_id);
	}
	else
	{
		this->ID += to_string(job_id);
	}
}
string job::getPostDetails()
{
	string temp = Post::getPostDetails()+ "\nProposed Price: " + to_string(this->Proposed_price)
		+ "\n"+ "Lowest Offer: " + to_string(this->Lowest_offer) + "\n";
	return temp;
}
bool job::handleReply(Reply replies)
{
	if (this->Status == true && replies.getValue() < this->Lowest_offer)
	{
		this->Lowest_offer = replies.getValue();
		this->replies = regrow(this->replies, size_reply, size_reply + 1, replies);
		return true;
	}
	return false;
}
string job::getReplyDetails()
{
	string temp = Post::getPostDetails();
	temp += "Offer-Back Data(History)";
	for (int i = 0; i < size_reply; i++)
	{
		temp += this->replies[i]->getResponderId() + ":" + to_string(this->replies[i]->getValue());
	}
	return temp;
}
int job::job_id = 0;
void job::setProposed_price(double pp)
{
	this->Proposed_price = pp;
}
void job::setLowest_offer(double lf)
{
	this->Lowest_offer = lf;
}

double job::getProposed_price()
{
	return Proposed_price;
}
double job::getLowest_offer()
{
	return job::Lowest_offer;
}
