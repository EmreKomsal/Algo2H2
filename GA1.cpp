#include <iostream>
#include <vector>

using namespace std;
class Color{
public:
    int color_id;

    Color(int id){
        color_id = id;
    }
};
class Node{
private:
    int node_num;
    vector<Node*> adjacent_nodes;
    Color* color_value;
public:
    Node(int num){
        node_num = num;
    }

    void Set_Adjacent(Node* adjacent){
        adjacent_nodes.push_back(adjacent);
    }

    void Print_Adjacent(){
        cout << endl;
        for (int i = 0; i < adjacent_nodes.size(); i++) {
            adjacent_nodes[i]->Print_Node();
        }
    }

    void Print_Node(){
        cout << node_num << ", " << color_value << endl;
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
    Node node1(1);
    Node node2(2);
    Node node3(3);
    Node node4(4);

    Color c1(1);
    Color c2(2);
    Color c3(3);
    Color c4(4);
    Color c5(5);

    node1.Set_Adjacent(&node2);
    node1.Set_Adjacent(&node3);
    node1.Set_Adjacent(&node4);

    node1.Set_Colour(&c1);
    node2.Set_Colour(&c2);
    node3.Set_Colour(&c3);
    node4.Set_Colour(&c4);

    node1.Print_Adjacent();
}
