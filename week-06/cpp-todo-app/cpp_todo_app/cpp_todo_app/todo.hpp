//
//  todo.hpp
//  cpp_todo_app
//
//  Created by Oz on 11/16/17.
//  Copyright © 2017 Oscar Inc. All rights reserved.
//

#ifndef todo_hpp
#define todo_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Todo_app_class{
private:
    void command_splitter(string user_input);
    
protected:
    struct task_struct{
        string description;
        int priority;
        bool completed;
    };
    
    string user_input;
    string command;
    string task;
    string priority;
    vector<task_struct> task_vector;
    
    void clear_screen();

public:
    Todo_app_class(){ //starts prg with print usage and input
    }
    ~Todo_app_class(){
    }
    void goodbye_screen();
    void input_command();
    void print_usage();
    void task_executer(string command, string task, string priority);
    void print_vector(){
        for(unsigned int i = 0; i < task_vector.size(); i++){
            cout << task_vector[i].description <<" ";
            cout << task_vector[i].priority << " ";
            cout << task_vector[i].completed << endl;
        }
    }
};


#endif /* todo_hpp */
