#include <iostream>
#include <string>
#include "./src/parser.cpp"
#include "./src/interpreter.cpp"
using namespace std;

int main()
{
  // the DOM tree
  DomTree *tree = nullptr;

  Interpreter::readCommand(tree);
  return 0;
}