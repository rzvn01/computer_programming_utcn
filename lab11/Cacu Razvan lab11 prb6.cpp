/*Cacu Razvan lab11 prb6
* Define a class called Record that stores the data related to a melody (artist, title, duration). An
abstract class (Playlist) contains as private attribute a pointer to an array of records. The
pointer is initialized in the constructor by a memory allocation process (the number of records
is defined by the user). The class contains accessor and mutator methods for each of a record’s
fields and an abstract method (pure virtual) that sorts the records array according to a criteria
coded in the received parameter (1=sorting by title, 2=sorting by artist, 3=sorting by
duration). The abstract method is implemented inside another class (PlaylistImplementation)
that inherits the Playlist class.
In the main( ) function, instantiate the PlaylistImplementation class and initialize and use all
the related data and methods*/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;
int artist_sort(const void* a, const void* b);
int title_sort(const void* a, const void* b);
int duration_sort(const void* a, const void* b);

class Record {
	char artist[20], title[20];
	int duration;
public:
	Record() {

		strcpy(artist, "No artist !");
		strcpy(title, "No title !");
		duration = 0;
	}
	Record(char* art, char* tit, int dur) {

		strcpy(artist, art);
		strcpy(title, tit);
		duration = dur;
	}
	void setArtist(char* aux) {
		strcpy(artist, aux);
	}
	char* getArtist() {
		return artist;
	}
	void setTitle(char* aux) {
		strcpy(title, aux);
	}
	char* getTitle() {
		return title;
	}
	void setDuration(int aux) {
		duration = aux;
	}
	int getDuration() {
		return duration;
	}
	~Record() {
		if (artist != NULL)
			delete[]artist;
		if (title != NULL)
			delete[]title;
	}
};

class Playlist {
	Record* arr;
public:
	char* getTitle(int i) { return arr[i].getTitle(); }
	char* getArtist(int i) { return arr[i].getArtist(); }
	int getDuration(int i) { return arr[i].getDuration(); }

	void setTitle(char* tit, int i) { arr[i].setTitle(tit); }
	void setArtist(char* art, int i) { arr[i].setArtist(art); }
	void setDuration(int dur, int i) { arr[i].setDuration(dur); }
	void setArr_dimension(int x) {
		arr = new(nothrow)Record[x];
	}
	Record* getArr() { return arr; }
	virtual Record* sort(int) = 0;
};
class PlaylistImplementation :public Playlist {
	int type, x;
public:
	PlaylistImplementation(int a = 1) {
		setArr_dimension(a);
		x = a;
	}
	virtual Record* sort(int)override {

		Record* str = getArr();
		if (type == 1)
			qsort(str, x, sizeof(Record), artist_sort);
		else if (type == 2)
			qsort(str, x, sizeof(Record), title_sort);
		else
			qsort(str, x, sizeof(Record), duration_sort);
		return str;
	}

};

int main() {
	int number;
	cout << "\n Enter the number of records : ";
	cin >> number;
	PlaylistImplementation t(number);
	char str[20];
	int dur;
	for (int i{}; i < number; i++) {
		getchar();
		cout << "\nEnter the artist : ";
		cin.getline(str, 20);
		t.setArtist(str, i);
		cout << "\nEnter the title:";
		cin.getline(str, 20);
		t.setTitle(str, i);
		cout << "\nEnter the duration of the song : ";
		cin >> dur;
		t.setDuration(dur, i);

	}
	int choice = 1;

		cout << "\nSort type ? (1-artist ,2-title,3-duration) : ";
		cin >> choice;
		while (choice != 1 && choice != 2 && choice != 3) {
			cout << "\nSort type ? (1-artist ,2-title,3-duration) : ";
			cin >> choice;
	   }
	
	Record* arr = t.sort(choice);
	for (int i{}; i < number; i++) {
		cout << "\nThe artist : " << arr[i].getArtist();
		cout << "\nThe title:" << arr[i].getTitle();
		cout << "\nEnter the duration of the song : " << arr[i].getDuration();
	}
	
}
int duration_sort(const void* a, const void* b) {
	Record* x = (Record*)a;
	Record* y = (Record*)b;
	int t = x->getDuration();
	int p = y->getDuration();
	if (t > p)
		return t - p;
	else
		return p - t;
}
int artist_sort(const void* a, const void* b) {
	Record* x = (Record*)a;
	Record* y = (Record*)b;
	char* t = x->getArtist();
	char* p = y->getArtist();
	return strcmp(t, p);
}
int title_sort(const void* a, const void* b) {
	Record* x = (Record*)a;
	Record* y = (Record*)b;
	char* t = x->getTitle();
	char* p = y->getTitle();
	return strcmp(t, p);
}