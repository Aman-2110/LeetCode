class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int j = 0, curr_size = 0;
        vector<string> res;
        for(int i = 0 ; i < words.size() ; i++){
            curr_size += words[i].size() + 1;
            if(curr_size > maxWidth + 1){
                string line = "";
                if(i == j + 1){
                    line += words[j];
                    for(int k = line.size() ; k < maxWidth ; k++)
                        line += ' ';
                    curr_size = words[i].size() + 1;
                    j = i;
                }else{
                    int prev_line_size = curr_size - words[i].size() - 2;
                    int extra_spaces = maxWidth - prev_line_size;
                    int number_of_gaps = i - j - 1;
                    curr_size = words[i].size() + 1;
                    int each_space = (extra_spaces) / (i - j - 1) + 1;
                    int start_space = (extra_spaces) % (i - j - 1);
                    for(; j < i ; j++){
                        line += words[j];
                        for(int k = 0 ; j != i - 1 && k < each_space ; k++){
                            line += ' ';
                        }
                        if(start_space > 0){
                            line += ' ';
                            start_space--;
                        }
                    }
                }
                res.push_back(line);
            }
        }
        string line = "";
        for(; j < words.size() ; j++)
            line += words[j] + ' ';

        if(line.size() == maxWidth + 1)
            line.pop_back();
        
        for(int k = line.size() ; k < maxWidth ; k++)
            line += ' ';

        res.push_back(line);

        return res;
    }
};
