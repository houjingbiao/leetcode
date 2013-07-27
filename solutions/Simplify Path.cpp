class Solution {
public:
	string simplifyPath(string path) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		char * pch;
		pch = strtok((char*)path.c_str(), "/");
		vector<string> vec_strs;
		while(pch){
			if(strcmp(pch, "..") == 0)
			{
				if(vec_strs.size() > 0)
					vec_strs.pop_back();
			}
			else if(strcmp(pch, ".") != 0)
				vec_strs.push_back(string(pch));

			pch = strtok(NULL, "/");
		}

		string ret;
		if(vec_strs.size() > 0){
			for(int i = 0; i < vec_strs.size(); i++){
				ret += "/";
				ret += vec_strs[i];
			}
		}
		else
			ret += "/";
		return ret;
	}
};







//version 2: don't use strtok()
class Solution {
public:
	string simplifyPath(string path) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<string> vec_strs;
		int i = 0;
		string str;
		do{
			if(str == string(".."))
			{
				if(vec_strs.size() > 0)
					vec_strs.pop_back();
			}
			else if(str != string(".") && !str.empty())
				vec_strs.push_back(str);

			while(i < path.size() && path[i] == '/')
				i++;

			str.clear();
			for(; i < path.size(); i++)
			{
				if(path[i] != '/')
					str += path[i];
				else
					break;
			}
		}while(!str.empty());//this method avoid to deal with the last string after the loop

		string ret;
		if(vec_strs.size() > 0){
			for(int i = 0; i < vec_strs.size(); i++){
				ret += "/";
				ret += vec_strs[i];
			}
		}
		else
			ret += "/";
		return ret;
	}
};