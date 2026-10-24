class Solution {
    public int lengthOfLongestSubstring(String s) {

        int n = s.length();
        if(n==0 || n==1) return n; 
        int ans = Integer.MIN_VALUE;
        HashMap<Character,Integer>m= new HashMap<>();
        for(int i=0;i<n-1;i++){
            m.put(s.charAt(i),m.getOrDefault(s.charAt(i),0)+1);
            int j=i+1;
            int cnt = 1;
            while(j<n && ! m.containsKey(s.charAt(j))){
                m.put(s.charAt(j),m.getOrDefault(s.charAt(j),0)+1);
                j++;
                cnt++;
            }
            m.clear();
            ans=Math.max(ans,cnt);
        }
        return ans;
    }
}
