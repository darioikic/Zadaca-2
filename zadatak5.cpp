#include<iostream>
#include<list>
#include<functional>

typedef std::function<bool(int)> fun;

std::list<int> filter(const std::list<int>& l1, fun f){
  std::list<int>::const_iterator it;
  std::list<int> l2;
  it = l1.begin();

  while(it!=l1.end()){
  if(f(*it))
    l2.push_back(*it);
  it++;
  }
  return l2;
}

int main(int argc, char *argv[])
{

  std::list<int> list_{1,13,14,5,7,10,8};

  auto lam = [&](int n){return !(n%2);};
 
  std::list<int> rez = filter(list_,lam);

  for(auto e : rez){
    std::cout<<e<<" ";
  }
  


  return 0;
}
