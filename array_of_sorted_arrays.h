#include <vector>
#include <set>
using namespace std;
class AofA{
        public:
                AofA(vector<int> _data){
                        data.resize(1);
                        temp.resize(1);
                        for(int t: _data){
                                temp[0].push_back(t);
                                update();
                                temp[0].clear();
                        }
                }
                multiset<int> range_query(int l,int r){
						vector<int> arr;
                        multiset<int> ret;
                        for(auto it : data){
								auto begin = lower_bound(it.begin(),it.end(),l);
                                for(; begin != it.end(); begin++){
                                        if(*begin > r){
                                                break;
                                        }
                                        arr.push_back(*begin);
                                }
                        }
                        return multiset<int>(arr.begin(),arr.end());
                }
                void update(){
                        int i = 0;
                        while(temp[i].size() + data[i].size() > pow(2,i)){
                                if(i == data.size()-1){
                                        data.push_back(vector<int>());
                                        temp.push_back(vector<int>());
                                }
                                merge(data[i],temp[i],temp[i+1]);
                                temp[i].clear();
                                data[i].clear();
                                i += 1;
                        }
                        vector<int> t(data[i]);
                        data[i].clear();
                        merge(t,temp[i],data[i]);
                        temp[i].clear();

                }
                void merge(vector<int> &a,vector<int> &b,vector<int> &tar){
                        int i = 0;
                        int j = 0;
                        while(i < a.size() or j < b.size()){
                                if(j >= b.size() or (i < a.size() and a[i] < b[j])){
                                        tar.push_back(a[i]);
                                        i++;
                                }else{
                                        tar.push_back(b[j]);
                                        j++;
                                }
                        }
                }
        private:
                vector<vector<int>> data;
                vector<vector<int>> temp;
};
