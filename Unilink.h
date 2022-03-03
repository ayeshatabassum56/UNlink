//
//#include"Event.h"
//#include"Reply.h"
//#include"Sale.h"
//#include"Post.h"
//#include<iostream>
//using namespace std;
//class UniLink
//{
//	Post** ptr;
//	int NoPosts;
//	Reply reply;
//public:
//	UniLink();
//	void Menu();
//	void MenuPrint();
//	void Regrow();
//};
#pragma once
#include"Event.h"
#include"Job.h"
#include"Post.h"
#include"Sale.h"
#include<iostream>
using namespace std;

class Unilink
{
	string user;
	Post** all;
	int sizep;
	void menu();
public:
	Unilink();
	Post** shrink(Post**, int, Post*&);
	Post** regrow(Post**, int, Post*&);
	void start();
	~Unilink();
};

