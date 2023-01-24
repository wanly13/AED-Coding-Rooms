#include <iostream>
#include <unordered_map>
//#include "chainhash.h"

using namespace std;

void porUnordered(){
    unordered_map<string , string > hash;
    hash["wanly"] = "obregon";
    hash["heider"] = "sanchez";
    hash["hola"] = "mmundo";
    hash["noelia"] = "cm";
    int n = hash.bucket_count();
    cout << "Capacidad del hashtable: " << n << endl;

    for(int i=0 ; i < n ; i++){
        cout<< "bucket #" << i << " tiene " << hash.bucket_size(i) << endl;
        for(auto it = hash.begin(i); it!= hash.end(i); ++it)
            cout << "[" << it-> first << " : " << it -> second << "]";
        cout << endl;
    }
}

void porChainHash(){
    /* ChainHash<string, string> hash;
    hash.set("heider","sanchez");
    hash.set("maria","vega");
    hash.set("paolo", "vasquez");
    hash.set("heider", "gonzales");
    
    for(int i=0;i<26;i++)
        hash.set('a'+i, 'a'+i);
    
    hash.remove("a");
    hash.remove("Z");

    int n = hash.bucket_count();
    cout<<"Capacidad del hashtable "<<n<<endl;
    for(int i = 0; i<n;i++){
        cout<<"Bucket #"<<i<<" tiene "<<hash.bucket_size(i)<<endl<<"\t";
        for(auto it = hash.begin(i); it != hash.end(i); ++it)
            cout<<"["<<it->first<<":"<<it->second<<"]";
        cout<<endl;
    }
     */
}

int main(){
    porUnordered();
    return 0;
}