class Solution {
public:
	int getOneLine(vector<string> &words, int pos, int width_limitation){
		if(pos >= words.size()) return 0;
		int len = words[pos].length();
		int i = 1;
		while(pos+i < words.size() && len + words[pos+i].length() + 1 <= width_limitation){
			len += words[pos+i].length() + 1;
			i++;
		}
		return i;
	}
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<string> rets;
		if(words.size() == 0) return rets;
		int word_count = 0;
		int pos = 0;
		while((word_count = getOneLine(words, pos, L))>0){
			string line;
			bool isEnd = (pos + word_count == words.size());
			if(isEnd){
				line = words[pos];
				int i = 1;
				for(; i < word_count; i++){
					line += " ";
					line += words[pos+i];
				}
				line += string(L - line.length(), ' ');
				rets.push_back(line);
				break;
			}
			else if(word_count == 1){
				line += words[pos];
				line += string(L - words[pos].length(), ' ');
			}
			else{
				int letter_count = 0;
				int i = 0;
				while(i < word_count)
					letter_count += words[pos+i++].length();
				int space_count = L - letter_count;
				int big_interval_count = space_count%(word_count-1);
				int interval_length = space_count/(word_count-1);
				line = words[pos];
				i = 1;
				while(i < word_count){
					if(i <= big_interval_count) line += string(interval_length+1, ' ');
					else line += string(interval_length, ' ');
					line += words[pos+i];
					i++;
				}
			}
			rets.push_back(line);
			pos += word_count;
		}
        return rets;
    }
};