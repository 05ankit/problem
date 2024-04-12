struct Node{
    Node *links[26];
    int score=0;
    bool containskey(char ch)
    {
        return (links[ch-'a']!=NULL);
    }
    void put(char ch,Node* node)
    {
        
        links[ch-'a']=node;
        node->score+=1;
    }
    Node *get(char ch)
    {
        return links[ch-'a'];
    }
};
class Solution {
private: Node* root;
public:
    Solution() {
        root=new Node();
    }
    void insert(string words) {
        Node* node = root;
        for(int i=0;i<words.length();i++)
        {
            if(!node->containskey(words[i]))
            {
                node->put(words[i],new Node());
                node=node->get(words[i]);
            }
            else{
                node=node->get(words[i]);
                node->score=node->score+1;
            }   
        }
    }
    int search(string word) {
        Node* node = root;
        int count=0;
        for(int i=0;i<word.length();i++)
        {
            if(!node->containskey(word[i]))
            {
                return count;
            }
            node=node->get(word[i]);
            count+=node->score;

        }  
        return count;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> ans;
        for(int i=0;i<words.size();i++)
        {
            insert(words[i]);
        }
        for(int i=0;i<words.size();i++)
        {
            ans.push_back(search(words[i]));
        }
        return ans;
    }
};
