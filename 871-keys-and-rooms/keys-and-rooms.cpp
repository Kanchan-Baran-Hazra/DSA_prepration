class Solution {
    void helper(int src,vector<vector<int>>& rooms,vector<bool>& mark){
        mark[src]=true;

        for(int i=0;i<rooms[src].size();i++){
            if(!mark[rooms[src][i]]){
                helper(rooms[src][i],rooms,mark);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> mark(n,false);

        helper(0,rooms,mark);

        for(int i=0;i<n;i++){
            if(!mark[i]) return false;
        }

        return true;
    }
};