#include "source.h"

void memory::setMas(int ** mas){
	this->mas=mas;
}

void memory::setPath(string path){
	this->path=path;
}

int** memory::getMas(){
	return this->mas;
}

string memory::getPath(){
	return this->path;
}

bool isBadVertex(int vertex, int countVert) {
	if (vertex > countVert || vertex < 1) {
		return true;
	}
	return false;
}

bool isNumber(int a){
	if(sizeof(a)!=sizeof(int)){
		return false;
	}
	return true;
}

bool isNumber(char a){
	if(sizeof(a)!=sizeof(int)){
		return false;
	}
	return true;
}

bool isNumber(char * a){
	if(sizeof(a)!=sizeof(int)){
		return false;
	}
	return true;
}

bool isNumber(std::string a){
	if(sizeof(a)!=sizeof(int)){
		return false;
	}
	return true;
}

bool isNumber(float a){
	if(sizeof(a)!=sizeof(int)){
		return false;
	}
	return true;
}

bool isNumber(double a){
	if(sizeof(a)!=sizeof(int)){
		return false;
	}
	return true;
}

string search(int** mas, int countVert, int beginVert, int endVert, list <memory> & mem){
	endVert--;
	queue<int> Queue;
	stack<Edge> Edges;
	Edge e;
	int* nodes = new int[countVert]; // ������� �����
	for (int i = 0; i < countVert; i++) // ������� ��� ������� ����� 0
		nodes[i] = 0;
	Queue.push(beginVert - 1); // �������� � ������� ������ �������
	while (!Queue.empty())
	{
		int node = Queue.front(); // ��������� �������
		Queue.pop();
		nodes[node] = 2; // �������� �� ��� ����������
		for (int j = 0; j < countVert; j++)
		{
			if (mas[node][j] == 1 && nodes[j] == 0)
			{ // ���� ������� ������� � �� ����������
				Queue.push(j); // ��������� �� � �������
				nodes[j] = 1; // �������� ������� ��� ������������
				e.begin = node; e.end = j;
				Edges.push(e);
				if (node == endVert) break;
			}
		}
		//cout << node + 1 << endl; // ������� ����� �������
	}
	bool flag = false;
	string p;
	while (!Edges.empty()) {
		e = Edges.top();
		Edges.pop();
		if (e.end == endVert) {
			if (flag == false) {
				//cout << "���� �� ������� " << beginVert << " �� ������� " << endVert + 1 << ":" << endl;
				//cout << endVert + 1;
				p = to_string(endVert + 1);
				flag = true;
			}
			endVert = e.begin;
			p += " <- ";
			p += to_string(endVert + 1);
			//cout << " <- " << endVert + 1;
		}
	}
	if (flag == false) {
		//cout << "���� �� ������� " << beginVert << " �� ������� " << endVert + 1 << " �� ������." << endl;
		p = "Path from " + to_string(beginVert) + " to " + to_string((endVert + 1)) + " not found.";
	}
	string path = p;
	memory cur;
	cur.setMas(mas);
	cur.setPath(p);
	mem.push_back(cur);
	return p;
}
