#include "tasks_rk2.h"

void task1(){
  Graph gr;
  gr.buildTreeBFS(3);
  gr.BFS();
}

void task2(){
  Graph gr;
  gr.buildTreeDFS(3);
  gr.DFS();
}

void task3(){
  Graph gr;
  gr.buildTreeBFS(3);
  auto searchResultDFS = gr.searchDFS(5);
  std::cout << "Result DFS search: ";
  if(searchResultDFS.first){
    for(auto nodeName : searchResultDFS.second){
      std::cout << nodeName << " ";
    }
  }
  else{
    std::cout << "Node not found";
  }
  std::cout << std::endl;
  auto searchResultBFS = gr.searchBFS(5);
  std::cout << "Result BFS search:";
  if(searchResultBFS.first){
    for(auto nodeName : searchResultBFS.second){
      std::cout << nodeName << " ";
    }
  }
  else{
    std::cout << "Node not found";
  }
  std::cout << std::endl;
}

int main(){
  task1();
  task2();
  task3();
  return 0;
}
