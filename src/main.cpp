#include <iostream>
#include <dlfcn.h>

int main(int argc,char *argv[])
{
  auto hModule = dlopen("libpr_chromium_wrapper.so",RTLD_LAZY | RTLD_GLOBAL);
  std::cout<<((hModule != NULL) ? "success" : "failure")<<std::endl;
}
