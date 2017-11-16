//
//  todo.cpp
//  cpp_todo_app
//
//  Created by Oz on 11/16/17.
//  Copyright © 2017 Oscar Inc. All rights reserved.
//

#include "todo.hpp"

#include <sstream>

void Todo_app_class::input_command(){
    
    while(command != "exit"){
        cout << "Your wish is my command: ";
        getline(cin, user_input);
        command_splitter(user_input);
        task_executer(command, task, priority);
    }
}
void Todo_app_class::command_splitter(string user_input){
    
    size_t pos = user_input.find(' ');//looks for char
    
    command = user_input.substr(0, pos);//fills up string until char
    
    user_input.erase(0, pos + 2); // deletes everythin befor char in original string
    pos = user_input.find('"'); //looks for new char
    
    task = user_input.substr(0, pos);//fills up task string with other info
    
    user_input.erase(0, pos + 2);
    
    priority = user_input;
}

void Todo_app_class::task_executer(string command, string task, string priority){
    if(command == "-a"){
        add_task_function();
        print_vector();
        
    } else if(command == "-wr"){
        cout << "you want to write" << endl;
        
    } else if(command == "-rd"){
        cout << "you want to read" << endl;
        
    } else if(command == "-l"){
        cout << "you want to list" << endl;
        
    } else if(command == "-e"){
        cout << "you want to empty" << endl;
        
    } else if(command == "-rm"){
        cout << "you want to remove" << endl;
        
    } else if(command == "-c"){
        cout << "you want to complete" << endl;
        
    } else if(command == "-p"){
        cout << "you want to add priority" << endl;
        
    } else if(command == "-lp"){
        cout << "you want to list by priority" << endl;
        
    } else if(command == "exit"){
    } else{
        cout << "invalid command" << endl;
    }
}
void Todo_app_class::add_task_function(){
    cout << "you want to add" << endl;
    if(priority != ""){
        struct task_struct temp_struct = {task, stoi(priority), 0};
        task_vector.push_back(temp_struct);
    }else{
        struct task_struct temp_struct = {task, 0, 0};
        task_vector.push_back(temp_struct);
    }
}

void Todo_app_class::clear_screen(){
    cout << "screen supposed to clear here, but I have a freakin' mac...." << endl << endl;
}

void Todo_app_class::print_usage(){
    cout << "\n\n        CLI Calculator\n"
    "====================================\n"
    "usage: [number] [operation] [number]\n"
    "Commands:\n\n"
    " +    addition\n"
    " -    subtraction\n"
    " *    multiplication\n"
    " /    division\n"
    " %    division with remainder\n"
    " ^    power\n"
    " <    square root\n"
    " log    logarithm\n"
    " binto    binary to hex or dec\n"
    " hexto    hexadecimal to bin or dec\n"
    " decto    decimal to bin or hex\n"
    " ====================================\n"
    " exit    exiting from the program\n"
    " clear    clear the screen\n"
    " help    print usage\n"
    " ====================================\n"
    " Hit enter to start!\n"
    " ====================================\n";
    cin.get();
    clear_screen();
}

void Todo_app_class::goodbye_screen(){
    cout << "Thank you for using this awesome calculator" << endl;
}

void Todo_app_class::print_vector(){
    for(unsigned int i = 0; i < task_vector.size(); i++){
        cout << i + 1;
        if(task_vector[i].completed == 0){
            cout << " - [ ] ";
        }else{
            cout << " - [x] ";
        }
        cout << task_vector[i].description;
        
        if(task_vector[i].priority != 0){
            cout << " - " <<task_vector[i].priority;
        }
        cout << endl;
    }
}
