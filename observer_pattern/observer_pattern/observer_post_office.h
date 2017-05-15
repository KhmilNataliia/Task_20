
#include <string>
#include <vector>

using namespace std;

class post_office
{
	vector<class observer*> readers;
	string magazine;
public:
	void attach(observer* readr){ readers.push_back(readr); }
	void set_mag(string m)
	{
		magazine = m;
		notify();
	}
	string get_mag() { return magazine; }
	void notify();
};


class observer
{
	post_office* office;
	string name;
	vector<string> received_pubs;
public:
	observer(post_office* p, string n)
	{
		office = p;
		name = n;
		office->attach(this);
	}

	virtual void update() = 0;
	void add_pub(string pub) { received_pubs.push_back(pub); }
	string get_name() { return name; }
	post_office*  get_post() { return office; }
	vector<string> get_pubs(){ return received_pubs; }
};

void post_office::notify()
{
	for (int i = 0; i < readers.size(); i++)
		readers[i]->update();
}

class reader :public observer
{
public:
	reader(post_office* p, string n) :observer(p, n){};
	void update()
	{
		string rec = get_post()->get_mag();
		add_pub(rec);
	}
};









