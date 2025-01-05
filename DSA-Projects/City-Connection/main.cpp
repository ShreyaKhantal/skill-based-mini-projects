#include <iostream>
using namespace std;
struct node{
    int data;
    struct node* next;
};
bool isempty(node*& f){
    return (f == NULL);
}
void enqueue(node* &f, node* &r, int val){
    node* p = new struct node;
    p->data = val;
    p->next = NULL;
    if (isempty(f)){
        f = r = p;
    }else{
        r->next = p;
        r = p;
    }
}
node* dequeue(node* &f, node* &r){
    node* p = new struct node;
    if (isempty(f)){
        cout << "Empty Queue";
    }
    else if (f->next == NULL){
        p = f;
        f = r = NULL;
    }else{
        p = f;
        f = f->next;
    }
    return p;
}
struct graph{
    int** adjmat;
    int numver;
    string* ver;
};
graph* create(int n){//n is size of matrix
    graph* g = new graph;
    g->ver = new string[n];
    for (int i = 0; i < n; ++i){
        cout << "Enter node " << i + 1 << " name: ";
        cin >> g->ver[i];
    }

    g->numver = n;
    g->adjmat = new int*[n];

    for (int i = 0; i < n; ++i){
        g->adjmat[i] = new int[n];
        for (int j = 0; j < n; ++j){
            g->adjmat[i][j] = 0;
        }
    }
    return g;
}
void display(graph* g){
    cout << "  ";
    for (int i = 0; i < g->numver; ++i){
        cout << g->ver[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < g->numver; ++i){
        cout << g->ver[i] << " ";
        for (int j = 0; j < g->numver; ++j){
            cout << g->adjmat[i][j] << " ";
        }
        cout << endl;
    }
}
void edge_undirected(graph* g){
    int row, col;
    string source, destination;
    cout << "Enter source node: ";
    cin >> source;
    cout << "Enter destination node: ";
    cin >> destination;

    for (int i = 0; i < g->numver; ++i){// Find indices of source and destination cities
        if (g->ver[i] == source)
            row = i;
        if (g->ver[i] == destination)
            col = i;
    }
    if (row >= g->numver || col >= g->numver){
        cout << "Invalid Input";
    }
    else{
        g->adjmat[row][col] = 1;
        g->adjmat[col][row] = 1;
    }
}
graph* addvertex(graph* g, string nodename){

    graph* newmat = new graph;
    int newv = g->numver + 1;

    newmat->numver = newv;
    newmat->adjmat = new int*[newv];
    newmat->ver = new string[newv];

    for (int i = 0; i < newv; ++i){// creating a new graph 
        newmat->adjmat[i] = new int[newv];
        for (int j = 0; j < newv; ++j){
            newmat->adjmat[i][j] = 0;
        }
    }
    for (int i = 0; i < g->numver; ++i){// copying data of old graph
        for (int j = 0; j < g->numver; ++j){
            newmat->adjmat[i][j] = g->adjmat[i][j];
        }
    }
    for (int i = 0; i < g->numver; ++i){// copying data of old graph
        newmat->ver[i] = g->ver[i];
    }
    newmat->ver[g->numver] = nodename;

    return newmat;
}

void bfs(graph* g){
    node* qf = NULL;
    node* qr = NULL;

    bool* visited = new bool[g->numver];
    for (int i = 0; i < g->numver; i++){
        visited[i] = false;
    }
    int row, col;
    string source, destination;
    cout << "Enter node to begin: ";
    cin >> source;
    cout << "Enter node to reach: ";
    cin >> destination;

    // Find indices of source and destination cities
    for (int i = 0; i < g->numver; ++i){
        if (g->ver[i] == source)
            row = i;
        if (g->ver[i] == destination)
            col = i;
    }

    visited[row] = true;
    enqueue(qf, qr, row);

    while (!isempty(qf))
    {
        node* x = dequeue(qf, qr);
        for (int i = 0; i < g->numver; ++i)
        {
            if (g->adjmat[x->data][i] == 1 && visited[i] == false)
            {
                if (g->ver[i] == destination) {
                    cout <<  "Path exists\n" << endl;
                    return;
                }
                visited[i] = true;
                enqueue(qf, qr, i);
            }
        }
    }
    cout << "Path does not exist\n" << endl;
}

int main(){
    int ch;
    string k;
    graph* g = NULL;
    cout << "1-Create Map" << endl;
    cout << "2-Add Path" << endl;
    cout << "3-Add vertex" << endl;
    cout << "4-Display matrix" << endl;
    cout << "5-Check Connection" << endl;
    cout << "6-exit" << endl;
    do{
        cout << endl;
        cout << "Enter Choice: ";
        cin >> ch;
        switch (ch){
        case 1:
            int n;
            cout << "Enter number of vertices: ";
            cin >> n;
            g = create(n);
            break;
        case 2:
            edge_undirected(g);
            break;
        case 3:
            cout << "Enter new node name: ";
            cin >> k;
            g = addvertex(g, k);
            break;
        case 4:
            display(g);
            break;
        case 5:
            bfs(g);
            break;
        case 6:
            break;
        default:
            cout<<"Inavalid Choice!\n";
            break;
        }
    } while (ch != 6);
    return 0;
}