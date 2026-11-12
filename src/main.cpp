#include "arguments.hpp"
#include <print>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
  bool withArgument = (argc > 1) ? true : false;

  
  if (!withArgument) noArgument();
  else {
    string arg = argv[1];
    if (arg == "cpp") cpp();
    else if (arg == "html") print("html");
    else println("Argument not valid");
  }

  return 0;
}
