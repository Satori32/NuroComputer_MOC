#include <iostream>
#include <vector>
#include <memory>
#include <cstdint>

//i not have parameta data.LOLOLOLOLOLOLOL

enum class Ganble3{//丁半ばくち、丁＝Allow,半＝Denie、１、胴元？　２，プレイヤー？　３、ささやき？　４、観測者？
	Satou = 2,
	Yamazaki = 1,
	Yanoji = 3,
	Sanoji = 4,
	kuuhaku = 2,
};

enum class Spark {
	None=8,
	MiraNew=0,
	Tron=1,
	MiraOld=2,
	Oranos=4,
	SystenRequest=99,
};

struct Point
{
	std::intmax_t ID=0;
};

typedef std::shared_ptr<Point> SPoint;

struct NewroStats
{
	Spark S{};
	double Verocity = 0;
	double Time = 0;
};

struct Data
{
	SPoint Other=nullptr;
	NewroStats SparkPosi{};
	//NewroStats SparlNega{};
};

struct Node
{
	SPoint P = nullptr;
	std::vector<Data> Points;
};

struct System
{
	std::vector<Node> Nodes;
};

Node MakeNode() {
	Node N;

	N.P = std::make_shared<Point>();
	N.Points.push_back({ std::make_shared<Point>(),Stats::None });

	return N;

}
Node MakeNode(SPoint P,SPoint Other,Stats S) {
	Node N;

	N.P = P;
	N.Points.push_back({ Other,S});

	return N;

}

int main() {
	System S;

	S.Nodes.push_back(MakeNode());
}