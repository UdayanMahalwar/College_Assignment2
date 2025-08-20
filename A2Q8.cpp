int distinct(vector<int>& arr) {
    // Your code here
    unordered_map<int,bool> check;
    int count=0;
    for(int i=0;i<arr.size();i++)
    {
        int curr=arr[i];
        if(check[curr]==0)
        {
            count++;
            check[curr]=true;
        }
    }
    return count;
}