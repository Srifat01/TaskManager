#include <iostream>
#include<string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;
class Task {
private:
    string description;
    bool done;
public:
    Task(const string& des) : description(des), done(false) {}
    string getDes(){ 
        return description; }
    bool isDone(){ 
        return done; 
    }
    void StatusDone(){
        done = true;
    }
};

class TaskM {
private:
    vector<Task> tasks;
    string filename="tasks.txt";
    void savefile(){
        ofstream outFile(filename);
        if(!outFile){
            cout<<"Couldn't Save Task Files "<<endl;
            return;
        }
        
        for(auto& task : tasks){
            outFile<< task.getDes() << "|" << (task.isDone() ? "1" : "0") << endl;
                    
        }
        outFile.close();
    }

void loadfile() {
    ifstream inFile(filename);
    if(!inFile) return;
    tasks.clear();
    string line;
    while (getline(inFile, line)) {
        auto parseLine= [](const string& l) -> pair<string, bool> {
            size_t delimPos = l.find('|');
            if(delimPos == string::npos) return {"", false};
            string desc= l.substr(0, delimPos);
            string statusStr = l.substr(delimPos + 1);
            statusStr.erase(statusStr.find_last_not_of(" \n\r\t") + 1);
            bool completed = (statusStr == "1");
            return {desc, completed};
        };
        auto [desc, completed]= parseLine(line);
        if(desc.empty()) continue;
        Task task(desc);
        tasks.emplace_back(desc);
        if(completed){
            tasks.back().StatusDone();
        }
  }
}   
    public:
    TaskM(){
        loadfile();
    }
    void addTask(const string& des){
        if(des.empty()){
            cout<< "Error!! Task description cannot be empty"<<endl;
            return;
        }
        tasks.emplace_back(des);
        savefile();
        cout<< "Task added successfully"<<endl;
    }

    void completeTask(size_t index){
        if(index >= tasks.size()){
            cout<< "Error! Invalid task number"<<endl;
            return;
        }
        if(tasks[index].isDone()){
                 cout << "Task is already completed!" << endl; 
                }
                else {
                       tasks[index].StatusDone();
                       savefile();
                       cout << "Task marked as completed." <<endl; 
                    }

        savefile();
        cout<< "Task marked as completed "<<endl;
    }

    void displayTasks(){
        if(tasks.empty()){
            cout<< "No tasks available "<<endl;
            return;
        }
        
        cout<<"\nYour Tasks: "<<endl;   cout<< "           "<<endl;
        
        for(size_t i= 0; i< tasks.size(); ++i){
            cout<< i + 1 << "<< "<< tasks[i].getDes()<< "(" << (tasks[i].isDone() ? "Completed" : "○ Pending") << ")"<<endl;
        }
        cout<< "   \n";
    }
};

int main() {
    TaskM manager;
    string input;
    
    cout<<"Simple Task Manager "<<endl;
    cout<<"         "<<endl;
    
    while (true) {
        cout << "\nOptions: "<<endl; 
        cout << "1. Add Task : "<<endl; 
        cout << "2. Complete Task: "<<endl;
        cout << "3. Show All Tasks: "<<endl; 
        cout << "4. Exit "<<endl; 
        cout << "Choose an option (1-4)= "<<endl;
        getline(cin, input);
        if(input == "1") {
            cout << "Enter task that you shall do: ";
            getline(cin, input);
            input.erase(0, input.find_first_not_of(" \t"));
            input.erase(input.find_last_not_of(" \t") + 1);
            if(input.empty()){
            cout << "Error! Task description cannot be empty." << endl;
            continue; 
        }
           manager.addTask(input);
            
        }else if(input == "2") {
            manager.displayTasks();
            cout << "Enter task number to complete: ";
            getline(cin, input);    
            try {
                size_t index = stoul(input) - 1;
                manager.completeTask(index);
            } 
            catch(const exception& ) {
                cout << "Error!! << Please enter a valid number "<<endl; 
            }
            }
             else if (input == "3") {
                   manager.displayTasks();
                }
             else if (input == "4") {
                   cout << "Goodbye" <<endl;
                   break;
                }
                else{
                    cout << "Invalid option!! Please choose 1-4" <<endl;
                }
            }
            
        return 0;
        }