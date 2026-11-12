#include "arguments.hpp"
#include <cstdlib>
#include <print>
#include <iostream>
#include <filesystem>
#include <fstream>

using namespace std;
namespace fs = std::filesystem;

void noArgument() { // if No Argument is added
  int choosen {};
  println("No Arguments Found");
  println("Select Workspace: ");
  println("1. C++");
  println("2. HTML");

  print("\nInput: ");
  while (cin >> choosen) {
    if (choosen == 1) { // C++
      println("Making Workpace for C++");
      // cpp();
      println("Done!");
    } else if (choosen == 2) { // HTML
      println("Making Workpace for HTML");
      // html();
      println("Done!");
    } 
    else {
      cin.clear();
      cin.ignore(10000, '\n');
      println("{} is not in the Options", choosen);
      continue;
    }

    break;
  }
}

void cpp() { // C++ Workpace generator
  fs::path directories[2] = {"include", "src"};

  for (const auto& i : directories) {
    if (fs::create_directory(i)) println("{}[SUCCESS]:{} {}/ was created successfully", GREEN, RESET, static_cast<string>(i));
    else println("{}[WARNING]:{} {}/ already exist or failed to create!", RED, RESET, static_cast<string>(i));
  }

  ofstream clangd(".clangd");
  if (!clangd) {
    println(stderr, "{}[WARNING]:{} clangd failed to open for writing!", RED, RESET);
    exit(1);
  }

  clangd << "CompileFlags:\n";
  clangd << "  Add: [-std=c++23, -I../include]\n";
  clangd.close();
  println("{}[SUCCESS]:{} .clangd was created successfully", GREEN, RESET);

  ofstream cnr("compileNrun");
  if (!clangd) {
    println(stderr, "{}[WARNING]:{} compileNrun failed to open for writing!", RED, RESET);
    exit(1);
  }

  cnr << "#!/bin/bash\n";
  cnr << "rm -f main\n";
  cnr << "g++ -std=c++23 -Iinclude src/*.cpp -o main\n";
  cnr << "./main\n";
  cnr.close();
  println("{}[SUCCESS]:{} compileNrun was created successfully", GREEN, RESET);

  ofstream maincpp("src/main.cpp");
  if (!maincpp) {
    println(stderr, "{}[WARNING]:{} src/main.cpp failed to open for writing!", RED, RESET);
    exit(1);
  }

  maincpp << "#include <print>\n";
  maincpp << "using namespace std;\n\n";
  maincpp << "int main() {\n";
  maincpp << "  println(\"Hello, World!\");\n\n";
  maincpp << "  return 0;\n}";


  system("chmod +x compileNrun");
  println("{}[SUCCESS]:{} compileNrun is now an executable file", GREEN, RESET);
}

