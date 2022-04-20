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

    int GetID(){
        return node_num;
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

    int Get_Degree(){
        return adjacent_nodes.size();
    }

    bool isContain(Node* node){
        for (int i = 0; i < adjacent_nodes.size(); ++i) {
            if (adjacent_nodes[i] == node){
                return true;
            }
        }
        return false;
    }
};
vector<Node*> SortByDesc(vector<Node*> nodelist){
    for (int i = 1; i < nodelist.size(); ++i) {
        for (int j = 0; j < nodelist.size() - i; ++j) {
            if (nodelist[j]->Get_Degree() < nodelist[j + 1]->Get_Degree() ){
                Node* temp = nodelist[j];
                nodelist[j] = nodelist[j + 1];
                nodelist[j + 1] = temp;
            }
        }
    }
    return nodelist;
}

void ColorDegreeList(vector<Node*> degreelist){
    int current_color = 1;
    vector<Node*> coloredNodes;
    while(!degreelist.empty()){
        degreelist.front()->Set_Colour(current_color);
        coloredNodes.push_back(degreelist.front());
        degreelist.erase(degreelist.begin());
        for (int i = 0; i < degreelist.size(); ++i) {
            bool isContain = false;
            for (int j = 0; j < coloredNodes.size(); ++j) {
                if (degreelist[i]->isContain(coloredNodes[j])){
                    isContain = true;
                    break;
                }
            }
            if (!isContain){
                degreelist[i]->Set_Colour(current_color);
                coloredNodes.push_back(degreelist[i]);
                degreelist.erase(degreelist.begin() + i);
            }
        }
        cout << endl;
        for (int i = 0; i < coloredNodes.size(); ++i) {
            cout << coloredNodes[i]->GetID() << ", ";
        }
        coloredNodes.clear();
        current_color++;
    }
}

int main() {
#pragma region
    Node node1(1);
    Node node2(2);
    Node node3(3);
    Node node4(4);
    Node node5(5);
    Node node6(6);
    Node node7(7);
    Node node8(8);
    Node node9(9);
    Node node10(10);
    Node node11(11);
    Node node12(12);
    Node node13(13);
    Node node14(14);
    Node node15(15);
    Node node16(16);
    Node node17(17);
    Node node18(18);
    Node node19(19);
    Node node20(20);
    Node node21(21);
    Node node22(22);
    Node node23(23);
    Node node24(24);
    Node node25(25);
    Node node26(26);
    Node node27(27);
    Node node28(28);
    Node node29(29);
    Node node30(30);
    Node node31(31);
    Node node32(32);
    Node node33(33);
    Node node34(34);
    Node node35(35);



    vector<Node*> nodelist;

    nodelist.push_back(&node1);
    nodelist.push_back(&node2);
    nodelist.push_back(&node3);
    nodelist.push_back(&node4);
    nodelist.push_back(&node5);
    nodelist.push_back(&node6);
    nodelist.push_back(&node7);
    nodelist.push_back(&node8);
    nodelist.push_back(&node9);
    nodelist.push_back(&node10);
    nodelist.push_back(&node11);
    nodelist.push_back(&node12);
    nodelist.push_back(&node13);
    nodelist.push_back(&node14);
    nodelist.push_back(&node15);
    nodelist.push_back(&node16);
    nodelist.push_back(&node17);
    nodelist.push_back(&node18);
    nodelist.push_back(&node19);
    nodelist.push_back(&node20);
    nodelist.push_back(&node21);
    nodelist.push_back(&node22);
    nodelist.push_back(&node23);
    nodelist.push_back(&node24);
    nodelist.push_back(&node25);
    nodelist.push_back(&node26);
    nodelist.push_back(&node27);
    nodelist.push_back(&node28);
    nodelist.push_back(&node29);
    nodelist.push_back(&node30);
    nodelist.push_back(&node31);
    nodelist.push_back(&node32);
    nodelist.push_back(&node33);
    nodelist.push_back(&node34);
    nodelist.push_back(&node35);


    //2,7
    node1.Set_Adjacent(&node2);
    node1.Set_Adjacent(&node7);
    //1,3,6
    node2.Set_Adjacent(&node1);
    node2.Set_Adjacent(&node3);
    node2.Set_Adjacent(&node6);
    //2,4
    node3.Set_Adjacent(&node2);
    node3.Set_Adjacent(&node4);
    //3,5,11,12
    node4.Set_Adjacent(&node3);
    node4.Set_Adjacent(&node5);
    node4.Set_Adjacent(&node11);
    node4.Set_Adjacent(&node12);
    //4,6
    node5.Set_Adjacent(&node4);
    node5.Set_Adjacent(&node6);
    //2,5,7,10
    node6.Set_Adjacent(&node2);
    node6.Set_Adjacent(&node5);
    node6.Set_Adjacent(&node7);
    node6.Set_Adjacent(&node10);
    //1,6,7,8
    node7.Set_Adjacent(&node1);
    node7.Set_Adjacent(&node6);
    node7.Set_Adjacent(&node7);
    node7.Set_Adjacent(&node8);
    //7,9,21
    node8.Set_Adjacent(&node7);
    node8.Set_Adjacent(&node9);
    node8.Set_Adjacent(&node21);
    //7,8,10,20
    node9.Set_Adjacent(&node7);
    node9.Set_Adjacent(&node8);
    node9.Set_Adjacent(&node10);
    node9.Set_Adjacent(&node11);
    //9,11,18,20
    node10.Set_Adjacent(&node9);
    node10.Set_Adjacent(&node11);
    node10.Set_Adjacent(&node18);
    node10.Set_Adjacent(&node19);
    //4,10,12,17
    node11.Set_Adjacent(&node4);
    node11.Set_Adjacent(&node10);
    node11.Set_Adjacent(&node12);
    node11.Set_Adjacent(&node17);
    //4,11,13
    node12.Set_Adjacent(&node4);
    node12.Set_Adjacent(&node11);
    node12.Set_Adjacent(&node13);
    //12,14,16
    node13.Set_Adjacent(&node13);
    node13.Set_Adjacent(&node14);
    node13.Set_Adjacent(&node16);
    //13,15
    node14.Set_Adjacent(&node13);
    node14.Set_Adjacent(&node15);
    //14,16,27
    node15.Set_Adjacent(&node14);
    node15.Set_Adjacent(&node16);
    node15.Set_Adjacent(&node27);
    //15,17,27
    node16.Set_Adjacent(&node15);
    node16.Set_Adjacent(&node17);
    node16.Set_Adjacent(&node27);
    //16,18,25,26
    node17.Set_Adjacent(&node16);
    node17.Set_Adjacent(&node18);
    node17.Set_Adjacent(&node25);
    node17.Set_Adjacent(&node26);
    //10,17,19,32
    node18.Set_Adjacent(&node10);
    node18.Set_Adjacent(&node17);
    node18.Set_Adjacent(&node19);
    node18.Set_Adjacent(&node32);
    //18,23,24
    node19.Set_Adjacent(&node18);
    node19.Set_Adjacent(&node23);
    node19.Set_Adjacent(&node24);
    //9,21,22
    node20.Set_Adjacent(&node9);
    node20.Set_Adjacent(&node21);
    node20.Set_Adjacent(&node22);
    //8,21,22
    node21.Set_Adjacent(&node8);
    node21.Set_Adjacent(&node21);
    node21.Set_Adjacent(&node22);
    //20,21,23,34,35
    node22.Set_Adjacent(&node20);
    node22.Set_Adjacent(&node21);
    node22.Set_Adjacent(&node23);
    node22.Set_Adjacent(&node34);
    node22.Set_Adjacent(&node35);
    //19,22,24,33
    node23.Set_Adjacent(&node19);
    node23.Set_Adjacent(&node22);
    node23.Set_Adjacent(&node24);
    node23.Set_Adjacent(&node33);
    //19,23,32,33
    node24.Set_Adjacent(&node19);
    node24.Set_Adjacent(&node23);
    node24.Set_Adjacent(&node32);
    node24.Set_Adjacent(&node33);
    //17,26,30
    node25.Set_Adjacent(&node17);
    node25.Set_Adjacent(&node26);
    node25.Set_Adjacent(&node30);
    //17,25,27,30
    node26.Set_Adjacent(&node17);
    node26.Set_Adjacent(&node25);
    node26.Set_Adjacent(&node27);
    node26.Set_Adjacent(&node30);
    //15,16,26,28,30
    node27.Set_Adjacent(&node15);
    node27.Set_Adjacent(&node16);
    node27.Set_Adjacent(&node26);
    node27.Set_Adjacent(&node28);
    node27.Set_Adjacent(&node30);
    //27,29
    node28.Set_Adjacent(&node27);
    node28.Set_Adjacent(&node29);
    //28,30,31
    node29.Set_Adjacent(&node28);
    node29.Set_Adjacent(&node30);
    node29.Set_Adjacent(&node31);
    //25,26,27,29,31,32
    node30.Set_Adjacent(&node25);
    node30.Set_Adjacent(&node26);
    node30.Set_Adjacent(&node27);
    node30.Set_Adjacent(&node29);
    node30.Set_Adjacent(&node31);
    node30.Set_Adjacent(&node31);
    //29,30,32
    node31.Set_Adjacent(&node29);
    node31.Set_Adjacent(&node30);
    node31.Set_Adjacent(&node32);
    //18,24,30,31,33
    node32.Set_Adjacent(&node18);
    node32.Set_Adjacent(&node24);
    node32.Set_Adjacent(&node30);
    node32.Set_Adjacent(&node31);
    node32.Set_Adjacent(&node33);
    //23,24,32,34
    node33.Set_Adjacent(&node23);
    node33.Set_Adjacent(&node24);
    node33.Set_Adjacent(&node32);
    node33.Set_Adjacent(&node34);
    //22,33,35
    node34.Set_Adjacent(&node22);
    node34.Set_Adjacent(&node33);
    node34.Set_Adjacent(&node35);
    //22,34
    node35.Set_Adjacent(&node22);
    node35.Set_Adjacent(&node34);




#pragma endregion Initilazation

    vector<Node*> degreelist;

    degreelist = SortByDesc(nodelist);

    ColorDegreeList(degreelist);

    cout << endl;

    int colour_count = 0;
    for (int i = 0; i < nodelist.size(); ++i) {
        nodelist[i]->Print_Node();
        if (colour_count < nodelist[i]->Get_Colour()){
            colour_count = nodelist[i]->Get_Colour();
        }
    }

    cout << endl <<"Number of different colour is: " << colour_count << endl;
}
