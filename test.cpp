#include "source.h"
#include <gtest/gtest.h>

TEST(oldTests, normGraph3){
	int** mas;
		mas = new int*[3];
		for (int i = 0; i < 3; i++)
			mas[i] = new int[3];
		mas[0][0] = 0;
		mas[0][1] = 1;
		mas[0][2] = 0;

		mas[1][0] = 1;
		mas[1][1] = 0;
		mas[1][2] = 1;

		mas[2][0] = 0;
		mas[2][1] = 1;
		mas[2][2] = 0;

		string expect = "3 <- 2 <- 1";
		list <memory> mem;
	ASSERT_EQ(expect, search(mas, 3, 1, 3, mem));
}

TEST(oldTests, normGraph5){
	int** mas;
		mas = new int*[5];
		for (int i = 0; i < 5; i++)
			mas[i] = new int[5];
		mas[0][0] = 0;
		mas[0][1] = 1;
		mas[0][2] = 1;
		mas[0][3] = 0;
		mas[0][4] = 0;

		mas[1][0] = 1;
		mas[1][1] = 0;
		mas[1][2] = 1;
		mas[1][3] = 0;
		mas[1][4] = 1;

		mas[2][0] = 1;
		mas[2][1] = 1;
		mas[2][2] = 0;
		mas[2][3] = 1;
		mas[2][4] = 0;

		mas[3][0] = 0;
		mas[3][1] = 0;
		mas[3][2] = 1;
		mas[3][3] = 0;
		mas[3][4] = 0;

		mas[4][0] = 0;
		mas[4][1] = 1;
		mas[4][2] = 0;
		mas[4][3] = 0;
		mas[4][4] = 0;

		string expect = "5 <- 2 <- 3 <- 4";
		list <memory> mem;
		ASSERT_EQ(expect, search(mas, 5, 4, 5, mem));
}

TEST(oldTests, Graph_with_edges_less_then_vertices){
	int** mas;
		mas = new int*[6];
		for (int i = 0; i < 6; i++)
			mas[i] = new int[6];
		mas[0][0] = 0;
		mas[0][1] = 1;
		mas[0][2] = 1;
		mas[0][3] = 0;
		mas[0][4] = 0;
		mas[0][5] = 0;

		mas[1][0] = 1;
		mas[1][1] = 0;
		mas[1][2] = 1;
		mas[1][3] = 0;
		mas[1][4] = 1;
		mas[1][5] = 0;

		mas[2][0] = 1;
		mas[2][1] = 1;
		mas[2][2] = 0;
		mas[2][3] = 1;
		mas[2][4] = 0;
		mas[2][5] = 0;

		mas[3][0] = 0;
		mas[3][1] = 0;
		mas[3][2] = 1;
		mas[3][3] = 0;
		mas[3][4] = 0;
		mas[3][5] = 0;

		mas[4][0] = 0;
		mas[4][1] = 1;
		mas[4][2] = 0;
		mas[4][3] = 0;
		mas[4][4] = 0;
		mas[4][5] = 0;

		mas[5][0] = 0;
		mas[5][1] = 0;
		mas[5][2] = 0;
		mas[5][3] = 0;
		mas[5][4] = 0;
		mas[5][5] = 0;

		string expect = "Path from 4 to 6 not found.";

		list <memory> mem;
		ASSERT_EQ(expect, search(mas, 6, 4, 6, mem));
}

TEST(oldTests, CyclicGraph){
	int** mas;
		mas = new int*[3];
		for (int i = 0; i < 3; i++)
			mas[i] = new int[3];
		mas[0][0] = 0;
		mas[0][1] = 1;
		mas[0][2] = 0;

		mas[1][0] = 1;
		mas[1][1] = 0;
		mas[1][2] = 1;

		mas[2][0] = 0;
		mas[2][1] = 1;
		mas[2][2] = 1;

		string expect = "3 <- 2 <- 1";

		list <memory> mem;
		ASSERT_EQ(expect, search(mas, 3, 1, 3, mem));
}

TEST(oldTests, Graph1231){
	int** mas;
		mas = new int*[3];
		for (int i = 0; i < 3; i++)
			mas[i] = new int[3];
		mas[0][0] = 0;
		mas[0][1] = 1;
		mas[0][2] = 1;

		mas[1][0] = 1;
		mas[1][1] = 0;
		mas[1][2] = 1;

		mas[2][0] = 1;
		mas[2][1] = 1;
		mas[2][2] = 0;

		string expect = "3 <- 1";

		list <memory> mem;
		ASSERT_EQ(expect, search(mas, 3, 1, 3, mem));
}

TEST(oldTests, multigraph){
	int** mas;
		mas = new int*[4];
		for (int i = 0; i < 4; i++)
			mas[i] = new int[4];
		mas[0][0] = 0;
		mas[0][1] = 1;
		mas[0][2] = 1;
		mas[0][3] = 0;

		mas[1][0] = 1;
		mas[1][1] = 0;
		mas[1][2] = 1;
		mas[1][3] = 1;

		mas[2][0] = 1;
		mas[2][1] = 1;
		mas[2][2] = 0;
		mas[2][3] = 1;

		mas[3][0] = 0;
		mas[3][1] = 1;
		mas[3][2] = 1;
		mas[3][3] = 0;

		string expect = "4 <- 2 <- 1";

		list <memory> mem;
		ASSERT_EQ(expect, search(mas, 4, 1, 4, mem));
}

TEST(oldTests, emptygraph){
	int** mas;
		mas = new int*[4];
		for (int i = 0; i < 4; i++)
			mas[i] = new int[4];
		mas[0][0] = 0;
		mas[0][1] = 0;
		mas[0][2] = 0;
		mas[0][3] = 0;

		mas[1][0] = 0;
		mas[1][1] = 0;
		mas[1][2] = 0;
		mas[1][3] = 0;

		mas[2][0] = 0;
		mas[2][1] = 0;
		mas[2][2] = 0;
		mas[2][3] = 0;

		mas[3][0] = 0;
		mas[3][1] = 0;
		mas[3][2] = 0;
		mas[3][3] = 0;

		string expect = "Path from 1 to 4 not found.";

		list <memory> mem;
		ASSERT_EQ(expect, search(mas, 4, 1, 4, mem));
}

TEST(oldTests, IncoherentGraph){
	int** mas;
		mas = new int*[5];
		for (int i = 0; i < 5; i++)
			mas[i] = new int[5];
		mas[0][0] = 0;
		mas[0][1] = 1;
		mas[0][2] = 0;
		mas[0][3] = 0;
		mas[0][4] = 0;

		mas[1][0] = 1;
		mas[1][1] = 0;
		mas[1][2] = 1;
		mas[1][3] = 0;
		mas[1][4] = 0;

		mas[2][0] = 0;
		mas[2][1] = 1;
		mas[2][2] = 0;
		mas[2][3] = 0;
		mas[2][4] = 0;

		mas[3][0] = 0;
		mas[3][1] = 0;
		mas[3][2] = 0;
		mas[3][3] = 0;
		mas[3][4] = 1;

		mas[4][0] = 0;
		mas[4][1] = 0;
		mas[4][2] = 0;
		mas[4][3] = 1;
		mas[4][4] = 0;

		string expect = "Path from 1 to 5 not found.";

		list <memory> mem;
		ASSERT_EQ(expect, search(mas, 5, 1, 5, mem));
}

TEST(newTests, equalLists){
	int** mas;
		mas = new int*[3];
		for (int i = 0; i < 3; i++)
			mas[i] = new int[3];
		mas[0][0] = 0;
		mas[0][1] = 1;
		mas[0][2] = 0;

		mas[1][0] = 1;
		mas[1][1] = 0;
		mas[1][2] = 1;

		mas[2][0] = 0;
		mas[2][1] = 1;
		mas[2][2] = 0;

		string expect = "3 <- 2 <- 1";
		list <memory> mem;
		list <memory> exp;
		memory tested;
		tested.setMas(mas);
		search(mas, 3, 1, 3, mem);
		tested.setPath(expect);
		exp.push_back(tested);
		tested.setMas(mas);
		search(mas, 3, 1, 2, mem);
		expect = "2 <- 1";
		tested.setPath(expect);
		exp.push_back(tested);
		bool eq=true;
		if(exp.size() == mem.size()){
			while(!mem.empty() || !exp.empty()){
				if(exp.front().getMas()==mem.front().getMas() && exp.front().getPath()==mem.front().getPath())
					;
				else
					eq=false;
				mem.pop_front();
				exp.pop_front();
			}
		}
		ASSERT_EQ(true, eq);
}

TEST(newTests, noEmptyList){
	int** mas;
		mas = new int*[3];
		for (int i = 0; i < 3; i++)
			mas[i] = new int[3];
		mas[0][0] = 0;
		mas[0][1] = 1;
		mas[0][2] = 0;

		mas[1][0] = 1;
		mas[1][1] = 0;
		mas[1][2] = 1;

		mas[2][0] = 0;
		mas[2][1] = 1;
		mas[2][2] = 0;

		list <memory> mem;
		search(mas, 3, 1, 3, mem);
		search(mas, 3, 1, 2, mem);
		bool null = false;
		if(mem.size()==0){
			null=true;
		}
		ASSERT_EQ(false, null);
}

int main(int argc, char *argv[]){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
