#include <iostream>
#include <list>

using namespace std;

class Node{
private:
    int node_num;
    list<Node*> adjacent_nodes;
    int color_value;
public:
    Node(int num){
        node_num = num;
    }

    void Set_Adjacent(Node* adjacent){
        adjacent_nodes.push_back(adjacent);
    }

    void Set_Colour(int color){
        color_value = color;
    }

    int Get_Colour(){
        return color_value;
    }

    void Check_Adjacent_Colour(int color){
        //for each ile listeyi kontrol et
    }
};

int main() {

}
