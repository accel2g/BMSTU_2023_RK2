#include <iostream>
#include <fstream>
#include <list>

#ifndef TASKS_RK2_H
#define TASKS_RK2_H

struct Node{
  Node();
  Node(int nameNode);
  ~Node();
  Node* parent;
  std::list<Node*> listChilds;
  int name;
  static int countNodes;
};

class Graph{
  private:
      Node* head;
      void printTreeDFS(std::ofstream& out, Node* node);
      Node* searchDFS(Node* node, int nameNode);
      Node* searchBFS(Node* node, int nameNode);
  public:
      Graph();
      Graph(int countNodes);
      ~Graph();
      int buildTreeBFS(int countNodes);
      int buildTreeDFS(int countNodes);
      void BFS();
      void DFS();
      std::pair<bool, std::list<int>> searchDFS(int nameNode);
      std::pair<bool, std::list<int>> searchBFS(int nameNode);
};

#endif