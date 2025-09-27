# Simple Task Manager

A basic console-based **Task Manager** written in **C++** that allows you to:

- Add tasks
- Mark tasks as completed
- View all tasks
- Save and load tasks from a file

## Features

- **Persistent storage**: Tasks are saved in `tasks.txt` and reloaded when the program starts.
- **Task status tracking**: Each task can be marked as **Completed** or **Pending**.
- **Input validation**: Prevents empty tasks and invalid task numbers.
- **Simple user interface**: Text-based console interaction.

## How to Use

1. Compile the program using a C++ compiler (e.g., g++):

   ```bash
    g++ -o TaskManager TaskManager.cpp
## Run

1.Run windows and Linux
  ```bash
    ./TaskManager   # Linux/macOS
    TaskManager.exe # Windows

