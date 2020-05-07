//Noorain Baig
//Project 1 
//CSCI 2270/Data Structures
//Section 310

#include <iostream>
#include <fstream>
#include <sstream>
#include "Menu.hpp"
#include "Project1.hpp"
using namespace std;


vertex queue[100]; int n = 100; int top = - 1; int rear = - 1;
//I am declaring a vertex queue to use for breadth first search


LinkedList::LinkedList() { //initalization!
    head = NULL;
}


Graph::Graph() {
  head = NULL;
  // queueSize = 0;
  // maxQueue = 16;
}



Graph::Graph(string key, int index, int districtID, vertex * next, bool solved, bool visited, int distance, string previous) {
   this->key = key;
   this->index = index;
   this->districtID = districtID;
   this->next = next;
   this->solved = solved;
   this->distance = distance;
   this->previous = previous;
}

Graph::~Graph() {
  vertex * iterator = head; 

  if(iterator == NULL){
    return;
  }

  while(iterator != NULL){
     head = iterator->next;
     delete iterator;
     iterator = head;
 }
delete head;
}


vertex *  Graph::insertVertex(string name, int count) { 
  if(isitDigit(name) == true) { //I created a isitDigit() function (in Menu.hpp) to avoid reading in the number at the end of the first line
            vertex * new_vertex = new vertex;
            new_vertex->key = name; //create new vertex node and set values
            new_vertex->index = count; //set index 
            new_vertex->districtID = -1; //set these to -1 at first
            new_vertex->INFECT = "";
            new_vertex->next = NULL; 
            new_vertex->solved = false;
            new_vertex->visited = false;
            new_vertex->distance = 0;
            new_vertex->previous = "";
            //new_vertex->parent = NULL;
           
            vertex * node2; //this is modeled after my append function that i wrote for midterm 2

           
           if(head==NULL) 
           {
                head = new_vertex; //sets head
           }
           else
           {
                node2 = head; //if not, appends the new node 
                while(node2->next!=NULL)
                {
                     node2 = node2->next;
                }
                node2->next = new_vertex;
           }
  return new_vertex; 
  }
return NULL;
}

//IMPLEMENTATION OF BREADTH FIRST SEARCH USING AN ARRAY QUEUE

        //I tried for hours to get this to work but could not resolve all of the errors

// int Graph::isEmpty() {
//       if (head == NULL) return 0; // We are empty, 0 for success!
//     else return -1; 
//   }


// void Insert(vertex * vertex_node) {
//    if (rear == n - 1) {
//       cout << "Queue Overflow"<< endl;
//    }
  
//    else {
//       if (top == - 1)
//       top = 0;
//       cout<< "Insert the element in queue : " <<endl;
//       rear++;
//       queue[rear] = vertex_node;
//    }
// }

// void Delete() {
//    if (top == - 1 || top > rear) {
//       cout<<"Queue Underflow ";
//    return;
//    } else {
//       cout<<"Element deleted from queue is : "<< queue[top] <<endl;
//       top++;;
//    }
// }


// void Graph::ShortestUnweightedPath(string vertice1key, string vertice2key) {
//   vertex * first_city_name = FindKeyVertex(vertice1key);
//   vertex * second_city_name = FindKeyVertex(vertice2key);

// while(first_city_name != NULL){
//   if(first_city_name->districtID != second_city_name->districtID) {
//     cout << "No safe path between cities." << "\n";
//     break;

//   }
//   else {
//     first_city_name->visited = true;
//     queue.Insert(first_city_name);
//     while(!queue.IsEmpty()){
//       vertex * n = queue.Delete();

//       while(n != NULL) {
//         adjVertex * m = n->head; 
//            if(m == NULL){
//             return;
//             }
//         while (m != NULL)
//         {
//             if(m->v->visited == false) {
//               m->v->visted = true;
//               cout << m->v->key << endl;
//               queue.Insert(m->v);
//             }
//               if(m == NULL) {
//                 return;
//               }
//          m = m->next;
//         }

//       n = n->next;
//   }
//     }

//   }
// }
// }


void Graph::print() {  //modeled after the print function for assignment 4
  vertex * current; 
  current = head;

  if(current == NULL){
    return;
  }

  while(current != NULL){

    cout << current->districtID << " ";
    cout << current->key << ": ";
    cout << current->INFECT << "\n";

      adjVertex * m = current->head; 
       if(m == NULL){
        return;
        }

      while (m != NULL)
      {
        cout << m->v->key << "\n"; //goes through the linked list of the linked list
            if(m == NULL) {
              return;
            }
       m = m->next;
      }

      current = current->next;
 }
}

vertex * Graph::FindKeyVertex(string city_name) {  
    vertex * current;
    current = head;

  while (current != NULL) //this is using the same idea as print to traverse, but only goes through the vertices 
  {
    if(current->key == city_name) //if these values match, return the node
     return current;
    current = current->next;
  }
  return current;
}


void Graph::SetDistrictID(int count) {
  int n = 0;
  vertex * current; 
  current = head;

  if(current == NULL){
    return;
  }

  while(current != NULL){
    if(current->districtID == -1){   
    n++;  
              current->districtID = n;
            }

        adjVertex * m = current->head;
         if(m == NULL){
          return;
          }

        while (m != NULL)
        {
            if(m->v->districtID == -1) { 
                m->v->districtID = n;

               vertex * current2 = FindKeyVertex(m->v->key);
               adjVertex * traversal = current2->head;

               while(traversal != NULL) {
                      traversal->v->districtID = n;

                  traversal = traversal->next;
                 } 
            }
            m = m->next;
        }

        current = current->next;    
    }
  }


vertex * Graph::FindVertex(int value) {  //this will find the vertex according to the index value, which is set in the main
    vertex * current;
    current = head;

  while (current != NULL)
  {
    if(current->index == value) //if these values match, return the node
     return current;
    current = current->next;
  }
  return current;
}



void addintoArray(string name, string names_fun[]) { //this was going to be used in a search
  for(int i=0; i<16; i++){
    if(names_fun[i] == "") {
      names_fun[i] = name;
    }
  }
}

int Graph::Infection(int t) { //this is my code for infection
  vertex * current; 
  current = head;

  if(current == NULL){
    return -1;
  }

  while(current != NULL){
    if(current->INFECT== "S"){   //this will change the linked list values if they weren't changed yet
              current->INFECT = "I";
              t++; //i iterate t here
            }

        adjVertex * m = current->head;
         if(m == NULL){
          return -1;
          }

        while (m != NULL)
        {
            if(m->v->INFECT == "S") { //here I change the infection value of the connected nodes
                m->v->INFECT = "I";

               vertex * current2 = FindKeyVertex(m->v->key);
               adjVertex * traversal = current2->head;

               while(traversal != NULL) { //now I go through the connected nodes of the connected nodes
                      if(traversal->v->INFECT == "S") {
                        traversal->v->INFECT = "I";
                      }
                  traversal = traversal->next;
                
              } 

            }
            m = m->next;
        }

        current = current->next;    
    }
     return t;
}



void Graph::ReadMore(string infect, int count, int p){ //this function sets the infection values 
//i started using the new project 1 file a bit later, so I decided to create a new function instead of trying to adapt my insertvertex function
bool tea = true;

while(tea == true){
  while(p<count) {
    //cout << p;
    vertex * vertex_friend = FindVertex(p); //this finds the vertex according to the index
    if(vertex_friend == NULL){
      return;
    }
    //cout << vertex_friend->key;
    if(vertex_friend->INFECT == ""){ //it was initalized to this in the insert vertex function
        vertex_friend->INFECT = infect; //setting the value according to what I'm reading in in main
    }
    break;
  }
  break;
  }
}

  
//ATTTEMPT AT BREADTH FIRST SEARCH WITHOUT A QUEUE
void Graph::ShortestUnweightedPath(string vertice1key, string vertice2key) {
  vertex * first_city_name = FindKeyVertex(vertice1key);
  vertex * second_city_name = FindKeyVertex(vertice2key);

while(first_city_name != NULL){
  if(first_city_name->districtID != second_city_name->districtID) {
    cout << "No safe path between cities." << "\n";
    break;

  }
  else {
  vertex * current = first_city_name;
  cout << first_city_name->key << "--->";

  if(current == NULL){
    return;
  }

  while(current != NULL){
    if(current->previous == ""){   

              current->previous = first_city_name->key;        
            }

        adjVertex * m = current->head;
         if(m == NULL){
          return;
          }

        while (m != NULL)
        {

          if(m->v->key == vertice2key){
            cout << m->v->key << "--->";
                  exit(0);
                }


            if(m->v->previous == "") { 

              if(m->v->key != current->key) {
                  cout << m->v->key << "-->";
              }
               m->v->previous = first_city_name->key;

               vertex * current2 = FindKeyVertex(m->v->key);
               adjVertex * traversal = current2->head;

               while(traversal != NULL) {
                if(traversal->v->key != current->key) {
                       cout << traversal->v->key  << "----->" << "\n";
              }
                    if(traversal->v->key == second_city_name->key) {
                      cout << traversal->v->key << "--->"; 
                      exit(0);
                    }
                      traversal->v->previous = m->v->key;

                  traversal = traversal->next;
                 } 
            }
            m = m->next;
        }
        break;   
    }
  }
}
}


bool Graph::isSolved(vertex * input_vertex, vertex * solved[], int size){ //this is a helper function for dijkstra's algorithm
  for(int i=0; i<size; i++){
    if(solved[i] == NULL) {
      return false;
    }
    else if(input_vertex->key == solved[i]->key){ //testing to see if the vertex is in the array
      return true;
    }
  }
return false;
}

void Graph::addElement(vertex * solved[], vertex * addin) { //here I am adding values into the array
  for(int i = 0; i<16; i++) {
    if(solved[i] == NULL){
      solved[i] = addin;
    }
  }
}



string Graph::DijkstrasAlgorithm(string start, string end, int count) {

vertex * start_node = FindKeyVertex(start); //here I am finding and setting vertices accoding to the string vertex names read in
vertex * end_node = FindKeyVertex(end);
start_node->solved = true; //setting the start node to solved
start_node->distance = 0;
vertex * solvedV;
int dist;


if(start_node->districtID != end_node->districtID){ 
  cout << "These cities are not in the same district." << "\n";
  return NULL;
}

vertex * solved[count];
for(int j = 1; j<count; j++){ //initalize all elements in the array to NULL 
  solved[j] = NULL;
}

solved[0] = start_node; //setting the first index of solved to the start node


vertex * current = FindKeyVertex(start); //I use this to set current, I do not want start node's value to change

  while(end_node->solved != true) { 

     if(current == NULL){
      return "";
    }

    int minDistance = 100000000; //setting this to a very large number
    solvedV = NULL; 

    while(current != NULL){
      if(current->districtID == start_node->districtID){
        cout << current->key << "--->"; //I wanted to print out what would be the start node
        for(int i=0; i<count; i++){
          vertex * s = solved[i];
          adjVertex * m = current->head; //traversing through connected linked list nodes
           if(m == NULL){
            return "";
            }

          while (m != NULL){
            if(isSolved(m->v, solved, count) != true) { //if it is NULL 
                dist = s->distance + m->weight; //set dist to the the distance
                if(dist < minDistance) { 
                  solvedV = m->v; //set the solvedV to the current linked lkist node
                  minDistance = dist; //reset the minDistance
                  s->key = previous; //set the previous
                }
              }
             m = m->next; //continue traversing 
          }
      
        solvedV->distance = minDistance;
        solvedV->previous = previous;
        solvedV->solved = true;
        addElement(solved, solvedV);
        //adds the solvedV to the array
        }
          current = current->next;
          for(int v = 0; v<count; v++){
            cout << solved[v]->key << "--->" << endl;
            if(solved[v]->key == solved[v+1]->key) {
              break;
            }
          }
          break;
}


}
      return end_node->key;
}


return "";
}


void Graph::ClearPrevious() { //this will clear the vertex names stored in previous
    vertex * current; 
    current = head;

  if(current == NULL){
    return;
  }

  while(current != NULL){

   current->previous = "";

      adjVertex * m = current->head; 
       if(m == NULL){
        return;
        }

      while (m != NULL)
      {
        m->v->previous = "";
            if(m == NULL) {
              return;
            }
       m = m->next;
      }

      current = current->next;
 }
}


void LinkedList::ReadAdjVertices(vertex * new_vertex, vertex * city_name, int weight) {  //this is also modeled after append function written for midterm 
    if(weight>0) { //if the weight is valid
      if(new_vertex != NULL){ 
        if(city_name != NULL) {
          adjVertex * newnode = new adjVertex; //create new adjVertex node and set its values
          adjVertex * node2;
           newnode->v= city_name; //sets v to the city name vertex
           newnode->weight = weight;
           newnode->next = NULL;
           
           if(new_vertex->head==NULL) //this is the append function that I wrote for the midterm 
           {
                new_vertex->head = newnode; //sets newnode as the head 
           }
           else
           {
                node2 = new_vertex->head;
                while(node2->next!=NULL)
                {
                     node2 = node2->next;
                }
                node2->next = newnode;
                node2->next->v = city_name;
                node2->next->weight = weight;
           }         
        }
    }
  }
}





int main(int argc, char* argv[]) {
    Graph g;
    LinkedList ll;
    ifstream myfile; 
    string names;
    string names2;
    string values;
    int count = 0;
    vertex * vertices;
    int h = 0;
    int b = 0;
    //int p = 0;
    //int r = 2;
    vertex adjVertex[15];  
    //the names array is hardcoded currently, sorry about that
    string names_array[15] = {"Atlanta","Boston","Boulder","Cheyenne","Chicago","Cleveland","Disneyland","Key West","Miami","New Orleans","New York","Portland","San Francisco","Seattle","Yakima"};
    int small_count = 0;
    string line = ""; 
    cout << "START HERE" << "\n";
        myfile.open(argv[1]);
          if(!myfile.is_open()) { //in case the file is invalid, this was a fix from Checkpoint 1
          cout << "Cannot open file. Please try again with a different file." << "\n";
          exit(0);
        }
        string first_line;
        getline(myfile, first_line);
        stringstream stream(first_line);
            while(getline(stream, names, ',')){
               if(names == "cities") continue;
                    vertex * vertices = g.insertVertex(names, count); //here I am setting the index values and keys and creating a linked list of vertices
                    count = count + 1; //this will iterate for each name read in, thus providing the number of cities
                }

             string word;
            while(getline(myfile, line)) { //vertices under here becomes cities instead of city names

                istringstream line_stream(line);
                line_stream.str() += ","; //adds comma at the end
                int super_count = 0;
                while(getline(line_stream, word, '\n')){ 


                     string line_array[count]; //create a new array for each line
                    string array_of_string[count];
                    string infections[count];
   
                        for (int i = 0; i < count; i++){
                            line_array[i] = word; //reads entire file into word
                        }
                   
                     int r = 1;
                        for(int t = 0; t < count; t++) {
                          //cout << line_array[t] << "\n";
                             split(line_array[t], ',', array_of_string, count); //splits the line in line_array by comma

                             for(int q=2; q < count+1; q++) { //starts at 2 so we only read in integer values
                                                              //count + 1 allows for b and h to iterate properly
                                       vertex * found_vertex = g.FindVertex(b); //for example, this will be atlanta until cityname->key = yamika is read in, then will switch to Boston
                                       vertex * city_name_vertex = g.FindKeyVertex(names_array[h]); //this will iterate through the names array and resets for each new found_vertex
                                     //cout << array_of_string[p];
                                      // cout << found_vertex->key << "\n";
                                      // cout << city_name_vertex->key << "\n";
                                       //cout << found_vertex->key << " : " << array_of_string[r] << "\n";
                                        ll.ReadAdjVertices(found_vertex, city_name_vertex, stoi(array_of_string[q])); 
                                        g.ReadMore(array_of_string[r], count, b); //this reads in the infection variables and sets them for the vertices

                                        if(q == count) {
                                          b++; //iterates b, we've reached the end of the names array
                                          r++; //iterates r to move to the new vertice
                                        }
                                        h++;

                                        if(h == count-1) {
                                          h = 0; //resets the names array so we start again from Atlanta to Yamika
                                        }

                                   
                               }
                               break;
                             }

                          }       
                        }

string vertice1key;
string vertice2key;
string djstring1;
string djstring2;
int t = 0;
int number;
string input = "1"; //this will allow the loop to run the first time
int currently_running = true; //this will help us break out when done running a function

  while(currently_running == true) {
    if(input > "3" || input < "0") { //valid input
        cout << "Please choose a different input value.\n";
        currently_running = false;
        break;
    }
    while(input < "3" && input > "0") { //if input is valid
        input = Menu(); //uses a function in my four.cpp file
        switch(stoi(input)){ 
          case 1:
                    cout << "1. Print Vertices" << endl; 
                    g.print();
                    currently_running = false;
                    break;
            case 2:
                    cout << "2. Find districts" << endl;
                    g.SetDistrictID(count);
                    currently_running = false;
                    break;
                    
            case 3:
                    cout << "3. Find shortest unweighted path" << endl;
                    cout << "What's the name of the first city?" << endl;
                    getline(cin, vertice1key);
                    cout << "What's the name of the second city?" << endl;
                    getline(cin, vertice2key);
                    g.ShortestUnweightedPath(vertice1key, vertice2key);
                    currently_running = false;
                    break;
            case 4:
                    cout << "4. Find shortest weighted path" << endl;
                    cout << "What's the name of the first city?" << endl;
                    getline(cin, djstring1);
                    cout << "What's the name of the second city?" << endl;
                    getline(cin, djstring2);
                    cout << g.DijkstrasAlgorithm(djstring1, djstring2, count);
                    currently_running = false;
                    break;
            case 5:

                  cout << "5. Run Zombie Infection" << endl;
                  cout << "The number of times it took for the infection to run its course: ";
                  number = g.Infection(t);
                  cout << number << "\n";
                  cout << "\n";
                  currently_running = false;
                   break;
            case 6:
                    cout << "Extra Credit Option";
                    currently_running = false;
                    break;
            case 7:
                  cout << "Quit \n";
                  g.~Graph();
                  currently_running = false;
                  break;
            case 8: 
                cout << "8. Please run this after every iteration of a search algorithm" << "\n";
                cout << "It will reset the previous values." << "\n";
                g.ClearPrevious();
                currently_running = false;
                break;
             }
         }
}
}



