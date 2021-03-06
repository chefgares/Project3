#include <iostream>
#include <limits>

using namespace std;

struct adjNode{
    int index, year;
    adjNode* next;
};
struct graphEdge{
    int start, end;
};

class Graph{
    //insert a new node to adjacency list
    adjNode* insertListNode(int ind, adjNode* head){
        //initialize new node
        adjNode* newNode = new adjNode;
        //populate new node
        newNode->index = ind;

        newNode->next = head; //insert before head
        return newNode;
    }
    int V; //number of nodes
public:
    adjNode **head;   //adjacency list represented as an array of pointers
    //constructor
    Graph(graphEdge edges[], int E, int V){
        head = new adjNode*[V]();
        this->V = V;
        //initialize head pointer at each index
        for (int i = 0; i < V; ++i){
            head[i] = nullptr;
        }
        //construct the graph by adding all the edges
        for (unsigned i = 0; i < E; i++){
            int startVert = edges[i].start;
            int endVert = edges[i].end;

            //insert the edge
            adjNode* newNode = insertListNode(endVert, head[startVert]);

            head[startVert] = newNode;
        }
    }
    ~Graph(){
        for(int i = 0; i < V; i++){
            //delete[] head[i];
            //delete[] head;
        }
    }
};

int getLongestDegree(Graph G, int range){
    int longest = 0;
    for(int i = 0; i < range; i++){
        int count = 0;
        adjNode* ptr = G.head[i];
        while(ptr != nullptr){
            count++;
            ptr = ptr->next;
        }
        if(count > longest){
            longest = count;
        }
    }
    return longest;
}
/*
void displayAdjacencyList(adjNode* ptr, int vertex){
    cout << vertex;
    cout << ": ";
    while(ptr != nullptr){
        cout << ptr->index;
        cout << "->";
        ptr = ptr->next;
    }
    cout << "\n";
}
*/