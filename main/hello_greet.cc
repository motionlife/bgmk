#include "main/hello_greet.h"
#include <string>

using namespace demo;

std::string get_greet(const Person& who) {
  return "Hello " + who.name() + ", your email: " + who.email();
}
