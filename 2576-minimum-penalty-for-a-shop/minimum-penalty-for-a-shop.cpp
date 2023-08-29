class Solution {
public:
    int bestClosingTime(string customers) {
        int curr = count(customers.begin(), customers.end(), 'Y');
        int mini = curr;
        int res = 0;

        for (int i = 0; i < customers.size(); i++) {
            char ch = customers[i];

            if (ch == 'Y') {
                curr--;
            } else {
                curr++;
            }

            if (curr < mini) {
                res = i + 1;
                mini = curr;
            }
        }

        return res;
    }
};