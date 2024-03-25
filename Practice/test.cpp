#include <bits/stdc++.h>
using namespace std;

struct file {
    string fileName;
    int size;
};

class Solution {
    int totalSize;
    unordered_map<string, int> collections;
    unordered_map<string, set<file>> colToFile;

public:
    Solution () {
        totalSize = 0;
    }

    void addFile(file& newFile) {
        totalSize += newFile.size;
    }

    void addFileAndCollection(file& newFile, string collection) {
        addFile(newFile);
        collections[collection] += newFile.size;
    }

    void addCollectionTag(file& file, string collection) {
        colToFile[collection].insert(file);
    }
    
    //Time: O(clogn) where c is the number of collections
    //Space: O(n) extra space apart from the hashmaps
    vector<string> getTopNCollections(int n) {
        // if(n == 0) return {};
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
        for(auto collection : collections) {
            if(pq.size() < n) {
                pq.push({collection.second, collection.first});
            }
            else if(!pq.empty()) {
                //maintain top n collections by size
                int topSize = pq.top().first;
                if(collection.second > topSize) {
                    pq.pop();
                    pq.push({collection.second, collection.first});
                }
            }
        }

        vector<string> answer;
        while(!pq.empty()) {
            answer.push_back(pq.top().second);
            pq.pop();
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
    
    int getTotalSize() {
        return totalSize;
    }
};

int main() {
    Solution s;

    file f1{"file1.txt", 100};
    file f2{"file2.txt", 501};
    file f3{"file3.txt", 200};
    file f4{"file4.txt", 300};
    file f5{"file5.txt", 10};
    
    s.addFile(f1);
    s.addFileAndCollection(f2, "collection1");
    s.addFileAndCollection(f3, "collection2");
    s.addFileAndCollection(f4, "collection2");
    s.addFile(f5);

    vector<string> ans = s.getTopNCollections(2);
    for(auto collection : ans) cout << collection << '\n';
    cout << "Total Size: " << s.getTotalSize() << '\n';
    
    return 0;
}