#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

class Edge
{
public:
    int destinationVertexId, weight;
    Edge() {}
    Edge(int dest, int w)
    {
        destinationVertexId = dest;
        weight = w;
    }
    void SetEdgeValue(int dest, int w)
    {
        destinationVertexId = dest;
        weight = w;
    }

    void SetWeight(int w)
    {
        weight = w;
    }
    int getWeight() const { return weight; }
    int getDestinationVertexId() const
    {
        return destinationVertexId;
    }
};
class Vertex
{

public:
    int state_ID;
    string stat_NAME;
    list<Edge> edgeList;
    Vertex()
    {
        stat_NAME = "";
        state_ID = -1;
    }
    Vertex(int stateI, string name)
    {
        stat_NAME = name;
        state_ID = stateI;
    }
    int getID() const { return state_ID; }
    string getNAME() const { return stat_NAME; }
    void setID(int id) { state_ID = id; }
    void setNAME(string name) { stat_NAME = name; }
    list<Edge> getEdge() const { return edgeList; }

    void printEdge()
    {
        cout << " [";
        for (auto it = edgeList.begin(); it != edgeList.end(); it++)
        {
            cout << it->getDestinationVertexId() << " (" << it->getWeight() << ") ,";
        }
        cout << "]";
        cout << endl;
    }
    void edit(int id, int weight)
    {
        for (auto it = edgeList.begin(); it != edgeList.end(); it++)
        {
            if (it->getDestinationVertexId() == id)
                it->SetWeight(weight);
        }
    }
};
class Graph
{

public:
    vector<Vertex> Vertices;
    Graph(){};
    void addVertex(int state_Id, string name)
    {
        if (checkVertex(state_Id))
        {
            cout << "vertex already exist \n";
            return;
        }
        else
        {
            Vertex v1(state_Id, name);
            Vertices.push_back(v1);
            cout << "Vertex aded succefully\n";
        }
    }
    void addEdge(int fromVertex, int toVertex, int weight)
    {
        if (checkVertex(fromVertex) && checkVertex(toVertex))
        {
            if (!checkEdge(fromVertex, toVertex))
            {
                for (size_t i = 0; i < Vertices.size(); i++)
                {
                    if (Vertices.at(i).getID() == fromVertex)
                    {
                        Edge e(toVertex, weight);
                        Vertices.at(i).edgeList.push_back(e);
                    }
                    else if (Vertices.at(i).getID() == toVertex)
                    {
                        Edge e(fromVertex, weight);
                        Vertices.at(i).edgeList.push_back(e);
                    }
                }
            }
            else
                cout << "edge already exist\n";
        }
        else
            cout << "vertices doesnot exist\n";
    }
    bool checkVertex(int id)
    {
        for (size_t i = 0; i < Vertices.size(); i++)
        {
            if (Vertices.at(i).getID() == id)
                return true;
        }
        return false;
    }
    bool checkEdge(int fromID, int toID)
    {
        size_t i;
        for (i = 0; i < Vertices.size(); i++)
        {
            if (Vertices.at(i).getID() == fromID)
                break;
        }
        list<Edge> e;
        e = Vertices.at(i).getEdge();
        for (auto it = e.begin(); it != e.end(); it++)
        {
            if (it->getDestinationVertexId() == toID)
                return true;
        }
        return false;
    }
    void print()
    {
        cout << "THE GRAPH \n";
        for (size_t i = 0; i < Vertices.size(); i++)
        {
            Vertex v = Vertices.at(i);
            cout << v.getNAME() << "(" << v.getID() << ")"
                 << "-->";
            v.printEdge();
        }
    }

    void updateEdge(int fromVertex, int toVertex, int newWeight)
    {
        if (checkVertex(fromVertex) && checkVertex(toVertex))
        {
            if (checkEdge(fromVertex, toVertex))
            {
                for (size_t i = 0; i < Vertices.size(); i++)
                {
                    if (Vertices.at(i).getID() == fromVertex)
                    {
                        Vertices.at(i).edit(toVertex, newWeight);
                    }
                    else if (Vertices.at(i).getID() == toVertex)
                    {
                        Vertices.at(i).edit(fromVertex, newWeight);
                    }
                }
            }
            else
                cout << "edge does not exist\n";
        }
        else
            cout << "vertices doesnot exist\n";
    }

    void delteEdge(int fromVertex, int toVertex)
    {
        if (checkEdge(fromVertex, toVertex))
        {
            for (size_t i = 0; i < Vertices.size(); i++)
            {
                if (Vertices.at(i).getID() == fromVertex)
                {
                    for (auto it = Vertices.at(i).edgeList.begin(); it != Vertices.at(i).edgeList.end(); it++)
                    {
                        if (it->getDestinationVertexId() == toVertex)
                        {
                            Vertices.at(i).edgeList.erase(it);
                            break;
                        }
                    }
                }
                else if (Vertices.at(i).getID() == toVertex)
                {
                    for (auto it = Vertices.at(i).edgeList.begin(); it != Vertices.at(i).edgeList.end(); it++)
                    {
                        if (it->getDestinationVertexId() == fromVertex)
                            Vertices.at(i).edgeList.erase(it);
                        break;
                    }
                }
            }
            cout << "deletion done successfully\n";
        }
        else
            cout << "edge does not exist \n";
    }
    void deleteVertex(int id)
    {
        int vid;
        for (size_t i = 0; i < Vertices.size(); i++)
        {
            if (Vertices.at(i).getID() == id)
            {
                vid = i;
                break;
            }
        }
        for (auto it = Vertices.at(vid).edgeList.begin(); it != Vertices.at(vid).edgeList.end(); ++it)
        {
            delteEdge(it->getDestinationVertexId(), id);
        }
        Vertices.erase(Vertices.begin() + vid);
        cout << "vertex deleted successfully\n";
    }
    void updateVertex(int id, string name)
    {
        if (checkVertex(id))
        {
            for (size_t i = 0; i < Vertices.size(); i++)
            {
                if (Vertices.at(i).getID() == id)
                {
                    Vertices.at(i).setNAME(name);
                    cout << "Vertex updated  Successfully \n";
                    break;
                }
            }
        }
        else
            cout << "Vertex does not exist\n";
    }
};

int main()
{
    Graph g1;
    int id;
    string name;
    for (int i = 0; i < 4; i++)
    {
        cin >> name;
        g1.addVertex(i + 1, name);
    }
    g1.addEdge(1, 2, 400);
    g1.addEdge(1, 3, 700);
    g1.print();
    g1.deleteVertex(1);
    g1.print();

    return 0;
}
