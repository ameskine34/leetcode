class Solution {
public:
    string reverseStr(string s, int i)
    {
        std::reverse(s.begin(), s.end());
        while ((int)s.size() < i)
            s.push_back('0');
        return s;
    }

    int size(ListNode* head) {
        int count = 0;
        ListNode* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    string addStrings(const string& a, const string& b) {
        string result;
        int i = (int)a.size() - 1, j = (int)b.size() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int x = (i >= 0) ? a[i--] - '0' : 0;
            int y = (j >= 0) ? b[j--] - '0' : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            result.push_back('0' + (sum % 10));
        }
        std::reverse(result.begin(), result.end());
        return result;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int i = size(l1);
        int j = size(l2);
        int maxLen = std::max(i, j);
        ListNode* current1 = l1;
        ListNode* current2 = l2;
        ListNode* result = NULL;
        ListNode* sup = NULL;
        string res, res1;

        while (maxLen)
        {
            if (current1)
            {
                res += std::to_string(current1->val);
                current1 = current1->next;
            }
            if (current2)
            {
                res1 += std::to_string(current2->val);
                current2 = current2->next;
            }
            maxLen--;
        }

        string a = reverseStr(res, i);
        string b = reverseStr(res1, j);
        string o = addStrings(a, b);

        if (o == "0")
            return new ListNode(0);

        ListNode* node;
        for (int k = (int)o.size() - 1; k >= 0; k--)
        {
            node = new ListNode(o[k] - '0');
            if (result == NULL)
            {
                result = node;
                sup = node;
            }
            else
            {
                result->next = node;
                result = result->next;
            }
        }
        return sup;
    }
};