// https://leetcode.com/problems/validate-ip-address/

// Just another tedious solution.

class Solution {
public:
    bool validIPv6(string ip, int count){
        if(count > 7 || ip.size() == 0) return false;
        int i = 0;
        while(ip[i] != ':' && i < ip.size()){
            bool flag = true;
            if(ip[i] >= '0' && ip[i] <= (9 + '0'))
                flag = false;
            else if(ip[i] >= 'a' && ip[i] <= 'f')
                flag = false;
            else if(ip[i] >= 'A' && ip[i] <= 'F')
                flag = false;
            if(i > 3) flag = true;
            if(flag)
                return false;
            ++i;
        }
        if(i == 0) return false;
        if(count == 7 && i == ip.size())
            return true;
        else if(i == ip.size())
            return false;
        return validIPv6(ip.substr(i + 1), count + 1); 
    }
    bool validIPv4(string ip, int count){
        if(count > 3 || ip.size() == 0) return false;
        int i = 0;
        while(ip[i] != '.' && i < ip.size()){
            if(ip[i] < '0' || ip[i] > (9 + '0') || i > 2)
                return false;
            ++i;
        }
        if((i > 1 && ip[0] == '0') || i == 0) return false;
        if(stoi(ip.substr(0, i)) > 255)
            return false;
        if(count == 3 && i == ip.size())
            return true;
        else if(i == ip.size())
            return false;
        return validIPv4(ip.substr(i + 1), count + 1);  
    }
    string validIPAddress(string IP) {
        if(validIPv4(IP, 0)) return "IPv4";
        if(validIPv6(IP, 0)) return "IPv6";
        return "Neither";
    }
};