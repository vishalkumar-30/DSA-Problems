/*
class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int res=0;
        string number="";
        int i=0, j=n-1;
        //leading zeroes
        while(i<n && j>=0){
            if(s[i]==' ') i++;
            if(s[j]==' ') j--;
        }
        char sign = '+';
        int indx = i;
        // bool minusFound=false;
        while(i<n && (s[i]!='-')){ 
            i++;
            sign = s[i];
            
        }
        if(sign == '+') i=indx;
        else{ 
            if(i<n)i++;
        }

        bool digitFound = false;
        //trailing non digit and zeroes
        while(!digitFound && i<n){
            if(s[i]>'0' && s[i]<'9' && !digitFound){
                digitFound = true;
            }
            else{
                i++;
            }
        }
        number.push_back(s[i]);
        i++;
        while(i<n){
            if(s[i]>='0' && s[i]<'9'){
                number.push_back(s[i]);
                i++;
            }
            else i++;
        }
        long long int value = stoi(number);
        res = (int)value;
        if(sign)
        return res;
        return 0;
    }
};
*/

class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        string number = "";
        int i = 0;

        // Skip leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Handle sign
        char sign = '+';
        if (s[i] == '-' || s[i] == '+') {
            sign = s[i];
            i++;
        }

        // Extract digits
        while (i < n && isdigit(s[i])) {
            number.push_back(s[i]);
            i++;
        }

        // Convert to long long
        long long value = 0;
        for (char c : number) {
            value = value * 10 + (c - '0');
            if (value > INT_MAX) {
                break; // Overflow
            }
        }

        // Apply sign
        if (sign == '-') {
            value = -value;
        }

        // Check for integer overflow
        if (value < INT_MIN) {
            return INT_MIN;
        } else if (value > INT_MAX) {
            return INT_MAX;
        }

        return static_cast<int>(value);
    }
};
