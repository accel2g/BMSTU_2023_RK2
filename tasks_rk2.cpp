#include "tasks_rk2.h"

int Node::countNodes = 0;

Node::Node(){
  parent = nullptr;
  name = -1;
}

Node::Node(int nameNode){
  parent = nullptr;
  name = nameNode;
  ++countNodes;
}

Node::~Node(){
  --countNodes;
  for(auto child : listChilds){
    delete child;
  }
}

Graph::Graph(){
  head = nullptr;
}

Graph::Graph(int countNodes){
  head = nullptr;
  buildTreeBFS(countNodes);
}

Graph::~Graph(){
  delete head;
}

int Graph::buildTreeBFS(int countNodes){
  if(head != nullptr){
    delete head;
  }
  head = new Node(0);
  std::list<Node*> currentLevel;
  std::list<Node*> nextLevel;
  currentLevel.push_back(head);
  int name = 1;
  int remainingNodes = countNodes - 1;
  while(remainingNodes > 0){
    for(auto node : currentLevel){
      for(int i = 0; i < countNodes; ++i){
        if(remainingNodes == 0){
          break;
        }
        --remainingNodes;
        auto child = new Node(name++);
        child->parent = node;
        node->listChilds.push_back(child);
        nextLevel.push_back(child);
      }
    }
    currentLevel = nextLevel;
    nextLevel.clear();
    --countNodes;
  }
  return Node::countNodes;
}

int Graph::buildTreeDFS(int countNodes){
  if(head != nullptr){
    delete head;
  }
  head = new Node(0);
  int name = 1;
  int remainingNodes = countNodes - 1;
  std::list<Node*> stack;
  stack.push_back(head);
  while(!stack.empty() && remainingNodes > 0){
    auto node = stack.back();
    if(node->listChilds.size() < countNodes){
      auto child = new Node(name++);
      child->parent = node;
      node->listChilds.push_back(child);
      stack.push_back(child);
      --remainingNodes;
    }
    else{
      stack.pop_back();
    }
  }
  return Node::countNodes;
}

void Graph::BFS(){
  std::ofstream out("bfs_res.txt");
  std::list<Node*> currentLevel;
  std::list<Node*> nextLevel;
  currentLevel.push_back(head);
  while(!currentLevel.empty()){
    for(auto node : currentLevel){
      out << node->name << "{";
      for(auto child : node->listChilds){
        out << child->name << ",";
        nextLevel.push_back(child);
      }
      out << "}";
    }
    out << std::endl;
    currentLevel = nextLevel;
    nextLevel.clear();
  }
  out.close();
}

void Graph::DFS(){
  std::ofstream out("dfs_res.txt");
  printTreeDFS(out, head);
  out.close();
}

void Graph::printTreeDFS(std::ofstream& out, Node* node){
  out << node->name << "{";
  for(auto child : node->listChilds){
    printTreeDFS(out, child);
  }
  out << "}";
}

std::pair<bool, std::list<int>>
Graph::searchDFS(int nameNode){
  auto node = searchDFS(head, nameNode);
  if(node != nullptr){
    std::pair<bool, std::list<int>> result(true, std::list<int>());
    result.second.push_front(node->name);
    while(node->parent != nullptr){
      node = node->parent;
      result.second.push_front(node->name);
    }
    return result;
  }
  else{
    return std::make_pair(false, std::list<int>());
  }
}

Node* Graph::searchDFS(Node* node, int nameNode){
  if(node->name == nameNode){
    return node;
  }
  for(auto child : node->listChilds){
    auto resultNode = searchDFS(child, nameNode);
    if(resultNode != nullptr){
      return resultNode;
    }
  }
  return nullptr;
}

std::pair<bool, std::list<int>>
Graph::searchBFS(int nameNode){
  std::list<Node*> currentLevel;
  std::list<Node*> nextLevel;
  currentLevel.push_back(head);
  while(!currentLevel.empty()){
    for(auto node : currentLevel){
      if(node->name == nameNode){
        std::pair<bool, std::list<int>>
        result(true,std::list<int>());
        result.second.push_front(node->name);
        while(node->parent != nullptr){
          node = node->parent;
          result.second.push_front(node->name);
        }
        return result;
      }
      for(auto child : node->listChilds){
        nextLevel.push_back(child);
      }
    }
    currentLevel = nextLevel;
    nextLevel.clear();
  }
  return std::make_pair(false, std::list<int>());
}