#include "Unilink.h"
Unilink::Unilink()
{
	user = {};
	all = nullptr;
	sizep = 0;
}

void Unilink::start()
{

	int choice = 0;
	while (choice != 2)
	{
		cout << "                                      -----------------------------------------------------\n";
		cout << "                                      |                UniLink System                     |" << endl;
		cout << "                                      ----------------------------------------------------- \n\n";
		cout << "1. Please Login (if you want to login)" << endl;
		cout << "2. Quit (if you not want to login system)" << endl << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "|Please Enter Your choice|\n";
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout<<"Enter: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			cout << "| Please Enter your UserName |\n";
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			cout << "Enter: ";
			cin >> this->user;
			cout << "\nWelcome To Unilink System " << this->user << "!" << endl;
			menu();
			break;
		}
		case 2:
		{
			break;
		}

		}
	}
}
void Unilink::menu()
{

	int choice1 = 0;
	while (choice1 != 9)
	{
		cout << "                                      -----------------------------------------------------\n";
		cout << "                                      |                Student Menu                       |" << endl;
		cout << "                                      -----------------------------------------------------\n\n";
		cout << "1. New Event Post" << endl;
		cout << "2. New Sale Post" << endl;
		cout << "3. New Job Post" << endl;
		cout << "4. Reply To Post" << endl;
		cout << "5. Display My Posts" << endl;
		cout << "6. Display All Posts" << endl;
		cout << "7. Close Post" << endl;
		cout << "8. Delete Post" << endl;
		cout << "9. Log Out" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "|Please Enter Your choice|\n";
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "Enter: ";
		cin >> choice1;
		string title = {};
		string description = {};
		Post* ptr;
		switch (choice1)
		{
		case 1:    ///New Event-Post///
		{
			string venue = {}, date{};
			int capacity = 0;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			cout << "|Please Enter the Post Of Event's details | \n";
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
			cout << "Enter: \n";
			cin.ignore();
			cout << "Title Please: ";
			getline(cin, title);
			cout << "Description Please: ";
			getline(cin, description);
			cout << "Venue Please: ";
			getline(cin, venue);
			cout << "Date Please: ";
			getline(cin, date);
			cout << "Capacity Please: ";
			cin >> capacity;
			///Check///
			if (title == " " || description == " " || venue == " ")
			{
				cout << "ooohhh noooo! Your Event is not Created Successfully. \n";
			}
			else
			{
				ptr = new Event(title, description, user, true, venue, date, capacity);
				this->sizep += 1;
				this->all = regrow(all, sizep, ptr);
				cout << "Congrates! Your event has been created Successfullly with id: " << all[sizep - 1]->getID() << " \n";
			}
			break;
		}
		case 2:    ///New Sale Post///
		{
			double Askprice = 0, Min = 0;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			cout << "| Enter the Sale-Post details |\n";
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			cout << "Enter: \n";
			cin.ignore();
			cout << "Title Please: ";
			getline(cin, title);
			cout << "Description Please: ";
			getline(cin, description);
			cout << "Asking Price Please: ";
			cin >> Askprice;
			cout << "Minimum raise Please: ";
			cin >> Min;
			///Check///
			if (title == " " || description == " " || Askprice == 0)
			{
				cout << "ooohhh noooo! Your Event is not Created Successfully. \n";
			}
			else
			{
				ptr = new Sale(title, description, user, true, Askprice, Min);
				this->sizep += 1;
				this->all = regrow(all, sizep, ptr);
				cout << "Congrates! Your Sale Post has been created Successfullly with id: " << all[sizep - 1]->getID() << " \n";
			}
			break;
		}
		case 3:   ///New Job Post///
		{
			double pro = 0;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			cout << "| Enter the Job-Post details |\n";
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			cout << "Enter: \n";
			cin.ignore();
			cout << "Title: ";
			getline(cin, title);
			cout << "Description: ";
			getline(cin, description);
			cout << "Propose Price: ";
			cin >> pro;
			///Check///
			if (title == " " || description == " " || pro == 0)
			{
				cout << "ooohhh noooo! Your Event is not Created Successfully. \n";
			}
			else
			{
				ptr = new job(title, description, user, true, pro);
				this->sizep += 1;
				this->all = regrow(all, sizep, ptr);
				cout << "Congrates! Your Job Post has been created Successfullly with id:" << all[sizep - 1]->getID() << " \n";
			}
			break;
		}
		case 4:
		{
			string check = {};
			bool flag = false;
			cin.ignore();
			cout << "\nEnter the Post-ID: ";
			getline(cin, check);
			for (int x = 0; x < sizep; x++)
			{
				if (check == all[x]->getID())
				{
					flag = true;
				}
			}
			if (flag)
			{
				if (check[0] == 'E')
				{

				}
				else if (check[0] == 'S')
				{

				}
				else if (check[0] == 'J')
				{

				}
				else
				{
					cout << "\nInvalid.\n";
				}
			}
			else
			{
				cout << "\n Sorry! ID not Found.\n";
			}

			break;
		}
		case 5:  ////Display My Posts////
		{
			string check = {};
			cin.ignore();
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			cout << "| Please Enter your Post-ID |\n";
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			cout << "Enter: ";
			getline(cin, check);
			bool flag = false;
			cout << "\n           My Posts           \n" << endl;
			for (int x = 0; x < sizep; x++)
			{
				if (user == all[x]->getCid() && check == all[x]->getID())
				{
					cout << all[x][0].getPostDetails();
					cout << all[x][0].getReplyDetails();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "ID not found or Currently You did not reply on any post. \n";
			}
			break;
		}
		case 6:  ////Display All Posts////
		{
			cout << "\n----------All Posts----------\n" << endl;
			if (sizep == 0)
			{
				cout << "           Empty!\n";
			}
			for (int x = 0; x < sizep; x++)
			{
				cout << "\nPost (" << x + 1 << "):" << endl;
				cout << all[x][0].getPostDetails();
			}
			cout << "\n------------END------------\n" << endl;
			break;
		}
		case 7: ////Post Close////
		{
			string check = {};
			cin.ignore();
			cout << "Enter your Post ID: ";
			getline(cin, check);
			bool flag = false;
			for (int x = 0; x < sizep; x++)
			{
				if (check == all[x]->getID())
				{
					all[x]->setStatus(false);
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "The Post is not Found or Already Closed. \n";
			}
			break;
		}
		case 8: /////Post Delete////
		{
			string check = {};
			cin.ignore();
			cout << "Enter your Post ID: ";
			getline(cin, check);
			bool flag = false;
			for (int x = 0; x < sizep; x++)
			{
				if (user == all[x]->getCid() && check == all[x]->getID())
				{
					for (int y = x; y < sizep; y++)
					{
						all[y] = all[y + 1];
					}
					flag = true;
				}
			}

			if (flag == false)
			{
				cout << "The Post is not Found or Already Closed. \n";
			}
			else
			{
				this->sizep -= 1;
				this->all = shrink(all, sizep, ptr);
				cout << "\n-----Successfully Delete!-----\n";
			}
			break;
		}
		case 9:
		{
			break;
		}
		}
	}

}
Post** Unilink::regrow(Post** all, int size, Post*& ptr)
{
	Post** temp = new Post * [size];
	for (int i = 0; i < size; i++)
	{
		if (i < size - 1)
		{
			temp[i] = all[i];
		}
		else
		{
			temp[i] = ptr;
		}
	}
	all = nullptr;
	delete[] all;
	ptr = nullptr;
	return temp;
}
Post** Unilink::shrink(Post** all, int size, Post*& ptr)
{
	Post** temp = new Post * [size];
	for (int i = 0; i < size; i++)
	{
		temp[i] = all[i];

	}
	all = nullptr;
	delete[] all;
	ptr = nullptr;
	return temp;
}
Unilink::~Unilink()
{
	if (all != nullptr)
	{
		delete[]all;
	}
}
