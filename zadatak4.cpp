#include<iostream>
#include<functional>
#include<vector>

typedef std::vector<std::function<bool(int)>> fun;

void default_if_not_all(std::vector<int>& v, fun& f,int x = -1){
  for(int i = 0; i<v.size(); i++){
  
    for(int j = 0; j<f.size(); j++){
       if(!(f[j](v[i])))
         v[i] = x;
    }
  }
}

int main(int argc, char *argv[])
{
  std::vector<int> v1{2,6,8,40,3,4,11};
  fun vf;

  vf.push_back([&](int num){return num > 0;});
  vf.push_back([&](int num){return num < 50;});
  vf.push_back([&](int num){return !(num%2);});

  default_if_not_all(v1,vf);

  for(auto e : v1){
    std::cout<<e<<" "<<std::endl;
  }
  



  return 0;
}
