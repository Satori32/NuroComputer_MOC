#include <iostream>
#include <vector>
#include <memory>
#include <cstdint>

//i not have parameta data.LOLOLOLOLOLOLOL


enum class Stats {
	NegaSpark=-1,
	NegaNone =8,
	None=0,
	Spark,
};

struct Point
{
	std::intmax_t ID=0;
};

typedef std::shared_ptr<Point> SPoint;

struct Data
{
	SPoint Other=nullptr;
	Stats S;
	double Velocity = 0;
	double Time = 0;
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