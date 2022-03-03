#pragma once
#include<string>
#include"Reply.h"
#include<iostream>
using namespace std;
class Post {
protected:
	string ID;
	string Title;
	string Des;
	string Cid;
	bool Status;
	Reply** replies;
    int size_reply;
    Reply** regrow(Reply**, int, int, Reply);
    bool check(Reply&);
public:
	Post();
	~Post();
	Post(const string&, const string&, const string&, bool);
	virtual bool handleReply(Reply reply) = 0;
	virtual string getReplyDetails() = 0;
	virtual string getPostDetails();
	string getID() const;
	void setID(string c);
	string getTitle() const;
	void setTitle(string T);
	string getDes() const;
	void setDes(string D);
	string getCid() const;
	void setCid(string c);
	bool getStatus() const;
	void setStatus(bool status);
};
