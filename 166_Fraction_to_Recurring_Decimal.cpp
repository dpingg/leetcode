//transform integer to string using stringstream
//using hash map for calculating circulating decimal
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(denominator==0 || numerator==0) {
            return "0";
        }
        string ans=((numerator<0)^(denominator<0))==1 ? "-":"";
        long a=abs(long(numerator));
        long b=abs(long(denominator));
        
        stringstream os;
        os<<a/b;
        ans += os.str();
        
        if(a%b==0) {
            return ans;
        }
        
        ans += ".";
        long x=a%b;
        string frac = "";
        unordered_map<int, int> pos_map;
        while(x) {
            long d=(x*10)/b;
            stringstream os;
            os<<d;
            frac += os.str();
            pos_map[x]=frac.size()-1;
            x=(x*10)%b;
            if(pos_map.find(x)!=pos_map.end()) {
                int i = pos_map[x];
                ans += string(frac, 0, i) + "(" + string(frac, i, frac.size()-i) + ")";
                return ans;
            }
        }
        ans += frac;
        return ans;
    }


};
