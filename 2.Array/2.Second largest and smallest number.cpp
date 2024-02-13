//T.C=O(n)
//A.S=O(1)

pair<int,int> lar_secLar(vector<int>& nums){
    int n=nums.size();
    int lar=-1,secLar=-1;
    for(int i=0;i<nums.size();i++){
        if(lar == -1 || nums[lar]<=nums[i]){
            secLar=lar;
            lar=i;
        }
        else if(secLar == -1 || nums[secLar]<=nums[i])
                secLar=i;
    }
  return {lar,seclar};
}
pair<int,int> small_secSmall(vector<int>& nums,vector<int>& res){
    int n=nums.size();
    int smal=-1,secSmal=-1;
    for(int i=0;i<n;i++){
        if(smal == -1 || nums[smal]>=nums[i]){
            secSmal=smal;
            smal=i;
        }
        else if(secSmal == -1 || nums[secSmal]>= nums[i])
            secSmal=i;
    }
    return {smal,secSmal};
}
