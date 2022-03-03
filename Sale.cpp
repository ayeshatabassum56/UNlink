#include "Sale.h"

Sale::Sale(const string& tit, const string& des, const string& c_i, bool st, double ap, double mr) :Post(tit, des, c_i, st)
{
	this->Asking_price = ap;
	this->Minimum_raise = mr;
	this->Highest_price = 0;
	this->ID = "SAL";
	sale_id++;
	if (sale_id >= 0 && sale_id <= 9)
	{
		this->ID += "00" + to_string(sale_id);
	}
	else if (sale_id >= 10 && sale_id <= 99)
	{
		this->ID += "0" + to_string(sale_id);
	}
	else
	{
		this->ID += to_string(sale_id);
	}

}
string Sale::getPostDetails()
{
	string temp = Post::getPostDetails()+"\nMinimum raise: " + to_string(this->Minimum_raise) + "\n";
	if (Highest_price > 0)
	{
		temp += "Highest-Offer: " + to_string(this->Highest_price) + "\n";
	}
	else
	{
		temp += "Highest-Offer: No Offer \n";
	}
	return temp;
}
bool Sale::handleReply(Reply replies)
{
	if (this->Status == true && replies.getValue() > this->Minimum_raise)
	{
		if (replies.getValue() > this->Highest_price)
		{
			this->Highest_price = replies.getValue();
			this->replies = regrow(this->replies, size_reply, size_reply + 1, replies);
			if (this->Highest_price >= this->Asking_price)
			{
				this->Status = false;
			}
			return true;
		}

	}
	return false;
}
string Sale::getReplyDetails()
{
	string temp = {};
	Reply sort;
	////sorting////
	if (size_reply > 1)
	{
		for (int i = 0; i < size_reply; i++)
		{
			for (int j = i + 1; i < size_reply; j++)
			{
				if (this->replies[i]->getValue() < this->replies[j]->getValue())
				{
					sort = this->replies[i][0];
					this->replies[i][0] = this->replies[j][0];
					this->replies[j][0] = sort;
				}
			}
		}
	}
	temp = this->getPostDetails() +"Asking-Price: " + to_string(this->Asking_price) + "\n"+ "Offer-History \n";
	for (int i = 0; i < size_reply; i++)
	{
		temp += this->replies[i]->getResponderId()+ ":" + to_string(this->replies[i]->getValue()) + "\n";
	}
	return temp;

}
int Sale::sale_id = 0;
void Sale::setAsking_price(double ap)
{
	this->Asking_price = ap;
}
void Sale::setHighest_price(double hp)
{
	this->Highest_price = hp;
}
void Sale::setMinimum_raise(double mr)
{
	this->Minimum_raise = mr;
}

double Sale::getAsking_price()
{
	return this->Asking_price;
}
double Sale::getHighest_price()
{
	return this->Highest_price;
}
double Sale::getMinimum_raise()
{
	return this->Minimum_raise;
}

