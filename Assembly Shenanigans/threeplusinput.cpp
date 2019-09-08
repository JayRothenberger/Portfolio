//topological sorting by Jay Rothenberger (jr2fh) 12/3/18
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
 
//ok, it is straight up retarded to make a bunch of data structures for this
//we gonna use vectors because they are easy to write with
vector<string> node;
vector<vector<string>> adj;
 
int main(int argc, char *argv[]){
  string line;
  ifstream file(argv[1]);
  if(!file.is_open())
    cout << "fucking idiot didn't give the right file name" << endl;
  while(getline(file, line)){
   
    string first = "";
    string second = "";
    bool tf = true;
    for(int i = 0; i < line.length(); i++){
      if(tf){
    if(line[i] == 32){
      tf = false;
    }else{
      first += line[i];
    }
      }else{
    second += line[i];
      }
    }
 
   
    for(int i = 0; i < node.size(); i++){
      if(first != "0"){
    if(node[i] == first){
      for(int j = 0; j < adj[i].size(); j++){
        if(adj[i][j] == second || adj[i][j] == ""){
          adj[i][j] = second;
          cout << first << " " << second << " set in " << node[i] << endl;
          break;
        }
        if((j+1) == adj[i].size() && adj[i][j] != second){
          cout << first << " " << second << " pushed to " << node[i] << endl;
                                        adj[i].push_back(second);
        }
      }
    }
      if((i+1 == node.size()) && node[i] != first){
        cout << "added " << first << endl;
        node.push_back(first);
        vector<string> n;
        n.push_back(second);
        adj.push_back(n);
      }
      }
    }
    if(node.size() == 0){
      node.push_back(first);
      vector<string> n;
      n.push_back(second);
      adj.push_back(n);
    }
 
  }
 
      for(int i = 0; i < node.size(); i++){
    cout << node[i] << endl;
 
      }
      file.close();
 
}