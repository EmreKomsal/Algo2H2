#include <iostream>
#include <vector>

using namespace std;
class Node{
private:
    int node_num;
    vector<Node*> adjacent_nodes;
   int color_value = 0;
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

    void Set_Colour(int color){
        color_value = color;
    }

    void Set_Colour(){
        int desired_colour = 1;
        bool isColorMatch = true;
        while(isColorMatch){
            isColorMatch = Check_Adjacents_Colours(desired_colour);
            if (!isColorMatch){
                color_value = desired_colour;
            }
            else{
                desired_colour++;
            }
        }
    }

    int Get_Colour(){
        return color_value;
    }

    bool Check_Adjacents_Colours(int color){
        for (int i = 0; i < adjacent_nodes.size(); i++) {
            if(color == adjacent_nodes[i]->color_value){
                return true;
            }
        }
        return false;
    }
};

int main() {

    Node node1(1);
    Node node2(2);
    Node node3(3);
    Node node4(4);
    Node node5(5);
    Node node6(6);
    Node node7(7);

    vector<Node*> nodelist;

    nodelist.push_back(&node1);
    nodelist.push_back(&node2);
    nodelist.push_back(&node3);
    nodelist.push_back(&node4);
    nodelist.push_back(&node5);
    nodelist.push_back(&node6);
    nodelist.push_back(&node7);


    node1.Set_Adjacent(&node2);
    node1.Set_Adjacent(&node4);
    node1.Set_Adjacent(&node5);

    node2.Set_Adjacent(&node1);
    node2.Set_Adjacent(&node3);
    node2.Set_Adjacent(&node4);

    node3.Set_Adjacent(&node2);
    node3.Set_Adjacent(&node4);
    node3.Set_Adjacent(&node7);

    node4.Set_Adjacent(&node1);
    node4.Set_Adjacent(&node2);
    node4.Set_Adjacent(&node3);
    node4.Set_Adjacent(&node5);
    node4.Set_Adjacent(&node6);

    node5.Set_Adjacent(&node1);
    node5.Set_Adjacent(&node4);
    node5.Set_Adjacent(&node6);

    node6.Set_Adjacent(&node3);
    node6.Set_Adjacent(&node4);
    node6.Set_Adjacent(&node5);
    node6.Set_Adjacent(&node7);

    node7.Set_Adjacent(&node3);
    node7.Set_Adjacent(&node6);

    for (int i = 0; i < nodelist.size(); i++) {
        nodelist[i]->Set_Colour();
    }

    int colour_count = 0;
    for (int i = 0; i < nodelist.size(); ++i) {
        nodelist[i]->Print_Node();
        if (colour_count < nodelist[i]->Get_Colour()){
            colour_count = nodelist[i]->Get_Colour();
        }
    }

    cout << endl <<"Number of different colour is: " << colour_count << endl;
}
