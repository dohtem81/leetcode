class Solution {
public:
    string addBinary(string a, string b) {
        string *longer = (a.length() > b.length() ? &a : &b);
        string *shorter = (a.length() <= b.length() ? &a : &b);
        bool carry = false;
        unsigned idx_long = longer->length();

        std::string::reverse_iterator lit = longer->rbegin();
        for(std::string::reverse_iterator sit = shorter->rbegin(); 
            sit != shorter->rend(); 
            sit++, lit++)
        {
            int count = 0;
            count += (*sit == '1' ? 1 : 0);
            count += (*lit == '1' ? 1 : 0);
            count += (carry ? 1 : 0);
            
            // update now
            carry = count > 1;
            *lit = (count == 1 || count == 3 ? '1' : '0');
        }

        while(carry && lit != longer->rend())
        {
            int count = 0;
            count += (*lit == '1' ? 1 : 0);
            count += (carry ? 1 : 0);

            // update now
            carry = count > 1;
            *lit = (count == 1 ? '1' : '0');

            lit++;
        }

        // now last item
        if(carry)
            *longer = "1" + (*longer);

        return *longer;
    }
};