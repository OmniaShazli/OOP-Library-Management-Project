#include <iostream>

using namespace std;

class LibraryItem {
	static int num_of_items;
	string  title;
	bool availability;
public:
	LibraryItem() {
		title = "";
		availability = true;
		num_of_items++;
	}
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
	void display1() {
		cout << "title =" << get_title() << endl;
		cout << "availability =" <<
			(availability ? "Available" : "Not Available") << endl;

	}
};
int LibraryItem::num_of_items = 0;
class Book :public LibraryItem {
	string author;
	int ISBN;
public:
	Book() {
		author = "";
		ISBN = 1234;
	}
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
		display1();
		cout << "author= " << author
			<< endl << "ISBN= " << ISBN << endl;
	}
};
class Magazine :public LibraryItem {
	int issueNumber;
	string publisher;
public:
	Magazine() {
		issueNumber = 0;
		publisher = "";
	}
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
		display1();
		cout << "issueNumber= " << issueNumber
			<< " " << "publisher= " << publisher << endl;
	}
};
class DVD :public LibraryItem {
	string director;
	int duration;
public:
	DVD() {
		director = "";
		duration = 0;
	}
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
		display1();
		cout << "director= " << director
			<< " " << "duration= " << duration << endl;
	}
};
class LibrarySystem {
	Book* books[100];
	Magazine* magazines[100];
	DVD* dvds[100];
	int bookCount = 0;
	int magazineCount = 0;
	int dvdCount = 0;
public:
	LibrarySystem(){}
	~LibrarySystem() {
		for (int i = 0; i < bookCount; i++) {
			delete books[i];
		}
		for (int i = 0; i < magazineCount; i++) {
			delete magazines[i];
		}
		for (int i = 0; i < dvdCount; i++) {
			delete dvds[i];
		}
	}
	void addBook() {
		int n;
		cout << "How many books do you want to add ? ";
		cin >> n;
		for (int i = 0; i < n; i++) {
			books[bookCount] = new Book;
			cout << "Enter the book title.";
			string s;
			cin >> s;
			books[bookCount]->set_title(s);
			cout << "Enter the book author .";
			cin >> s;
			books[bookCount]->set_author(s);
			cout << "Enter the book ISBN .";
			int I;
			cin >> I;
			books[bookCount]->set_ISBN(I);
			bookCount++;
			cout << "Done..." << endl;
		}
	}
	void addMagazine() {
		int n;
		cout << "How many magazines do you want to add ? ";
		cin >> n;
		for (int i = 0; i < n; i++) {
			magazines[magazineCount] = new Magazine;
			cout << "Enter the magazine title.";
			string s;
			cin >> s;
			magazines[magazineCount]->set_title(s);
			cout << "Enter the magazine issueNumber .";
			int I;
			cin >> I;
			magazines[magazineCount]->set_issueNumber(I);
			cout << "Enter the magazine publisher .";
			cin >> s;
			magazines[magazineCount]->set_publisher(s);
			magazineCount++;
			cout << "Done..." << endl;
		}
	}
	void addDVD() {
		int n;
		cout << "How many DVDs do you want to add ? ";
		cin >> n;
		for (int i = 0; i < n; i++) {
			dvds[dvdCount] = new DVD;
			cout << "Enter the DVD title.";
			string s;
			cin >> s;
			dvds[dvdCount]->set_title(s);
			cout << "Enter the DVD director.";
			cin >> s;
			dvds[dvdCount]->set_director(s);
			cout << "Enter the DVD duration .";
			int I;
			cin >> I;
			dvds[dvdCount]->set_duration(I);
			dvdCount++;
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
			cin >> s;
			bool ch = 0;
			for (int i = 0; i < bookCount; i++) {
				if (s == books[i]->get_title()) {
					if (books[i]->get_availability() == true) {
						ch = 1;
						books[i]->set_availability(false);
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
			cin >> s;
			bool ch = 0;
			for (int i = 0; i < magazineCount; i++) {
				if (s == magazines[i]->get_title()) {
					if (magazines[i]->get_availability() == true) {
						ch = 1;
						magazines[i]->set_availability(false);
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
			cin >> s;
			bool ch = 0;
			for (int i = 0; i < dvdCount; i++) {
				if (s == dvds[i]->get_title()) {
					if (dvds[i]->get_availability() == true) {
						ch = 1;
						dvds[i]->set_availability(false);
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
			cin >> s;
			bool ch = 0;
			for (int i = 0; i < bookCount; i++) {
				if (s == books[i]->get_title()) {
					if (books[i]->get_availability() == false) {
						ch = 1;
						books[i]->set_availability(true);
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
			cin >> s;
			bool ch = 0;
			for (int i = 0; i < magazineCount; i++) {
				if (s == magazines[i]->get_title()) {
					if (magazines[i]->get_availability() == false) {
						ch = 1;
						magazines[i]->set_availability(true);
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
			cin >> s;
			bool ch = 0;
			for (int i = 0; i < dvdCount; i++) {
				if (s == dvds[i]->get_title()) {
					if (dvds[i]->get_availability() == false) {
						ch = 1;
						dvds[i]->set_availability(true);
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
				if (bookCount == 0) {
					cout << "No books available" << endl;
				}
				else {
					cout << "Books in the library: " << endl;
					for (int i = 0; i < bookCount; i++) {
						books[i]->display();
						cout << "----------------------" << endl;
					}
				}
				break;
			case 2:
				if (magazineCount == 0) {
					cout << "No magazines available" << endl;
				}
				else {
					cout << "magazines in the library: " << endl;
					for (int i = 0; i < magazineCount; i++) {
						magazines[i]->display();
						cout << "----------------------" << endl;
					}
				}
				break;
			case 3:
				if (dvdCount == 0) {
					cout << "No DVDs available" << endl;
				}
				else {
					cout << "DVDs in the library: " << endl;
					for (int i = 0; i < dvdCount; i++) {
						dvds[i]->display();
						cout << "----------------------" << endl;
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
