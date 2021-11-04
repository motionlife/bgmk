#include "lib/hello_time.h"
#include "main/hello_greet.h"
#include <iostream>
#include <string>
#include <sstream>
#include "absl/strings/str_join.h"
#include "proto/person.pb.h"

std::string ver_string(int a, int b, int c)
{
  std::ostringstream ss;
  ss << a << '.' << b << '.' << c;
  return ss.str();
}

std::string true_cxx =
#ifdef __clang__
    "clang++";
#else
    "g++";
#endif

std::string true_cxx_ver =
#ifdef __clang__
    ver_string(__clang_major__, __clang_minor__, __clang_patchlevel__);
#else
    ver_string(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
#endif

int main(int argc, char **argv)
{
  std::string who = "world";
  if (argc > 1)
  {
    who = argv[1];
  }

  demo::Person p;
  p.set_name("Hao");
  p.set_email("haoxiong@outlook.com");
  std::cout << get_greet(p) << std::endl;
  print_localtime();

  std::cout << true_cxx << " version " << true_cxx_ver << std::endl;
  
  std::vector<std::string> v = {"foo", "bar", "baz"};
  std::string s = absl::StrJoin(v, "-");

  std::cout << "Joined string: " << s << "\n";
  
  return 0;
}
