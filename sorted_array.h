#include <vector>
#include <set>
using namespace std;
class SortedArray{
        public:
                SortedArray(vector<int> data){
                        arr = data;
                        n = arr.size();
                        sort(arr.begin(),arr.end());
                }
                multiset<int> range_query(int l,int r){
                        vector<int> ret;
                        auto begin = lower_bound(arr.begin(),arr.end(),l);
//						auto begin = arr.begin(); 
                        for(;begin != arr.end();begin ++){

								if(*begin > r){
                                        break;
                                }
					
                                ret.push_back(*begin);
                        }
                        return multiset<int>(ret.begin(),ret.end());
                }
        private:
                vector<int> arr;
                int n;
};
