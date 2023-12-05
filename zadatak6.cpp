#include<iostream>
#include<list>
#include<functional>

typedef std::function<int(int)> fun;

std::list<int> map(const std::list<int>& l1,fun f){

  std::list<int> rez;
  std::list<int>::const_iterator it;
  it = l1.begin();

  while(it!=l1.end()){
  rez.push_back(f(*it));
  it++;
  }
  return rez;
}

int main(int argc, char *argv[])
{
  std::list<int> list_1{2,4,6,8,10};
  auto lam = [](int num){return 2*num;};

  std::list<int> rez = map(list_1,lam);

  for(auto e : rez){
    std::cout<<e<<" ";
  }
  return 0;
}
