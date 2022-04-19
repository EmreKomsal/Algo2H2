#include <iostream>
#include <list>

using namespace std;
class Color{
public:
    int color_id;
};
class Node{
private:
    int node_num;
    list<Node*> adjacent_nodes;
    Color* color_value;
public:
    Node(int num){
        node_num = num;
    }

    void Set_Adjacent(Node* adjacent){
        adjacent_nodes.push_back(adjacent);
    }

    void Set_Colour(Color* color){
        color_value = color;
    }

    Color* Get_Colour(){
        return color_value;
    }

    void Check_Adjacent_Colour(Color* color){
        //for each ile listeyi kontrol et
    }
};

int main() {

}
