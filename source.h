#include <iostream>
#include <queue> // очередь
#include <stack> // стек
#include <string>
#include <unistd.h>
#include <list>
using namespace std;
struct Edge {
	int begin;
	int end;
};

class memory{

	private:

	int ** mas;

	string path;

	public:

	void setMas(int ** mas);

	void setPath(string path);

	int ** getMas();

	string getPath();

};

string search(int** mas, int countVert, int beginVert, int endVert, list <memory> & mem);

bool isBadVertex(int vertex, int countVert);

list <memory> getList();
