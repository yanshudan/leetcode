struct TrieNode{
    vector<TrieNode*> children;
    bool is_word;
    TrieNode():children(26,nullptr),is_word(false){};
};
class Trie {
    TrieNode* root;
    TrieNode* curr;
public:
    /** Initialize your data structure here. */
    Trie() {
        root=new TrieNode();
        curr=nullptr;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        curr=root;
        for(auto& c:word){
            auto& ptr=curr->children[c-'a'];
            if(ptr==nullptr) ptr=new TrieNode();
            curr=ptr;
        }
        curr->is_word=true;
    }
    bool search(string& word,int begin,TrieNode* croot) {
        if(croot==nullptr) return false;
        if(begin==word.size()) return croot->is_word;
        auto c=word[begin];
        if(c=='.'){
            for(auto ptr:croot->children){
                if(search(word,begin+1,ptr)) return true;
            }
            return false;
        }else{
            return search(word,begin+1,croot->children[c-'a']);
        }
    }
    /** Returns if the word is in the trie. */
    bool search(string word) {
        curr=root;
        for(auto& c:word){
            auto& ptr=curr->children[c-'a'];
            if(ptr==nullptr) return false;
            curr=ptr;
        }
        return curr->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        curr=root;
        for(auto& c:prefix){
            auto& ptr=curr->children[c-'a'];
            if(ptr==nullptr) return false;
            curr=ptr;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */