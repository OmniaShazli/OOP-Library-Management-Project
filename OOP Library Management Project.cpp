#include <iostream>
#include <string>

using namespace std;

class LibraryItem {
protected:
	static int num_of_items;
	string  title;
	bool availability;
public:
	LibraryItem() :title(""), availability(true){ num_of_items++; }
	virtual ~LibraryItem() { num_of_items--; }
	
	void set_title(string  title) {
		this->title = title;
	}
	void set_availability(bool  availability) {
		this->availability = availability;
	}
	string get_title() {
		return title;
	}
	bool get_availability() {
		return availability;
	}
	static int get_num_of_items() {
		return num_of_items;
	}
	virtual void display() = 0;
};
int LibraryItem::num_of_items = 0;
class Book :public LibraryItem {
	string author;
	int ISBN;
public:
	Book() :author(""), ISBN(123){}

	void set_author(string  author) {
		this->author = author;
	}
	void set_ISBN(int  ISBN) {
		this->ISBN = ISBN;
	}
	string get_author() {
		return author;
	}
	int get_ISBN() {
		return ISBN;
	}
	void display() {
		cout << "title =" << get_title() << endl;
		cout << "availability =" <<(availability ? "Available" : "Not Available") << endl;
		cout << "author= " << author
			<< endl << "ISBN= " << ISBN << endl;
	}
};
class Magazine :public LibraryItem {
	int issueNumber;
	string publisher;
public:
	Magazine() :issueNumber(0), publisher(""){}
	
	void set_issueNumber(int  issueNumber) {
		this->issueNumber = issueNumber;
	}
	void set_publisher(string  publisher) {
		this->publisher = publisher;
	}
	int get_issueNumber() {
		return issueNumber;
	}
	string get_publisher() {
		return publisher;
	}
	void display() {
		cout << "title =" << get_title() << endl;
		cout << "availability =" <<(availability ? "Available" : "Not Available") << endl;
		cout << "issueNumber= " << issueNumber
			<< " " << "publisher= " << publisher << endl;
	}
};
class DVD :public LibraryItem {
	string director;
	int duration;
public:
	DVD() :director(""), duration(0){}
	
	void set_director(string  director) {
		this->director = director;
	}
	void set_duration(int  duration) {
		this->duration = duration;
	}
	string get_director() {
		return director;
	}
	int get_duration() {
		return duration;
	}
	void display() {
		cout << "title =" << get_title() << endl;
		cout << "availability =" <<(availability ? "Available" : "Not Available") << endl;
		cout << "director= " << director
			<< " " << "duration= " << duration << endl;
	}
};
class LibrarySystem {

	LibraryItem* Array[100];
	static int Count;
	int BookCount = 0;
	int MagazineCount = 0;
	int DVDCount = 0;
public:
	LibrarySystem() {}
	virtual ~LibrarySystem() {
		for (int i = 0; i < Count; i++) {
			delete Array[i];
		}
	}
	void addBook() {
		int n;
		cout << "How many books do you want to add ? ";
		cin >> n;
		for (int i = 0; i < n; i++) {
			Array[Count] = new Book;
			Book* curbook = dynamic_cast<Book*>(Array[Count]);
			cout << "Enter the book title.";
			string s;
			cin.ignore();
			getline(cin, s, '\n');
			Array[Count]->set_title(s);
			cout << "Enter the book author .";
			getline(cin, s);
			curbook->set_author(s);
			cout << "Enter the book ISBN .";
			int I;
			cin >> I;
			curbook->set_ISBN(I);
			Count++;
			BookCount++;
			cout << "Done..." << endl;
		}
	}
	void addMagazine() {
		int n;
		cout << "How many magazines do you want to add ? ";
		cin >> n;
		for (int i = 0; i < n; i++) {
			Array[Count] = new Magazine;
			Magazine* mcur = dynamic_cast<Magazine*>(Array[Count]);
			cout << "Enter the magazine title.";
			string s;
			cin.ignore();
			getline(cin, s, '\n');
			Array[Count]->set_title(s);
			cout << "Enter the magazine issueNumber .";
			int I;
			cin >> I;
			mcur->set_issueNumber(I);
			cout << "Enter the magazine publisher .";
			getline(cin, s);
			mcur->set_publisher(s);
			Count++;
			MagazineCount++;
			cout << "Done..." << endl;
		}
	}
	void addDVD() {
		int n;
		cout << "How many DVDs do you want to add ? ";
		cin >> n;
		for (int i = 0; i < n; i++) {
			Array[Count] = new DVD;
			DVD* dcur = dynamic_cast<DVD*>(Array[Count]);
			cout << "Enter the DVD title.";
			string s;
			cin.ignore();
			getline(cin, s, '\n');
			Array[Count]->set_title(s);
			cout << "Enter the DVD director.";
			getline(cin, s);
			dcur->set_director(s);
			cout << "Enter the DVD duration .";
			int I;
			cin >> I;
			dcur->set_duration(I);
			Count++;
			DVDCount++;
			cout << "Done..." << endl;
		}
	}
	void BorrowItem() {
		cout << "1.Borrow Book" << endl << "2.Borrow Magazine" << endl
			<< "3.Borrow DVD" << endl << "0.Exit" << endl;
		int n;
		cin >> n;
		switch (n)
		{
		case 1:
		{
			cout << "Enter the book title" << endl;
			string s;
			cin.ignore();
			getline(cin, s, '\n');
			bool ch = 0;
			for (int i = 0; i < Count; i++) {
				if (s == Array[i]->get_title()) {
					if (Array[i]->get_availability() == true) {
						ch = 1;
						Array[i]->set_availability(false);
						cout << "Borrowed successfully" << endl;
					}
				}
			}
			if (ch == 0) {
				cout << "The book is not available" << endl;
			}

			break;
		}
		case 2:
		{
			cout << "Enter the magazine title" << endl;
			string s;
			cin.ignore();
			getline(cin, s);
			bool ch = 0;
			for (int i = 0; i < Count; i++) {
				if (s == Array[i]->get_title()) {
					if (Array[i]->get_availability() == true) {
						ch = 1;
						Array[i]->set_availability(false);
						cout << "Borrowed successfully" << endl;
					}
				}
			}
			if (ch == 0) {
				cout << "The magazine is not available" << endl;
			}
			break;
		}
		case 3:
		{
			cout << "Enter the dvd title" << endl;
			string s;
			cin.ignore();
			getline(cin, s, '\n');
			bool ch = 0;
			for (int i = 0; i < Count; i++) {
				if (s == Array[i]->get_title()) {
					if (Array[i]->get_availability() == true) {
						ch = 1;
						Array[i]->set_availability(false);
						cout << "Borrowed successfully" << endl;
					}
				}
			}
			if (ch == 0) {
				cout << "The dvd is not available" << endl;
			}
			break;
		}
		case 0:
			break;
		default:
			cout << "Invalid choice!" << endl;
			break;
		}
	}
	void ReturnItem() {
		cout << "1.Return Book" << endl << "2.Return Magazine" << endl
			<< "3.Return DVD" << endl << "0.Exit" << endl;
		int n;
		cin >> n;
		switch (n)
		{
		case 1:
		{
			cout << "Enter the book title" << endl;
			string s;
			cin.ignore();
			getline(cin, s, '\n');
			bool ch = 0;
			for (int i = 0; i < Count; i++) {
				if (s == Array[i]->get_title()) {
					if (Array[i]->get_availability() == false) {
						ch = 1;
						Array[i]->set_availability(true);
						cout << "Returned successfully" << endl;
					}
				}
			}
			if (ch == 0) {
				cout << "The book was not found in the library" << endl;
			}

			break;
		}
		case 2:
		{
			cout << "Enter the magazine title" << endl;
			string s;
			cin.ignore();
			getline(cin, s, '\n');
			bool ch = 0;
			for (int i = 0; i < Count; i++) {
				if (s == Array[i]->get_title()) {
					if (Array[i]->get_availability() == false) {
						ch = 1;
						Array[i]->set_availability(true);
						cout << "Returned successfully" << endl;
					}
				}
			}
			if (ch == 0) {
				cout << "The magazine was not found in the library" << endl;
			}
			break;
		}
		case 3:
		{
			cout << "Enter the dvd title" << endl;
			string s;
			cin.ignore();
			getline(cin, s, '\n');
			bool ch = 0;
			for (int i = 0; i < Count; i++) {
				if (s == Array[i]->get_title()) {
					if (Array[i]->get_availability() == false) {
						ch = 1;
						Array[i]->set_availability(true);
						cout << "Returned successfully" << endl;
					}
				}
			}
			if (ch == 0) {
				cout << "The dvd was not found in the library" << endl;
			}
			break;
		}
		case 0:
			break;
		default:
			cout << "Invalid choice!" << endl;
			break;
		}
	}
	void displayItems() {
		int f = 1;
		while (f != 0)
		{
			cout << "1.Books" << endl << "2.Magazines" << endl
				<< "3.DVDs" << endl << "0.Exit" << endl;
			int n;
			cin >> n;
			switch (n)
			{
			case 1:
				if (BookCount == 0) {
					cout << "No books available" << endl;
				}
				else {
					cout << "Books in the library: " << endl;
					for (int i = 0; i < Count; i++) {
					Book* curbook = dynamic_cast<Book*>(Array[i]);
						if (curbook) {
							Array[i]->display();
							cout << "----------------------" << endl;
						}
					}
				}
				break;
			case 2:
				if (MagazineCount == 0) {
					cout << "No magazines available" << endl;
				}
				else {
					cout << "magazines in the library: " << endl;
					for (int i = 0; i < Count; i++) {
					Magazine* mcur = dynamic_cast<Magazine*>(Array[i]);
						if (mcur) {
							Array[i]->display();
							cout << "----------------------" << endl;
						}
					}
				}
				break;
			case 3:
				if (DVDCount == 0) {
					cout << "No DVDs available" << endl;
				}
				else {
					cout << "DVDs in the library: " << endl;
					for (int i = 0; i < Count; i++) {
							DVD* dcur = dynamic_cast<DVD*>(Array[i]);
							if (dcur) {
							Array[i]->display();
							cout << "----------------------" << endl;
						}
					}
				}
				break;
			case 0:
				f = 0;
				break;
			default:
				cout << "Invalid choice!" << endl;
				break;
			}
		}
	}
};
int LibrarySystem::Count = 0;;
int main()
{
	LibrarySystem op1;
	while (true) {
		cout << "Welcome to the library system" << endl;
		cout << "-----------------------------" << endl;
		cout << "1.Add Book" << endl << "2.Add Magazine" << endl << "3.Add DVD" << endl <<
			"4.Borrow Item" << endl << "5.Return Item" << endl << "6.Display available items"
			<< endl << "7.Exit" << endl << "Please select an option" << endl;
		int n;
		cin >> n;
		switch (n) {
		case 1:
			op1.addBook();
			break;
		case 2:
			op1.addMagazine();
			break;
		case 3:
			op1.addDVD();
			break;
		case 4:
			op1.BorrowItem();
			break;
		case 5:
			op1.ReturnItem();
			break;
		case 6:
			op1.displayItems();
			break;
		case 7:
			return 0;
			break;
		default:
			cout << "Invalid choice!" << endl;
			break;
		}
	}
}
