class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        
        // for indices sorting according the first element
        vector<pair<int, int>> sort_indices;
        for(int i = 0 ; i < indices.size() ; i++)
        {
            sort_indices.push_back({indices[i], i});
        }
        
        sort(sort_indices.begin(), sort_indices.end());
        
        string ans = "";
        int curidx = 0;
        
        for(int i = 0 ; i < sort_indices.size() ; i++)
        {
            // indices (3, 5, 1)
            // sort_indices ({3, 0}, {5, 1}, {1, 2})
            // sort_indices ({1, 2}, {3, 0}, {5, 1})
            
            if(sort_indices[i].first != curidx)
            {
                for(int j = curidx ; j < sort_indices[i].first ; j++)
                {
                    ans = ans + s[j];
                    curidx = curidx + 1;
                }
            }
            
            string substr = s.substr(sort_indices[i].first, sources[sort_indices[i].second].length());

            if(substr == sources[sort_indices[i].second])
            {
                ans = ans + targets[sort_indices[i].second];
                cout << ans << "!! ";
                curidx = curidx + sources[sort_indices[i].second].length();
            }

        }
        for(int j = curidx ; j < s.length() ; j++)
        {
            ans = ans + s[j];
            curidx = curidx + 1;
        }
        
        return ans;
    }
};
