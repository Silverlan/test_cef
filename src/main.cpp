#include <iostream>
#include <dlfcn.h>

int main(int argc,char *argv[])
{
  auto hModule = dlopen("./modules/chromium/libpr_chromium_wrapper.so",RTLD_LAZY | RTLD_GLOBAL);
  std::cout<<((hModule != NULL) ? "success" : "failure")<<std::endl;
  if(hModule == NULL)
  {
    auto *msg = dlerror();
    if(msg)
      std::cout<<"Error: "<<msg<<std::endl;
  }
  return 0;
}
