class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>ans;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        set<pair<int,int>> s;

        int i=0;
        int j=0;

        pair<int,int>p1;
        p1.first=i;
        p1.second=j;
        s.insert(p1);

        pq.push({nums1[i]+nums2[j],p1});

        while(pq.size()!=0 && k>0){
            pair<int,pair<int,int>>tops=pq.top();
            pq.pop();
            i=tops.second.first;
            j=tops.second.second;

            vector<int>sub;
            sub.push_back(nums1[tops.second.first]);
            sub.push_back(nums2[tops.second.second]);
            ans.push_back(sub);

            if(i+1<nums1.size()){
                i++;
                pair<int,int>p1;
                p1.first=i;
                p1.second=j;

                if(s.find(p1)==s.end()){
                    s.insert(p1);
                    pq.push({nums1[i]+nums2[j],p1});
                }
                i--;
            }
            if(j+1<nums2.size()){
                j++;
                pair<int,int>p1;
                p1.first=i;
                p1.second=j;

                if(s.find(p1)==s.end()){
                    s.insert(p1);
                    pq.push({nums1[i]+nums2[j],p1});
                }
                j--;
            }
            k--;
            // i++;
            // j++;
        }

        return ans;
    }
};